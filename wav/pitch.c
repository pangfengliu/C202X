#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

int seq(char c, int n)
{
  char *tune = "C D EF G A B";
  return (n * 12 + strchr(tune, c) - tune);
}

double freq(char *name)
{
  if (strcmp(name, "pause") == 0)
    return 0.0;
  assert(strlen(name) == 2 || strlen(name) == 3);
  char c = name[0];
  int n = name[1] - '0';
  assert(c >= 'A' && c <= 'G' && n >= 0 && n < 8);  
  const double r = 1.0594630943593;
  int diff = seq(c, n) - seq('A', 4);

  double f = 440.0;
  if (diff >= 0) {
    int oct = diff / 12;
    int inc = diff % 12;
    for (int i = 0; i < oct; i++)
      f *= 2.0;
    for (int i = 0; i < inc; i++)
      f *= r;
  } else {
    diff = -diff;
    int oct = diff / 12;
    int inc = diff % 12;
    for (int i = 0; i < oct; i++)
      f /= 2.0;
    for (int i = 0; i < inc; i++)
      f /= r;
  }
  if (strlen(name) == 3) {
    switch (name[2]) {
    case '#':
      f *= r;
      break;
    case 'b':
      f /= r;
      break;
    default:
      printf("invalid char %c\n", name[2]);
    }
  }
  return f;
}

#define MAXF 10

typedef struct note
{
  int feqNum;
  double frequency[MAXF];
  double duration;
} Note;

typedef struct WAVheader
{
  char RIFF[4];
  int chunkSize;
  char wave[4];
  char format[4];
  int subChunkSize;
  short audioFormat;
  short numChannel;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  char data[4];
  int dataSize;
} WAVHeader;

// #define SAMPLE 65536
#define LOWFREQTHRESHOLD 100
#define MAGNIFYFACTOR 20000
#define MAXSAMPLE 100000

#define min(a, b) (a < b? a:b)


int genWAV(Note note[], int noteNum, FILE *fp, WAVHeader header)
{
  int dataSize = 0;
  const double PI = 3.1415926;


  for (int n = 0; n < noteNum; n++) {
    int sampleNum = note[n].duration * header.sampleRate;
    assert(sampleNum < MAXSAMPLE);
    printf("sample number %d\n", sampleNum);
    short int samples[MAXSAMPLE * 2] = {0}; /* two channels */
    
    for (int f = 0; f < note[n].feqNum; f++) {
      double frequency = note[n].frequency[f];
      if (frequency < LOWFREQTHRESHOLD) {
	printf("warning, low frequency %lf\n", frequency);
	assert(note[n].feqNum == 1);
	short zero[MAXSAMPLE * 2] = {0};
	fwrite(zero, sizeof(short), 2 * sampleNum, fp);
	dataSize += sizeof(short) * 2 * sampleNum;
	break;			/* get out of loop */
      } else {
	int samplePerCycle = header.sampleRate / (double)frequency;
	assert(samplePerCycle < sampleNum);
	printf("%d samples per cycle\n", samplePerCycle);	
	double duration = note[n].duration;
	double delta = (2.0 * PI) / samplePerCycle;
	short sins[samplePerCycle];
	for (int s = 0; s < samplePerCycle; s++) 
	  sins[s] = (sin(delta * s) * MAGNIFYFACTOR) / note[n].feqNum;
	int sindex = 0;
	while (sindex + 2 * samplePerCycle <= 2 * sampleNum) {
	  for (int s = 0; s < samplePerCycle; s++) {
	    samples[sindex++] += sins[s]; /* two channels */
	    samples[sindex++] += sins[s];
	  }
	}
	printf("%d samples added for freq %lf\n", sindex, frequency);
      }
    }
    fwrite(samples, sizeof(short), 2 * sampleNum , fp);
    dataSize += sizeof(short) * 2 * sampleNum;
  }
  return dataSize;
}

#define MAXNOTE 1024

int main()
{
  WAVHeader header = {
    {'R', 'I', 'F', 'F'}, 0, {'W', 'A', 'V', 'E'}, {'f', 'm', 't', ' '},
    16, 1, 2, 44100, 176400, 4, 16, {'d', 'a', 't', 'a'}, 0
  };
  int dataSize = 0;
  Note note[MAXNOTE];


  int beatPerSecond;
  scanf("%d", &beatPerSecond);

  char line[1024];
  int n = 0;
  while (fgets(line, 1023, stdin) != NULL) {
    char *beatptr = strtok(line, " \t\n\r");
    if (beatptr == NULL)
      continue;
    
    note[n].duration = (60.0 / beatPerSecond) * atof(beatptr);
    char *name;
    while ((name = strtok(NULL, " \t\n\r")) != NULL)
      note[n].frequency[note[n].feqNum++] = freq(name);

    printf("duration %f seconds ", note[n].duration);
    for (int i = 0; i < note[n].feqNum; i++)
      printf("frequency %f ", note[n].frequency[i]);
    printf("\n");
    n++;
  }
  
  FILE *fp;
  fp = fopen("sample.wav", "wb");
  assert(fp != NULL);
  fwrite(&header, sizeof(WAVHeader), 1, fp);

  dataSize = genWAV(note, n, fp, header);
  printf("dataSize = %d\n", dataSize);
  int chunkSize = dataSize + 36;
  printf("chunkSize = %d\n", chunkSize);
  fseek(fp, 4, SEEK_SET);
  fwrite(&chunkSize, sizeof(int), 1, fp);
  fseek(fp, 40, SEEK_SET);
  fwrite(&dataSize, sizeof(int), 1, fp);
  fclose(fp);
  return 0;
}
