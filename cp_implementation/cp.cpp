#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char* argv[]){
    if(argc != 3){
        cout<<"error"<<endl;
    }
    ifstream myfile1(argv[1]);
    ofstream myfile2(argv[2]);
    char c;
    while(!myfile1.eof()){
        myfile1.get(c);
        myfile2<<c;
    }

}