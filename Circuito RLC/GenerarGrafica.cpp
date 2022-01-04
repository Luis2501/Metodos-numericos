#include<bits/stdc++.h>
#include"GenerarGrafica.h"

using namespace std;

	void Graficadora::datosGrafica(int circuito, double Xi, double Xf, double Y){
	
	ofstream archivo;
	archivo.open("solucion.txt");

	archivo<<"reset\n\n";
	archivo<<"set size 1,1\n\n";
	archivo<<"set grid\n\n";
	archivo<<"set multiplot\n\n";
	
	if(circuito ==1){

		archivo<<"set size 0.5,0.5 \n set origin 0,0.5 \n";
		archivo<<"set title \"Circuito RLC en serie\" \n";
		archivo<<"set ylabel \"Corriente (A)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucion.dat\" u 1:2 w l lw 3 title \"I(t)\" \n\n\n"; 

		archivo<<"set size 0.5,0.5 \n set origin 0.5,0.5 \n";
		archivo<<"set title \"Circuito RLC en serie\" \n";
		archivo<<"set ylabel \"Corriente (A)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n"; 
		archivo<<"plot \"solucionreal.dat\" u 1:2 w l lw 3 lt 2 title \"I(t)\" \n\n\n";

		archivo<<"set size 0.5,0.5 \n set origin 0,0 \n";
		archivo<<"set title \"Circuito RLC en serie\" \n";
		archivo<<"set ylabel \"Corriente (A)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucion.dat\" u 1:2 w l lw 3 title \"Sol. Númerica\" \n"; 
		archivo<<"replot \"solucionreal.dat\" u 1:2 w l lw 3 title \"Sol. Analítica\" \n\n\n";

		archivo<<"set size 0.5,0.5 \n set origin 0.5,0 \n";
		archivo<<"set title \"Circuito RLC en serie\" \n";
		archivo<<"set ylabel \"Voltaje (V)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucion.dat\" u 1:3 w l lw 3 title \"Voltaje R\", \"solucion.dat\" u 1:4 w l lw 3 title \"Voltaje L\",  			\"solucion.dat\" u 1:5 w l lw 3 title \"Voltaje C\" \n\n\n"; 
		 

	}else{
		
		archivo<<"set size 0.5,0.5 \n set origin 0,0.5 \n";
		archivo<<"set title \"Circuito RLC en paralelo\" \n";
		archivo<<"set ylabel \"Voltaje (V)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucion.dat\" u 1:2 w l lw 3 title \"V(t)\" \n\n\n"; 

		archivo<<"set size 0.5,0.5 \n set origin 0.5,0.5 \n";
		archivo<<"set title \"Circuito RLC en paralelo\" \n";
		archivo<<"set ylabel \"Voltaje (V)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucionreal.dat\" u 1:2 w l lw 3 lt 2 title \"V(t)\" \n\n\n";

		archivo<<"set size 0.5,0.5 \n set origin 0,0 \n";
		archivo<<"set title \"Circuito RLC en paralelo\" \n";
		archivo<<"set ylabel \"Voltaje (V)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n"; 
		archivo<<"plot \"solucion.dat\" u 1:2 w l lw 3 title \"Sol. Númerica\" \n"; 
		archivo<<"replot \"solucionreal.dat\" u 1:2 w l lw 3 title \"Sol. Analítica\" \n\n\n";

		archivo<<"set size 0.5,0.5 \n set origin 0.5,0 \n";
		archivo<<"set title \"Circuito RLC en paralelo\" \n";
		archivo<<"set ylabel \"Corriente (A)\" \n";
		archivo<<"set xlabel \"Tiempo (s)\" \n";
		archivo<<"plot \"solucion.dat\" u 1:3 w l lw 3 title \"Corriente R\", \"solucion.dat\" u 1:4 w l lw 3 title \"Corriente L\",  			\"solucion.dat\" u 1:5 w l lw 3 title \"Corriente C\" \n\n\n"; 


	}

	archivo.close();
	
	}
