#include <stdlib.h>
#include "twoDimensionalArray.c"

#define MAX(a, b) a > b?a:b

typedef struct{
    int count;
    int len;
    char **str;
}SplitStr;

static char s_node = 1;
static char s_pattern = 2;

char isPattern(char c, char * pattern)
{
    char *p = pattern;
    while(*p){
        if(c == *p)
            return s_pattern;
        p++;
    }
    return s_node;
}

SplitStr split(char *buffer, char *pattern)
{
    SplitStr res;
    char *scan = buffer;
    int node = 0;
    int i = 0;
    int maxlen = 0;
    char status, condition;
    char c;

    while(*scan){
        status = isPattern(*scan++, pattern);
        if(status == s_pattern){
            maxlen = MAX(i, maxlen);
            i = 0;
            continue;
        }
        if(!i)
            node++;
        i++;
    }
    maxlen = MAX(maxlen, i);
    res.str = (char**)twoDA(node, maxlen, sizeof(char));
    res.count = node;
    res.len = maxlen;
    scan = buffer;
    node = 0;
    i = 0;
    status = 0;
    while(*scan){
        c = *scan++;
        condition = isPattern(c, pattern);        
        if(status == s_node && condition == s_pattern){
            status = s_pattern;
            node++;
            i = 0;
        }
        else if(condition == s_node)
            status = s_node;
        if(condition == s_pattern)
            continue;
        res.str[node][i++] = c;
    }
    return res;
}

void splitClean(SplitStr n)
{
    free(n.str);
}