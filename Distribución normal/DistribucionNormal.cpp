//Universidad Autonoma de Coahuila
//Facultad de Ciencias Fisico Matematicas
//Luis Eduardo Sánchez González

#include<bits/stdc++.h>
#include"Normal.cpp"

using namespace std;

int main(){

	DistribucionNormal Normal;

	system("clear");

	int opc, opc1;

	cout<<"\n\t\t<<<<Probabilidad por medio de la distribución normal>>>>";

	cout<<"\n\nEste programa determina la probabilidad de un suceso en base a la distribución normal,";
	cout<<"\ntodo esto se realiza mediante un método númerico. Además de eso también este programa \n";
	cout<<"puede determinar una aproximación a la distribución binomial por medio de la normal\n";

	Normal.Distribucion();

	cout<<"\nPara obtener más información sobre la distribución normal y sobre este programa presione 1,";
	cout<<"\nde lo contrario presione cualquier otra tecla: ";
	cin>>opc;

	if(opc==1){

		system("evince Distribución_normal.pdf");	

	}

	cout<<"\nEl programa genera automaticamente un GIF interactivo para mostrar el área bajo la\n";
	cout<<"curva. Si desea observar el GIF presione 1, de lo contrario cualquier otro número: ";
	cin>>opc1;

	if(opc1==1){	
	
		system("gnome-open DistribucionNormal.gif");
		
		cout<<"\nEspere un momento, esta operación puede demorar algunos segundos...\n";
				
	}

	return 0;
}
