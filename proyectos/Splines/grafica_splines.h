class GraficaSplines{

	public:

		void datosGrafica(int n, double Polinomio[]);
		void GraficaG(int gradoPolinomio, double coeficientes[]);
		double Evaluacion(int grado, double xi, double coef_Polinomio[]);

	private:

		double f, x, dx; //datos para graficación
		double x1, x2; 
		double fx;

};//fin clase graficadora
