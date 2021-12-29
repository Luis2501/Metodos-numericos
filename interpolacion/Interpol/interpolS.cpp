#include<bits/stdc++.h>

using namespace std;

class Interpol{

public:

	long double Evaluacion(int g, long double D[], long double x){

		f=0;

		for(int i=g;i>=1;i--){
			f += D[i]*pow(x,i-1);
		}
	
		return f;
	}

	void Grafica(int g, long double C[], long double x, long double dx){

	ofstream file_plot;
	file_plot.open("interpol.dat");

	x=-50;
	dx= 0.001;

	while(x<=50){

		f=0;
	

		for(int i=g;i>=1;i--){
			f += Evaluacion(g, C, x);
		}
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"interpol.txt\"\n"); 

	}

	void mostrarMatriz(int g, long double B[][20]){	


	for(int i=1;i<=g;i++){
                 for(int j=1;j<=g+1;j++){
			cout<<B[i][j]<<"\t";
                        }
             cout<<endl<<endl;
        }


	}

	void Gauss(int g, long double B[][20], long double auxi){

//Metodo de Gauss-Jordan--------------------------------------------------------------------------------------------------------

		for(int i=1;i<=g;i++){
			if(B[i][i]!=0){
				aux=1/B[i][i];
					for(int j=1;j<=g+1;j++){
						B[i][j]=aux*B[i][j];
					}

					for(int j=1;j<=g;j++){
						if(j!=i){
							aux=-B[j][i];
								for(int k=1;k<=g+1;k++){
									B[j][k]=B[j][k]+aux*B[i][k];
								}
						}
					}

			}
		}

//---------------------------------------------------------------------------------------------------------------------------------


	}

	void Inter(){

	cout<<"\n\n\t    \t     <<<<Metodo de Interpolación Simple>>>>"<<endl<<endl;

//	cout<<"Este programa resuelve sistemas de ecuaciones de la forma ' Ax=b ' \n";
//	cout<<"donde 'A' es una matriz n x n, 'x' y 'b' son vectores en R^n. \n\n";

	cout<<"Numero de puntos que desea ingresar: ";
        cin>>n;

	long double A[20][20];
	long double C[20];
		
	cout<<"\nDigite los elementos de la tabla: \n\n";

	cout<<"\tx\tf(X)\n\n";

	for(int i=1;i<=n;i++){
		cout<<"X["<<i<<"]\t";
		cin>>x1;
		for(int j=1;j<=n;j++){	
			A[i][j] = pow(x1,j-1);
		}
		cin>>y;
		A[i][n+1] = y;
		cout<<"\n";
	}

	

	cout<<"La matriz asociada a la interpolación es: \n\n";

	mostrarMatriz(n, A);

	Gauss(n, A, aux);

	cout<<endl<<"La matriz identidad es: "<<endl<<endl;

	mostrarMatriz(n, A);

			cout<<"El polinomio de la interpolación es: \n\n";

		for(int i=n;i>=1;i--){
			C[i] = A[i][n+1];
		      
		}

		for(int i=n;i>=1;i--){
  			cout<<C[i]<<"*x^"<<i-1<<" + ";
				if(i==2){
				i=1;
			cout<<C[i];
			}
		}

		cout<<"\n\n";

		cout<<"Ingrese el punto que quiere evaluar en la aproximación: ";
		cin>>xo;

		fxo = Evaluacion(n, C, xo);

		cout<<"\n\nEl punto f("<<xo<<") = "<<fxo<<"\n\n";

		Grafica(n, C, x, dx); 

	}

private: 

	long double f,x,dx;
	long double y,xo,fxo,x1;
	int n;
	long double  aux;

}; //fin clase

int main(){

	Interpol interpol;
	interpol.Inter();

	return 0;

}
