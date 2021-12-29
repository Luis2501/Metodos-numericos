#include<bits/stdc++.h>
#include"Funcion.cpp"

using namespace std;

#define pi 3.141592

	struct datos_metodos{

		int gradoPolinomio;
		int tolerancia;
		int maximo_iteraciones;
		double Polinomio[100];
		double puntos[3];
		double evaluaciones[3];
		double errores[3];
		string nombreArchivo;

	}metodo[1];


int main(){

	generarFuncion Funcion;

	metodo[1].tolerancia = 1;
	metodo[1].maximo_iteraciones = 1000;

	cout<<"\n				<<<<Metodo de Posición Falsa>>>>		\n";
	cout<<"\nEste programa desarrolla el metodo de posición falsa para aproximar las raices de polinomios de grado 'n'\n";
	cout<<"dado un intervalo incial [a,b], el cual debe cumplir ciertas condiciones.\n";

/*
	cout<<"\nIntroduce el grado del polinomio (Maximo grado 10): ";
	cin>>metodo[1].gradoPolinomio;
	cout<<"\nLos polinomios de grado 'n' tienen la forma: ";
	cout<<"\n\n\t\tA(n)*x^n + A(n-1)*x^(n-1) + ... + A(2)*x^2 + A(1)*x^1 + A(0)*x^0\n";

	cout<<"\nIntroduzca los coeficientes del polinomio f(x):\n\n";

	for(int j=metodo[1].gradoPolinomio;j>=0;j--){
		cout<<"A"<<"("<<j<<")*x^"<<j<<": ";
		cin>>metodo[1].Polinomio[j];
	}

	cout<<"\nEl polinomio que ingresaste es: \n\n";

        for(int j=metodo[1].gradoPolinomio;j>=1;j--){
                cout<<metodo[1].Polinomio[j]<<"*x^"<<j<<" + ";
		if(j==1){
		j=0;
		cout<<metodo[1].Polinomio[j];
		}
        }
*/


	cout<<"\n\nEl intervalo [a,b] tiene que cumplir que f(a) y f(b) tienen signos distintos.\n";
	cout<<"\nIntroduzca el intervalo [a,b]: ";
	cout<<"\n\na = ";
	cin>>metodo[1].puntos[1];

	//for(int i=metodo[1].gradoPolinomio;i>=0;i--){
		metodo[1].evaluaciones[1] = Funcion.Evaluacion(metodo[1].puntos[1]);//+= (metodo[1].Polinomio[i])*pow((metodo[1].puntos[1]),i);
	//}//evaluación f(a)

	cout<<"b = ";
	cin>>metodo[1].puntos[2];

	//for(int i=metodo[1].gradoPolinomio;i>=0;i--){
		metodo[1].evaluaciones[2] = Funcion.Evaluacion(metodo[1].puntos[2]);//+= (metodo[1].Polinomio[i])*pow((metodo[1].puntos[2]),i);
	//}//evaluación f(b)

	if(metodo[1].evaluaciones[1] ==0 || metodo[1].evaluaciones[2] ==0){
		cout<<"\nUno de los valores del intervalo es la raiz del polinomio.\n";
cout<<"\n\tf("<<metodo[1].puntos[1]<<") = "<<metodo[1].evaluaciones[1]<<"\t"<<"f("<<metodo[1].puntos[2]<<") = "<<metodo[1].evaluaciones[2]<<endl;

		if(metodo[1].evaluaciones[1]==0){
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<metodo[1].puntos[1]<<endl;
		}else{
		cout<<"\nPor lo tanto la raiz del polinomio es x= "<<metodo[1].puntos[2]<<endl;
		}
		
	}else{

		if(((metodo[1].evaluaciones[1])*(metodo[1].evaluaciones[2])) > 0){

			cout<<"\nEl intervalo que selecciono no es el adecuado para desarrollar el metodo.";
			cout<<"\n\t\tf(a) = "<<metodo[1].evaluaciones[1]<<"\t"<<"f(b) = "<<metodo[1].evaluaciones[2]<<endl;
			cout<<"\nNOTA: Es probable que la función no tenga raices reales.";
		}else{

		cout<<"\nIntroduzca el error permitido: ";
		cin>>metodo[1].errores[1];

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t				<<<<Tabla de valores.>>>>			\n\n";
cout<<endl<<"\tPunto x = a"<<"\tPunto x = b"<<"\tPunto x = c"<<"\tEvaluación f(c)."<<"\tError relativo."<<"\t\tError absoluto."<<endl;

		while(metodo[1].tolerancia <= metodo[1].maximo_iteraciones){

metodo[1].puntos[3] = metodo[1].puntos[2] - (metodo[1].evaluaciones[2]*(metodo[1].puntos[2]-metodo[1].puntos[1]))/(metodo[1].evaluaciones[2]-metodo[1].evaluaciones[1]);

		metodo[1].errores[2] = (abs(metodo[1].puntos[2]-metodo[1].puntos[1])) / abs(metodo[1].puntos[2]);

		metodo[1].errores[3] = (abs(metodo[1].puntos[2]-metodo[1].puntos[1]));


			if(metodo[1].errores[2]<metodo[1].errores[1]){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nPara un error permitido de Xr = "<<metodo[1].errores[1]<<" se obtuvo que";
				cout<<" la raiz del polinomio se encuentra en x = "<<setprecision(10)<<metodo[1].puntos[3]<<endl<<endl;

			break;

			}

			metodo[1].evaluaciones[3] =0;

				//for(int i=metodo[1].gradoPolinomio;i>=0;i--){
					metodo[1].evaluaciones[3] = Funcion.Evaluacion(metodo[1].puntos[3]);//+= (metodo[1].Polinomio[i])*pow(metodo[1].puntos[3],i);
				//} //evaluación f(c)

			if(metodo[1].evaluaciones[3]==0){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
				cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<metodo[1].puntos[3]<<endl<<endl;

			break;


			}


//Tabla de valores-------------------------------------------------------------------------------------------------------------------

			if(metodo[1].tolerancia<=10){

cout<<endl<<metodo[1].tolerancia<<setw(15)<<metodo[1].puntos[1]<<setw(15)<<metodo[1].puntos[2]<<setw(15)<<metodo[1].puntos[3]<<setw(20)<<metodo[1].evaluaciones[3]<<setw(20)<<metodo[1].errores[2]<<setw(20)<<metodo[1].errores[3]<<endl;

			}

//------------------------------------------------------------------------------------------------------------------------------------			

			if((metodo[1].evaluaciones[3])*(metodo[1].evaluaciones[1])<0){

				metodo[1].puntos[2] = metodo[1].puntos[3];
			}
			else{
			
				metodo[1].puntos[1] = metodo[1].puntos[3];
			}
						

			//for(int i=metodo[1].gradoPolinomio;i>=0;i--){
				metodo[1].evaluaciones[1]  = Funcion.Evaluacion(metodo[1].puntos[1]);//+= (metodo[1].Polinomio[i])*pow(metodo[1].puntos[1],i);
			//} 


			//for(int i=metodo[1].gradoPolinomio;i>=0;i--){
				metodo[1].evaluaciones[2] = Funcion.Evaluacion(metodo[1].puntos[2]);//+= (metodo[1].Polinomio[i])*pow(metodo[1].puntos[2],i);
			//}

			//cout<<endl<<fa<<" "<<fb<<endl;

			metodo[1].tolerancia++;

			if(metodo[1].tolerancia == metodo[1].maximo_iteraciones){

cout<<"\n\n-------------------------------------------------------------------------------------------------------------------";
			cout<<"\n\nPara el numero de iteraciones permitidas no se encontro una raiz.";				
			//cout<<"\n\nLa raiz del polinomio se encuentra en x = "<<setprecision(10)<<c<<endl<<endl<<endl;

				break;

			}

		}

		}//fin if-else fa*fb>0

	}//fin if-else fa=0

	Funcion.GraficaG();

	return 0;

}

