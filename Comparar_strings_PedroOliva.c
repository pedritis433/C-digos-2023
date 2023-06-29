#include <stdio.h>
int compSTR(char*, char*);

int main()
{
    char str1[14];
    char str2[14];
    str1[13] = 0;
    str2[13] = 0;
    char* pstr1=str1;
    char* pstr2=str2;
    printf("Bienvenido al programa que compara strings");
    printf("\nIngrese el primer string: ");
    scanf("%s", str1);
    printf("\nIngrese el segundo string: ");
    scanf("%s", str2);
    
    compSTR(pstr1, pstr2);
    
    if (compSTR(pstr1, pstr2) == 1) printf("Los strings son distintos");
    else printf("Los strings son iguales");
}

int compSTR(char *pstr1,char *pstr2){
    int flag = 0;
    for(int i=0; i<=13; i++){
        if (*(pstr1+i) == *(pstr2+i)){
        flag=0;
        }else{
            flag=1;
            break;
        }
    }
    if (flag == 1) return 1;
    else return 0;
}
