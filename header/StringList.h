#ifndef __LISTESTRING__
#define __LISTESTRING__

        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        struct _StringCell_{
               int size;
               char* string;
               struct _StringCell_ *next;
               }
               
        typedef struct _StringCell_ StringCell;
        
        struct _StringList_{
               StringCell* first;
               int size;
               }
        
        typedef struct _StringList_ StringList;
        
        
        StringList* newStringList (void);
        void freeStringList (StringList* strlist);
        void reinitStringList (Stringlist* strlist);
        int addtoStringList (StringList* strlist, char* String);
        
        StringCell* newStringCell (char* String);
        void freeStringCell (StringCell* cell);
        
#endif
