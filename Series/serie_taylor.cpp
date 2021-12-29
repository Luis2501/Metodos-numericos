#include<bits/stdc++.h>

using namespace std;	

int main(){

		long long int i,j,a=3, n, b=2, c=1, fact=1;
        	long double coseno, xo;
       	 	long double x=-50, dx=0.001;

        	cout<<"\n                       <<<<Series de Taylor>>>>                \n\n";
        	cout<<"Este programa desarrolla la serie de Taylor de la función Cos(x) \n";
        	cout<<"en torno a x=0, mejor conocida como Serie de Maclaurin.";
		cout<<"\n\nIngrese el grado del polinomio de Taylor: ";
                cin>>n;
		cout<<"\nIngrese el valor Xo que desee evaluar: ";
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

		cout<<"\nCos("<<xo<<")"<<" = "<<coseno<<endl;

		ofstream file_plot;
		file_plot.open("grafica3.dat");

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
                
                
