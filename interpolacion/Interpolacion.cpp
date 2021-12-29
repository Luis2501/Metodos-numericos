#include<bits/stdc++.h>
#include"Gauss.cpp"

using namespace std;

//	void Grafica(int, long double*);

int main(){

	Gauss Interpolacion;

	long double *Polinomio[100];
	long double xo;
	long double fxo;
	int n;
	long double A[100][100];
	long double p[100][2];

	cout<<"\n\n\t\t     <<<<Metodo de interpolación simple>>>>		\n\n";

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


	for(int i=1;i<=n;i++){
		archivo>>p[i][1];
		for(int j=1;j<=n;j++){	
			A[i][j] = pow(p[i][1],j-1);
		}
		archivo>>p[i][2];
		A[i][n+1] = p[i][2];
	}
		
	archivo.close(); //Cerrando el archivo 

	cout<<"\nLa matriz asociada a la interpolación es: \n\n";
	
	Interpolacion.mostrarMatriz(n,A);

	for(int i=1;i<=n;i++){
		Polinomio[i] = Interpolacion.MetGauss(n,A);

	}

	cout<<"La matiz indentidad asociada a la interpolación. \n\n";

	Interpolacion.mostrarMatriz(n,A);

	cout<<"El polinomio de la interpolación es: \n\nf(x) = ";

	for(int i=n;i>=1;i--){
	  		cout<<*(Polinomio[i]+i)<<" *x^"<<i-1<<"  +  ";
		if(i==2){
			i=1;
			cout<<*(Polinomio[i]+i)<<endl;			
		}
	}

	cout<<"\nIngrese el punto que quiere evaluar en el polinomio aproximado: ";
	cin>>xo;

	for(int i=1;i<=n;i++){
		fxo += *(Polinomio[i]+i)*pow(xo,i-1);
	}

	cout<<"\nEl punto f("<<xo<<") = "<<fxo<<"\n\n";

	//Grafica(n, *Polinomio);

//---------------------------------------------------------------------------------------------------------------------------------------

	long double x, f, dx;

	ofstream file_plot;
	file_plot.open("interpol.dat");

	x=-100;
	dx= 0.001;

	while(x<=100){

		f=0;
	
		for(int i=1;i<=n;i++){
			f += *(Polinomio[i]+i)*pow(x,i-1);
		}
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"interpol.txt\"\n"); 

	return 0;
}

	//void Grafica(int g, long double* C[]){

	//}
