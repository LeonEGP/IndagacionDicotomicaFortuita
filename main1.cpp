#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void espacio(){
    cout << endl;
}

int lasVegas(int limiteInferior, int limiteSuperior) {
	srand(time(NULL));
	return (limiteInferior + rand() % (limiteSuperior-limiteInferior+1));
}

int randomizedBinarySearch(vector<int> datos, int izquierda, int derecha, int busqueda) {

	if (derecha >= izquierda) {

		int medio = lasVegas(izquierda, derecha);

		if (datos[medio] == busqueda){
			return medio;
        }

		if (datos[medio] > busqueda){
		    return randomizedBinarySearch(datos, izquierda, medio-1, busqueda);
        }

        if (datos[medio] < busqueda){
		    return randomizedBinarySearch(datos, medio+1, derecha, busqueda);
        }
	}

	return -999999999;
}

int main(void) {

	vector <int> datos;
	int busqueda;
    int aux;
    int resultado;

    cin >> busqueda;

    cin >> aux;
    while (aux != -1){
        datos.push_back(aux);
        cin >> aux;
    }

    sort(datos.begin(),datos.end());

	resultado = randomizedBinarySearch(datos, 0, datos.size()-1, busqueda);

    espacio();
    if (resultado != -999999999){
        cout << "El elemento esta presente en el indice: " << resultado << endl;
    }
    else {
        cout << "El elemento no esta presente en el arreglo" << endl;
    }
    espacio();

	return 0;
}
