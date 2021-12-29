#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){

		string octal;
		int n, i=0, exp=0, m=0;
		double suma = 0;
		string numero;

	cout<<"\nIntroduce un numero en sistema octal: ";
	cin>>octal;

	n = octal.size();

	for(int k=0;k<n;k++){
		if(octal[k] != '.' && octal[k] != '-'){
			exp++;
		}
		if(octal[k]== '.'){
		k=n+1;
		}
	}

	while(i<n){
		if(octal[i] != '.' && octal[i] != '-'){
			suma += (octal[i]-'0')*pow(8.0, exp-1);
			exp--;
		}
	i++;
	}


	if(octal[0] == '-'){
	cout<<"El numero en sistema decimal es: "<<"-"<<suma<<endl;
	}else
	cout<<"El numero en sistema decimal es: "<<suma<<endl;
	

	return 0;

}
