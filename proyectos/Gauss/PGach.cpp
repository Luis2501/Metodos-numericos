#include<math.h>
#include<iostream>
#include<vector>
#include <fstream>
#include "Gauss1.cpp"
using namespace std;
int main(){
    system("clear");
    int dim;
    float sis[101][102];
    R(&dim,sis);
    printf("\n");
    RG(dim,sis);
    printf("\nLas soluciones son:\n");
    for(int C=1;C<=dim;C++) printf("\n X%d = %f\n",C,sis[C][dim+1]);
    scanf("");
    return(0);
}
