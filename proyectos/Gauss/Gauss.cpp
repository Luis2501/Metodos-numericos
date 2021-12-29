//Gauss para interpolacion

#include<bits/stdc++.h>
#include"gauss.h"

using namespace std;

   void::Gauss::mostrarMatriz(int tamanio, long double M[][100]) {

      for (int i=0; i<tamanio; i++) {

         for (int j=0; j<=tamanio; j++) {

            cout<<M[i][j]<<"\t";

         }//fin for[j]

         cout<<endl;

      }//fin for[i]


   }//fin mostrarMatriz

   long double*::Gauss::metGauss(int tamanio, long double Sistema[][100]) {

   static long double Vector[100];

         for (int i=0, p=0, r=1; i<=(tamanio*2)-1; i++) { //p es de pivote

      if(i%2==0) { //Para hacer los pivotes

         Aux=Sistema[p][p];

         for (int j=0; j<=tamanio; j++) {

            Sistema[p][j] /= Aux;
            
         }//fin for j

      p++;

      }//fin if

      else { //Para hacer 0 la primera columna

         for (int k=r; k<tamanio; k++) {

            Aux = Sistema[k][r-1];

            for (int j=r-1; j<=tamanio; j++) {

               Sistema[k][j] -= Aux*Sistema[r-1][j];

            }//fin for j

         }//fin for k

      r++;

      }//fin else

      if(i==(tamanio*2)-1) {

         for(int k=tamanio-2; k>=0; k--) {

            if(k==tamanio-2) {

               Aux = Sistema[k][k+1];

               for (int j=0; j<=tamanio; j++)
                  Sistema[k][j] -= Aux*Sistema[k+1][j];

            }//fin if

            else {

               for (int s=0; s<tamanio-(k+1); s++) {

                  Aux = Sistema[k][k+s+1];
                  Sistema[k][k+s+1] -= Aux*Sistema[k+s+1][k+s+1];
                  Sistema[k][tamanio] -= Aux*Sistema[k+s+1][tamanio];

               }//fin for s

            }//fin else

         }//fin for

      }//fin if

   }//fin for i

      for(int i=0; i<=tamanio; i++) {

         Vector[i] = Sistema[i][tamanio];

      }

	return Vector;

   }//fin metGauss
