#include <brainfuck.hpp>

int main(int argc, char** argv)
{
	bf::BrainFuck engine;

	engine.read("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.");
	engine.execute();

	std::cout << engine;

	return EXIT_SUCCESS;
}