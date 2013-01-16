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
     freecontentofStringList(strlist);
     free(strlist);
     }

void reinitStringList (Stringlist* strlist){
     freecontentofStringList(strlist);
     strlist->size=0;
     }

int addtoStringList (StringList* strlist, char* String){
    StringCell* tmp=strlist->first;
    int i;
    for(i=1;i<=strlist->size;i++)tmp=tmp->suivant;
    tmp->suivant=newStringCell(String);
    if(tmp->suivant!=NULL){strlist->size+=1;return EXIT_SUCCESS;}
    return EXIT_FAILURE;
    }

void freecontentofStringList (Stringlist* strlist){
     int i;
     StringCell* tmp=strlist->first;
     for(i=1;i<strlist->size;i++)tmp=tmp->suivant;     
     for(i=strlist->size-1;i>0;i--)freeStringCell(tmp->suivant);
     free(tmp);     
     }

StringCell* newStringCell (char* String){
     StringCell* tmp=(StringCell*)malloc(sizeof(StringCell));
     if(tmp!=NULL){
                   tmp->string=String;
                   tmp->size=strlen(String);
                   }
     return tmp;       
     }

void freeStringCell (StringCell* cell){
     free(cell->String);
     free(cell);
     }
