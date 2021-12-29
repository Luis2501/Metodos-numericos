#include<bits/stdc++.h>

using namespace std;

int main(){

	cout<<"\n\nLectura de un archivo de texto.\n\n";

	ifstream archivo;
	string nombreArchivo;
	string texto;

	cout<<"Digite el nombre del archivo: ";
	getline(cin,nombreArchivo);

	cout<<"\n\n";

	archivo.open(nombreArchivo.c_str(),ios::in); //Abriendo el archivo 

	if(archivo.fail()){

		cout<<"No se pudo abrir el archivo. \n"; //Condicion por si el archivo no abre
		exit(1);
	}

	while(!archivo.eof()){

		getline(archivo,texto);
		cout<<texto<<endl;
	}

	archivo.close(); //Cerrando el archivo 

	return 0;
}
