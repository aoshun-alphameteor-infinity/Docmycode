#include "File.h"

int Open(FILE* file,char* filename,char* mode){
	file=fopen(filename,mode);
	if(file==NULL)return EXIT_FAILURE;
	else return EXIT_SUCCESS;
	}

void close(FILE* file){
	 fclose(file);
	 }
	 
char* GetLine(FILE* input){
	  char buffer[100];
	  char* line;
	  fgets(buffer,100,input);
	  line=(char*)malloc(sizeof(char)*(1+strlen(buffer)));
	  if(line==NULL)return NULL;
	  strcpy(line,buffer);
	  return line;
	  }
	 
