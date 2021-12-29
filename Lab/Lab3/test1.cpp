#include <iostream>
#include "RuntimeException.h"


using namespace std;

void test1() {
    try {
        throw RuntimeException("Replace this error message");
        cout << "failed to throw in test1" << endl;
    }
    catch (RuntimeException& exception) {
        cout << "passed. " << exception.getMessage() << endl;
    }
}


void test2(){
    for(int i=1;i<=10;i++){
        if(i == 4){
            try{
                throw RuntimeException("Replace this error message");
            }
            catch(RuntimeException& exception){
                cout << "passed at i=4 " << exception.getMessage() << endl;
            }  
        }
    }
    cout << "failed to throw in test2" << endl; 
}

void test3(){
    for(int i=1;i<=10;i++){
        if(i == 4){
            try{
                throw LaboratoryException("Replace this error message");
            }
            catch(LaboratoryException& exception){
                cout << "passed at i=4 " << exception.getMessage() << endl;
            }  
        }
    }
    cout << "failed to throw in test2" << endl; 
}


void test4(){
    try{
        Laboratory test;
        test.execute();
        
        cout<<"fail"<<endl;
    }
    catch(LaboratoryException& exception){
        cout<<"nice job"<<endl;
    }
}



int main(){
    test1(); 
    test2();
    test3();
    test4();
    return 0;
}