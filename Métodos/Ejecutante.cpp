#include<bits/stdc++.h>
#include"generar_funcion.cpp"

using namespace std;

int main(){

	generarFuncion gFuncion;

	gFuncion.Funcion();

	int n;

	cout<<"\nLa función que digito es "<<funcion<<"\n¿Desea continuar?\n";
	cout<<"1. Si \t\t 2. No\n";
	cout<<"Opcion: ";
	cin>>n;

	if(n==1){

	system("c++ -o taylor taylor.cpp && ./taylor ");

	}else{

	system("pause");

	}	

	return 0;
}
