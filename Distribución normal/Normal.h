//Universidad Autonoma de Coahuila
//Facultad de Ciencias Fisico Matematicas
//Luis Eduardo Sánchez González

class DistribucionNormal{

	public:

		double Funcion(double z);			 //Evaluar en la función de densidad
		double Integral(double h);			 //Resolver la integral
		double Error(double epsilon);			 //Obtener el error de la integral
		void grafica(double ti, double tf);		 //Generar la gráfica
		void Distribucion();

	private:

		double nu, sigma, pi;				 //Parametros de la distribución 
		double t, ti, tf, f, dt, g;			 //Parametros de gráficación
		double F;					 //Evaluación en la función de densidad 
		double I,zo,z1,z2,z3,h3;			 //Parametros método de simpson
		double zi, x; 					 //Condición 
		double xo,x1, P; 				 //Condiciones del problema
		double E, epsilon; 				 //Error en el método de Simpson 
		double p, q, n; 				 //Parametros de la distribución binomial
		int opc;
};
