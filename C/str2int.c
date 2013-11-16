/**
 * Convert String to Integer
 * @param  buf String only contain numbers.
 * @return     Result
 */
int str2int(const char * buf)
{
    /*
    Initialize
     */
    int num = 0;
    int i = 0;
    int scale = 1;

    /*
    If input is negative
     */
    if(buf[0] == '-'){
        scale = -1;
        i = 1;
    }
    for(; buf[i] != '\0'; i++)
    {
        num *= 10;                  // num = num*10
        num += (int)buf[i] - 48;    // num = num + (int)buf[i] - 48
    }

    return num*scale;
}
