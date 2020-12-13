#include <stdio.h>
#include <stdlib.h>

void ScanName(char *FileName)
{
  int i = 0;
  printf("Enter the name of the file to be deleted: ");
  for(; (FileName[i] = getchar()) != '\n'; i++);
  FileName[i] = '\0';
}

void FileSize(char* FileName, long* Size)
{
  FILE* fp;
  fp = fopen(FileName, "rb");
  fseek(fp, 0, SEEK_END);
  *Size = ftell(fp);
  fclose(fp);
}

void Rubbing(char* FileName, long* Size)
{
  FILE* fp;
  int i;
  fp = fopen(FileName, "wb");
  for(i = 0; i <= *Size; i++) fwrite("1", sizeof(char), *Size, fp);
  fseek(fp, 0, SEEK_SET);
  for(i = 0; i <= *Size; i++) fwrite("0", sizeof(char), *Size, fp);
  fclose(fp);
  remove(FileName);
}
int main()
{
  FILE* Deletion;
  char FileName[PATH_MAX];
  long Size = 0;
  ScanName(FileName);
  FileSize(FileName, &Size);
  Rubbing(FileName, &Size);
  return 0;
}
