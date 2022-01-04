class RungeKutta{

	public:

		double EcuacionDife(int ecu, double y, double dy);	//Función paa evaluar en la ecuación diferencial
		void CompararParametros(double Alfa, double Omega);	//Compara los parámetros para saber el tipo de respuesta
		void Runge(int opcion);					//Método de Runge Kutta 

	private:

		double x, y, dy; 					//Variables en la ecuación diferencial
		double R, L, C; 					//Paraemtros del circuito
		double yo, dyo, yf, dyf, h;	 			//Variables del método de Runge Kutta
		double K1,K2, K3, K4, L1, L2, L3, L4; 			//Variables del método de Runge Kutta
		double Io, Vo, xf, xi, F1, F2; 				//Condiciones inciales
		double alpha, omega, Alfa, Omega;			//Parametros que definen el tipo de respuesta
		double P1, P2, P3; 					//Parámetros secundarios
		int opcion, ecu, c; 					//Opcion para escoger la ecuación diferecial
};
