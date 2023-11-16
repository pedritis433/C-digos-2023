#include <iostream>
using namespace std;

class Cafetera {
    private:
        int _cantidadMaxima, _cantidadActual;
    public:
        void Lee(int &a2, int &b2);
        void Guarda(int a2, int b2) {
            _cantidadActual = a2;
            _cantidadMaxima = b2;
        }
};
void Cafetera::Lee(int &a2, int &b2) {
    a2 = _cantidadMaxima;
    b2 = _cantidadActual;
}

int main()
{
    int accion;
    cout << "Bienvenido al programa que permite controlar una cafetera" << endl << "Ingrese el numero que corresponda a la acción que desea realizar" << endl << endl;
    cout << " -Revisar contenido en la cafetera: 1" << endl << " -Llenar cafetera: 2"<< endl << " -Vaciar cafetera: 3" << endl << " -Agregar café: 4" << endl << " -Servir taza: 5" << endl;
    cin >> accion;
    Cafetera par1;
    int x, y;
    par1.Guarda(12, 32);
    par1.Lee(x, y);
    cout << "Valor de par1.a: " << x << endl;
    cout << "Valor de par1.b: " << y << endl;
    return 0;
}
