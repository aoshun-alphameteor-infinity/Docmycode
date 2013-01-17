#include "Comment.h"

Comment* newComment (){
         Comment* tmp=(Comment*)malloc(sizeof(Comment));
         if (tmp!=NULL){
                        tmp->author=NULL;
                        tmp->version=NULL;
                        tmp->date=NULL;
                        tmp->brief=NULL;
                        tmp->details=NULL;
                        tmp->fn=NULL;
                        tmp->return_value=NULL;
                        tmp->bug=NULL;
                        tmp->file=NULL;
                        
                        tmp->parameters=newStringList();
                        }
         return tmp;
         }

void freeComment (Comment* comment){
     free(tmp->author);
     free(tmp->version);
     free(tmp->date);
     free(tmp->brief);
     free(tmp->details);
     free(tmp->fn);
     free(tmp->return_value);
     free(tmp->bug);
     free(tmp->file);
     freeStringList(tmp->parameters);
     }
