#include<math.h>
#include<iostream>
#include<vector>
#include"Gauss.h"
using namespace std;
void R(int *dim,float sist[][102]){
    int A,B;
    printf("Introduce el numero de incognitas:(menor que 100)\n");
    printf("\t\t\t");
    scanf("%d",&*dim);
    printf("\n\n INTRODUZCA CADA COMPONENTE DEL SISTEMA (A|Vector Solucion):");
    printf("\n\n MATRIZ A:\n");
    for(A=1;A<=*dim;A++) for(B=1;B<=*dim;B++){
        printf("\n Termino (%d,%d):",A,B); scanf("%f",&sist[A][B]);}
    printf("\nVECTOR SOLUCION:\n");
    for(A=1;A<=*dim;A++){
        printf("\n Termino 2 (%d):",A);scanf("%f",&sist[A][*dim+1]);
    }
}

void E(int dim, float sist[][102]){
    int A,B;
    for(A=1;A<=dim;A++){
        for(B=1;B<=(dim+1);B++){
            printf("%7.2f",sist[A][B]);
            if(B==dim) printf("   |");}
        printf("\n");
    }
}

void RG(int dim, float sist[][102])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;

    for(Col=1;Col<=dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
           if((abs(sist[A][Col])>0.0000001)){
                NoCero=1;}
            else A++;}
        Pivote=sist[A][Col];
        for(C1=1;C1<=(dim+1);C1++){
            V1=sist[A][C1];
            sist[A][C1]=sist[Col][C1];
            sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=dim;C2++){
            V1=sist[C2][Col];
            for(C1=Col;C1<=(dim+1);C1++){
                sist[C2][C1]=sist[C2][C1]-V1*sist[Col][C1];}
    }}

    for(Col=dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        sist[C1][dim+1]=sist[C1][dim+1]-sist[C1][Col]*sist[Col][dim+1];
        sist[C1][Col]=0;
    }
}
