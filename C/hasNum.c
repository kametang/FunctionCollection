#include "str2int.c"
#include <stdlib.h>
#include <string.h>

/**
 * Does buf has figure number
 * @param  buf          source string
 * @param  pattern      want to find number
 * @param  splitPattern pattern for spliting source number
 * @return              0=success; 1=failed.
 */
int hasNum(const char *buf, char * pattern, const char *splitPattern)
{

    char *tmp = (char *)malloc(strlen(buf) + 1*sizeof(char));
    char *p = NULL;

    strcpy(tmp, buf);
    p = strtok(tmp, splitPattern);

    while(p != NULL){
        if(pattern == str2int(p))
            return 0;
        else
            p = strtok(NULL, splitPattern);
    }
    return -1;
}
