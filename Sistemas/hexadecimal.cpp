#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long int exp,digito;
    long int hexadecimal, decimal;

   cout << "Introduce numero: ";
   cin >> decimal;
   exp=0;
   hexadecimal=0;


   while(((int)(decimal/16))!=0){
           digito = (int)decimal%16;
           hexadecimal = hexadecimal + digito * pow(10.0,exp);
           exp++;
           decimal=(int)(decimal/16);
   }

   hexadecimal = hexadecimal + decimal * pow(10.0,exp);

	            if(hexadecimal<16){
                switch(hexadecimal){
                        case 10: cout<<"A"; break;
                        case 11: cout<<"B"; break;
                        case 12: cout<<"C"; break;
                        case 13: cout<<"D"; break;
                        case 14: cout<<"E"; break;
                        case 15: cout<<"F"; break;
                }
        }

else{
   cout << endl << "Hexadecimal: " << hexadecimal<< endl;
}

        return 0;
}
