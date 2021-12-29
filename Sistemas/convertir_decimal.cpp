#include<iostream>
#include<string>
#include<cmath>
#include<math.h>

using namespace std;

int main(){

//Variables

	int opc, base, exp, i=0;
	long int digito,  entero;
	string decimals = "";
	double decimal1 = 0, decimal;
	string revisar = "";
	int respuesta;

while(respuesta = 1){

//Encabezado y menú

	cout<<endl<<"\t     <<<<Sistemas de numeración>>>>    "<<endl<<endl;
	cout<<"Esta herramienta simple te permite convertir un mismo número \n";
	cout<<"en sus representaciones bajo diferentes sistemas numéricos. \n\n";
        cout<<"1. Convertir Decimal-Binario."<<endl;
        cout<<"2. Convertir Octal-Decimal."<<endl;
        cout<<"3. Convertir Binario-Octal."<<endl;
	cout<<"4. Salir"<<endl<<endl;
        cout<<"Opcion: ";
        cin>>opc;

//Opciones del menú

	switch(opc){

//Convertir de Decimal<->Binario

		case 1:

		cout<<"\nSeleccione la conversion a realizar."<<endl<<endl;
		cout<<"1. Decimal->Binario."<<endl;
		cout<<"2. Binario->Decimal."<<endl<<endl;
		cout<<"Opcion: ";
		cin>>base;

		switch(base){
//Decimal->Binario
			case 1:{

				double numero,numero1;
                                int dividendo, resto, divisor = 2, i = 0;
                                string binario = "";

				cout<<"\nIntroduce un numero en sistema decimal: ";
   				cin>>numero1;

				numero=abs(numero1);

				if(numero>100000000000){

				cout<<"\n¿Qué pedo, qué pedo?"<<endl<<endl;
				}

				else{

				dividendo = numero;
				decimal1 = numero -dividendo;
				//cout<<dividendo<<endl<<decimal<<endl;
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


				while(i<20){

				decimal1 = decimal1 * 2;
				entero = decimal1;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal1 = decimal1 - entero;
				//cout<<convertir;		
				i++;

				}

				if(numero1<0){
   				cout<<endl<<"El numero en sistema binario es: "<<"-"<<binario<<"."<<decimals<<endl;
				}else
				cout<<endl<<"El numero en sistema binario es: "<<binario<<"."<<decimals<<endl;
				//fin else
				}
			}
		break;
//Binario->Decimal
			case 2:{
				string binario;
				int n, i=0, exp=0;
				double suma = 0;

				cout<<"\nIntroduce un numero en sistema binario: ";
				cin>>binario;

				n = binario.size();

				for(int k=0;k<n;k++){
					if(binario[k] != '.'){
					exp++;
					}
				else
					k=n;
				}

				while(i<n){
					if(binario[i] != '.'){
						suma += (binario[i]-'0')*pow(2.0, exp-1);
						exp--;
				}
				i++;
				}

				cout<<"\nEl numero en sistema decimal es: "<<suma<<endl;


			}//fin metodo
		break;
		}//fin switch
	break;

//Convertir de Octal<->Decimal

		case 2:

		cout<<"\nSeleccione la conversion a realizar."<<endl<<endl;
                cout<<"1. Decimal->Octal."<<endl;
                cout<<"2. Octal->Decimal."<<endl<<endl;
                cout<<"Opcion: ";
                cin>>base;

                switch(base){
//Decimal->Octal
                        case 1:{
				int base, suma, num, res, i = 0;
     				double a;
				base = 1;
     				suma = 0;

				cout<<"\nIntroduce un numero en sistema decimal: ";
   				cin>>a;
				num = a;
				decimal = a -num;
				do
            			 {//inicio while octales
                 			res = num % 8;
                			num = num / 8;
                			suma = suma + res * base;
                 			base = base * 10;

             			} while(num > 0);//fin 

				while(i<20){

				decimal = decimal * 8;
				entero = decimal;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal = decimal - entero;
				//cout<<convertir;		
				i++;

				}

   				cout<<endl<<"El numero en sistema octal es: "<<suma<<"."<<decimals<<endl;
			}
                break;
//Octal->Decimal
                        case 2:{
				string octal;
				int n, i=0, exp=0;
				double suma = 0;

				cout<<"\nIntroduce un numero en sistema octal: ";
				cin>>octal;

				n = octal.size();

				for(int k=0;k<n;k++){
					if(octal[k] != '.'){
					exp++;
				}
				else
					k=n;
				}

				while(i<n){
					if(octal[i] != '.'){
					suma += (octal[i]-'0')*pow(8.0, exp-1);
					exp--;
					}
				i++;
				}

				cout<<"\nEl numero en sistema decimal es: "<<suma<<endl;

			}				
                break;

                }

	break;

//Convertir Binario<->Octal

		case 3:

		cout<<"\nSeleccione la conversion a realizar."<<endl<<endl;
                cout<<"1. Binario->Octal."<<endl;
                cout<<"2. Octal->Binario."<<endl<<endl;
                cout<<"Opcion: ";
                cin>>base;

                switch(base){
//Binario->Octal
                        case 1:{
				string binario;
				int n, i=0, exp=0, m=0;
				double algo = 0;
				int base=1, suma=0, num, res;

				cout<<"\nIntroduce un numero en sistema binario: ";
				cin>>binario;

				n = binario.size();

				for(int k=0;k<n;k++){
					if(binario[k] != '.'){
						exp++;
					}
				else
					k=n;
				}

				while(i<n){
					if(binario[i] != '.'){
						algo += (binario[i]-'0')*pow(2.0, exp-1);
						exp--;
					}
				i++;
				}

				num = algo;
				decimal = algo -num;
				//cout<<endl<<decimal<<endl;
				do
            			 {//inicio while octales
                 			res = num % 8;
                			num = num / 8;
                			suma = suma + res * base;
                 			base = base * 10;

             			} while(num > 0);//fin 

				while(m<20){

				decimal = decimal * 8;
				entero = decimal;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal = decimal - entero;
				//cout<<convertir;		
				m++;

				}

   				cout<<endl<<"El numero en sistema octal es: "<<suma<<"."<<decimals<<endl;
	

			}

                break;
//Octal->Binario
                        case 2:{
				string octal;
		int n, i=0, exp=0, m=0;
		double numero = 0;
                                int dividendo, resto, divisor = 2;
                                string binario = "";

	cout<<"\nIntroduce un numero en sistema octal: ";
	cin>>octal;

	n = octal.size();
	

	for(int k=0;k<n;k++){
		if(octal[k] != '.'){
			exp++;
		}
		else
		k=n;
		}

	while(i<n){
		if(octal[i] != '.'){
			numero += (octal[i]-'0')*pow(8.0, exp-1);
			exp--;
		}
	i++;
	}
			       


				dividendo = numero;
				decimal1 = numero -dividendo;
				//cout<<dividendo<<endl<<decimal<<endl;
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


				while(m<20){

				decimal1 = decimal1 * 2;
				entero = decimal1;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal1 = decimal1 - entero;
				//cout<<convertir;		
				m++;

				}

				if(numero<0){
   				cout<<endl<<"El numero en sistema binario es: "<<"-"<<binario<<"."<<decimals<<endl;
				}else
				cout<<endl<<"El numero en sistema binario es: "<<binario<<"."<<decimals<<endl;
				//fin else
				
	
			}
                break;

                }


	break;

		case 4: break;

		default: 

		cout<<"\n¡ERROR! El numero que selecciono no se encuentra en el menú.\n"<<endl;
		
	}//fin menu

	cout<<"\n¿Desea continuar haciendo calculos? "<<endl;
	cout<<"1. Si.			2. No."<<endl;
	cout<<"Opcion: ";
	cin>>respuesta;


}//fin while de menu

	return 0;
}//Fin de la función main
