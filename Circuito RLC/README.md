# Resolución a un circuito RLC 

El programa consta de 13 archivos, cada archivo consta de un archivo con extensión .cpp y otro con extensión .h, excepto el archivo Circuito.cpp que contiene la función principal, podemos hacer un diagrama en forma de arbol para saber como se maneja el programa.


			       	 <<<<<<<<<Arbol de funcionamiento del programa>>>>>>>>>

				 --------------------Circuitos-----------------------
                                 |                                                  |
		    ----------Verlet----------			    -----------Runge Kutta----------
		    |                        |                      |                              |
		Grafica 		Solucion A 		GraficaRK4  			Solucion A


Es decir los archivos que utiliza el programa son:

Circuito (.cpp)  --------------------------------------------------> Función principal
VerlocityVerlet (.cpp, .h) ----------------------------------------> Ejecuta el método de Verlet
RungeKutta (.cpp, .h) ---------------------------------------------> Ejecuta el método de RK4
GeneraGrafica (.cpp, .h) ------------------------------------------> Realiza los datos de la gráfica para Verlet
SolucionVV (.cpp, .h) ---------------------------------------------> Realiza la solución analítica para el archivo Verlet 
GeneraGraficaRK4 (.cpp, .h) ---------------------------------------> Realiza los datos de la gráfica para RK4
SolucionRK4 (.cpp, .h) --------------------------------------------> Realiza la solución analítica para el archivo RK4 

El plotter que se utiliza para graficar es gnuplot, por lo cual debe verificar si lo tiene instalado, de lo contrario para poder instalarlo digite lo siguiente en la terminal:

``` 
sudo apt-get install gnuplot
```

Guia de uso:

Para poder ejecutar el programa de forma correcta debe digitar en la terminal lo siguiente:

```
c++ -o Circuito Circuito.cpp && ./Circuito
```

Es decir debe ejecutar el archivo "Circuito.cpp". 
		

