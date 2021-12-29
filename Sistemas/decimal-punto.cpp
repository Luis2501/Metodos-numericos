#include <iostream>
//#include <array>
#include <math.h>
using namespace std;

int main(){
	int n, m, entero;
double original,convertir,decimal=0;
string decimals = "";

				double numero;
				int dividendo, resto, divisor = 2, i = 0;
				string binario = "";
				cout<<"De el numero en decimal a convertir";
				cin>>numero;
				
				dividendo = numero;
				decimal = numero -dividendo;
				cout<<dividendo<<endl<<decimal<<endl;
				while(dividendo >= divisor){
					resto = dividendo % 2;
					if(resto == 1)
						binario = "1" + binario;
					else 
						binario = "0" + binario;
					dividendo = dividendo / divisor;
				}
				
				if(dividendo == 1)
					binario = "1" + binario;
				else 
					binario = "0" + binario;


				while(i<8){

				decimal = decimal * 2;
				entero = decimal;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal = decimal - entero;
				//cout<<convertir;		
				i++;

				}
				cout<<"En sistema binario"<< numero  << "se escribe: "<<binario<<"."<<decimals<<endl;


	return 0;

}//fin funcion main
