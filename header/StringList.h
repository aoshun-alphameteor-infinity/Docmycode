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
        
        /**
        \fn StringList* newStringList (void)
        \brief allocate a structure StringList
        \return a pointer on the new StringList
        */
        StringList* newStringList (void);
        /**
        \fn void freeStringList (StringList* strlist)
        \param strlist  the StringList need to be free
        \brief free a StringList
        */
        void freeStringList (StringList* strlist);
        /**
        \fn void reinitStringList (StringList* strlist)
        \brief return the Stringlist at empty StringListlist state
        */
        void reinitStringList (Stringlist* strlist);
        /**
        \fn int addtoStringList (StringList* strlist, char* String)
        \brief add String to the StringList strlist
        \return EXIT_SUCCESS if the add was successful or EXIT_FAILURE in other case
        */
        int addtoStringList (StringList* strlist, char* String);
        
        /**
        \fn StringCell* newStringCell (char* String)
        \brief allocate a structure StringCell
        \return a pointer on the new StringCell
        \param the String which will be stored in the StringCell structure
        */
        StringCell* newStringCell (char* String);
        /**
        \fn void freeStringCell (StringCell* strlist)
        \param cell  the StringCell need to be free
        \brief free a StringCell
        */
        void freeStringCell (StringCell* cell);
        
#endif
