class Metodos_raices{

	public:

	int menuMetodos(int opcion);
	int pedirGrado(int n);
	void pedirPolinomio(int n);
	double Evaluacion(int g, double x, double poli[]);
	void Biseccion(int n);
	void Posicion(int n);

	private:

	int tol, max;//Tolerancia y numero de iteraciones
	double f; //Evaluacion del polinomio 
	double fxo, fxf; //Evaluacion en los puntos 
	double xo, xf; //Puntos del metodo
	double xr; //Error dado por usuario
	double er, ea; //Evaluacion de error relativo y absoluto
	double pm, fp;//Punto medio en el metodo biseccion y evaluacion del punto medio
	double coef[100];
	double c, fc;//Punto y evaluacion en el metodo de posicion falsa

};//fin de la clase Metodos_raices

/*	Estructura

	1.- Biseccion 
	2.- Posicion falsa
	3.- Newton-Rhapson
	4.- Secante
	5.- Horner
	6.- Müller
	7.- Gauss-Jordan	*/
