#include<bits/stdc++.h>

using namespace std;

#define pi 3.141592

int main(){

	double t=-2;
	double dt=0.5;
	double y=0, v=0;
	double yo=20;
	double vo=10;
	double g;

	g = 9.81;

	ofstream archivo;
	archivo.open("funcion.txt");

	cout<<"t (seg) "<<" "<<" y (metros) "<<endl<<endl;

	while(t<=2){
	
		y=0;

		//y = vo*t - (g*pow(t,2)/2);
		y = pow(cos(t),10);
		
		
		archivo<<t<<"\t"<<y<<endl;
		cout<<t<<"\t"<<y<<endl;
		t+=dt;
	
	}

	archivo.close();
/*
	t=0;

	ofstream archivo1;
	archivo1.open("velocidad.txt");

	cout<<"\n\ntiempo (seg)"<<" "<<" velocidad (m/seg)"<<endl<<endl;

	while(t<=5){
	
		v=0;

		v = vo - g*(t);
		
		archivo1<<t<<"\t"<<v<<endl;
		cout<<t<<"\t"<<v<<endl;
		t+=dt;
	
	}

	archivo1.close();
*/

	return 0;
}
