//Programa que: Implementa el algoritmo de Búsqueda Binaria Aleatorizada.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Martes 01 de Noviembre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio(){ //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    cout << endl;
}

//Función que implementa el algoritmo aleatorio de Las Vegas, recibe como parámetros el entero límite inferior y el entero límite superior, retorna un entero aleatorio. 
int lasVegas(int limiteInferior, int limiteSuperior) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
	srand(time(NULL));
	return (limiteInferior + rand() % (limiteSuperior-limiteInferior+1));
}

//Función que implementa Búsqueda Binaria Aleatorizada, recibe el vector de enteros con los datos, el valor entero izquierda, el valor entero derecha, y el valor entero que se busca; retorna el valor entero del índice donde se encuentra la búsqueda.
int randomizedBinarySearch(vector<int> datos, int izquierda, int derecha, int busqueda) { //Complejidad Computacional: O(log n), siendo n la cantidad de datos en el vector. 

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

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main() {  //Complejidad Computacional: O(1). Dentro de esa ejecución lineal, se ejecuta un algoritmo de Ordenamiento para el Vector de Datos, de Complejidad Computacional: O(n log n), siendo n la cantidad de datos en el vector. Así mismo, el realizar la búsqueda binaria tiene una Complejidad Computacional: O(log n), siendo n la cantidad de datos en el vector. 

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

    sort(datos.begin(),datos.end()); //Complejidad Computacional: O(n log n), siendo n la cantidad de datos en el vector. 

	resultado = randomizedBinarySearch(datos, 0, datos.size()-1, busqueda); //Complejidad Computacional: O(log n), siendo n la cantidad de datos en el vector. 

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

/*
    https://www.geeksforgeeks.org/randomized-binary-search-algorithm/
    https://www.geeksforgeeks.org/randomized-algorithms-set-2-classification-and-applications/
    https://www.geeksforgeeks.org/binary-search/
    https://nuwant.medium.com/randomized-algorithms-8425e6302a7d 
*/