#include<bits/stdc++.h>
#include"SolucionVV.h"

using namespace std;

	double SolucionAnalitica::FuncionReal(int circuito, double x, double A){

		if(circuito==1){

			I1 = ((A1)*(exp(S1*x)) + (A2)*(exp(S2*x))); 

			return I1;

		}else{

			if(circuito==2){

				I2 = (exp((-A)*(x)))*((K1)*(cos(O*x)) + (K2)*(sin(O*x))); 

				return I2;
			}else{

				I3 = (C1)*(x)*(exp((-A)*(x))) + (C2)*(exp((-A)*(x)));

				return I3;

			}	
		}

	}

	void SolucionAnalitica::Analitica(int caso, double a, double w, double xi, double dxi, double ti, double tf, double dt){

	if(caso==1){

		S1 = -a + sqrt(pow(a,2) - pow(w,2));
		S2 = -a - sqrt(pow(a,2) - pow(w,2));
		
		A1 = (((xi)*(S2) - dxi)/((exp(S1*ti))*(S2 - S1)));

		A2 = ((dxi - (xi)*(S1))/((exp(S2*ti))*(S2 - S1)));
	
	}else{	

		if(caso==2){

			O = sqrt(abs(pow(a,2) - pow(w,2)));

			K2 = (((cos(O*ti))*(dxi + (xi)*(a)) + (xi*O)*(sin(O*ti)))/((exp(-a*ti))*(O)));
	
			K1 = ((xi - (K2)*(sin(O*ti))*(exp(-a*ti)))/((cos(O*ti))*(exp(-a*ti))));	

		}else{

			C1 = ((dxi - (a)*(xi))/(exp((-a)*(ti))));
			
			C2 = ((xi - (C1)*(ti)*(exp((-a)*(ti))))/(exp((-a)*(ti))));

		}

	}

		t=ti;
		
		ofstream file;
		file.open("solucionreal.dat");

		while(t<=tf){

			f = FuncionReal(caso, t, a);

			file<<t<<"\t"<<f<<endl;

			t+=dt;
		}	

		file.close();

	}
