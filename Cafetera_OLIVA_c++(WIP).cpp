#include <iostream>
using namespace std;

class Cafetera {
    private:
        int _cantidadMaxima, _cantidadActual;
    public:
        Cafetera (void){
            _cantidadMaxima=1000;
        }
        void Lee(int &vActual, int &vMax);
        void Guarda(int vActual);
        
};
void Cafetera::Guarda(int vActual){
    _cantidadActual = vActual;
}
void Cafetera::Lee(int &vActual, int &vMax) {
    vActual = _cantidadActual;
    vMax = _cantidadMaxima;
}

int main()
{
    Cafetera liquido;
    liquido.Guarda(0);
    int again=1;
        do{
        cout << "Bienvenido al programa que permite controlar una cafetera" << endl 
        << "Ingrese el numero que corresponda a la acción que desea realizar" << endl << endl;
        cout << " -Revisar contenido en la cafetera: 1" << endl << 
        " -Llenar cafetera: 2"<< endl << " -Vaciar cafetera: 3" << endl 
        << " -Agregar café: 4" << endl << " -Servir taza: 5" << endl;
        int accion;
        cin >> accion;
        switch (accion) {
            case 1:
                int actual, max;
                liquido.Lee(actual, max);
                cout << "Valor de liquido.max: " << max << "cc" << endl;
                cout << "Valor de liquido.actual: " << actual << "cc" << endl << endl;
                break;
            case 2:
                liquido.Guarda(1000);
                break;
            case 3:
                liquido.Guarda(0);
                break;
        }
        cout << "Ingrese 1 si quiere realizar otro comando" << endl;
        cin >> again;
    }
    while(again==1);
    return 0;
}
