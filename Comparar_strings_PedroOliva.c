#include <stdio.h>

int main()
{
    char str1[14];
    char str2[14];
    str1[14]=0;
    str2[14]=0;
    char* pstr1=&str1[0];
    char* pstr2=&str2[0];
    printf("Bienvenido al programa que compara strings");
    printf("\nIngrese el primer string: ");
    scanf("%s", str1);
    printf("\nIngrese el segundo string: ");
    scanf("%s", str2);
    int flag;
    int i;
    for(i=0; i<=13; i++){
        if (*(pstr1+i) == *(pstr2+i)){
            flag=0;
        }else{
            printf("Los strings son distintos");
            flag=1;
            break;
        }
    }
    if (flag==0) printf("Los strings son iguales");
    return 0;
}
