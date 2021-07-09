# Brainfuck-Interpreter
Simple Brainfuck interpreter utillising C++20

Adds a namespace named "bf" that contains 2 public classes, `BrainFuck` and `Instruction`.

## Instruction
Instruction is an enumerated class type that just contains the possible operations in any given BrainFuck implementation.

## Brainfuck
The BrainFuck class is the core implementation of the interpreter. It has a "read" function that takes instructions in string form and then parses each character using the `identifyInstruction` function to put into a list, this instruction is then immediately executed. The class also has basic getter functions for the current cell index, the memory cells themselves, and the instructions gathered from the "read" function.

Furthermore, the BrainFuck class also has an overloaded ostream operator to show the values of each "cell".

## TODO
- Split up the read function into a read and execute function respectively, as they're conjoined at the moment
