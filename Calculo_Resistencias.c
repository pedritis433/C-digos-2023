#include <stdio.h>

float ohm (float tension, float corriente);

int main(){
   float tension,corriente,resistencia;
    printf("Bienvenido al programa.. \n");
    printf("Ingrese la tensión: \n");
    scanf("%f",&tension);
    printf("Ingrese la corriente: \n");
    scanf("%f",&corriente);
    resistencia = ohm (tension,corriente);
    printf("El valor de la resistencia es de : %f ohms", resistencia);
    return 0;
}

float ohm (float tension,float corriente){
    return(tension/corriente);
}
