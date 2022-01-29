#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc,char *argv[]){
    if(argc!=2){
        cout<<"error";
    }
    ifstream myfile(argv[1]);
    if(myfile.is_open()){
        string line;
        while (getline(myfile,line))
        {
            cout<<line<<endl;
        }
        myfile.close();
    }
    

    
}
