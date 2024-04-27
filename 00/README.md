# CPP00

> This is the first C++ module. It is composed of 3 exercises. (I did not do the last one)

## ex00 - Megaphone

```shell
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

This is a simple program that displays a string on the standard output. However, the string(s) supplied as arguments are looped thru and all alphabet characters are converted to uppercase. If no arguments are supplied, the program displays "\* LOAD UNBEARABLE NOISE \*" on the standard output.

Skills learned:

-   Basic C++ syntax
-   Command line arguments
-   Loops
-   Conditionals
-   String manipulation

## ex01 - Phonebook

```shell
$> ./phonebook
[ADD] [SEARCH] [EXIT]
```

This is a simple cli tool that functions as a phonebook. It can store up to 8 contacts. The user can add, search, and display contacts. The user can also exit the program by typing "EXIT". If the user tries to add a contact when the phonebook is full, the program will remove the oldest contact and add the new one.

Skills learned:

-   Terminal I/O
-   Classes
-   Arrays
-   Do-while loops (for input validation)
-   Space padding for table formatting
