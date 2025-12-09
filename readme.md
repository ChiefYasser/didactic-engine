| Function      | Purpose                              |
| ------------- | ------------------------------------ |
| **fopen()**   | Opens a file (read/write).           |
| **fclose()**  | Closes an opened file.               |
| **fscanf()**  | Reads a word from a file.            |
| **fprintf()** | Writes formatted text to a file.     |
| **fgets()**   | Reads an entire line from a file.    |
| **fputs()**   | Writes a full line to a file.        |
| **remove()**  | Deletes a file.                      |
| **rename()**  | Renames or replaces a file.          |
| **strcmp()**  | Compares two strings.                |
| **strcpy()**  | Copies a string.                     |
| **isspace()** | Checks if a character is whitespace. |
| **printf()**  | Displays text to the user.           |
| **scanf()**   | Reads user input.                    |

A C-based command-line tool for text file manipulation with three main operations: filtering forbidden words, removing empty lines, and sorting lines alphabetically.

Features
Filter Forbidden Words: Remove specified words from a file using a forbidden words list
Remove Empty Lines: Clean up files by eliminating blank lines
Sort Lines: Arrange file lines in alphabetical order
a fun lil project to refresh my memory for basics in C language 


to run the code first compile with this 
gcc main.c operations.c -o output/main.exe

then run it with 
.\output\main.exe
