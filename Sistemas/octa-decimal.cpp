#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){

		double octal, parte;
		int n, i=0, exp=0, entero, numoct, entero1, parte1;
		string  suma ="";

	cout<<"\nIntroduce un numero en sistema octal: ";
	cin>>octal;

	entero = octal;
	numoct= entero;
	parte = octal - entero;
	cout<<endl<<parte<<endl;

	while(i<20){

		parte = parte*10;
		suma += parte*pow(8.0, exp-1);
		parte = parte - entero1;
		exp--;
		i++;
	}

	cout<<"El numero en sistema decimal es: "<<suma<<endl;

	return 0;
}
