#include<bits/stdc++.h>

using namespace std;

#define g 9.81

class Simpson{

public:

	double Integral(double t, double v){

		I = 0;		

		I = v - g*t;
	
		return I;

	}

	double Simpson1(double h){

		Simpson1_3 = 0;

		Simpson1_3 = (h*(Integral(to,vo) + 4*Integral(t1,vo) + Integral(tf,vo)) )/3;

		return Simpson1_3;

	}

	double Simpson3(double h){

		Simpson3_8 = 0;

		Simpson3_8 = ((3*h)*(Integral(to,vo) + 3*Integral(t2,vo) + 3*Integral(t3,vo)+ Integral(tf,vo)) )/8;

		return Simpson3_8;

	}

	void simpson(){

		cout<<"\n\n\t\t<<<<Método de Simpson: Integración numérica.>>>>";

		cout<<"\n\nEste programa realiza la integración numérica mediante el método de Simpson \n";
		cout<<"de 1/3 y 3/8, haciendo una comparativa entre los dos métodos.\n\n";
		cout<<"La problemática a resolver es el desplazamiento de una pelota que es lanzada \n";
		cout<<"con una cierta velocidad Vo en un intervalo de tiempo [to,tf], de modo que se \n";
		cout<<"tiene la siguiente expresión: ";
		cout<<"\n\n \t\t\t V = Vo - gt \n";

		cout<<"\nDigite la velocidad incial Vo de lanzamiento: ";
		cin>>vo;

		cout<<"\nDigite el intervalo de tiempo [to,tf] en el cual quiere saber el desplazamiento. \n";
		cout<<"to: ";
		cin>>to;
		cout<<"tf: ";
		cin>>tf;
		
		h1 = (tf-to)/2;

		h3 = (tf-to)/3;

		t1 = to + h1;

		t2 = to + h3;
		
		t3 = t2 + h3;

		S1 = Simpson1(h1);

		S3 = Simpson3(h3);
	
		Error = abs(S3 - S1)/abs(S3);

		cout<<"\nEl valor del desplzamiento en el intervalo ["<<to<<","<<tf<<"] de la pelota es: \n\n";
		cout<<"Método de Simpson 1/3."<<setw(25)<<"Método de Simpson 3/8. "<<setw(25)<<" Error. \n\n";
		cout<<S1<<setw(25)<<S3<<setw(25)<<Error<<endl<<endl;

		x=to;
		dx=0.1;

		ofstream file_plot;
		file_plot.open("simpson.dat");

		while(x<tf){

			f=0;

			f += Integral(x,vo);
		
		//cout<<x<<" "<<f<<endl;
		file_plot<<x<<" "<<f<<endl;
		x+=dx;
		}

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"simpson.txt\"\n"); 

	}

private:

	double vo, to, tf, t1, t2, t3, h1, h3; //Valores condiciones inciales
	double I; //Función de la integral a evaluar
	double S1, S3; //Valores finales
	double Simpson1_3, Simpson3_8; //Funciones
	double Error;
	double f,x,dx;
};
		

int main(){

	Simpson simps;
	simps.simpson();

	return 0;	
}
