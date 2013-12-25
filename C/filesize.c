#include <stdio.h>

unsigned long filesize(const char *filename)
{
	unsigned long s, e;
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
		return -1;
	fseek(fp, 0L, SEEK_SET);
	s = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	e = ftell(fp);

	return e-s;
}