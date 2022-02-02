#include<iostream>
#include<sys\stat.h>
#include<dirent.h>
#include <ctime>
#include<vector>
using namespace std;



void print(string path, string args){
    struct dirent *d; //iterator to iterate through out the directory
    struct stat dst; //structure of getting file details->type,size,file creation time,file modified time. it also has 
    DIR *dir;
    vector<string> arr; //created to find read-write permission
    

    dir = opendir(path.c_str());
    if(dir !=NULL){
        for(d = readdir(dir); d != NULL ; d = readdir(dir)){ //it returns the pointer of next directory entry
            string type = d->d_name;
            type = path + type;
            if(stat(type.c_str(), &dst) == 0){
                
                if(dst.st_mode & S_IFDIR){
                    type = "DIRECTORY: ";
                }
                else if (dst.st_mode & S_IFREG){
                    type = "FILE     :";
                }
                
            }

                mode_t modeSt = dst.st_mode;
                cout<<modeSt<<endl;
                arr.push_back((modeSt & S_IRUSR) ? "r" : "-");
                arr.push_back((modeSt & S_IWUSR) ? "w" : "-");
                arr.push_back((modeSt & S_IXUSR) ? "x" : "-");
                arr.push_back("-");
                arr.push_back((modeSt & S_IRGRP) ? "r" : "-");
                arr.push_back((modeSt & S_IWGRP) ? "w" : "-");
                arr.push_back((modeSt & S_IXGRP) ? "x" : "-");
                arr.push_back("-");
                arr.push_back((modeSt & S_IROTH) ? "r" : "-");
                arr.push_back((modeSt & S_IWOTH) ? "w" : "-");
                arr.push_back((modeSt & S_IXOTH) ? "x" : "-");

                string temp = "";
                for (auto it = arr.begin(); it != arr.end(); ++it)
                    temp = temp + *it;
            
            if(args == "a" || args == "no"){
                cout<<d->d_name<<endl;
            }else if(args == "l"){
                cout<<type<<" "<<temp<<" "<<"size: "<<dst.st_size<<"\t"<<"createTime: "<<std::ctime(&dst.st_ctime)<<"\t"<<"modifiedTime: "<<std::ctime(&dst.st_mtime)<<"\t"<<"name: "<<d->d_name<<endl;
            }
            arr.clear();
        }
        closedir(dir);
    }
    else{
        cout<<"directory not opening"<<endl;
    }
}

int main(int argc, const char *argv[]){
    string j="";
    if(argc == 1){
        j=".\\";
        print(j,"no");
    }
    else if(argc==2){
        print(j + argv[1],"a");
    }
    else if(argc == 3){
        if((j + argv[1]) == "-l"){
            print(j + argv[2],"l");
        }
    }
    return 0;
}
