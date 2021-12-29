#include<iostream>
#include<string>
#include<cmath>
#include<math.h>

using namespace std;

int main(){

//Variables

	int opc, base, exp;
	long int digito, binario, decimal, octal, entero;
	string decimals = "";
	long double decimal1 = 0;
	
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
		cout<<"1. Decimal->Binario (Enteros).			3.Decimal->Binario (Punto decimal)."<<endl;
		cout<<"2. Binario->Decimal (Enteros).			4.Binario->Decimal (Punto decimal)."<<endl<<endl;
		cout<<"Opcion: ";
		cin>>base;

		switch(base){
//Decimal->Binario
			case 1:
				cout<<"\nIntroduce un numero en sistema decimal: ";
   				cin>>decimal;
   				exp=0;
   				binario=0;

   				while(((decimal/2))!=0){
        				digito = decimal% 2;
           				binario = binario + digito * pow(10.0,exp);
           				exp++;
           				decimal=(decimal/2);
   				}

   				binario=binario + decimal * pow(10.0,exp);
   				cout<<endl<<"El numero en sistema binario es: "<<binario<<endl;

		break;
//Binario->Decimal
			case 2:
				cout<<"\nIntroduce un numero en sistema binario: ";
   				cin>>binario;
   				exp=0;
   				decimal=0;

   				while(((binario/10))!=0){
          				digito = binario%10;
           				decimal = decimal + digito * pow(2.0,exp);
           				exp++;
           				binario=(binario/10);
   				}

   				decimal=decimal+binario*pow(2.0,exp);
				cout<<endl<<"El numero en sistema decimal es: "<<decimal<<endl;

		break;

//Decimal->Binario con punto decimal

			case 3:
			{
				double numero;
				int dividendo, resto, divisor = 2, i = 0;
				string binario = "";

				cout<<"\nIntroduce un numero en sistema decimal: ";
				cin>>numero;

				dividendo = numero;
				decimal1 = numero -dividendo;
//				cout<<dividendo<<endl<<decimal1<<endl;
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


				while(i<30){

				decimal1 = decimal1 * 2;
				entero = decimal1;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal1 = decimal1 - entero;
				//cout<<convertir;
				i++;

				}
				cout<<"El numero en sistema binario es:  "<<binario<<"."<<decimals<<endl;
			}
		break;

//Convertir Binario->Decimal (Punto decimal)

			case 4:{
				int exp,digito, entero, i=0;
				    double binario, decimal, numero, parted;
			//	   int arreglo[20];
				   cout << "\nIntroduce numero en sistema binario: ";
				   cin >> numero;
				   entero = numero;
				   binario = entero;
				   parted = numero - entero;
				//  cout<<parted;
				   //decimal = numero - binario;				   
				   exp=0;
				   decimal=0;
				   while(((int)(binario/10))!=0)
				   {
					   digito = (int)binario % 10;
					   decimal = decimal + digito * pow(2.0,exp);
					   exp++;
					   binario=(int)(binario/10);
				   }
				   decimal=decimal + binario * pow(2.0,exp);



		break;

		}

	break;

//Convertir de Octal<->Decimal

		case 2:

		cout<<"\nSeleccione la conversion a realizar."<<endl<<endl;
                cout<<"1. Decimal->Octal (Enteros).			3.Decimal->Octal (Punto decimal)."<<endl;
                cout<<"2. Octal->Decimal (Enteros).				4.Octal->Decimal (Punto decimal)."<<endl<<endl;
                cout<<"Opcion: ";
                cin>>base;

                switch(base){
//Decimal->Octal
                        case 1:
				cout<<"\nIntroduce un numero en sistema decimal: ";
   				cin>>decimal;
   				exp=0;
   				octal=0;

   				while(((decimal/8))!=0){
           				digito = decimal%8;
           				octal = octal + digito * pow(10.0,exp);
           				exp++;
           				decimal=(decimal/8);
   				}

   				octal = octal + decimal * pow(10.0,exp);
   				cout<<endl<<"El numero en sistema octal es: "<<octal<< endl;

                break;
//Octal->Decimal
                        case 2:
				cout<<"\nIntroduce un numero en sistema octal: ";
   				cin>>octal;
   				exp=0;
   				decimal=0;

   				while(((octal/10))!=0){
           				digito = octal%10;
           				decimal = decimal + digito * pow(8.0,exp);
           				exp++;
           				octal =(octal/10);
   				}

   				decimal = decimal + octal * pow(8.0,exp);
   				cout<<endl<<"El numero en sistema decimal es: "<<decimal<<endl;
                break;

			case 3:{
				int base, suma, num, res, i = 0;
     				double a;
				base = 1;
     				suma = 0;

				cout<<"De el numero decimal a convertir";
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

				while(i<8){

				decimal = decimal * 8;
				entero = decimal;
				//decimals = decimals + (char(entero) +48);
				decimals += (char)entero+48;

				//cout<<entero<<endl<<convertir;
				decimal = decimal - entero;
				//cout<<convertir;		
				i++;

				}
				//while (octales)
           			
					cout<<"El numero octal es: " << suma<<"."<<decimals;
				}
			}
			break;
                

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
                        case 1:

				cout<<"\nIntroduce un numero en sistema binario: ";
        	                cin>>binario;
                	        exp=0;
                        	decimal=0;
				octal=0;

				while(((binario/10))!=0){
                                        digito = binario%10;
                                        decimal = decimal + digito * pow(2.0,exp);
                                        exp++;
                                        binario=(binario/10);
                                }

                                decimal=decimal+binario*pow(2.0,exp);

				exp=0;
				while(((decimal/8))!=0){
                                        digito = decimal%8;
                                        octal = octal + digito * pow(10.0,exp);
                                        exp++;
                                        decimal=(decimal/8);
                                }

                                octal = octal + decimal * pow(10.0,exp);
                                cout<<endl<<"El numero en sistema octal es: "<<octal<< endl;

                break;
//Octal->Binario
                        case 2:
				cout<<"\nIntroduce un numero en sistema octal: ";
                                cin>>octal;
                                exp=0;
                                decimal=0;
				binario=0;

                                while(((octal/10))!=0){
                                        digito = octal%10;
                                        decimal = decimal + digito * pow(8.0,exp);
                                        exp++;
                                        octal =(octal/10);
                                }

                                decimal = decimal + octal * pow(8.0,exp);

				exp=0;
				while(((decimal/2))!=0){
                                        digito = decimal% 2;
                                        binario = binario + digito * pow(10.0,exp);
                                        exp++;
                                        decimal=(decimal/2);
                                }

                                binario=binario + decimal * pow(10.0,exp);
                                cout<<endl<<"El numero en sistema binario es: "<<binario<<endl;

                break;

                }


	break;

		case 4: break;

	}

	return 0;
}

//Fin de la función main
