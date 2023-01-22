#include <iostream>
#include <conio.h>
using namespace std;
template<typename T>
 void  minmax( const T& num_a, const T& num_b ){
    if (num_a<num_b)//true if num_a less than num_b
   cout<<"El valo más alto es"<<num_b<<endl;
    else    
   cout<<"El valo más alto es"<<num_a<<endl;
 }; 