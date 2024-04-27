# CPP01

> This is the second C++ module. It is composed of 6 exercises.

## ex00 - Zombie & the random Chump

This program demonstrates stack and heap memory allocation. It creates a Zombie object on the stack and a Zombie object on the heap. The Zombie object on the heap is created using the `new` keyword and must be deleted using the `delete` keyword. The Zombie object on the stack is created using the default constructor. And destroyed when it goes out of scope.

## ex01 - ZombieHorde

This program demonstrates dynamic memory allocation. It creates a horde of Zombie objects on the heap. The ZombieHorde is created by creating an array of Zombie objects. Then looping thru the array and calling the Zombie class announce method. Then the delete[] keyword is used to free the memory allocated for the ZombieHorde object.

## ex02 - Pointers & References

This program demonstrates the use of pointers and references. It creates a string and then assigns the string to a pointer and a reference. Then it demonstrates the difference between and similarities between pointers and references. References are essentially pointers that are automatically dereferenced. They are also immutable. Pointers can be reassigned and can be null. References cannot be null. Pointers can be used to iterate thru arrays. References cannot.

## ex03 - Human

This program demonstrates inheritance. It creates a HumanA and HumanB class. HumanA has a constructor that takes in its name and a reference to a weapon class. HumanB differs in the way it constructs itself. The constructor only takes in a name. The weapon is assigned to the HumanB object using the setWeapon method. The weapon is a reference to a weapon object. The weapon object is created on the stack in the main function. The HumanA and HumanB objects are created on the stack in the main function. The HumanA and HumanB objects are then destroyed when they go out of scope.

## ex04 - Replace all instances of a string in a file

The title kind of says it all. This program reads a file and replaces all instances of a string with another string. The program takes in 3 arguments. The first argument is the file to read. The second argument is the string to replace. The third argument is the string to replace the second argument with. The program reads the file line by line and uses the find and a self made replace method to replace the string. The program then writes the modified line to a file with the original file name appended with ".replace".

## ex05 - Harl

Harl is a program that likes to complain. The first argument is either: DEBUG, INFO, WARNING, or ERROR. If any other string is provided Harl will just randomly complain. If no arguments are provided Harl will also just randomly complain. Harl is a simple program that demonstrates the use of function pointers and arrays of function pointers. This is the simple version the next excesise will be a more complex version of Harl.

## ex06 - Harl (Filtered)

The more complex version of Harl requires a switch statement to be able to have multiple cases to trigger based on the level of the complaint. However if no level is provided or an invalid level is provided Harl will just randomly complain.
