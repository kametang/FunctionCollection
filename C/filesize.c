#include <stdio.h>

unsigned long filesize(const char *filename)
{
	unsigned long e;
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		return -1;
	if(fseek(fp, 0L, SEEK_END) < 0)
		return -1;
	e = ftell(fp);
	fclose(fp);
	return e;
}