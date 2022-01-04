//Universidad Autonoma de Coahuila
//Facultad de Ciencias Fisico Matematicas
//Luis Eduardo Sánchez González

#include<bits/stdc++.h>
#include"Normal.h"

using namespace std;

	double DistribucionNormal::Funcion(double z){

		F = 0;		

		F =  (exp(-(pow(z,2))/(2)))/(sqrt(2*pi));
	
		return F;

	}

	double DistribucionNormal::Integral(double h){

		I = 0;

		I = ((3*h)*(Funcion(zo) + 3*Funcion(z1) + 3*Funcion(z2) + Funcion(z3)))/8 - Error(z2);

		return I;

	}

	double DistribucionNormal::Error(double epsilon){

		E = (3*pow(h3,5)/80)*(Funcion(epsilon))*(6*(pow(epsilon,2)) - (pow(epsilon,4)) - 3);

		return E;

	}

	void DistribucionNormal::grafica(double ti, double tf){

		t=-5;
		dt =0.05;

		ofstream file_plot;
		ofstream file_plot_gif;
		file_plot.open("grafica.dat");
		file_plot_gif.open("grafica_gif.dat");
	
		int i;
		i = 1;

		while(t<5){

			f=0;
			if(t>=ti && t<=tf){
			f = Funcion(t);
			}else{
				f=0;
			}
			g = Funcion(t);
		
		file_plot<<i<<"\t"<<t<<"\t"<<f<<"\t"<<g<<"\n";
		file_plot_gif<<i<<"\t"<<t<<"\t"<<f<<"\t"<<g<<"\n \n \n";
		t+=dt;
		i++;
		}

		file_plot.close();
		file_plot_gif.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"grafica.txt\"\n"); 
		fprintf(vent, "load \"grafica.gp\"\n"); 	

	}


	void DistribucionNormal::Distribucion(){

		cout<<"\nDigite el intervalo de tiempo [xo,x1] en el cual quiere calcular la probabilidad. \n\n";
		cout<<"---------------------------------------------------------------------------------------\n";
		cout<<"| Opciones:                                                                           | \n";
		cout<<"| * Si desea calcular la probabilidad de una variable aleatoria 'X' tal que P(X = x), | \n";
		cout<<"| entonces digite '0' para xo y x1.                                                   | \n";
		cout<<"| * Si desea calcular la probabilidad de una variable aleatoria 'X' tal que P(X < x), | \n";
		cout<<"| entonces digite '1000' para xo y para x1 digite el dato correspondiente.            | \n";
		cout<<"| * Si desea calcular la probabilidad de una variable aleatoria 'X' tal que P(X > x), | \n";
		cout<<"| entonces digite '1000' para x1 y para xo digite el dato correspondiente.            | \n";
		cout<<"---------------------------------------------------------------------------------------\n\n";
		cout<<"xo: ";
		cin>>xo;
		cout<<"x1: ";
		cin>>x1;
		
		pi=3.1416;

		if(xo == 0 && x1==0){
		
			cout<<"\nDigite el valor x en el cual quiere calcular la probabilidad. \n";
			cout<<"x: ";
			cin>>x;

			cout<<"\nDigite la media y la desviación estandar de la distribución. \n";
			cout<<"μ: ";
			cin>>nu;
			cout<<"σ: ";
			cin>>sigma;

			zi = (x - nu)/sigma;

			P = Funcion(zi);

			cout<<endl<<"La probabilidad en P(x = "<<x<<") = "<<P<<endl;

		}else{

			cout<<"\nINFO: Si desea realizar una aproximación de la distribución binomial a la distribución\n";
			cout<<"normal, digite '0' para la media y la desviación estandar \n";
			cout<<"\nDigite la media y la desviación estandar de la distribución. \n";		
			cout<<"μ: ";
			cin>>nu;
			cout<<"σ: ";
			cin>>sigma;

			if(nu == 0 && sigma==0){

				cout<<"\nADVERTENCIA: Debe tomar en cuenta que para hacer una aproximación lo bastante\n";
				cout<<"buena, se necesita que 'n' sea lo \"suficientemente\" grande. \n";
				cout<<"\nDigite las condiciones para la distribución binomial. \n";
				cout<<"n = ";
				cin>>n;
				cout<<"p = ";
				cin>>p;

				if(xo ==1000 || x1 ==1000){

					if(xo==1000){

						x1 = x1 - 0.5;

					}else{

						xo = xo - 0.5;						
			
					}

				}else{

				xo = xo - 0.5;
				x1 = x1 + 0.5;
				
				}//fin if else condion infinito

				q = 1 -p;
				nu = n*p;
				sigma = sqrt(n*p*q);

				zo = (xo - nu)/(sigma);
				z3 = (x1 - nu)/(sigma);

			}else{ 

				zo = (xo - nu)/sigma;
				z3 = (x1 - nu)/sigma;

			}//fin if-else condicion de la aproximacion binomial por medio de la normal

			if(xo==1000 || xo==999.5){

				zo = -4;

			}

			if(x1==1000 || x1 == 1000.5){

				z3 = 4;
			}

			cout<<"\nConforme a los datos que ingresaste, obtenemos que: \n";

			cout<<endl<<"zo = "<<zo<<"\t  \t z1 = "<<z3<<endl<<endl;

			h3 = (z3-zo)/3;

			z1 = zo + h3;
		
			z2 = z1 + h3;

			P = Integral(h3);
	
			if(x1==1000 || xo==1000 || x1==1000.5 || xo==999.5){
		 
				if(x1==1000 || x1 ==1000.5){

					cout<<"La probabilidad en el intervalo ["<<xo<<",∞] es: \n\n";

					cout<<"P(x > "<<xo<<") = "<<P<<endl;

					grafica(zo,z3);

				}else{

					cout<<"La probabilidad en el intervalo [-∞,"<<x1<<"] es: \n\n";

					cout<<"P(x < "<<x1<<") = "<<P<<endl;

					grafica(zo,z3);

				}
			}else{

				cout<<"La probabilidad en el intervalo ["<<xo<<","<<x1<<"] es: \n\n";

				cout<<"P("<<xo<<" < x < "<<x1<<") = "<<P<<endl;

				grafica(zo,z3);
		
			}//fin if-else para mostrar resultados

			cout<<"\nNOTA: Recuerde que este programa realiza aproximaciones mediante un método númerico,\n";
			cout<<"por esa razón es que los resultados obtenidos no son totalmente exactos a los que podemos  \n";
			cout<<"encontrar en algunos libros o tablas de valores para la distribución normal.\n";			

		}//fin if-else tomar la probabilidad acumulada

	}
