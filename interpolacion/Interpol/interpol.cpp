#include<bits/stdc++.h>

using namespace std;

int main(){

	int opc;
	int n;
	double A[20][20];
	double B[2][20];
	double C[20];
	double  aux;

	//cout<<"\n\n\t     <<<<Resolución de sistemas de ecuaciones>>>>";
 	cout<<"\n\n\t    \t     <<<<Metodo de INterpolación Simple>>>>"<<endl<<endl;

	cout<<"Este programa resuelve sistemas de ecuaciones de la forma ' Ax=b ' \n";
	cout<<"donde 'A' es una matriz n x n, 'x' y 'b' son vectores en R^n. \n\n";

	cout<<"Numero de puntos que desea ingresar: ";
        cin>>n;

	cout<<"\nDigite los elementos de la tabla: \n\n";

	for(int i=1;i<=1;i++){
		for(int j=1;j<=n;j++){
			cout<<"\t"<<j;
		}	
	}

	cout<<"\n\n";

	for(int i=1;i<=2;i++){
		cout<<"X["<<i<<"] \t";
                for(int j=1;j<=n;j++){
                        cin>>B[i][j];
                }
		cout<<"\n";
        }


	cout<<endl<<"La matriz aumentada es: "<<endl<<endl;


                for(int i=1;i<=2;i++){
                        for(int j=1;j<=n;j++){
				cout<<B[i][j]<<"\t";
                        }
                cout<<endl<<endl;
                }

for(int j=1;j<=n;j++){
	for(int i=1;i<=n;i++){
		
			for(int k=0; k<=n-1; k++){
				A[i][k+1] = pow(B[1][j], k);			
			}
		}
	}

	for(int i=1;i<=n;i++){
                 for(int j=1;j<=n;j++){
			cout<<A[i][j]<<"\t";
                        }
             cout<<endl<<endl;
        }	
/*
//Metodo de Gauss-Jordan--------------------------------------------------------------------------------------------------------

		for(int i=1;i<=n;i++){
			if(A[i][i]!=0){
				aux=1/A[i][i];
					for(int j=1;j<=n+1;j++){
						A[i][j]=aux*A[i][j];
					}
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

	cout<<"El valor de las incognitas es: ";
		for(int i=1;i<=n;i++){
			cout<<"\nx["<<i<<"] = "<<A[i][n+1]<<"\n";
		}
*/

	return 0;

}
