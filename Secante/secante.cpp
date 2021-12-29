#include<bits/stdc++.h>

using namespace std;

int main(){

	double xo = 0, xf = 0, p=0, fx = 0, fxo = 0, xr = 0, fxf=0, er = 0, ea; 
	int n, max = 50, tol = 0;	
	double coef[11], A[11][11], der[11];
	double f = 0,x=-50,dx=0.001;

	cout<<"\n				<<<<Metodo de la Secante>>>>		\n";
	cout<<"\nEste programa desarrolla el metodo de la secante para aproximar las raices de polinomios de grado 'n'\n";
	cout<<"dado un intervalo inicial [Xo,Xf], el cual debe cumplir ciertas condiciones.\n";
	cout<<"\nIntroduce el grado del polinomio (Maximo grado 10): ";
	cin>>n;		
	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio f(x):\n\n";

	for(int j=n;j>=0;j--){
		cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
		cin>>coef[j];
	}

	cout<<"\nEl polinomio que ingresaste es: \n\n";

        for(int j=n;j>=1;j--){
                cout<<coef[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<coef[j];
		}
        }

	cout<<"\n\nEl intervalo tiene que cumplir que f(Xf) y f(Xo) son distintos.";
	cout<<"\n\nIntroduzca el valor del intervalo [Xo,Xf]: ";
	cout<<"\n\nXo = ";
	cin>>xo;
	cout<<"Xf = ";
	cin>>xf;


	for(int i=n;i>=0;i--){
		fxo += coef[i]*pow(xo,i);
	}//evaluación f(Xo)

	for(int i=n;i>=0;i--){
		fx += coef[i]*pow(xf,i);
	}//evaluacion f'(xo)

	if(fxo==fx){

		cout<<"\nEl metodo no se puede realizar debido a que f(Xo)=f(Xf)."<<endl;
		cout<<"\nEsto quiere decir que la pendiente de la recta secante";
		cout<<"\nque pasa por los dos puntos es igual a cero."<<endl;

	}else{

	if(fxo==0){
		cout<<"\nUno de los valores del intervalo incial es la raiz del polinomio.\n";
		cout<<"\n\tf("<<xo<<") = "<<fxo<<"\tf("<<xf<<") = "<<fx<<endl;

		if(fxo==0){

		cout<<"\nPor lo tanto la raiz del polinomio es x = "<<xo<<endl;

		}else{

		cout<<"\nPor lo tanto la raiz del polinomio es x = "<<xf<<endl;
		}
		
	}else{

/*		if(fxo*fx>0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\t\tf(Xo) = "<<fxo<<"\t"<<"f(Xf) = "<<fx<<endl;
			cout<<"\nEs probable que la función no tenga raices reales.";
		}else{ */

		cout<<"\nNOTA: Si el valor de Xo es muy alejado de la raiz el metodo puede no funcionar.\n";
		cout<<"\nIntroduzca el error permitido: ";
		cin>>xr;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto Xf"<<"\tPunto p"<<"\tEvaluación f(Xf)."<<"\tEvaluación f(p)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(tol<=max){

			p = xf - ((fx*(xf-xo)) / (fx-fxo));

			er = (abs(p-xf)) / abs(p);

			ea = (abs(p-xf));


			if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<xr<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<p<<endl<<endl;

				break;

			}

			fxf=0;

			for(int i=n;i>=0;i--){
					fxf += coef[i]*pow(p,i);
				} //evaluación f(xf)

			if(fxf==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<p<<endl<<endl;

				break;


			}


//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(tol<=10){

			cout<<endl<<tol<<"\t"<<xf<<" \t"<<p<<" \t"<<fx<<" \t\t"<<fxf<<" \t\t"<<er<<" \t\t"<<ea<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------			
			
				xo=xf;
				fxo=fx;	
				xf=p;
				fx=fxf;
			
			tol++;


			if(tol==max){
				
cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.\n\n";
				//cout<<"\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<xf<<endl<<endl<<endl;


			}//fin if(tol==max)  

		}

		//}//fin if-else fa*fb>0

	}//fin if-else fa=0

}//fin else fx=fxo

	ofstream file_plot;
	file_plot.open("grafica7.dat");

	while(x<=50){

		f=0;

		for(int i=n;i>=0;i--){
			f += coef[i]*pow(x,i);
		}
		//cout<<x<<" "<<f<<endl;
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"polinomio3.txt\"\n"); 

	return 0;
}
