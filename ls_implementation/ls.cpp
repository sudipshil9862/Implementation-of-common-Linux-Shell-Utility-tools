#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<dirent.h>
using namespace std;


int main(int argc,char* argv[]){
    if(argc != 3){
        cout<<"error"<<endl;
    }
    else if(argc == 3){
        struct stat st1;
        struct stat st2;
        stat(argv[1], &st1);
        stat(argv[2], &st2);

        //if both are file
        if((st1.st_mode & S_IFREG) && (st2.st_mode & S_IFREG)){
            ifstream myfile1(argv[1]);
            ofstream myfile2(argv[2]);
            chmod(argv[2], st1.st_mode); // copy file permission
            string line;
            while (getline(myfile1,line))
            {
                myfile2 << line;
            }
            
        }

        //if 1st one is file and 2nd one is folder (file create and copy to folder)
        else if((st1.st_mode & S_IFREG) && (st2.st_mode & S_IFDIR)){
            ifstream myfile1(argv[1]);
            string path = "";
            for(int i=string(argv[1]).length(); i>0 ; i--){
              if(string(argv[1])[i] != '/'){
                path = string(argv[1])[i] + path;
              }
              else{
                break;
              }
            }
            ofstream myfile2(string(argv[2]) + string(path));
            chmod(argv[2], st1.st_mode); // copy file permission
            string line;
            while (getline(myfile1,line))
            {
                myfile2 << line;
            }
        }


        // if folder to folder
        else if ((st1.st_mode & S_IFDIR) && (st2.st_mode & S_IFDIR)){
            
            // mkdir((string(argv[2]) + string(argv[1])));
            // char* dirname = argv[2];
            string dirname = string(argv[2]) + string(argv[1]);
            mkdir(dirname.c_str(),0777);


            struct stat st1;
            struct stat st2;
            stat(argv[1], &st1);
            stat(argv[2], &st2);
            chmod(argv[2], st1.st_mode); //copy folder permission to another

            struct stat dst;
            struct dirent *d;
            DIR *dir;
            dir = opendir(argv[1]);
            for(d = readdir(dir); d != NULL ; d = readdir(dir)){
                string type = d->d_name;
                type = string(argv[1]) + type;
                if(stat(type.c_str(), &dst) == 0){
                    if(dst.st_mode & S_IFDIR){
                        //type = "DIRECTORY: ";
                        struct stat st5;
                        stat(((string(argv[1]) + type).c_str()), &st5);
                        mkdir((string(argv[2]) + string(argv[1]) + type).c_str(),0777);
                        chmod(((string(argv[2]) + string(argv[1]) + type).c_str()), st5.st_mode);
                        // copyDir(type3, (type2 + type3).c_str());

                    }
                    else if (dst.st_mode & S_IFREG){
                        //type = "FILE     :";
                        ifstream myfile1(type);
                        string path2 = "";
                        for(int i=string(type).length(); i>0 ; i--){
                            if(string(type)[i] != '/'){
                                path2 = string(type)[i] + path2;
                            }
                            else{
                                break;
                            }
                        }
                        ofstream myfile2(string(argv[2]) + string(argv[1]) + string(path2));
                        chmod((string(argv[2]) + string(argv[1]) + path2).c_str(), dst.st_mode); // copy file permission
                        string line;
                        while (getline(myfile1,line))
                        {
                            myfile2 << line;
                        }

                    }
                }
            }


        }


        //if 1st one is folder and 2nd one is file error
        else if ((st1.st_mode & S_IFDIR) && (st2.st_mode & S_IFREG)){
            cout<<"error: 1st one is file and 2nd one is folder"<<endl;
        }
    }

}

