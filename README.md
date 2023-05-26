# Monty
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The project is an interpreter for Monty ByteCodes files.

## Getting Started
Ensure that you have gcc installed and build the program with bash `./build.bash`. This would generate an executable called `monty`. Run the program with `./monty file.`

## Supported Opcodes
| **Name** | **Description** |
|pop     |Removes the top element of the stack|
|push    |Pushes an element to the stack. Usage: `push integer`|
|swap    |Swaps the top two elements of the stack|
|pall    |Prints all the values on the stack, starting from the top of the stack|
|add     |Adds the top two elements of the stack|
|pint    |Prints the value at the top of the stack, followed by a new line|
|nop     |Does nothing|

## Commenting
Comments start with the `#` character after all the leading whitespaces have been skipped.

## Examples
```c
push 1
push 2
push 10
push 3
sub
pall
```
```c
push 56
push 72
pchar
```
### Author
- Fredrick Kiboi
