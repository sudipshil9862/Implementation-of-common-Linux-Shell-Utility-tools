#include<iostream>
#include<sys\stat.h>
#include<dirent.h>
#include<conio.h>
using namespace std;

int main(int argc, const char *argv){
    if(argc == 1){
        cout<<"printing list of the dic";
        struct dirent *d; //iterator to iterate in dic
        struct stat dst; //struct finds is it a file or folder
        DIR *dr; //object of DIR
        string path = ".\\"; //path of where I am

        dr = opendir(path.c_str()); //open directory in dir variable
        if(dr !=NULL){
            for(d = readdir(dr); d != NULL ; d = readdir(dr)){ //it returns the pointer of next directory entry
                string type = d->d_name;   //store is it file or folder
                type = path + type; //type means the complete path
                if(stat(type.c_str(), &dst) == 0){
                    if(dst.st_mode & S_IFDIR){
                        type = "is a FOLDER";
                    }
                    else if (dst.st_mode & S_IFREG){
                        type = "is a FILE";
                    }
                }
                cout<<d->d_name<<" "<<type<<endl;
            }
            closedir(dr);
        }
        else{
            cout<<"dic null"<<endl;
        }
    }
    // if the argc > 1 that means it can be ls -a or ls -p so that will have specific work 
    return 0;
}