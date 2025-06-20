/**
 * All imports.
 */
 #include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

/**
 * Runs the encrpytion algorithm. 
 * 
 * @param argc The amount of available arguments.
 * @param argv A list of the available arguments.
 */
int main(int argc, char* argv[])
{
    Cipher cipher(argv[1]);

    cipher.stage();
    cipher.encrypt();

    return 0;
}