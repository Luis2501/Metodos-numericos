#include<bits/stdc++.h>

using namespace std;

int main(){

	double a = 0, b = 0, fa = 0, fb = 0, xr = 0, fc=0, er = 0, c=0, ea =0; 
	int n, max = 200, tol = 0;	
	double coef[11];
	double f = 0,x=-50,dx=0.001;

	cout<<"\n				<<<<Metodo de Posición Falsa>>>>		\n";
	cout<<"\nEste programa desarrolla el metodo de posición falsa para aproximar las raices de polinomios de grado 'n'\n";
	cout<<"dado un intervalo incial [a,b], el cual debe cumplir ciertas condiciones.\n";
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

	cout<<"\n\nEl intervalo [a,b] tiene que cumplir que f(a) y f(b) tienen signos distintos.\n";
	cout<<"\nIntroduzca el intervalo [a,b]: ";
	cout<<"\n\na = ";
	cin>>a;

	for(int i=n;i>=0;i--){
		fa += coef[i]*pow(a,i);
	}//evaluación f(a)

	cout<<"b = ";
	cin>>b;

	for(int i=n;i>=0;i--){
		fb += coef[i]*pow(b,i);
	}//evaluación f(b)

	if(fa==0 || fb==0){
		cout<<"\nUno de los valores del intervalo es la raiz del polinomio.\n";
		cout<<"\n\tf("<<a<<") = "<<fa<<"\t"<<"f("<<b<<") = "<<fb<<endl;

		if(fa==0){
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<a<<endl;
		}else{
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<b<<endl;
		}
		
	}else{

		if(fa*fb>0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\t\tf(a) = "<<fa<<"\t"<<"f(b) = "<<fb<<endl;
			cout<<"\nNOTA: Es probable que la función no tenga raices reales.";
		}else{

		cout<<"\nIntroduzca el error permitido: ";
		cin>>xr;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto x = a"<<"\tPunto x = b"<<"\tPunto x = c"<<"\tEvaluación f(c)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(tol<=max){

			c = b - (fb*(b-a))/(fb-fa);

			er = (abs(b-a)) / abs(b);

			ea = (abs(b-a));


			if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<xr<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl;
				cout<<"Tol: "<<tol;

			break;

			}

			fc=0;

				for(int i=n;i>=0;i--){
					fc += coef[i]*pow(c,i);
				} //evaluación f(c)

			if(fc==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl;

			break;


			}


//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(tol<=10){

			cout<<endl<<tol<<setw(15)<<a<<setw(15)<<b<<setw(15)<<c<<setw(20)<<fc<<setw(20)<<er<<setw(20)<<ea<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------			

			if(fc*fa<0){

				b = c;
			}
			/*if(fp*fb<0)*/else{
			
				a = c;
			}
						

			for(int i=n;i>=0;i--){
				fa += coef[i]*pow(a,i);
			} 


			for(int i=n;i>=0;i--){
				fb += coef[i]*pow(b,i);
			}

			//cout<<endl<<fa<<" "<<fb<<endl;

			tol++;

			if(tol==max){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
			cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.";				
			//cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl<<endl;

				break;

			}

		}

		}//fin if-else fa*fb>0

	}//fin if-else fa=0


	ofstream file_plot;
	file_plot.open("grafica5.dat");

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
	fprintf(vent, "load \"polinomio1.txt\"\n");


	return 0;
}
