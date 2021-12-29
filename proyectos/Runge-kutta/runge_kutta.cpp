#include<bits/stdc++.h>

using namespace std;

#define pi 3.1416

class RungeKutta{

public:

	long double Ecuacionx(long double t, long double x){

		f=0;

		f = Vo*cos(teta);

		return f;

	}

	long double Ecuaciony(long double t, long double y){

		g = 0;

		g = Vo*sin(teta) - (9.81)*t;

		return g;

	}

	void Runge(){

	cout<<"\n\n\t\t\t<<<<Metodo de Runge-Kutta>>>>";
	cout<<"\n\nEste programa realiza el método de Runge-Kutta de cuarto orden para una ecuación \n";
	cout<<"diferencial de orden 1, con condiciones inciales.\n\n";
	cout<<"La problemática a resolver es la trayectoria de una pelota que es lanzada \n";
	cout<<"con una cierta velocidad Vo en un intervalo de tiempo [to,tf], de modo que se \n";
	cout<<"tiene la siguiente expresión: ";
	cout<<"\n\n \t\t\t r'(t) = (Vo Cos(θ), Vo Sen(θ) - gt) \n";
	cout<<"\n\t\tCon X(to) = Xo \t y \t Y(to) = Yo\n";

	cout<<"\nDigite la condicion incial X(to) y Y(to): \n";
	cout<<"Xo = ";
	cin>>xo;
	cout<<"Yo = ";
	cin>>yo;
	cout<<"\nIngrese el intervalo de tiempo de la trayectoria [to,tf]: \n";
	cout<<"to = ";
	cin>>to;
	cout<<"tf = ";
	cin>>tf;

	cout<<"\nDigite el ángulo de lanzamiento incial (en grados): ";
	cin>>teta;

	teta = (teta)*(pi/180);

	cout<<"\nIngrese la velocidad incial Vo  de lazamiento: ";
	cin>>Vo;

	cout<<"\nDigite el numero de iteraciones permitidas: ";
	cin>>n;

	h = (tf-to)/n;
	t=to;
	x=xo;
	y=yo;
	

	ofstream file_plot;
	file_plot.open("solucion.dat");

	file_plot<<x<<" "<<y<<endl;

	while(t<=tf){

		Xt=0; K1=0; K2=0; K3=0; K4=0;

		K1 = Ecuacionx(t, x);
		K2 = Ecuacionx(t + h/2, x + (h*K1)/2);
		K3 = Ecuacionx(t + h/2, x + (h*K2)/2);
		K4 = Ecuacionx(t + h, x + h*K3);
				
		Xt = x + (h/6)*(K1 + 2*K2 + 2*K3 + K4);


		//Xt = Ecuacionx(t);

		Yt=0; K5=0; K6=0; K7=0; K8=0;

		K5 = Ecuaciony(t, y);
		K6 = Ecuaciony(t + h/2, y + (h*K5)/2);
		K7 = Ecuaciony(t + h/2, y + (h*K6)/2);
		K8 = Ecuaciony(t + h, y + h*K8);

		Yt = y + (h/6)*(K5 + 2*K6 + 2*K7 + K8);
		
		file_plot<<Xt<<"  "<<Yt<<endl;
		t+=h;
		x=Xt;
		y=Yt;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"solucion.txt\"\n"); 

	}

private:

	long double K1, K2, K3, K4, K5, K6, K7, K8;
	long double Xt, Yt;
	long double tf,to, f, h, t, x, xo, yo, Vo, g, y, teta; 
	int n;

}; //fin clase

int main(){

	RungeKutta runge;
	runge.Runge();

	return 0;
}
