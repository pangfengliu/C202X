#include <stdio.h>
#define MAX 65536
 
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
 
int main(){
  char source[80], output[80];
  int second;
  scanf("%s%s%d",source,output,&second);
  FILE *fin = fopen(source,"rb");
  WAVHeader head;
  fread(&head,sizeof(WAVHeader),1,fin);
  FILE *fout = fopen(output,"wb");
  head.dataSize = head.byteRate * second;
  head.chunkSize = head.dataSize + 36;
  fwrite(&head,sizeof(WAVHeader),1,fout);
  short content[head.byteRate * second];
  fread(&content,sizeof(short),head.sampleRate * second,fin);
  fwrite(&content,sizeof(short),head.sampleRate * second,fout);
  fclose(fin);
  fclose(fout);
}
