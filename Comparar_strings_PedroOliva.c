#include <stdio.h>
int flag;
void compSTR(char*, char*);

int main()
{
    char str1[14];
    char str2[14];
    str1[13] = 0;
    str2[13] = 0;
    char* pstr1=&str1[0];
    char* pstr2=&str2[0];
    printf("Bienvenido al programa que compara strings");
    printf("\nIngrese el primer string: ");
    scanf("%s", str1);
    printf("\nIngrese el segundo string: ");
    scanf("%s", str2);
    
    compSTR(pstr1, pstr2);
    
    if (flag == 1) printf("Los strings son distintos");
    else printf("Los strings son iguales");
}

void compSTR(char *pstr1,char *pstr2){
    for(int i=0; i<=13; i++){
        if (*(pstr1+i) == *(pstr2+i)){
            flag=0;
        }else{
            flag=1;
            break;
        }
    }
}
