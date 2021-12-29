#include<bits/stdc++.h> 
#include "Funcion.h" 

using namespace std; 

#define pi 3.141592 

	double generarFuncion::Evaluacion(double x){

		fx=0;

			fx = sqrt(x);

		return fx;

	}

	void generarFuncion::GraficaG(){

	ofstream file_plot;
	file_plot.open("funcion.dat"); 

	xi=-50; dx=0.001;

	while(xi<=50){

		f=0;

			f = generarFuncion::Evaluacion(xi);

		file_plot<<xi<<" "<<f<<endl;
		xi+=dx;

	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist", "w");
	fprintf(vent, "load \"funcion.txt\"\n "); 

	}
