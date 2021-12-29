#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long int exp,digito;
    long int  octal, decimal;

   cout << "Introduce numero: ";
   cin >> octal;
   exp=0;
   decimal=0;

   while(((int)(octal/10))!=0){
           digito = (int)octal%10;
           decimal = decimal + digito * pow(8.0,exp);
           exp++;
           octal =(int)(octal/10);
   }

   decimal = decimal + octal * pow(8.0,exp);

   cout << endl << "decimal: " << decimal<< endl;


        return 0;
}
