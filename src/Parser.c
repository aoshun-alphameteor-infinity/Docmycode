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
     StringList bloc=NULL;
     int end=0;
     if(doc==NULL)doc=newComment();
     if(doc==NULL)exit(EXIT_FAILURE);
     switch(type){
                  case '/':
                       line=GetLine(file);
                        ParseLine(file,doc);
                        free(line);
                        break;
                  case '*':
                       bloc=newStringList();
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
                       freeStringList(bloc);
                       break;
                  default:
                          break;
                  }
     
     }

void ParseLine (String* line,Comment* doc){
     int begin, end;
     char* finally;
     char* marker;
     if(strstr(line,"///")==line)begin=3;     
     if(strstr(line,"/**")==line)begin=3;
     if((finally=strstr(line,"*/"))!=NULL){
                                           finally[0]='\n';
                                           finally[1]='\0';
                                           free(&finally[2]);
                                           }
     if(marker=strstr(line,"\\author")){
                                        detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->author,tmp);
                                        }
     if(marker=strstr(line,"\\version")){
                                         detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->version,tmp);
                                         }
     if(marker=strstr(line,"\\date")){
                                      detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->date,tmp);
                                      }
     if(marker=strstr(line,"\\brief")){
                                       detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->brief,tmp);
                                       }
     if(marker=strstr(line,"\\details")){
                                         detail=1;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->details,tmp);
                                         }
     if(marker=strstr(line,"\\fn")){
                                    detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->fn,tmp);
                                    }
     if(marker=strstr(line,"\\param")){
                                       detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        addtoStringList(doc->parameters,tmp);
                                       }
     if(marker=strstr(line,"\\return")){
                                        detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->return_value,tmp);
                                        }
     if(marker=strstr(line,"\\bug")){
                                     detail=0;
                                        int i=strlen(field),max=strlen(marker);
                                        while((marker[i]==' ' || marker[i]=='\t')&& i<=max)i++;
                                        char* tmp=(char*)malloc(sizeof(char)*(1+strlen(&marker[i])));
                                        if(tmp==NULL)exit(EXIT_FAILURE);
                                        strcpy(tmp,&marker[i]);
                                        setComment(doc->bug,tmp);
                                     }
     
     if(detail==1){
                   int length=1+strlen(doc->details)+strlen(line);
                   char* tmp=(char*)malloc(length*sizeof(char));
                   tmp[0]='\0';
                   if(tmp==NULL)exit(EXIT_FAILURE);
                   strcat(tmp,doc->details);
                   strcat(tmp,line);
                   free(doc->details);
                   doc->details=tmp;
                   }
     
     
     }

void setComment(char* field, ,char* doc){
     if(field==NULL)field=doc;
     else{
          int length=1+strlen(field)+strlen(doc);
          char* tmp=(char*)malloc(length*sizeof(char));
          if(tmp==NULL)exit(EXIT_FAILURE);
          tmp[0]='\0';
          strcat(tmp,field);
          strcat(tmp,doc);
          free(field);
          free(doc);
          field=tmp;
     }                                                       
}
