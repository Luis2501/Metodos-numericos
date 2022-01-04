#include<bits/stdc++.h>
#include"RungeKutta.h"
#include"GenerarGraficaRK4.cpp"
#include"SolucionRK4.cpp"

using namespace std;

	GraficadoraRK4 GraficaRK4;
	SolucionRK4 Solucion;

	double RungeKutta::EcuacionDife(int ecu, double y, double dy){

		if(ecu==1){

			F1 = 0;

			F1 = -((R*dy)/(L)) - ((y)/(L*C)); //Ecuación diferencial circuito en serie 

			return F1;
		
		}else{

			F2 = 0;

			F2 = -((dy)/(R*C)) - ((y)/(L*C)); //Ecuación diferencial circuito en paralelo

			return F2;

		}

	}

	void RungeKutta::CompararParametros(double Alfa, double Omega){

		if(Omega < Alfa){

			c=1;
		
			cout<<"\nLa respuesta del circuito es un caso sobreamortiguado. \n";

		}else{

			if(Alfa < Omega){
		
				c=2;	
	
				cout<<"\nLa respuesta del circuito es un caso subamortiguado. \n";
	
			}else{

				c=3;

				cout<<"\nLa respuesta del circuito es un caso críticamente amortiguado. \n";

			}
		}
	}

	void RungeKutta::Runge(int opcion){

		cout<<"\nDigite los parámetros del circuito RLC: \n";
		cout<<"R = ";
		cin>>R;
		cout<<"L = ";
		cin>>L;
		cout<<"C = ";
		cin>>C;

		if(opcion == 1){

			alpha = ((R)/(2*L));
			omega = ((1)/(sqrt(L*C)));
	
		}else{

			alpha = ((1)/(2*R*C));
			omega = ((1)/(sqrt(L*C)));

		}

		
		cout<<"\nNOTA: Recuerde que en algunos casos si no se digita el tamaño de paso\n";
		cout<<"adecuado, la solución no será tan precisa como se espera. \n\n";
		cout<<"Digite el tamaño de paso adecuado: \n";
		cout<<"h = ";
		cin>>h;

		CompararParametros(alpha, omega);

		x=0;

		cout<<"\nDigite las condiciones iniciales, es decir: \n";
	
		if(opcion==1){

			cout<<"\nI(ti) = Ic \t \t I'(ti) = Vl/L \n\n";

		}else{		

			cout<<"\nV(ti) = Vl \t \t V'(ti) = Ic/C \n\n";
		
		}
	
		cout<<"ti = ";
		cin>>xi;
		cout<<"tf = ";
		cin>>xf;
		cout<<"Io = ";
		cin>>Io;
		cout<<"Vo = ";
		cin>>Vo;

		if(opcion == 1){

			yo=Io;

			dyo = -((Io*R + Vo)/(L));
		
			GraficaRK4.datosGrafica(opcion, xi, xf, yo);

			Solucion.Analitica(c, alpha, omega, yo, dyo, xi, xf, h);

		}else{

			yo = Vo;

			dyo = -((((Vo)/(R)) + Io)/(C));

			GraficaRK4.datosGrafica(opcion, xi, xf, yo);	

			Solucion.Analitica(c, alpha, omega, yo, dyo, xi, xf, h);		

		}

		ofstream file_plot;
		file_plot.open("solucion.dat");

		file_plot<<x<<"\t"<<yo<<endl;

		int i;
		i=1;

		while(x<=xf){

			K1=0, K2=0, K3=0, K4=0;
			L1=0, L2=0, L3=0, L4=0;
			yf=0;

//Adaptación para encontrar voltajes y corrientes------------------------------------------------------------------------------------

			if(opcion==1){

				P1 = (R)*(yo);			//Voltaje en la resistencia
				P2 = (L)*(dyo);			//Voltaje en el inductor
				P3 = -(P1 + P2);		//Voltaje en el capacitor

			}else{

				P1 = ((yo)/(R));		//Corriente en la resistencia
				P2 = (C)*(dyo);			//Corriente en el capacitor
				P3 = -(P1 + P2);		//Corriente en el inductor

			}

//-----------------------------------------------------------------------------------------------------------------------------------

			K1 = h*dyo;
			L1 = h*(EcuacionDife(opcion, yo, dyo));
			K2 = h*(dyo + (1/2)*(L1));
			L2 = h*(EcuacionDife(opcion, yo + (1/2)*(K1), dyo + (1/2)*(L1)));
			K3 = h*(dyo + (1/2)*(L2));
			L3 = h*(EcuacionDife(opcion, yo + (1/2)*(K2), dyo + (1/2)*(L2)));
			K4 = h*(dyo + L3);
			L4 = h*(EcuacionDife(opcion, yo + K3, dyo + (1/2)*(L3)));

			yf = yo + (K1 + 2*K2 + 2*K3 + K4)/(6);
			dyf = dyo + (L1 + 2*L2 + 2*L3 + L4)/(6);

			file_plot<<x<<"\t"<<yf<<"\t"<<P1<<"\t"<<P2<<"\t"<<P3<<endl;

			yo = yf;
			dyo = dyf;
			x+=h;
			i++;
		}	

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"solucion.txt\"\n");
		

	}
