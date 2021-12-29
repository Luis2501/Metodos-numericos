#include<bits/stdc++.h>

using namespace std;

int main(){

	double x,y,dx,dy;
	double fx, fy;

	ofstream file_plot;
	file_plot.open("field_vector.dat");
	
	x=-10, y= -10,
	dx= 1, dy = 1;

	while(x<=10 && y<= 10){

		fx=0, fy=0;

		fx = pow(y,3) - 9*y;
		fy = pow(x,3)  - 9*x;

		file_plot<<x<<"\t"<<y<<"\t"<<fx<<"\t"<<fy<<endl;
		x+=dx;
		y+=dy;

	}


	file_plot.close();
	

	
	return 0;
}
