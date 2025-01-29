#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void compiler(char filecontent[]) {
	int x = 0;
	while (filecontent[x] != '\0') {
		if (filecontent[x] == 'p' && filecontent[x + 1] == 'r' && filecontent[x + 2] == 'i' && filecontent[x + 3] == 'n' && filecontent[x + 4] == 't') {
			
			x += 5;
			if (filecontent[x] == ' ' ) {
				x++;
			} if (filecontent[x] == '(') {
				x++;
			}
			while (filecontent[x] != '\"') {
				x++;
				if (filecontent[x] == '\"') {
					break;
				}
			}
			x++;
			while (filecontent[x] != '\"') {
				if(filecontent[x] == '\"'){
					break;
				}
				printf("%c",filecontent[x]);
				x++;
			}
		}
		else {
			x++;
		}
		if (filecontent[x] == '\0') {
			break;
		}
	}
}

// this reads the file and gives it to the compiler

void filereader(char filename[]) {
	FILE* createbytecode = NULL;
	createbytecode = fopen("main.byt", "a+");
	FILE * filer = fopen(filename,"r");
	char charreader = ' ';
	int x = 0;
	while (charreader != EOF && !feof(filer)) {  // charreader is where the file is stored basically
		charreader= (char)fgetc(filer);
		if (charreader == EOF) {
			break;
		}
		x++;
		
	}
	char file[x];
	charreader = ' ';
	filer = fopen(filename, "r");
	x = 0;
	while (charreader != EOF && !feof(filer)) {  // charreader is where the file is stored basically
		charreader = (char)fgetc(filer);
		if (charreader == EOF) {
			break;
		}
		file[x] = charreader;
		x++;

	}
	compiler(file);
	
	
	
}

void options(int arguments, char* argv[]) {
	if (arguments == 1) {
		printf("\n FATAL ERROR\n No input files specified\n\n");
		exit(0);
	}
	if (strcmp(argv[1], "-o") == 0 && argv[2] != NULL) {
		// this will start the file reader
		filereader(argv[2]);
	}
}