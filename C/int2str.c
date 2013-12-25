#include <string.h>

static char cc[256] = {0};

char * int2str(int n)
{
	int scale = 1;
	int id = 0;
	memset(cc, 0, 256);
	while(scale < n) scale *= 10;
	scale /= 10;

	while(n > 0){
		cc[id++] = n/scale + '0';
		n %= scale;
		scale /= 10;
	}
	cc[id] = '\0';

	return cc;
}