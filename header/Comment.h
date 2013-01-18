#ifndef __COMMENT__
#define __COMMENT__

        #include "File.c"
        #inlcude "StringList.h"
        
        struct _comment_ {
               char* author;
               char* version;
               char* date;
               char* brief;
               char* details;
               char* fn;
               char* return_value;
               char* bug;
               StringList* parameters;
               }
               
        typedef struct _comment_ Comment;

        Comment* newComment ();
        void freeComment (Comment* comment);
#endif
