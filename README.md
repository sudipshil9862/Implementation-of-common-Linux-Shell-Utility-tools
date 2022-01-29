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
in linux command-line:-
one time compile:- g++ -o wcimp wc.cpp
alias wcMine = "./wcimp"
**execution command will become:-  wcMine

**procedure:-
1. I made it in general:- wc -l. wc -r, wc - c anything can be possible
2. error handling :- if the argument_count is 1 that means error printing
3. error handling :- if the argument_count > 3 that means unnecessary arguments
4. if argument is 3 then continue
5. if the 2nd argument i "-l" then we iterate the file line by line and count
6. if the 2nd argument is "-w" then we iterate the file word by word and count
7. if the 2nd argument is "-c" then we iterate the file character by character(here I used ascii value concept) and count

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
