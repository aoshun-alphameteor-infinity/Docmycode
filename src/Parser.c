#include "Parser.h"


/**
   \fn int ParseFile (FILE* file, Comment* result)
   \brief parse a file and put the documentation comments to result
   \param file    the file for the parsing
   \param result    the table which contains the documentation comments
   \return the number of documentation comments find during the parsing
*/
int ParseFile (FILE* file, Comment** result){
         int count=0,test=0,bloc=0;
         char c,tmp;
         detail=0;
         while(!feof()){
                        c=fgetc(file);
                        if(test==0 && c=='/')
                                   test++;
                        else 
                             if(bloc==1){
                                         bloc==0;
                                         count++;
                                         }
                        
                        if(test==1 && (c=='/' || c=='*')){
                                   tmp=c;
                                   test++;
                                   }
                        else {
                             test=0;
                             if(bloc==1){
                                         bloc==0;
                                         count++;
                                         }
                             }
                        
                        if(test==2 && (c=='/' || c=='*') && c=tmp){
                                   ParseComment(file,tmp,result[count]);
                                   bloc=1;
                                   test=0;
                                   }
                        else{
                             test=0;
                             if(bloc==1){
                                         bloc==0;
                                         count++;
                                         }
                             }
         }
         return count;
}



void ParseComment (FILE* file,char type,Comment* doc){
     char* line=NULL;
     StringList bloc=newStringList();
     int end=0;
     if(doc==NULL)doc=newComment();
     if(doc==NULL)exit(EXIT_FAILURE);
     switch(type){
                  case '/':
                       line=GetLine(file);
                        ParseLine(file,doc);
                        break;
                  case '*':
                       while(end==0){
                                     char* tmp=GetLine(file);
                                     int length=strlen(tmp);
                                     if(strstr(tmp,"*/")!=NULL)end=1;
                                     addtoStringList(bloc,tmp);
                                     }
                       StringCell* tmp;
                       int i;
                       for(tmp=bloc.first, i=1;i<=bloc.size;i++, tmp=tmp->suivant){
                                           ParseLine(tmp->string,doc);
                                           }
                       break;
                  default:
                          break;
                  }
     
     }
