#include<bits/stdc++.h>

using namespace std;

int main(){

        long long int i,j,a=3, n, b=2, c=1, fact=1, opc;
        long double seno, coseno, exp;
        long double x=-50, dx=0.001, xo;

        cout<<"\n                       <<<<Series de Taylor>>>>                \n\n";
        cout<<"Este programa desarrolla la serie de Taylor de algunas funciones \n";
        cout<<"notables en torno a x=0, mejor conocida como Serie de Maclaurin.";
	cout<<"\n\nLas Series de Maclaurin tienen la forma:";
	cout<<"\n\n\tΣ f^n(x)*(x)^n";
	cout<<"\n\t        n!    ";
	cout<<"\n\nSeleccione la funcion con la que desea trabajar.";
	cout<<"\n\n1. Función Sen(x).\n";
	cout<<"2. Función Cos(x).\n";
	cout<<"3. Función e^x.";
	cout<<"\n\nOpcion: ";
	cin>>opc;

//-----------------------------------------------------------------------------------------------------------------------

if(opc==1){

        	cout<<"\nIngrese el grado del polinomio de Taylor: ";
        	cin>>n;
        	cout<<"\nIngrese el valor Xo que desee evaluar en el polinomio: ";
        	cin>>xo;

        	seno=xo;
		a=3;

        	for(i=1; i<=n ; i++){
                	fact=1;
               		for (j=1 ; j<=a ; j++){
                        	fact=fact*j;
                	}
                		if (i%2==0){
                        		seno=seno + ((pow(xo,a))/fact);
                		} else {
                        		seno=seno - ((pow(xo,a))/fact); 
                		}
                	a=a+2;
        	}
        	cout<<"\nSen("<<xo<<")"<<" = "<<setprecision(11)<<seno<<endl;

		ofstream file_plot;
		file_plot.open("seno.dat");

		n=n-3;

		while(x<=50){
	
		seno=x;
		a=3;

        	for(i=1; i<=n ; i++){
                	fact=1;
               		for (j=1 ; j<=a ; j++){
                        	fact=fact*j;
                	}
                		if (i%2==0){
                        		seno=seno + (pow(x,a))/fact;
                		} else {
                        		seno=seno - pow(x,a)/fact; 
                		}
                	a=a+2;
        	}
			//cout<<x<<" "<<exp<<endl;
			file_plot<<x<<" "<<seno<<endl;
			x+=dx;
		}

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"seno.txt\"\n");

		return 0;

}

//-------------------------------------------------------------------------------------------------------------------------

if(opc==2){

		cout<<"\nIngrese el grado del polinomio de Taylor: ";
                cin>>n;
		cout<<"\nIngrese el valor Xo que desee evaluar en el polinomio: ";
                cin>>xo;

		coseno=1;

		for(i=1; i<=n ; i++){
                        fact=1;
                        for (j=1 ; j<=b ; j++){
        	                fact=fact*j;
                        }
        	                if (i%2==0){
                	                coseno = coseno + (pow(xo,b))/fact;
                        	} else {
                                	coseno = coseno - pow(xo,b)/fact; 
                        	}
                        b=b+2;
                }

		cout<<"\nCos("<<xo<<")"<<" = "<<setprecision(11)<<coseno<<endl;

		ofstream file_plot;
		file_plot.open("grafica3.dat");

		if(n<=4){
		n=n-2;
		}else{
		n=n;
		}

		while(x<=50){
	
		coseno=1;
		b=2;

		for(i=1; i<=n ; i++){
                        fact=1;
                        for (j=1 ; j<=b ; j++){
        	                fact=fact*j;
                        }
        	                if (i%2==0){
                	                coseno = coseno + (pow(x,b))/fact;
                        	} else {
                                	coseno = coseno - pow(x,b)/fact; 
                        	}
                        b=b+2;
                }

			//cout<<x<<" "<<exp<<endl;
			file_plot<<x<<" "<<coseno<<endl;
			x+=dx;
		}

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"serietaylor.txt\"\n");

	return 0;

}

//----------------------------------------------------------------------------------------------------------------------------

if(opc==3){

		cout<<"\nIngrese el grado del polinomio de Taylor: ";
                cin>>n;
                cout<<"\nIngrese el valor Xo que desee evaluar en el polinomio: ";
                cin>>xo;

		exp=1;

                for(i=1; i<=n ; i++){
                        fact=1;
                	for (j=1 ; j<=c; j++){
                        	fact=fact*j;
                        }
                 	exp+=pow(xo,c)/(fact);
			c++;
                }
                cout<<"\ne^("<<xo<<")"<<" = "<<setprecision(11)<<exp<<endl;

		ofstream file_plot;
		file_plot.open("exp.dat");

		while(x<=50){
	
		exp=1;
		c=1;

                for(i=1; i<=n ; i++){
                        fact=1;
                	for (j=1 ; j<=c; j++){
                        	fact=fact*j;
                        }
                 	exp+=pow(x,c)/(fact);
			c++;
                }

			//cout<<x<<" "<<exp<<endl;
			file_plot<<x<<" "<<exp<<endl;
			x+=dx;
		}

		file_plot.close();

		FILE * vent = popen("gnuplot -persist","w");
		fprintf(vent, "load \"exp.txt\"\n");

	return 0;

}

//----------------------------------------------------------------------------------------------------------------------------

if(opc!=1 || opc!=2 || opc!=3){

		cout<<"\n¡ERROR! El numero que selecciono no se encuentra en el menú."<<endl;
	}

        return 0;
}
