#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){

		string binario;
		int n, i=0, exp=0;
		double suma = 0;

	cout<<"\nIntroduce un numero en sistema binario: ";
	cin>>binario;

	n = binario.size();

	for(int k=0;k<n;k++){
		if(binario[k] != '.'){
			exp++;
		}
		else
		k=n;
		}

	while(i<n){
		if(binario[i] != '.'){
			suma += (binario[i]-'0')*pow(2.0, exp-1);
			exp--;
		}
	i++;
	}

	cout<<"\nEl numero en sistema decimal es: "<<suma<<endl;

	return 0;
}
