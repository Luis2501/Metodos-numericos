#include<string>
#include<iostream>

using namespace std;

int main() {

	int n;
    	string b = "";


	cout<<"Este programa sirve para convertir un numero de sistema decimal o binario"<<endl;

 	cout << "Ingrese un numero entero positivo: \n";
    	cin>>n;

    	if(n>0){

	while(n>0){

        	if(n%2==0){
        		b = "0"+ b;
            	}
	    	else{
                	b = "1"+ b;
            	}

            		n = (int) n/2;
        	}
    	}
    	else
		if(n==0){
        		b = "0";

    	}
		else {
			b = "No se puede realizar la conversión. Ingrese solo numeros positivos";
    	}

    	cout <<"El resultado de la conversion es: "<<b<<endl;

    	return 0;
}
