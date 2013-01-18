#ifndef __FILE__
#define __FILE__

		#include<stdio.h>
		#include<stdlib.h>
		#include<string.h>
		
		/**
		\fn int Open(FILE* file,char*filename,char*mode)
		\brief open the file of name 'filename' with the mode 'mode' 
		\return EXIT_SUCCESS if file is successfully open or EXIT_FAILURE in other case
		*/
		int Open(FILE* file,char* filename, char* mode);
		/**
		\fn void close(FILE* file)
		\brief close the file 'file'
		\param the file need to be closed
		*/
        void Close(FILE* file);
		
		/**
		\fn char* GetLine (FILE* input)
		\brief take a line in the file 'input' and return a String which contains this line
		\param the file in which this function take the line
		\return the String which represent the line
        */
		char* GetLine(FILE* input);
		/**
		\fn int WriteString (FILE* output,char* string)
		\brief write the string in the file output
		*/
        int WriteString(FILE* output,char* string);

#endif
