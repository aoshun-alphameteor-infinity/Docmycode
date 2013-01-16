#include "StringList.h"

StringList* newStringList (void){
        StringList* strlist=(StringList)malloc(sizeof(StringList));
        if(strlist!=NULL){
                    strlist->size=0;
                    strlist->first=NULL;
                    }
        return strlist;
     }
        
void freeStringList (StringList* strlist){
     int i;
     StringCell* tmp=strlist->first;
     for(i=1;i<strlist->size;i++)tmp=tmp->suivant;     
     for(i=strlist->size-1;i>0;i--)freeStringCell(tmp->suivant);
     free(tmp);
     free(strlist);
     }

void reinitStringList (Stringlist* strlist);

int addtoStringList (StringList* strlist);
