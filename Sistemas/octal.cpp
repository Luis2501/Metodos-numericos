#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long int exp,digito;
    long int  octal, decimal;

   cout << "Introduce numero: ";
   cin >> decimal;
   exp=0;
   octal=0;

   while(((int)(decimal/8))!=0){
           digito = (int)decimal%8;
           octal = octal + digito * pow(10.0,exp);
           exp++;
           decimal=(int)(decimal/8);
   }

   octal = octal + decimal * pow(10.0,exp);

   cout << endl << "Octal: " << octal<< endl;


        return 0;
}


