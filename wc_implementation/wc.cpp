#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int lineFun(string a){
    int count=0;
    ifstream myfile(a);
        string line;
            while (getline(myfile,line))
            {
                count++;
            }
            //fclose(myfile);
    return count;          
}

int wordFun(string a){
    int count = 0;
    ifstream myfile(a);
    string word;
            while (myfile >> word)
            {
                count++;
            }
    return count;
}

int charFun(string a){
    int count = 0;
    ifstream myfile(a);
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
    return count;
}


int main(int argc,char *argv[]){
    int lineCount = 0, wordCount = 0, charCount = 0;
    if(argc == 1){
        cout<<"invalid may be not included the file name"<<endl;
        return 0;
    }
    else if(argc > 3){
        cout<<"too many parameters"<<endl;
        return 0;
    }
    else if(argc == 2){
        string j = "";
        cout<<lineFun(j + argv[1])<<" "<<wordFun(j + argv[1])<<" "<<charFun(j + argv[1])<<" "<<(j + argv[1])<<endl;
    }
    else if(argc == 3){
        string j;

        // ifstream myfile(argv[2]);
        // string line;
        // if(strcmp(argv[1],"-l")==0){
        //     while (getline(myfile,line))
        //     {
        //         lineCount++;
        //     }
            
        // }
        if(strcmp(argv[1],"-l")==0){
            cout<<lineFun(j + argv[2])<<" "<<(j + argv[2])<<endl;
            
        }
        
        
        else if(strcmp(argv[1],"-w")==0){
            // string word;
            // while (myfile >> word)
            // {
            //     lineCount++;
            // }
            cout<<wordFun(j + argv[2])<<" "<<(j + argv[2])<<endl;
            
        }
        
        
        else if(strcmp(argv[1],"-c")==0){
            // char c;
            // int i;
            // while (!myfile.eof())
            // {
            //     myfile.get(c);
            //     i = c;
            //     if((i>63 && i<91) || (i>96 && i<123)){
            //         lineCount++;
            //     }
            // }
            cout<<charFun(j + argv[2])<<" "<<(j + argv[2])<<endl;
            
        }
    }

return 0;

}
