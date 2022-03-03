#include <iostream>
#include <stdexcept>
using namespace std;


void mat(int a, int b, char c, char d ){
    if(a==0 || b==0){
        throw "error 1";
    }
    if(a<0 || b<0){
        throw "error 2";
    }
    if (a%2==0 || b%2==0){
        throw "error 3";
    }
    if (c==d){
        throw "error 4";
    } 

    bool arr [a];
    double rowhalfd=b/2.0;
    int rowhalf=b/2;
    int pasthalf=0;

    for (int i=0; i< a; i++){
        arr[i]=false;
    }
    for (int j=0;j<b; j++){ // rows
        for (int i=0; i< a; i++){ // columns
        if(arr[i]==false){
            cout << c;
        }
        else{
            cout << d;
        }
        }
        cout << endl;
      //  cout << "pasthalf: "<< pasthalf << "  j: "<< j<<  endl;
        if(j<rowhalf){
            if(j%2==0){
                for (int k= j+1; k<a-j-1;k++){
                    arr[k]=true;
                }
            }
            else{
                for (int k= j+1; k<a-j-1;k++){
                    arr[k]=false;
                } 
            }
        }
        else{
            pasthalf++;
            if(j<b-2){
                if(j%2==0){
                    for (int k=j-pasthalf;k<a-j+pasthalf;k++)
                        arr[k]=true;       
                }
                else{   
                    for (int k= j-pasthalf; k<a-j+pasthalf;k++)
                        arr[k]=false;
                    }
            }
            else{
                if(j%2==0){
                    for (int k=j-pasthalf-2;k<a-j+pasthalf+1;k++)
                        arr[k]=true;       
                }
                else{   
                    for (int k= j-pasthalf-2; k<a-j+pasthalf+1;k++)
                        arr[k]=false;
                    }
            }
        }
    }  
}

/*
for long and thin try following the middle of both width and hight;


*/
int main(){
    // mat(9,7,'%','-'); // works
    // cout << "\n"<< endl;
    // mat(3,3,'%','-'); //  works
    // cout << " \n"<< endl;
    // mat(1,1,'%','-'); //works
    // cout << " \n"<< endl;
    // mat(1,3,'%','-'); // works
    // cout << " \n"<< endl;
    // mat(3,1,'%','-'); // works
    // cout << "\n "<< endl; 
    // mat(7,3,'%','-'); // not working
    // cout << "\n "<< endl;
    mat(5,13,'%','-'); // not working

    return 0;
}