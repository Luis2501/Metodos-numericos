#include<bits/stdc++.h>

using namespace std;

int main(){

	double a,c, raiz; 

	complex<double> b,dis;

	cout<<"a:";
	cin>>a;

	cout<<"\nb:";
	cin>>b;
	
	cout<<"\nc:";
	cin>>c;

	c = complex<double>(-b, sqrt((pow(b,2)-4*a*c)));

	cout<<c<<endl;



	return 0;
}
