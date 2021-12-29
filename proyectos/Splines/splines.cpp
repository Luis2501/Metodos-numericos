#include<bits/stdc++.h>

using namespace std;

int main(){

	GraficaSplines Grafica_polinomio;
	
	int n; //Numero de datos totales
	double X[100][2]; //Datos del archivo
	double H[100], A[100], L[100], N[100], Z[100], C[100], B[100], D[100];	

	cout<<"\n\n\t\t\t<<<<Splines cúbicos>>>>\n\n";
	cout<<"Este programa desarrolla el método de interpolación por medio de trazadores \n";
	cout<<"cúbicos o mejor conocidos como Splines o incluso interpolación segmentaria.\n";
	cout<<"A un conjunto de datos dados en un archivo de texto se puede aproximar una función \n";
	cout<<"en fragmentos de manera polinomica.\n\n";

	ifstream archivo;
	string nombreArchivo;

	cout<<"Digite el nombre del archivo donde se encuentran sus datos: ";
	getline(cin,nombreArchivo);

	archivo.open(nombreArchivo.c_str(),ios::in); //Abriendo el archivo 

        archivo>>n;

	if(archivo.fail()){

		cout<<"\n¡Error! No se pudo abrir el archivo.\n"; //Condicion por si el archivo no abre
		exit(1);
	}

	for(int i=0;i<=n-1;i++){
		archivo>>X[i][1]>>X[i][2];
		
	}

	cout<<"\nLos puntos que desea aproximar son los siguientes: \n\n";
	cout<<"X[i]"<<setw(15)<<"f(X[i])"<<endl<<endl;

	for(int i=0;i<=n-1;i++){

		cout<<X[i][1]<<setw(17)<<X[i][2]<<endl;
	}

	archivo.close();

	cout<<"\n\nLos polinomios asociados a los puntos son: \n";


			for(int i=0; i<=n-1; i++){
				H[i] = X[i+1][1] - X[i][1];

			}

			for(int i=1; i<=n-1; i++){

				A[i] = ((3*(X[i+1][2] - X[i][2]))/(H[i]))  - ((3*(X[i][2] - X[i-1][2]))/(H[i-1])); 

			}

			L[0] = 1;
			N[0] = 0;
			Z[0] = 0;

			for(int i=1; i<=n-1;i++){

				L[i] = (2*(X[i+1][1] - X[i-1][1])) - (H[i-1]*N[i-1]);
				N[i] = (H[i])/(L[i]); 
				Z[i] = (A[i] - H[i-1]*Z[i-1])/(L[i]);

			}
			
			L[n] = 1;
			N[n] = 0;
			C[n] = 0;

			for(int i=n-1; i>=0;i--){
			
				C[i] = Z[i] - N[i]*C[i+1];
				B[i] = ((X[i+1][2] - X[i][2])/(H[i])) -  ((H[i]*(C[i+1] + 2*C[i]))/(3));
				D[i] = (C[i+1] - C[i])/(3*H[i]);

			}

			for(int j=0; j<=n-1; j++){

cout<<"\nP["<<j+1<<"](X) =  "<<D[j]<<" (x - "<<X[j][1]<<")³ + "<<C[j]<<" (x - "<<X[j][1]<<")² + "<<B[j]<<"(x - "<<X[j][1]<<") + "<<X[j][2]<<endl;

			}

			cout<<"\n\n";

			double f,x, dx=0.001;
			int j=0;
			ofstream file_plot;		
			file_plot.open("spline.dat");

			x = X[0][1];

			while(x<=X[n-1][1]){
				
				while(x<=X[j+1][1]){

				f=0;

				f +=  D[j]*pow((x - X[j][1]), 3) + C[j]*pow((x - X[j][1]),2) + B[j]*pow((x - X[j][1]),1) + X[j][2];
				x+=dx;

				file_plot<<x<<" "<<f<<endl; 

				}	

				j++;		
			}

			

			file_plot.close();

			FILE * vent = popen("gnuplot -persist","w");
			fprintf(vent, "load \"splines.txt\" \n");


	return 0;
}
