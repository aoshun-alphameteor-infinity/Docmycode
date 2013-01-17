#include <stdio.h>
#include <stdlib.h>
#include "Site.h"
#include "File.h"

FILE* init_site(){
FILE* f;
int e=Open(f,"index.html","w+");
fprintf(f,"<html>\n <body>\n ");


fprintf(f,"</body>\n </html>\n");
return f;
}

FILE* create_page_file(char* page_name){
FILE* f;
int e=Open(f,page_name,"w+");


return f;
}

FILE* create_page_function(char* page_name){
FILE* f;
int e=Open(f,page_name,"w+");


return f;
}

