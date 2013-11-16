#include <string.h>

/**
 * Determine whether if linePattern in buf by line.
 * @param  buf         source string
 * @param  linePattern want to find content
 * @return             result; NULL
 */
char * hasLine(const char * buf, const char * linePattern)
{
    char *tmp = buf;
    char *res = NULL;
    char line[128] = {0};
    do
    {
        sscanf(tmp, "%[^\n]", line);
        tmp += strlen(line) + 1;
        if(tmp[0] == '\0')
            break;
        res = strstr(line, linePattern);
    } while (res == NULL);

    return res;
}
