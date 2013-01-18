#include "Parser.h"


/**
   \fn int ParseFile (FILE* file, Comment* result)
   \brief parse a file and put the documentation comments to result
   \param file    the file for the parsing
   \param result    the table which contains the documentation comments
   \return the number of documentation comments find during the parsing
*/
int ParseFile (FILE* file, Comment* result){
         int count=0,test=0;
         char c,tmp;
         while(!feof()){
                        c=fgetc(file);
                        if(test==0 && c=='/')test++;
                        if(test==1 && (c=='/' || c=='*')){tmp=c;test++;}
                        else test=0;
                        if(test==2 && (c=='/' || c=='*') && c=tmp){
                                   result[count]=ParseComment(file,tmp);
                                   count++;
                                   test=0;
                                   }
                        else test=0;
         }
         return count;
}
