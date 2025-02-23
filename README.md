# Brainfuck-Interpreter
A simple BrainFuck interpreter.

Adds a namespace named "bf" that contains 2 public classes, `BrainFuck` and `Instruction`.

## Example Program Usage
Drag and drop an input file stream (replaces the standard input buffer used by the parser), and then copy and paste your BF code into the command line window. The code is then executed once it has been entered and the ENTER button has been pressed.

## Instruction
Instruction is an enumerated class type that just contains the possible operations in any given BrainFuck implementation.

## Brainfuck
The BrainFuck class is the core implementation of the interpreter. It has a "read" function that takes instructions in string form and then parses each character using the `identifyInstruction` function to put into a list. The "execute" function is used for running each instruction. The "clear" function is used for clearing each instruction from the instruction list, and optionally resetting memory without resizing it.

The class also has basic getter functions for the current cell index, the memory cells themselves, the instructions gathered from the "read" function, and the raw unordered conversion map.

Furthermore, the BrainFuck class also has an overloaded ostream operator to show the values of each "cell".
