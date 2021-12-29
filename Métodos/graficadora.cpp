#include<bits/stdc++.h>
#include"graficadora.h"

using namespace std;

	void Grafica::datosGrafica(int n, double Polinomio[]){
	
	ofstream archivo;
	archivo.open("grafica.txt");
	
	archivo<<"reset\n\n";
	archivo<<"set size 1,1\n\n";
	archivo<<"set grid\n";
	archivo<<"set title \"Polinomio\" \n"; 

	cout<<"\n\nDigite los limites de la grafica: \n";
	cout<<"x1: ";
	cin>>x1;
	cout<<"\nx2: ";
	cin>>x2;
	
	fx1 = Evaluacion(n, x1, Polinomio);

	archivo<<"set xlabel \"Eje X\" \n";
	archivo<<"set ylabel \"Eje Y\" \n";
	archivo<<"set xrange["<<x1<<":"<<x2<<"]\n";
	archivo<<"set yrange["<<fx1<<":"<<x2<<"]\n";
	archivo<<"plot \"grafica.dat\" u 1:2 w l title \"f(x)\" \n"; 

	archivo.close();
	
	}

	double Grafica::Evaluacion(int grado, double xi, double coef_Polinomio[]){

		fx=0;

		for(int i=grado;i>=0;i--){
			fx += coef_Polinomio[i]*pow(xi,i);
	
		}

		return fx;

	}

	void Grafica::GraficaG(int gradoPolinomio, double coeficientes[]){

	ofstream file_plot;
	file_plot.open("grafica.dat");
	
	x=-50; dx=0.001;

	while(x<=50){

		f=0;
			f = Grafica::Evaluacion(gradoPolinomio, x, coeficientes);

		//cout<<x<<" "<<f<<endl;
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"grafica.txt\"\n"); 

	}


	void Grafica::Documento(){

	cout<<"\n¿Desea abrir el libro \"Apuntes de Métodos Númericos\"?\n";
	cout<<"1. Si \t 2. No \nOpcion:";
	cin>>abrirPdf;

	if(abrirPdf == 1){

		FILE *archivo = popen("evince Métodos.pdf","r");

	}else{

		exit(1);

	}


	}
