In linux command-line:- one time compile:- g++ ls.cpp
COMMAND- ./a.out (print all the folders and files in directory
COMMAND- ./a.out -l  (will print all file/folders with details-> type, size, creation time, modified time)
COMMAND- ./a.out dir_name (will print all file/folders in a path)
COMMAND- ./a.out -l dir_name (will print all file/folders in a path with details-> type, size, creation time, modified time)

**procedure:-

1. check how many arguments are there
2. if arg count = 1 then it will print all files/folder in same location
3. if arg count = 2 then  (if 2nd arg= "-l" then it will print all files/folder with details in same location
       and if 2nd arg= any path then will print files/folder in that path)
4. if arg count = 3 then will print all file/folders in a path with details

this ls command is only supported by above commands.

printing approach:
1. iterate through directory
2. checking whether its file or folder using stat structure in sys\stat.h library
3. To print the file permission:- checking for user(r,w,x),Group(r,w,x),Other(r,w,x) and pushing back to string vector
4. calculating the size, file creation time, file modified time
5. closing the directory

(This ls command in c++ will work for directories)
