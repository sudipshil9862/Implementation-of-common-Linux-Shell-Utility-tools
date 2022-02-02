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
In linux command-line:- one time compile:- g++ wc.cpp commands:-

COMMAND- ./a.out file_name (will print the lineCount, wordCount, charactercount, fileName)
COMMAND- ./a.out -l file_name (will print the lineCount with fileName)
COMMAND- ./a.out -w file_name (will print the wordCount with fileName)
COMMAND- ./a.out -c file_name (will print the charCount with fileName)
**procedure:-

I made it in general:- wc -l. wc -r, wc - c anything can be possible (depending upon the arguments that are given)
error handling :- if the argument_count is 1 that means error (need to include the argument)
error handling :- if the argument_count > 3 that means unnecessary arguments
if argument is 2:- then will print all the lineCount, wordCount, charactercount, fileName
if argument is 3 then continue
if the 2nd argument i "-l" then we iterate the file line by line and will print lineCount
if the 2nd argument is "-w" then we iterate the file word by word and count
if the 2nd argument is "-c" then we iterate the file character by character(here I used ascii value concept) and count


ls implementation
-------------------
in linux command-line:-
one time compile:- g++ -o lsimp ls.cpp
alias lsMine = "./lsimp"
**execution command will become:-  lsMine

**procedure:-
1. importing diret.h and sys\stat.h library
2. making a pointer of a in built structure dirent to iterate in dic
3. making stat structure to find the whether it is file or folder
4. making object of DIR to open the directory
5. taking the path as a string where I am located now
6. opening directory
7. error handling:- if directory is not opened then printing an error
8. iterate through directory
9. storing the file or folder's name and concatinate with the cuurent path
10. check whether it is a file ot folder by the stat function(just for advance version)
11. printing all the file or folder's name one by one along with type(file/foler)
12. close the directory

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
