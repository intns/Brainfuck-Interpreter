# Brainfuck-Interpreter
Simple Brainfuck interpreter utillising C++20

Adds a namespace named "bf" that contains 2 public classes, BrainFuck and Instruction.
Instruction is an enumerated class type that just contains the possible operations in any given BrainFuck implementation.
Brainfuck is the main engine of this project, it contains the code that runs the BrainFuck, and has implemented functions to help identify a command it's given, it's memory cells and even the index of memory that the program is currently operating at.
