#include <brainfuck.hpp>
#include <iostream>
#include <string>

#include <filesystem>
namespace fs = std::filesystem;

static void handleExit()
{
    std::cout << "Press ENTER to exit...";
    ((void)std::getchar());
}

int main(int argc, char** argv)
{
    std::atexit(handleExit);

    std::FILE* inputStream = stdin;
    bool openedFile = false;
    if (argc == 2) {
        errno_t error;
        if ((error = fopen_s(&inputStream, argv[1], "r") != 0)) {
            std::cout << "Cannot open file " << argv[1] << " as input stream for brainfuck code";
            return EXIT_FAILURE;
        }
        openedFile = true;
    }

    std::cout << "Input brainfuck code: ";
    std::string input = "";
    std::getline(std::cin, input);

    bf::BrainFuck parser(0x200, inputStream);
    parser.read(input.c_str());
    parser.execute();

    if (openedFile) {
        fclose(inputStream);
    }

    return EXIT_SUCCESS;
}