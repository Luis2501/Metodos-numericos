#include<bits/stdc++.h>
#include"Metodos_raices.cpp"

using namespace std;

int main(){

	Metodos_raices Metodos1;

	int opc; //Opciones de los tipos de métodos
	int grado; //grado de los polinomios
	double xo, xf; //Puntos para los métodos de raices
	double fxo, fxf; //Evaluaciones para los puntos
	
	opc = Metodos1.menuMetodos(opc);

	switch(opc){

//Método de Biseccion---------------------------------------------------------------------------------------------------------------------------

		case 1:

		cout<<"\n				<<<<Metodo de Bisección>>>>		\n";

		grado = Metodos1.pedirGrado(grado);

		Metodos1.pedirPolinomio(grado);

		Metodos1.Biseccion(grado);


		break;

//Método de posición falsa----------------------------------------------------------------------------------------------------------------------

		case 2:

		cout<<"\n				<<<<Metodo de Posición Falsa>>>>		\n";

		grado = Metodos1.pedirGrado(grado);
		
		Metodos1.pedirPolinomio(grado);

		Metodos1.Posicion(grado);

		break;

//Método de Newton-Rhapson----------------------------------------------------------------------------------------------------------------------

		case 3:

		
	
		
		break;

//Opción por si no se elige un método-----------------------------------------------------------------------------------------------------------

		default: 

		cout<<"¡Error! La opción seleccionada no se encuentra en el menú, reinicie el programa.\n\n";

		break;

	}//fin del switch opciones métodos

	return 0;
}
