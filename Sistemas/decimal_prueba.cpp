#include <iostream>
#include <cmath>

using namespace std;

int main(){

	long int exp,digito;
	long int binario, decimal;

   	cout<<"Introduce numero: ";
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
   	cout<<endl<<"Binario: "<<binario<<endl;

        return 0;
}

