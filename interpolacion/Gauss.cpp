#include<bits/stdc++.h>
#include"Gauss.h"

using namespace std;

	void Gauss::mostrarMatriz(int g, long double B[][100]){	

		for(int i=1;i<=g;i++){
                	for(int j=1;j<=g+1;j++){
				cout<<B[i][j]<<"\t";
                        }
            		cout<<endl<<endl;
        	}

	}//Fin metodo imprimir la matriz 

	long double* Gauss::MetGauss(int g, long double B[][100]){

	static long double Soluciones[100];

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
		for(int i=1;i<=g;i++){
			Soluciones[i]= B[i][g+1];
		}

	return Soluciones;
	}
