#include<bits/stdc++.h>

using namespace std;

int main(){

	int opc;
	int n;
	double A[20][20];
	double B[20][20];
	double C[20][20];
	double I[20][20];
	double  aux;

	cout<<"\n\n\t     <<<<Resolución de sistemas de ecuaciones>>>>";
 	cout<<"\n\n\t    \t     <<<<Metodo de Gauss-Jordan>>>>"<<endl<<endl;

	cout<<"Este programa resuelve sistemas de ecuaciones de la forma ' Ax=b ' \n";
	cout<<"donde 'A' es una matriz n x n, 'x' y 'b' son vectores en R^n. \n\n";

	cout<<"La expresión 'Ax=b' tiene la forma: \n\n";

	cout<<"\t _                                     _    _      _     _      _ "<<endl;
	cout<<"\t|  a[1][1] a[1][2] a[1][3] ... a[1][n]  |  |  x[1]  |   |  b[1]  |"<<endl;
	cout<<"\t|  a[2][1] a[2][2] a[2][3] ... a[2][n]  |  |  x[2]  |   |  b[2]  |"<<endl;
	cout<<"\t|  a[3][1] a[3][2] a[3][3] ... a[3][n]  |  |  x[2]  |   |  b[2]  |"<<endl;
	cout<<"\t|      .       .       .           .    |  |    .   | = |    .   |"<<endl;
	cout<<"\t|      .       .       .           .    |  |    .   |   |    .   |"<<endl;
	cout<<"\t|      .       .       .           .    |  |    .   |   |    .   |"<<endl;
	cout<<"\t|_ a[n][1] a[n][2] a[n][3] ... a[n][n] _|  |_ x[n] _|   |_ b[n] _| \n\n\n";

	cout<<"Defina el tamaño de la matriz: ";
        cin>>n;

	cout<<"\nDigite los elementos de la matriz en cada posición: \n\n";

	cout<<"---------------------------------------------------------------------\n";
	cout<<"| Intrucciones.       						    |\n"; 
	cout<<"| 								    |\n"; 
	cout<<"| Pulse [Tab] para seguir agregando en las siguiente columnas        |\n"; 
	cout<<"| y pulse [Enter] para agregar en las siguientes filas.              |\n";
	cout<<"---------------------------------------------------------------------\n\n";

	for(int i=1;i<=1;i++){
		for(int j=1;j<=n+1;j++){
		if(j==n+1){
			cout<<"b"<<endl<<endl;
		}else{
			cout<<"x["<<j<<"] \t";
			}
		}	
	}


	for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                  //      cout<<endl<<"M = ["<<i<<","<<j<<"]: ";
                        cin>>A[i][j];
                }
		//cout<<"\nTermino independiente de b"<<i<<": ";
		cin>>A[i][n+1];
		cout<<"\n";
        }

	cout<<endl<<"La matriz aumentada es: "<<endl<<endl;


                for(int i=1;i<=n;i++){
                        for(int j=1;j<=n+1;j++){
				if(j==n+1){	
					j==n+1;
					cout<<"= "<<A[i][j];
				}else{
                                	cout<<A[i][j]<<" x"<<j<<" +"<<"\t";
				}
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
//Impeime Primer paso-------------------------------------------------------------------------------------------------
				cout<<"Primer Paso"<<endl;
					 for(int m=1;m<=n;m++){
                       				for(int l=1;l<=n+1;l++){
                      	         			cout<<A[m][l]<<"\t";
                       				 }
               				 cout<<endl<<endl;
               				 }
		cout<<endl;
//---------------------------------------------------------------------------------------------------
					for(int j=1;j<=n;j++){
						if(j!=i){
							aux=-A[j][i];
								for(int k=1;k<=n+1;k++){
									A[j][k]=A[j][k]+aux*A[i][k];
								}
						}
					}
//Imprime Segundo paso-----------------------------------------------------------------------------------------------
								cout<<"Segundo Paso:"<<endl;
					 for(int m=1;m<=n;m++){
                       				for(int l=1;l<=n+1;l++){
                      	         			cout<<A[m][l]<<"\t";
                       				 }
               				 cout<<endl<<endl;
               				 }
		cout<<endl;
//--------------------------------------------------------------------------------------------------
			}
		}

//---------------------------------------------------------------------------------------------------------------------------------

/*	if(A[n][n] == 0 && A[n][n+1] !=0){
		
		cout<<"No existe solución para el sistema de ecuaciones. \n\n";
	}else{
*/		
		cout<<endl<<"La matriz identidad es: "<<endl<<endl;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				cout<<A[i][j]<<"\t";
				if(A[i][j]==0){
					A[i][j] = (A[i][j])*(-1);
				}
			}
		cout<<endl<<endl;
		} 

	cout<<"El valor de las incognitas es: ";
		for(int i=1;i<=n;i++){
			cout<<"\nx["<<i<<"] = "<<A[i][n+1]<<"\n";
		}

//	}//fin else

	return 0;

}
