#include<iostream>
#include<cmath>

using namespace std;

int main(){

	double decimal, binario;
	int exp, digito;

				cout<<"\nIntroduce un numero en sistema decimal: ";
   				cin>>decimal;
   				exp=0;
   				binario=0;

   				while(((decimal/2))!=0){
        				digito = (int)decimal* 2;
           				binario = binario + digito * pow(10.0,exp);
           				exp--;
           				decimal=(decimal/2);
   				}

   				binario=binario + decimal * pow(10.0,exp);
   				cout<<endl<<"El numero en sistema binario es: "<<binario<<endl;
	return 0;
}
