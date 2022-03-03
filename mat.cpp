#include <iostream>
#include <stdexcept>
using namespace std;


void mat(int a, int b, char c, char d){
    if(a==0 || b==0){
        throw "error 1";
    }
    if(a<0 || b<0){
        throw "error 2";
    }
    if (a%2==0 || b%2==0){
        throw "error 3";
    }
    if (c=d){
        throw "error 4";
    } 
}
