#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main(int argc,char *argv[]){
    int count = 0;
    if(argc == 1){
        cout<<"invalid may be not included the file name"<<endl;
    }
    else if(argc > 3){
        cout<<"too many parameters"<<endl;
    }
    else if(argc == 3){
        ifstream myfile(argv[2]);
        string line;
        if(strcmp(argv[1],"-l")==0){
            while (getline(myfile,line))
            {
                count++;
            }
            
        }
        else if(strcmp(argv[1],"-w")==0){
            string word;
            while (myfile >> word)
            {
                count++;
            }
            
        }
        else if(strcmp(argv[1],"-c")==0){
            char c;
            int i;
            while (!myfile.eof())
            {
                myfile.get(c);
                i = c;
                if((i>63 && i<91) || (i>96 && i<123)){
                    count++;
                }
            }
            
        }
    }
    cout<<"count="<<count<<endl;

}