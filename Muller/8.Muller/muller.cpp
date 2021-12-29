//MÉTODO DE MULLER

#include<bits/stdc++.h>
using namespace std;

class Muller {

public: 

   long double Evaluacion(int g, long double Coeficientes[], long double x) {

       f = 0;
       for(int i = 0; i <= grado; i++) {

          f+=(pow(x,grado-i))*(Coeficientes[i]);
       }

       return f;
   }

   void Grafica(int g, long double Coeficientes[], long double x) {

      ofstream file_plot;
      file_plot.open("muller.dat");

      for(double i=x-10; i <= x+10; i+=0.001) {

         f = Evaluacion(g, Coeficientes, i);
         file_plot<<i<<" "<<f<<endl;
      }

      file_plot.close(); 
      FILE * vent = popen("gnuplot -persist","w"); 
      fprintf(vent, "load \"muller.txt\" \n"); 
   }


   void Grados() {

      cout<<"PROGRAMA DEL MÉTODO DE MULLER"<<endl;
      cout<<"Sea un polinomio de la forma Ax^n + Bx + C"<<endl<<endl;
      cout<<"Ingrese el grado de su polinomio: "<<endl;
      cin>>grado;
      long double Coeficientes[grado+1];
      cout<<"Ingrese los coeficientes para su polinomio: "<<endl;

      for(int i = 0; i <= grado; i++) {

	 cout<<"x^"<<grado-i<<" = ";
	 cin>>Coeficientes[i];
      }

      cout<<"Ingrese tres puntos: "<<endl;
      cout<<"x0 = ";
      cin>>x0;
      cout<<"x1 = ";
      cin>>x1;
      cout<<"x2 = ";
      cin>>x2;
      cout<<"Ingrese su error permitido: "<<endl;
      cin>>error;

      Grafica(grado, Coeficientes, x0);

      fX0 = Evaluacion(grado, Coeficientes, x0);
      fX1 = Evaluacion(grado, Coeficientes, x1);
      fX2 = Evaluacion(grado, Coeficientes, x2);

      //CONDICIÓN POR SI EL INTERVALO ES RAÍZ {

      if (fX0 == 0 || fX1 == 0 || fX2 == 0) {

      if(fX0 == 0) {
         x3 = x0;
	 cout<<endl<<"La raíz se encuentra en = "<<setprecision(10)<<x3<<endl;
      }

      if(fX1 == 0) {
	 x3 = x1;
	 cout<<endl<<"La raíz se encuentra en = "<<setprecision(10)<<x3<<endl;
      }

      if(fX2 == 0) {
	 x3 = x2;
	 cout<<endl<<"La raíz se encuentra en = "<<setprecision(10)<<x3<<endl;
      }

      }

      //}

      cout<<setw(10)<<"x2"<<setw(20)<<"f(x2)"<<setw(25)<<"Error Relativo"<<setw(25)<<"Error Absoluto"<<setw(20)<<endl;

      for(int i = 0; i <= 1000; i++) { 

         fX0 = Evaluacion(grado, Coeficientes, x0);
         fX1 = Evaluacion(grado, Coeficientes, x1);
         fX2 = Evaluacion(grado, Coeficientes, x2);

	 c = fX2;
	 h1 = x1-x2;
	 h2 = x0-x2;
	 e0 = fX0-c;
	 e1 = fX1-c;
	 w = ((h1*(h2*h2))-((h1*h1)*h2));
	 a = ((e0*h1)-(e1*h2))/w;
	 b = (((e1)*(h2*h2))-((e0)*(h1*h1)))/w;

	 x3 = x2-((2*c)/(b+sqrt((b*b)-4*a*c)));

	 if(((b*b)-4*a*c) < 0) {

	    i = 1000;
            cout<<"La raíz es compleja"<<endl;

	 }
            
	 eRel= (abs(X3-x3)/X3)*100;
	 eAbs= abs(X3-x3)/abs(X3+x3);

	 fX3 = Evaluacion(grado, Coeficientes, x3);

         if(i<=15) {

            cout<<setw(10)<<x2<<setw(20)<<fX2<<setw(20);

	    if(i>=1)
	       cout<<eRel<<setw(25)<<eAbs<<setw(20);

	    else

	       cout<<setw(20)<<"0"<<setw(20)<<"0"<<setw(20);

	    cout<<endl;
         }

         if(fX3 == 0) {
            i = 1000;
	    cout<<endl<<"La raíz se encuentra en = "<<setprecision(10)<<x3<<endl;
         }



         if(abs(error-eRel) <= error) {
            i = 1000;
	    cout<<endl<<"La raíz se encuentra en = "<<setprecision(10)<<x3<<endl;
         }


	 x2 = x3;
	 X3 = x3;

      }//fin for


   }//fin Grados


private:

    int grado;
    long double x0;
    long double x1;
    long double x2;
    long double x3;
    long double f=0;
    long double fX0, fX1, fX2,fX3;
    long double a, b, c, w, h1, h2, e0, e1;
    long double X3; //Viejo
    long double eRel=0;
    long double eAbs=0;
    long double error;

}; //fin class

int main () {

   Muller muller;
   muller.Grados();

return 0;

}//fin main
