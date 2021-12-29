#include<bits/stdc++.h>
#include"Funcion.h"

using namespace std;

	void generarFuncion::Funcion(){


	string funcion;

	cout<<"\n\nDigite la funcion a graficar: ";
	getline(cin, funcion);

	ofstream archivo;
	archivo.open("Funcion.cpp");

	archivo<<"#include<bits/stdc++.h> \n";
	archivo<<"#include \"Funcion.h\" \n\n";

	archivo<<"using namespace std; \n\n";

	archivo<<"#define pi 3.141592 \n\n";
	
	archivo<<"\tdouble generarFuncion::Evaluacion(double x){\n\n";
	archivo<<"\t\tfx=0;\n\n";
	archivo<<"\t\t\tfx = "<<funcion<<";\n\n";
	archivo<<"\t\treturn fx;\n\n";
	archivo<<"\t}";

	archivo<<"\n\n\tvoid generarFuncion::GraficaG(){\n\n";
	archivo<<"\tofstream file_plot;\n";
	archivo<<"\tfile_plot.open(\"funcion.dat\"); \n\n";
	archivo<<"\txi=-50; dx=0.001;\n\n";
	archivo<<"\twhile(xi<=50){\n\n";
	archivo<<"\t\tf=0;\n\n";
	archivo<<"\t\t\tf = generarFuncion::Evaluacion(xi);\n\n";
	archivo<<"\t\tfile_plot<<xi<<\" \"<<f<<endl;\n";
	archivo<<"\t\txi+=dx;\n\n";
	archivo<<"\t}\n\n";
	archivo<<"\tfile_plot.close();\n\n";
	archivo<<"\tFILE * vent = popen(\"gnuplot -persist\", \"w\");\n";
	archivo<<"\tfprintf(vent, \"load \\"<<"\""<<"funcion.txt"<<"\\"<<"\""<<"\\n \"); \n\n";
	archivo<<"\t}\n";

	archivo.close();

	}
	
