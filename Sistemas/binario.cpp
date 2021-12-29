#include<iostream>
#include<cmath>

using namespace std;

int main(){

	long int exp, digito;
	long int binario, decimal;

   	cout<<"Introduce numero: ";
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
	cout<<endl<<"Decimal: "<<decimal<<endl;

	return 0;
}
