# Simple Computer (SMAC) emulator

This project is a simple computer emulator (SMAC) implemented in C++. The emulator simulates a basic computer architecture with a set of opcodes for various operations, including move operations, input/output, arithmetic operations, increment/decrement, jump statements, and a halt command.

## Introduction

The SMAC emulator provides a simple yet extensible environment for understanding and experimenting with basic computer architecture. The implementation includes a set of opcodes that users can use to create custom programs.

## Features

- Emulation of a simple computer architecture
- Various opcodes for performing operations
- Input and output capabilities
- Extensible for creating custom programs

## Getting Started

To run the SMAC emulator on your machine, follow these steps:

1. Clone the repository to your local machine.
2. Compile the C++ code using your preferred compiler.
3. Execute the compiled program.

## How to Use

1. Compile the code using a C++ compiler (e.g., g++).
   Run the following code in the 

   '''g++ smac0.cpp -o smac0'''

2. Run the compiled program 

    '''./smac0'''

3. Enter the filename (along with path) of the SMAC program you want to run when prompted.



## Opcodes

The following opcodes are available in the SMAC emulator:

### Move Operations:

09: Move to registers
10: Move to location

### Input and Output:

81: User input
82: Output

### Arithmetic Operations:

11: Addition
12: Subtraction
13: Multiplication
14: Division

### Increment and Decrement:

23: Increment
24: Decrement

### Jump Statements:

30: Jump
31: Jump if negative
32: Jump if positive
33: Jump if not zero
34: Jump if zero

### Execute Program and Halt:

90: Halt


## Example Programs

The repository includes example programs in the output/codes directory. These programs demonstrate various functionalities of the SMAC emulator.

### program to find out factorial of given number 

- 81010001   ; Input: Read a number into register 1
- 09020001   ; Move the value in register 2 to memory location 1
- 24020000   ; Decrement the value in register 2
- 13020000   ; Multiply the value in memory location 2 by the value in register 2
- 24020000   ; Decrement the value in register 2
- 32020003   ; Jump to instruction 3 if the value in register 2 is not zero
- 82010004   ; Output: Display the value in register 1 (factorial result)
- 90000000   ; Halt: End of program


>[!WARNING]
>Do not include semicolon and comments in your progarm file

## Contributing

Contributions to the project are welcome! If you find a bug or have an enhancement in mind, please open an issue or submit a pull request.

