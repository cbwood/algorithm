#include <stdio.h>
#include <string.h>
void nevercalled()
{
    printf("never called\n");
}
void functioncalled(char *arg)
{
    char buf[10];
    int x,y,zw;
    strcpy(buf,arg);
}
int main(int argc,char * argv[])
{
    printf("%p", &nevercalled);
//    functioncalled(argv[1]);
    return 0;
}
