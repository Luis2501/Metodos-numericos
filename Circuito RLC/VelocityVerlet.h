class VelocityVerlet{

	public:

		double EcuacionDif(int ecu, double y, double dy);	//Función paa evaluar en la ecuación diferencial
		void CompararParametros(double Alfa, double Omega);	//Compara los parámetros para saber el tipo de respuesta
		void Verlet(int opcion);				//Método de Velocity Verlet
	
	private:

		double x, y, dy; 					//Variables en la ecuación diferencial
		double R, L, C; 					//Paraemtros del circuito
		double yo, dyo, yf, dy1, dyf,  dx; 			//Variables del método de Velocity Verlet
		double Io, Vo, xf, xi, F1, F2; 				//Condiciones inciales
		double alpha, omega, Alfa, Omega;			//Paraemtros que definen el tipo de respuesta
		double P1, P2, P3; 					//Parámetros secundarios
		int opcion, ecu, c; 					//Opcion para escoger la ecuación diferecial

};
