#include "headers/argvreader.h"

int main(int argc, char *argv[]){
  if(argc == 1){
    printf("\nERROR\nNO INPUT FILES\n");
    return -1;
  } 
  options(argc,argv);
}
