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
	  char buffer[1000];
	  char* line;
	  fgets(buffer,1000,input);
	  line=(char*)malloc(sizeof(char)*(1+strlen(buffer)));
	  if(line==NULL)return NULL;
	  strcpy(line,buffer);
	  return line;
	  }
	 
int WriteString(FILE* output,char* string){
	int lenght, check;
	if(output==NULL)return EXIT_FAILURE;
	if(string==NULL)return EXIT_SUCCESS;
	lenght=strlen(string);
	check=fwrite(string, sizeof(char), lenght, output);
	if(check==sizeof(char)*lenght)return EXIT_SUCCESS;
	else return EXIT_FAILURE;
	}

