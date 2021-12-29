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
	double decimal1 = 0;
	char menu = 'n';
	char s;

while(menu!=s){

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

		}

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
}

	cout<<"\n¿Deseas continuar haciendo calculo s/n? "<<endl;
	cin>>menu;

	return 0;
}

//Fin de la función main
