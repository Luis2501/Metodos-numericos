#include<bits/stdc++.h>

using namespace std;


int main(){


	ofstream file_plot;
	file_plot.open("grafica.dat");

	double dx=0.001;
	double x=1;
	double f, g;

	while(x<=2){

	if(x<=1.5){
		f=0;
		f = (-22.2156)*pow(x,3) + (37.3056)*pow(x,2) + (17.92)*pow(x,1) - 28.1222 ;
		cout<<x<<" "<<f<<endl;
		file_plot<<x<<" "<<f<<endl;

	}

	if(x>1.5 && x<=2){
		g=0;
		g = (22.2156)*pow(x,3) + (-37.3056)*pow(x,2) + (58.6822)*pow(x,1) - 191.976;
		cout<<x<<" "<<g<<endl;
		file_plot<<x<<" "<<g<<endl;

		
	}
		x+=dx;

	}

	file_plot.close();

	FILE * vent = popen("gnuplot -persist","w");
	fprintf(vent, "load \"grafica.dat\"\n"); 

	return 0;

}
