#include <stdio.h>
#include <stdlib.h>
#include "Site.h"
#include "File.h"
#include "StringList.h"

int main (int argc, char* argv[]){
FILE* f=NULL;
f=fopen("index.html","r+");
if(f==NULL) /* the site does not exist */
f=init_site();




fclose(f);
return 0;
}
