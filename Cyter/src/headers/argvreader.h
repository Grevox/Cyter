#include "parser.h"

static inline void options(int argc, char *argv[]){
  
  if(strcmp(argv[1], "-o") == 0){
    // COMPILE / INTERPRET
    // filename is argv[2]
    if(argv[2] == NULL || !strstr(argv[2],".cyter")){
      printf("\nINVALID FILETYPE\n");
      return;
    }
    readfile(argv[2]);
    
  }
  /* -v / -h commands
   TODO:    
   Choose between bytecode interpreter and interpreter && compiler
  */

}
