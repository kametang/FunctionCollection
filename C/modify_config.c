#include <stdio.h>
#include <string.h>

int modifyConfig(const char *filename, const char *pattern, const char *value)
{
	char *tmpfile = tmpnam(NULL);
	char line[128] = {0};
	int patternLen = strlen(pattern);

	FILE *tf = fopen(tmpfile, "w");
	FILE *ori = fopen(filename, "r");
	while(fgets(line, 128, ori)){
		if(strncmp(line, pattern, patternLen) == 0)
			fprintf(tf, "%s=%s\n", pattern, value);
		else
			fputs(line, tf);
	}

	fclose(tf);
	fclose(ori);
	rename(tmpfile, filename);
	return 0;
}