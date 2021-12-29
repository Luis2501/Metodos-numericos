#include<iostream>
#include<math.h>

using namespace std;


int main(){

	int fact = 1, n, c=1;
	double x=-10, exp, total;


	cout<<"\n			<<<<Series de Taylor>>>>		\n\n";
	cout<<"Este programa desarrolla la serie de Taylor de la funcion Cos(x)\n";
	cout<<"en torno a x=0, serie de Maclaurin";

	cout<<"\nIngrese el grado del polinomio de Taylor: ";
        cin>>n;
                
               
while(x<=10){

                for(int i=1; i<=n ; i++){
                        fact=1;
                	for (int j=1 ; j<=c; j++){
                        	fact=fact*j;
                        }
                 	exp = pow(x,c)/(fact);
			c++;
                x+=0.01;
		cout<<x<<" "<<exp<<endl;
	}
    
}
	return 0;
}
