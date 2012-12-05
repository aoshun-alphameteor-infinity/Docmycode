#include <stdio.h>
#include <stdlib.h>

FILE* init_site(){
FILE* f=fopen("index.html","w+");
fprintf(f,"<html>\n <body>\n ");


fprintf(f,"</body>\n </html>\n");
return f;
}

FILE* create_page_file(char* page_name){
FILE* f=fopen(page_name,"w+");


return f;
}

FILE* create_page_function(char* page_name){
FILE* f=fopen(page_name,"w+");


return f;
}

int main (int argc, char* argv[]){
	FILE* f=NULL;
	f=fopen("index.html","r+");
	if(f==NULL) /* the site does not exist */
		f=init_site();
	
	
	
	
	fclose(f);
	return 0;
	}