#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc,char *argv[]){
    if(argc==1){
        cout<<"no parameter to display or concatinate";
    }
    if(argc == 2){
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
    if(argc == 3){
        ifstream myfile1(argv[1]);
        ifstream myfile2(argv[2]);
        if(myfile1.is_open() && myfile2.is_open()){
            string line1,line2;
            while (getline(myfile1,line1))
            {
                cout<<line1<<endl;
            }
            while (getline(myfile2,line2))
            {
                cout<<line2<<endl;
            }
            myfile1.close();
            myfile2.close();
            
        }
    }
    

    
}
