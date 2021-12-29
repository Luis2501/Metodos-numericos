#include<bits/stdc++.h>
 
using namespace std;
 
#include <iomanip>
 
void monomio2(int n, double *x, double *D);
 
int main () {
     
    cout << "Polinomio de interpolacion de Lagrange\n\n";
 
    ifstream label1 ("pato1.txt");
     
    int n, i, j, k;
 
    label1 >> n;
 
    double *x, *xp, *f, *L, *D, producto, sum, *P;
 
    x = new double [n], xp = new double [n], f = new double [n];
    L = new double [n], D = new double [n+1], P = new double [n];
 
    cout << "Numero de pares ordenados = " << n << "\n\n";
 
    cout << "Valores de x y f(x)\nx   f(x)\n";
 
    for (i= 0; i < n; i++){
 
        label1 >> x[i] >> f[i];
        cout << x[i] << setw(5) << setiosflags(ios::right) << f[i] << "\n";
 
    }
 
    cout << endl;
 
    for (k = 0; k < n; k++){
 
    producto = 1;
 
        for (i = 0; i < n; i++){
 
            if (i != k) producto = producto * (x[k] - x[i]);
 
        }
     
    L[k] = f[k]/producto;
 
    }
 
    cout << "Coeficientes de interpolacion de Lagrange\n\n";
 
    cout.setf(ios::fixed);
 
    cout.precision(1);
 
 
    for (i= 0; i < n; i++){
 
        cout << "L(" << n-i-1 << ") = " << setw(4) << setiosflags(ios::right) << L[i] << endl;
 
    }
 
    cout << endl;
 
    for (k = 0; k < n; k++){
     
        j = 0;  
         
        for (i = 0; i < n; i++){
 
            if (i != k) {xp[j] = x[i]; j += 1;}
 
        }
     
        monomio2(n-1, xp, D);
 
        for (i= 0; i < n; i++){
 
            P[i] = P[i] + L[k]*D[i];
 
        }
      
    }
 
    cout << "Polinomio de interpolacion de Lagrange (grado " << n-1 << ")\n\n";
 
    for (i= 0; i < n; i++){
 
        cout << "P(" << n-i-1 << ") = " << setw(4) << setiosflags(ios::right) << P[i] << endl;
             
    }

double fX = 0,xo=-50,dx=0.001;

		ofstream file_plot;
	file_plot.open("grafica6.dat");

	while(xo<=50){

		fX=0;

		for(int i=n;i>=0;i--){
			fX += P[i]*pow(xo,i);
		}
		//cout<<x<<" "<<f<<endl;
		file_plot<<xo<<" "<<fX<<endl;
		xo+=dx;
	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"polinomio2.txt\"\n"); 
 
    return 0;
 
}
 
void monomio2(int n, double *x, double *D){
 
    double *E;
 
    E = new double [n];
 
    D[0] = 1;
 
    D[1] = -x[0];
 
    for (int i = 1; i < n; i++) {
 
        for (int k =1; k < i+1; k++) {
 
            E[k] = D[k] + D[k-1]*(-x[i]);
 
        }
 
        D[i+1] = D[i]*(-x[i]);
 
        for (int j = 1; j < i+1; j++) {
 
            D[j] = E[j];
 
        }
 
    }
 
    delete E;
 
}
