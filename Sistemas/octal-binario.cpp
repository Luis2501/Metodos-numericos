#include<iostream>
#include<cmath>

using namespace std;

int main(){

	long int exp, digito;
	long int octal;
	long int binario;

	cout<<"Introduce un numero en sistema binario: ";
        cin>>binario;

//	n=log10(binario)+1;

/*	for(int i=0;i<=n;i++){
	   	cout<<"Introduce un numero en sistema binario: ";
   		cin>>binario[i];
*/	//}
   	exp=0;
   	octal=0;

   	while(((binario/8))!=0){
          	digito = binario%8;
           	octal = octal + digito * pow(2.0,exp);
           	exp++;
           	binario=(binario/8);
   	}

  	octal=octal+binario*pow(2.0,exp);
	cout<<endl<<"El numero en sistema octal es: "<<octal<<endl;


                cout<<"\n\nEl numero octal  es "<<octal<<endl;

	return 0;
}
