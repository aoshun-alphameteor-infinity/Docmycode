#ifndef __FILE__
#define __FILE__

		#include<stdio.h>
		#include<stdlib.h>
		#include<string.h>
		
		int Open(FILE* file,char* filename, char* mode);
		void Close(FILE* file);
		
		char* GetLine(FILE* input);

#endif
