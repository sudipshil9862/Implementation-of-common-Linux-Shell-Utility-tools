wc implementation
in linux command-line:- one time compile:- g++ wc.cpp 
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
