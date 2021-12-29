#include<bits/stdc++.h>

using namespace std;

int main(){

	double xo = 0, xf = 0, fx = 0, fxo = 0, xr = 0, fxf=0, er = 0, ea; 
	int n, max = 50, tol = 0;	
	double coef[11], A[11][11], der[11];
	double f = 0,x=-50,dx=0.001;

	cout<<"\n				<<<<Metodo de Newton-Raphson>>>>		\n";
	cout<<"\nEste programa desarrolla el metodo de Newton para aproximar las raices de polinomios de grado 'n'\n";
	cout<<"dado un punto inicial Xo, el cual debe cumplir ciertas condiciones.\n";
	cout<<"\nIntroduce el grado del polinomio (Maximo grado 10): ";
	cin>>n;

	for(int i=0;i<n;i++){
                for(int j=0;j<n+1;j++){
			if(j==0){
                       		A[i][j] = 0;
			}if(j==1+i){
				A[i][j] = 1+i;
			}else{
				A[i][j] = 0;
			}
			
                }
        }	
	
	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio f(x):\n\n";

	for(int j=n;j>=0;j--){
		cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
		cin>>coef[j];
	}

	for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
			if(coef[j]==0){
				der[i] = 0;
			}else{
                       		der[i] += A[i][j]*coef[j];
			}
                }
        }

	cout<<"\nEl polinomio que ingresaste es: \n\n";

        for(int j=n;j>=1;j--){
                cout<<coef[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<coef[j];
		}
        }

	cout<<"\n\nLa derivada del polinomio es: \n\n";

        for(int j=n-1;j>=1;j--){
                cout<<der[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<der[j];
		}
        }

	cout<<"\n\nEl punto inicial Xo tiene que cumplir que f'(Xo) es distinto de cero.";
	cout<<"\n\nIntroduzca el valor inicial de Xo: ";
	cin>>xo;

	for(int i=n;i>=0;i--){
		fxo += coef[i]*pow(xo,i);
	}//evaluación f(Xo)

	for(int i=n-1;i>=0;i--){
		fx += der[i]*pow(xo,i);
	}//evaluacion f'(xo)

	if(fxo==0){

		cout<<"\nEl valor del punto incial es la raiz del polinomio.\n";
		cout<<"\n\tf("<<xo<<") = "<<fxo<<endl;
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<xo<<endl;

	}else{		

		if(fx==0){

		cout<<"\nEL metodo no puede desarrollarse, debido a que f'(Xo) = 0."<<endl;
	
	}else{

/*		if(fa*fb>0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\t\tf(a) = "<<fa<<"\t"<<"f(b) = "<<fb<<endl;
			cout<<"\nEs probable que la función no tenga raices reales."
		}else{ */

		cout<<"\nNOTA: Si el valor de Xo es muy alejado de la raiz el metodo puede no funcionar.\n";
		cout<<"\nIntroduzca el error permitido: ";
		cin>>xr;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto Xo"<<"\tPunto Xf"<<"\tEvaluación f(Xo)."<<"\tEvaluación f(Xf)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(tol<=max){

			xf = xo - (fxo/fx);

			er = (abs(xf-xo)) / abs(xf);

			ea = (abs(xf-xo));


			if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<xr<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<xf<<endl<<endl;

				break;

			}

			fxf=0;

			for(int i=n;i>=0;i--){
					fxf += coef[i]*pow(xf,i);
				} //evaluación f(xf)

			if(fxf==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<xf<<endl<<endl;

				break;


			}


//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(tol<=10){

			cout<<endl<<tol<<"\t"<<xo<<" \t"<<xf<<" \t"<<fxo<<" \t\t"<<fxf<<" \t\t"<<er<<" \t\t"<<ea<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------			
			
			fxo=0; fx=0;

			for(int i=n;i>=0;i--){
				fxo += coef[i]*pow(xf,i);
			} 


			for(int i=n;i>=0;i--){
				fx += der[i]*pow(xf,i);
			}

			xo=xf;

			tol++;


			if(tol==max){
				
cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.\n\n";
				//cout<<"\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<xf<<endl<<endl<<endl;


			}//fin if(tol==max)  

		}

		//}//fin if-else fa*fb>0

	}//fin if-else fa=0

}//fin else fx=0

	ofstream file_plot;
	file_plot.open("grafica6.dat");

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
	fprintf(vent, "load \"polinomio2.txt\"\n"); 

	return 0;
}
