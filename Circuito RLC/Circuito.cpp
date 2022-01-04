//Ana Cecilia Cortes Vargas 
//Luis Eduardo Sánchez González
//Edgar Orlando Rodríguez Figueroa

#include<bits/stdc++.h>
#include"VelocityVerlet.cpp"
#include"RungeKutta.cpp"

using namespace std;

int main(){

	VelocityVerlet MetodoVerlet;
	RungeKutta MetodoRK4;

	int opc, opc1, opc2;
	
	unsigned t0, t1;

	system("clear");

	cout<<"\n\t\t\t <<<<Circuitos eléctricos en ingenieria física>>>> \n";
	cout<<"\t\t\t      Facultad de Ciencias Fisico Matematicas \n\n";

	cout<<"\t\t\t\t   Resolución de un circuito RLC \n\n";

	cout<<"¿Qué tipo de circuito quiere resolver? \n";
	cout<<"1. En serie \t\t 2. En paralelo \n";
	cout<<"Opción: ";
	cin>>opc;

	switch(opc){

		case 1:

			system("clear");

			cout<<"\n\t\t\t <<<<Resolución de un circuito RLC en serie>>>> \n\n";
			cout<<"La ecuación diferencial que modela un circuito RLC en serie es: \n\n";
			cout<<"\t\t\t i\"(t) + (R/L) i'(t) + (1/LC) i(t) = 0    \n\n";

			cout<<"¿Desea ver un circuito RLC en serie? \n"; 
			cout<<"Si su respuesta es \"sí\" presione 1, de lo contrario presione cualquier tecla. \n";
			cout<<"Opción: ";
			cin>>opc1;

			if(opc1==1){

				cout<<"Un circuito en serie se ve de la siguiente manera. \n";

				system("gnome-open SerieRLC.JPG");	
			
			}

			cout<<"\n¿Qué método númerico desea utilizar para resolver la ecuación diferencial? \n";
			cout<<"1. Velocity Verlet \t\t 2. Runge Kutta 4to orden \n";
			cout<<"Opción: ";
			cin>>opc2;

			if(opc2 == 1){

				t0=clock();

				MetodoVerlet.Verlet(opc);

				t1 = clock();

				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				cout<<"\nTiempo de ejecución: "<<time<<endl;
		
			}else{
		
				t0=clock();

				MetodoRK4.Runge(opc);

				t1 = clock();

				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				cout<<"\nTiempo de ejecución: "<<time<<endl;

			}
			
			break;
 

		case 2:
			
			system("clear");

			cout<<"\n\t\t\t <<<<Resolución de un circuito RLC en paralelo>>>> \n\n";
			cout<<"La ecuación diferencial que modela un circuito RLC en paralelo es: \n\n";
			cout<<"\t\t\t V\"(t) + (1/RC) V'(t) + (1/LC) V(t) = 0    \n\n";	

			cout<<"¿Desea ver un circuito RLC en paralelo? \n"; 
			cout<<"Si su respuesta es \"sí\" presione 1, de lo contrario presione cualquier tecla. \n";
			cout<<"Opción: ";
			cin>>opc1;

			if(opc1==1){

			cout<<"Un circuito en paralelo se ve de la siguiente manera. \n";

			system("gnome-open ParaleloRLC.JPG");	
			
			}

			cout<<"\n¿Qué método númerico desea utilizar para resolver la ecuación diferencial? \n";
			cout<<"1. Velocity Verlet \t\t 2. Runge Kutta 4to orden \n";
			cout<<"Opción: ";
			cin>>opc2;

			if(opc2 == 1){

				t0=clock();

				MetodoVerlet.Verlet(opc);

				t1 = clock();

				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				cout<<"\nTiempo de ejecución: "<<time<<endl;
		
			}else{
		
				t0=clock();

				MetodoRK4.Runge(opc);

				t1 = clock();

				double time = (double(t1-t0)/CLOCKS_PER_SEC);
				cout<<"\nTiempo de ejecución: "<<time<<endl;

			}

			break;

		default: 

			cout<<"\nLa opción seleccionada es incorrecta o no se encuentra entre las opciones. \n";

			break;

	}

	return 0; 

}
