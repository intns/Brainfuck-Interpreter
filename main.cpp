#include <brainfuck.hpp>

int main(int argc, char** argv)
{
	bf::BrainFuck engine;
	engine.read("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.");
	return EXIT_SUCCESS;
}