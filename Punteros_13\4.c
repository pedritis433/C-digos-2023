#include <stdio.h>

int main()
{
    
    int var[]={0x12345678,0x87654321};
    //char var2=4;
    char *p=&var[0];
    for(int i=0;i<4;i++)
        printf("Var vale: 0x%X \n", *(p+i)); //lugar de memoria
    //printf("Var vale: %d \n", *pint); //Valor de la variable
    return 0;
}
