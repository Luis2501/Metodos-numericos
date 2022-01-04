class SolucionRK4{

	public:

		void Analitica(int caso, double a, double w, double xi, double dxi, double ti, double tf, double dt);
		double FuncionReal(int circuito, double x, double A);

	private:

		double a, w, S1, S2, O, A;				//Parametros de la ecuación caracteristica
		double A1, A2, K1, K2, C1, C2;				//Constantes de la solución
		double xi, dxi, ti, tf, dt, x, t;			//Condiciones inciales del problema
		double f, I1, I2, I3; 					//Evaluación en las funciones
		int caso, circuito;

};
