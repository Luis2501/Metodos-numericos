#include<bits/stdc++.h>

using namespace std;

int main(){

	double xo = 0, xf= 0, fxo = 0, fxf=0, er=0, xr=0, ea= 0; 
	int n, max = 50, tol = 0;	
	double coef[11], der[11];
	double f = 0,x=-50,dx=0.001;

	cout<<"\n				<<<<Metodo de Horner>>>>		\n";
	cout<<"\nEste programa desarrolla el metodo de Horner para aproximar la evaluación de un punto Xo en un \n";
	cout<<"polinomio de grado 'n' y la evaluación de este punto en la derivada del polinomio.\n";
	cout<<"\nIntroduce el grado del polinomio (Maximo grado 10): ";
	cin>>n;	
	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio P(x):\n\n";

	for(int j=n;j>=0;j--){
		cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
		cin>>coef[j];
	}

	cout<<"\nEl polinomio que ingresaste es: \n\n";

	cout<<"P(x) = ";

        for(int j=n;j>=1;j--){
                cout<<coef[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<coef[j];
		}
        }

	cout<<"\n\nIntroduzca el valor inicial de Xo: ";
	cin>>xo;

	fxo=coef[n];
	fxf=coef[n];

	for(int j=n-1;j>=1;j--){

		fxo=(xo*fxo)+coef[j];
		fxf=(xo*fxf)+fxo;

	}

	fxo=(xo*fxo)+coef[0];

	if(fxf==0){
		cout<<"\nEl metodo no se puede desarrollar, debido a que P'(x) = 0\n\n";
	}else{

	cout<<"\nIntroduzca el error perimitido: ";
	cin>>xr;


	//cout<<"\n\tP(Xo) = "<<fxo<<"\t\t"<<"P'(Xo) = "<<fxf<<endl;

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto Xo"<<"\tPunto Xf"<<"\tEvaluación P(Xf)."<<"\tEvaluación P'(Xf)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

while(tol<=max){

	xf = xo - fxo/fxf;
	er=abs(xf-xo)/abs(xf);
	ea = (abs(xf-xo));

	fxo=coef[n];
	fxf=coef[n];

	for(int i=n-1;i>=1;i--){

		fxo=(xf*fxo)+coef[i];
		fxf=(xf*fxf)+fxo;

	}

	fxo=(xf*fxo)+coef[0];

	if(er<xr){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
		cout<<"\nEl valor de P(Xo) es igual a cero."<<endl;	
		cout<<"\nPor lo tanto x = "<<xf<<" es la raiz del polinomio P(x)."<<endl;
		break;

	}

	if(fxo==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------";
		cout<<"\nEl valor de P(Xo) es igual a cero."<<endl;	
		cout<<"\nPor lo tanto x = "<<xf<<" es la raiz del polinomio P(x)."<<endl;
		break;

	}

//Tabla de valores-------------------------------------------------------------------------------------------------------------------

	if(tol<=10){

		cout<<endl<<tol<<"\t"<<xo<<" \t"<<xf<<" \t"<<fxo<<" \t\t"<<fxf<<" \t\t"<<er<<" \t\t"<<ea<<endl;

	}

//------------------------------------------------------------------------------------------------------------------------------------			


	xo=xf;

	tol++;

}//fin while  

}//fin else
	ofstream file_plot;
	file_plot.open("grafica8.dat");

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
	fprintf(vent, "load \"polinomio4.txt\"\n"); 

	return 0;
}
