/*1
Write a program that copies itself and adds line numbers to each line. You can (for now, to simplify your task, of course) assume constant file names.

First, open the file in read mode, then open the copy file in write mode. After that, line by line, get the lines from the source file, append the number of the line to the destination file, and append the line content.

Remember to close both files.

Note: in a real program, it's important to check whether all the needed files exist and that you can create a copy. In our program, you should at least check that both files have been successfully opened.

If one of the fopen functions fails, then print the message: Error opening a file. and end the program.

Expected output
Copy of source file with line numbers.
*/

/*2
Write a program that counts the metrics of a file:

Number of all characters
Number of whitespaces
Number of lines
Number of all lower-case letters
You can (for now, to simplify your task, of course) assume constant file names. To speed up your programming, you can test your program on its source code. First, open a file in read mode. After that, character by character, read the file and count the numbers asked. Remember to close the file.

Note: in a real program, it's important to check whether all the files needed actually exist and that you can read their contents. In our program, you should at least check that the files have been successfully opened.

If the fopen function fails, then print the message Error opening file. and end the program. There's only one instance of output from your program - your output can vary, depending on the file contents.

Expected output
Lines: 34
Whitespaces: 153
Characters: 686
Small letter: a : 23
Small letter: b : 1
Small letter: c : 25
Small letter: d : 7
Small letter: e : 27
Small letter: f : 13
Small letter: g : 1
Small letter: h : 12
Small letter: i : 32
Small letter: j : 0
Small letter: k : 1
Small letter: l : 14
Small letter: m : 6
Small letter: n : 36
Small letter: o : 16
Small letter: p : 9
Small letter: q : 0
Small letter: r : 20
Small letter: s : 23
Small letter: t : 39
Small letter: u : 14
Small letter: v : 0
Small letter: w : 4
Small letter: x : 0
Small letter: y : 0
Small letter: z : 3
*/

/*3
Write a program that will copy a file. However, if there is a destination file, then the program should try to create a new file (with a new file name) until the moment a destination file has been created.

Remember to close both files.

Note: in a real program, it's important to check whether all the files needed actually exist and that you can create a copy. In our program, you should at least check that both files have been successfully opened.

If the fopen function for the source file fails, then the program should print the message Error opening file. and end the program. If the process of creating a file fails, then you should change the name of the destination file.

You can append an integer number to the old file name.

Think about a limit on the number of attempts to create a file (it depends on your operating system and, of course, on the specific needs of your program). If you create too many files, it could be hard to use a directory that contains these files.

If your program has reached this limit, then it should print the message: File count limit reached. and end the program.

Expected output
Copy of the source file with the new file name.
*/

