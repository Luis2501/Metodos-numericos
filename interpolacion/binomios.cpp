#include<bits/stdc++.h>

using namespace std;

int main(){

	double A[10], B[10], Polinomio[10];
	int n;

	cout<<"Digite el grado de los polinomios: ";
	cin>>n;

	for(int i=n; i>=0;i--){
		cout<<"X^"<<i<<": ";
		cin>>A[i];
		cout<<endl;
	}
	
	for(int i=n; i>=0;i--){
		cout<<"X^"<<i<<": ";
		cin>>B[i];
		cout<<endl;
	}
	
	
	for(int i=n;i>=0;i--){
		for(int j=n; j>=0; j--){
			Polinomio[j+1] = A[i]*B[j];
		}
	}


	for(int i=n+1; i>=0; i--){
		cout<<Polinomio[i]<<"X^"<<i<<" + ";
	}


	return 0;
}
