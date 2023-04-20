#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20];
    char str2[20];
    printf("Bienvenido al programa que compara strings\n");
    printf("Ingrese el primer string de hasta 20 carácteres:\n");
    scanf("%s", str1);
    printf("Ingrese el segundo string de hasta 20 carácteres:\n");
    scanf("%s", str2);
    if (strcmp(str1, str2) == 0){
        printf("\n0 Los string coinciden");
    }
    else{
        printf("\n1 Los string no coinciden");
    }
}
