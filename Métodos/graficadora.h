class Grafica{

	public:

		void datosGrafica(int n, double Polinomio[]);
		void GraficaG(int gradoPolinomio, double coeficientes[]);
		void Documento();
		double Evaluacion(int grado, double xi, double coef_Polinomio[]);

	private:

		double f, x, dx; //datos para graficación
		double x1, x2, fx1; 
		double fx;
		int abrirPdf;

};//fin clase graficadora
