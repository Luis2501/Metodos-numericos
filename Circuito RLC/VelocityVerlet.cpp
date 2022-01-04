//Ana Cecilia Cortes Vargas 
//Luis Eduardo Sánchez González
//Edgar Orlando Rodríguez Figueroa

#include<bits/stdc++.h>
#include"VelocityVerlet.h"
#include"GenerarGrafica.cpp"
#include"SolucionVV.cpp"

using namespace std;

	Graficadora Grafica;
	SolucionAnalitica SolucionVV;

	double VelocityVerlet::EcuacionDif(int ecu, double y, double dy){

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

	void VelocityVerlet::CompararParametros(double Alfa, double Omega){

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

	void VelocityVerlet::Verlet(int opcion){

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
		cout<<"adecuado, la solución no será tan precisa como se espera.\n\n";
		cout<<"Digite el tamaño de paso adecuado: \n";
		cout<<"dt = ";
		cin>>dx;

		CompararParametros(alpha, omega);

		x=0;

		cout<<"\nDigite las condiciones iniciales, es decir: \n";
	
		if(opcion==1){

			cout<<"\n I(ti) = Il \t \t I'(ti) = Vl/L \n\n";

		}else{		

			cout<<"\n V(ti) = Vc \t \t V'(ti) = Ic/C \n\n";
		
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
		
			Grafica.datosGrafica(opcion, xi, xf, yo);

			SolucionVV.Analitica(c, alpha, omega, yo, dyo, xi, xf, dx);

		}else{

			yo = Vo;

			dyo = -((((Vo)/(R)) + Io)/(C));

			Grafica.datosGrafica(opcion, xi, xf, yo);

			SolucionVV.Analitica(c, alpha, omega, yo, dyo, xi, xf, dx);			

		}

		ofstream file_plot;
		file_plot.open("solucion.dat");

		file_plot<<x<<"\t"<<yo<<endl;

		int i;
		i=1;

		while(x<=xf){

			yf=0, dy1=0, dyf=0;

			yf = yo + dyo*dx + (1/2)*(EcuacionDif(opcion, yo, dyo))*(pow(dx,2));

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

			file_plot<<x<<"\t"<<yf<<"\t"<<P1<<"\t"<<P2<<"\t"<<P3<<endl;

			dy1 = dyo + (EcuacionDif(opcion, yo, dyo))*dx;

			dyf = dyo + dx*(EcuacionDif(opcion, yo, dyo) + EcuacionDif(opcion, yf, dy1))/(2);

			yo=0, dyo=0;

			yo = yf;
			dyo = dyf;
			x+=dx;
			i++;
		}	

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"solucion.txt\"\n"); 
		

	}
