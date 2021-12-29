#include <iostream>
//#include <array>
#include <math.h>
using namespace std;

int main(){
	int n, m, entero;
double original,convertir,decimal=0;
string decimals = "";
cout<<"Seleccione el sistema numerico incial"<<endl;
cout<<"1) Decimal \n2) Binario \n3) Octal"<<endl;
cin>>n;

cout<<"Seleccione el sistema numerico a convertir"<<endl;
cout<<"1) Decimal \n2) Binario \n3) Octal"<<endl;
cin>>m;



	switch(n){
		case 1: 
			if(m == 1){
				cout<<"De el numero en decimal";
				cin>>original;
				cout<<"El numero en decimal es :"<<original;
			}
			if(m==2){
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
				cout<<"En sistema binario"<< numero  << "se escribe: "<<binario<<"."<<decimals;
			}

			if(m==3){
				//string octal = "";

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

            			//}
				/* int parte_entera, c,r;
   				double parte_decimal;   
				string Result;
   
   				parte_entera = convertir/1;
   				parte_decimal = convertir-parte_entera;

				c = parte_entera/8;
				r = parte_entera % 8;
				
				octal = Result + octal;
				while(c >= 8){
					r = c%8;

					c = c/8;
				

				
					octal = Result + octal;
					
				}
				
				

				
				
				octal = Result + octal;*/
				/*int i = 0;
				while(i<10){
				convertir = convertir * 8;
				entero = convertir;
				cout<<entero<<endl<<convertir;
				convertir = convertir - entero;
				cout<<convertir;
				i++;
				}*/

				//cout<<"En sistema octal "<<original<<"se escribe: "<<convertir;
			}

			break;

		case 2:
			if(m ==1){
				    int exp,digito, entero;
				    double binario, decimal, numero, parted;
				   int arreglo[20];
				   cout << "Introduce numero: ";
				   cin >> numero;
				   entero = numero;
				   binario = entero;
				   parted = numero - entero;
				  cout<<parted;
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
				   
				   for(int k = 0; k<8;k++){

					arreglo[k] =decimal; 
				   }
 				   cout << endl << "Decimal: " << decimal << endl;
			
				
				
				
				
				}

			if(m==2){
				cout<<"De el numero en Binario";
				cin>>original;
				cout<<"El numero en binario es :"<<original;
			}

			if(m==3){}

			break;

		case 3:

			if(m==1){

				int octalNumber, decimalNumber = 0, i = 0, rem;
				double numero;
				cout<<"De el numero en octal a convertir";
				cin>>numero;
				octalNumber = numero;
				
			    while (octalNumber != 0)
			    {
				rem = octalNumber % 10;
				octalNumber /= 10;
				decimalNumber += rem * pow(8, i);
				++i;
			    }
			cout<<"En sistema octal"<< numero << "se escribe: "<< decimalNumber;

			}

			if(m==2){
				int octalNumber, decimalNumber = 0, i = 0, rem;
				double numero;
				cout<<"De el numero en octal a convertir";
				cin>>numero;
				octalNumber = numero;
				
			    while (octalNumber != 0)
			    {
				rem = octalNumber % 10;
				octalNumber /= 10;
				decimalNumber += rem * pow(8, i);
				++i;
			    }
				
				int dividendo, resto, divisor = 2, j = 0;
				string binario = "";
							
				dividendo = decimalNumber;
				
				
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

				cout<<"En sistema octal"<< numero  << "se escribe: "<<binario;
					
			}
			

	}
return 0;
}
