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
    
    cout << "rows : " << b << " columns : " << a << endl;
    
    bool arr [a];
   // double rowhalfd=b/2.0;
    int rowhalf=b/2;
    int pasthalfr=0;
    int colhalf=a/2;
    int x=colhalf;

    for (int i=0; i< a; i++){
        arr[i]=false;
    }
    if (a+4>b){ // checking if the mat is long and not wide - ths will be true if there are at least 4 columns mor than the rows
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
            //  cout << "pasthalfr: "<< pasthalfr << "  j: "<< j<<  endl;
            if(j<rowhalf){
                if(j%2==0){
                    for (int k= j+1; k<a-j-1;k++)
                        arr[k]=true;
                }
                else{
                    for (int k= j+1; k<a-j-1;k++)
                        arr[k]=false; 
                }
            }
            else{
                pasthalfr++;
                if(j<b-2){
                    if(j%2==0){
                        for (int k=j-pasthalfr;k<a-j+pasthalfr;k++)
                            arr[k]=true;       
                    }
                    else{   
                        for (int k= j-pasthalfr; k<a-j+pasthalfr;k++)
                            arr[k]=false;
                        }
                }
                else{
                    if(j%2==0){
                        for (int k=j-pasthalfr-2;k<a-j+pasthalfr+1;k++)
                            arr[k]=true;       
                    }
                    else{   
                        for (int k= j-pasthalfr-2; k<a-j+pasthalfr+1;k++)
                            arr[k]=false;
                    }
                }
            }
        }  
    }
    else{
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
            //  cout << "pasthalfr: "<< pasthalfr << "  j: "<< j<<  endl;
            if (j<colhalf || j>= b-colhalf-1){ // if not in this range we dont need to chane what is printed
                if(j<rowhalf){
                    if(j%2==0){
                        for (int k= j+1; k<a-j-1;k++)
                            arr[k]=true;
                    }
                    else{
                        for (int k= j+1; k<a-j-1;k++)
                            arr[k]=false; 
                    }
                }
                else{
                    for (int y=x; y< a-x;y++){
                        if(arr[y]==true){
                           arr[y]=false; 
                        }
                        else{
                            arr[y]=true;
                        }
                    }
                    x--;
                    //pasthalfr++;
                    // if(j<b-2){
                    //     if(j%2==0){
                    //         for (int k=j-pasthalfr;k<a-j+pasthalfr;k++)
                    //             arr[k]=true;       
                    //     }
                    //     else{   
                    //         for (int k= j-pasthalfr; k<a-j+pasthalfr;k++)
                    //             arr[k]=false;
                    //         }
                    // }
                    // else{
                    //     if(j%2==0){
                    //         for (int k=j-pasthalfr-2;k<a-j+pasthalfr+1;k++)
                    //             arr[k]=true;       
                    //     }
                    //     else{   
                    //         for (int k= j-pasthalfr-2; k<a-j+pasthalfr+2;k++)
                    //             arr[k]=false;
                    //     }
                    // }
                }
            }  
        }
    }
}

/*
for long and thin try following the middle of both width and hight;
*/


int main(){

    mat(9,7,'%','-'); // works
    cout << "\n"<< endl;
    mat(3,3,'+','-'); //  works
    cout << " \n"<< endl;
    mat(1,1,'^','-'); //works
    cout << " \n"<< endl;
    mat(1,3,'&','*'); // works
    cout << " \n"<< endl;
    mat(3,1,'$','+'); // works
    cout << "\n "<< endl; 
    mat(7,3,'/','-'); // not working
    cout << "\n "<< endl;
    mat(5,9,'@','*'); 
    cout << " \n"<< endl;
    mat(5,11,'@','*'); 
    cout << " \n"<< endl;
    mat(7,21,'@','*'); 
    cout << " \n"<< endl;
    mat(11,5,'@','*'); 

    return 0;
}