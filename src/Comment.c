#include "Comment.h"

/**
\fn Comment* newComment()
\return a pointer on the Comment structure which be allocated
\brief a function for allocate Comment structure
*/
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


/**
   \fn void freeComment (Comment* comment)
   \param the comment structure wich need to be free.
   \brief a function in order to free a Comment structure.
*/
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
