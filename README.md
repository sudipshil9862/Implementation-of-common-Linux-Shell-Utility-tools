(language:- c++)

cp command implementation
----------------------------
in linux command-line:-
one time compile:- g++ -o cpimp cp.cpp
alias cpMine = "./cpimp"
**execution command will become:-  cpMine f1.txt f2.txt

**procedure:-
1. in main function taking the count of arguments and arguments in character array
2. for error handling:- if argument_count > 3 that means some wrong entry by the user
3. read the file1 in argv[1]
4. write in file2 in arhv[2]
5. iterate through the file1 and get the character one by one
6. writing all the character one by one to the file2
7. file content coppied successfully

wc implementation
-------------------
In linux command-line:- one time compile:- g++ wc.cpp 
commands:-
1. COMMAND-  ./a.out file_name  (will print the lineCount, wordCount, charactercount, fileName)
2. COMMAND-  ./a.out -l file_name (will print the lineCount with fileName)
3. COMMAND-  ./a.out -w file_name (will print the wordCount with fileName)
4. COMMAND-  ./a.out -c file_name (will print the charCount with fileName)

**procedure:-

1. I made it in general:- wc -l. wc -r, wc - c anything can be possible (depending upon the arguments that are given)
2. error handling :- if the argument_count is 1 that means error (need to include the argument)
3. error handling :- if the argument_count > 3 that means unnecessary arguments
4. if argument is 2:- then will print all the lineCount, wordCount, charactercount, fileName
5. if argument is 3 then continue
6. if the 2nd argument i "-l" then we iterate the file line by line and will print lineCount
7. if the 2nd argument is "-w" then we iterate the file word by word and count
8. if the 2nd argument is "-c" then we iterate the file character by character(here I used ascii value concept) and count


ls implementation
-------------------
In linux command-line:- one time compile:- g++ ls.cpp COMMAND- ./a.out (print all the folders and files in directory COMMAND- ./a.out -l (will print all file/folders with details-> type, size, creation time, modified time) COMMAND- ./a.out dir_name (will print all file/folders in a path) COMMAND- ./a.out -l dir_name (will print all file/folders in a path with details-> type, size, creation time, modified time)

**procedure:-

check how many arguments are there
if arg count = 1 then it will print all files/folder in same location
if arg count = 2 then (if 2nd arg= "-l" then it will print all files/folder with details in same location and if 2nd arg= any path then will print files/folder in that path)
if arg count = 3 then will print all file/folders in a path with details
this ls command is only supported by above commands.

printing approach:

iterate through directory
checking whether its file or folder using stat structure in sys\stat.h library
To print the file permission:- checking for user(r,w,x),Group(r,w,x),Other(r,w,x) and pushing back to string vector
calculating the size, file creation time, file modified time
closing the directory
(This ls command in c++ will work for directories)

cat implementation
-------------------
in linux command-line:-
one time compile:- g++ -o catimp cat.cpp
alias catMine = "./catimp"
**execution command will become:-  catMine

**procedure:-
1. if command line argument is not 2 then pass error
2. if arg_count is 2 then read file by the argument 1
3. we will go through line by line and print them in the command line
4. closing the file
