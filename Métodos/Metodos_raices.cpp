#include<bits/stdc++.h>
#include"Metodos_raices.h"

using namespace std;

	int Metodos_raices::menuMetodos(int opcion){

	cout<<"\n\t\t\t <<<<Métodos númericos para Ingenieria física>>>> \n";
	cout<<"\t\t\t     Facultad de Ciencias Fisico Matematicas.\n\n";

	cout<<"Digite la opción del método que desea realizar: \n";
	cout<<"\nMétodos para solución de ecuaciones no lineales. \n";
	cout<<"\n1.- Método de Bisección.";
	cout<<"\n2.- Método de Posición Falsa.";
	cout<<"\n3.- Método de Newton-Rhapson.";
	cout<<"\n4.- Método de la Secante.";
	cout<<"\n5.- Método de Horner.";
	cout<<"\n6.- Método de Müller.";
	cout<<"\n\nMétodos para solución de sistemas de ecuaciones lineales.\n";
	cout<<"\n7.- Solución por método de Gauss-Jordan.";
	cout<<"\n8.- Solución por método de la inversa.";
	cout<<"\n\nMétodos de interpolación.\n";
	cout<<"\n9.- Interpolación Simple.";
	cout<<"\n10.- Interpolación de Lagrange.";
	cout<<"\n11.- Interpolación de trazadores cúbicos.\n\n";
	cout<<"Opcion: ";
	cin>>opcion;

	return opcion;

	}//fin funcion menú

	int Metodos_raices::pedirGrado(int n){

	cout<<"\n\nIntroduce el grado del polinomio (Maximo grado 10): ";
	cin>>n;

		return n;
	}
	

	void Metodos_raices::pedirPolinomio(int n){
	
	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio f(x):\n\n";

		for(int j=n;j>=0;j--){
			cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
			cin>>coef[j];
		}//fin for

	cout<<"\nEl polinomio que ingresaste es: \n\n";

        	for(int j=n;j>=1;j--){
                	cout<<coef[j]<<"*x^"<<j<<" + ";
				if(j==1){
				j=0;
				cout<<coef[j];
			}//fin if
        	}//fin for


	}//fin función pedir polinomio

	double Metodos_raices::Evaluacion(int g, double x, double poli[]){

		f=0;

		for(int i=g;i>=0;i--){
			f += poli[i]*pow(x,i);
		}

		return f;

	}//fin funcion evaluacion
	
//Metodo de Biseccion---------------------------------------------------------------------------------------------------------------------------

	void Metodos_raices::Biseccion(int n){

	tol=0, max=1000;
	
	cout<<"\n\nEl intervalo [xo,xf] tiene que cumplir que f(xo) y f(xf) tienen signos distintos.\n";
	cout<<"\nIntroduzca el intervalo [xo,xf]: ";
	cout<<"\n\nxo = ";
	cin>>xo;

	fxo = Evaluacion(n, xo, coef);

	cout<<"xf = ";
	cin>>xf;	

	fxf = Evaluacion(n,xf,coef);

	if(fxo==0 || fxf==0){
		cout<<"\nUno de los valores del intervalo es la raiz del polinomio.\n";
		cout<<"\n\tf("<<xo<<") = "<<fxo<<"\t"<<"f("<<xf<<") = "<<fxf<<endl;

		if(fxo==0){
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<xo<<endl;
		}else{
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<xf<<endl;
		}
	}else{

		if(fxo*fxf>0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\tf(xo) = "<<fxo<<"\t"<<"f(xf) = "<<fxf<<endl;
			cout<<"\nNOTA: Es probable que la función no tenga raices reales.\n\n";
		}else{

		cout<<"\nIntroduzca el error permitido: ";
		cin>>xr;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto x = a"<<"\tPunto x = b"<<"\tPunto medio."<<"\tEvaluación f(pm)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(tol<=max){

			pm = xo + ((xf-xo)/2); //Calcular el punto medio 

			er = (abs(xf-xo)) / abs(xf);

			ea = (abs(xf-xo));

			if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<xr<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<pm<<endl<<endl;

			break;

			}

			fp=0;

				fp = Evaluacion(n,pm,coef);

			if(fp==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<pm<<endl<<endl;

			break;

			}

//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(tol<=10){

			cout<<endl<<tol<<"\t"<<xo<<" \t"<<xf<<" \t"<<pm<<" \t"<<fp<<" \t\t"<<er<<" \t\t"<<ea<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------	


			if(fp*fxo<0){

				xf = pm;
			}else{
			
				xo = pm;
			}
			

			tol++;

			if(tol==max){
	
cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
			cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.";				

			break;

			}

		}

		}//fin if-else fa*fb>0

	}//fin if-else fa=0


	}//fin de la funcion biseccion

//Metodo de posicion falsa----------------------------------------------------------------------------------------------------------------------

	void Metodos_raices::Posicion(int n){

	tol=0, max=1000; fxo=0; fxf=0; c=0;
	xr=0; er=0; fc=0; xo=0; xf=0;
	
	cout<<"\n\nEl intervalo [xo,xf] tiene que cumplir que f(xo) y f(xf) tienen signos distintos.\n";
	cout<<"\nIntroduzca el intervalo [xo,xf]: ";
	cout<<"\n\nxo = ";
	cin>>xo;

	fxo = Evaluacion(n, xo, coef);

	cout<<"xf = ";
	cin>>xf;	

	fxf = Evaluacion(n,xf,coef);

	if(fxo==0 || fxf==0){
		cout<<"\nUno de los valores del intervalo es la raiz del polinomio.\n";
		cout<<"\n\tf("<<xo<<") = "<<fxo<<"\t"<<"f("<<xf<<") = "<<fxf<<endl;

		if(fxo==0){
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<xo<<endl;
		}else{
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<xf<<endl;
		}
	}else{

		if(fxo*fxf>0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\tf(xo) = "<<fxo<<"\t"<<"f(xf) = "<<fxf<<endl;
			cout<<"\nNOTA: Es probable que la función no tenga raices reales.\n\n";
		}else{

		cout<<"\nIntroduzca el error permitido: ";
		cin>>xr;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto x = a"<<"\tPunto x = b"<<"\tPunto x = c"<<"\tEvaluación f(c)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(tol<=max){

			c = xf - (((fxf)*(xf-xo))/(fxf-fxo));

			er = (abs(xf-xo)) / abs(xf);

			ea = (abs(xf-xo));


			if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<xr<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl;

			break;

			}

			fc=0;

			fc = Evaluacion(n,c,coef);

			if(fc==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl;

			break;


			}


//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(tol<=10){

			cout<<endl<<tol<<"\t"<<xo<<" \t"<<xf<<" \t"<<c<<" \t"<<fc<<" \t\t"<<er<<" \t\t"<<ea<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------			

			if(fc*fxo<0){

				xf = c;
			}
			/*if(fp*fb<0)*/else{
			
				xo = c;
			}

			fxo = Evaluacion(n,xo,coef);

			fxf = Evaluacion(n,xf,coef);
			
			//cout<<endl<<fa<<" "<<fb<<endl;

			tol++;

			if(tol==max){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
			cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.\n\n";				
			//cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl<<endl;

				break;

			}

		}

		}//fin if-else fa*fb>0

	}//fin if-else fa=0

	}//fin de la funcion posicion

//Metodo de Newton------------------------------------------------------------------------------------------------------------------------------
