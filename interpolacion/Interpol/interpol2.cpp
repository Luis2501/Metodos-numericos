#include<bits/stdc++.h>

using namespace std;

int main(){

	double f = 0,x=-50,dx=0.001;
	long double y,xo,fxo,x1;
	int n;
	long double A[20][20];
	long double C[20];
	long double  aux;

 	cout<<"\n\n\t    \t     <<<<Metodo de Interpolación Simple>>>>"<<endl<<endl;

	cout<<"Este programa resuelve sistemas de ecuaciones de la forma ' Ax=b ' \n";
	cout<<"donde 'A' es una matriz n x n, 'x' y 'b' son vectores en R^n. \n\n";

	cout<<"Numero de puntos que desea ingresar: ";
        cin>>n;

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

	for(int i=1;i<=n;i++){
                 for(int j=1;j<=n+1;j++){
			cout<<A[i][j]<<"\t";
                        }
             cout<<endl<<endl;
        }
	

//Metodo de Gauss-Jordan--------------------------------------------------------------------------------------------------------

		for(int i=1;i<=n;i++){
			if(A[i][i]!=0){
				aux=1/A[i][i];
					for(int j=1;j<=n+1;j++){
						A[i][j]=aux*A[i][j];
					}

					for(int j=1;j<=n;j++){
						if(j!=i){
							aux=-A[j][i];
								for(int k=1;k<=n+1;k++){
									A[j][k]=A[j][k]+aux*A[i][k];
								}
						}
					}

			}
		}

//---------------------------------------------------------------------------------------------------------------------------------

		cout<<endl<<"La matriz identidad es: "<<endl<<endl;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				cout<<A[i][j]<<"\t";
			}
		cout<<endl<<endl;
		} 


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

		for(int i=n;i>=1;i--){
			fxo += C[i]*pow(xo,i-1);
		}//evaluación f(Xo)

		cout<<"\n\nEl punto f("<<xo<<") = "<<fxo<<"\n\n";

		ofstream file_plot;
	file_plot.open("interpol.dat");

	while(x<=50){

		f=0;

		for(int i=n;i>=1;i--){
			f += C[i]*pow(x,i-1);
		}
		//cout<<x<<" "<<f<<endl;
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"interpol.txt\"\n"); 

	return 0;

}
