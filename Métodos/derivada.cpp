#include<bits/stdc++.h>
#include"Funcion.cpp"

using namespace std;

	generarFuncion derivada;

	double derivadaOrden::derivacion(int orden, double xo){

		h = 0.001;

		for(int i=1; i<=orden; i++){
			diferencial =  (derivada.Evaluacion(xo + h) - derivada.Evaluacion(xo - h))/(2*h);		

		}

	}
