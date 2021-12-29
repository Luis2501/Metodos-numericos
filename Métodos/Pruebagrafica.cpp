#include<bits/stdc++.h>
#include"graficadora.cpp"

using namespace std;

int main(){

	Grafica Grafica_generada;

	int g;
	double coeficiente_Polinomio[100];
	
	time_t rawtime;
        string fecha;

        time(&rawtime);
        fecha = ctime(&rawtime);
	cout<<endl<<fecha;

	cout<<"\n\nIntroduce el grado del polinomio (Maximo grado 100): ";
	cin>>g;

	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio f(x):\n\n";

	for(int j=g;j>=0;j--){
		cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
		cin>>coeficiente_Polinomio[j];
	}

	cout<<"\nEl polinomio que ingresaste es: \n\n";

        for(int j=g;j>=1;j--){
                cout<<coeficiente_Polinomio[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<coeficiente_Polinomio[j];
		}
        }

	Grafica_generada.datosGrafica(g, coeficiente_Polinomio);
	Grafica_generada.GraficaG(g, coeficiente_Polinomio);
	Grafica_generada.Documento();

	return 0;
}
