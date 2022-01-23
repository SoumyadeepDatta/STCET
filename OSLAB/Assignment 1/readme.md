# Logon to UNIX system and perform the following:
1. Create five empty files empty1, empty2, empty3, empty4 and empty5.
2. Create a file called text and store your name, age and address in it.
3. Display the contents of the file text on the screen.
4. Make a copy of the file text into another file newtext.
5. Create a file matter and type any 2 sentences in t.
6. Combine the contents of the file text and matter into another file txtmat.
7. Delete the file text.
8. Change the permission of the file newtext to 666.
9. Rename the file newtext to oldtext.
10. Create a directory mydir in the current directory.
11. Move the files oldtext and matter to the directory mydir.
12. Create another directory mydir in the current directory.
13. Copy the contents of mydir directory to the newdir directory.
14. Display the current date in the format dd/mm/yyyy.
15. Check the current users.
16. Obtain a complete listing of all files and directories in the whole system.
17. Count the number of users currently logged into the system.
18. When will rmdir xyz (assume xyz is directory) fail to work?
```
If there are already some files inside the directory 'rmdir' will not work. First we have to dlelete all those files which are inside 'xyz' using rmdir. 
To delete a directory 'xyz' which already contains some files we can use 'rm -r xyz'.
```
19. What does cd do when used without arguments?
```
It takes back to home directory when used without arguments. 
We can also use 'cd $HOME' to get the same effect.
```
