#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bytcomp(char filecont[]){
  printf("\n%s\n",filecont);
}

void readfile(char *argv){
  FILE *filereader = fopen(argv,"r");
  fseek(filereader, 0L, SEEK_END);
  int sz = ftell(filereader);
  rewind(filereader);
  int i = 0; // index
  char read[sz + 2];
  while(read[i] != EOF){
    if(read[i] == EOF){
  break;
    }
    read[i] = fgetc(filereader);
    i++;
  }
  bytcomp(read);
}
