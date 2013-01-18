#ifndef __PARSER__
#define __PARSER__

        #include "Comment.h"
        
        /*variable globale permettant de savoir si une balise \detail
         est en cours d'écriture entre deux appel de fonctions*/
        int detail;
        
        /*voir doc dans Parser.c*/
        int ParseFile (FILE* file, Comment* result);
        
        
#endif
