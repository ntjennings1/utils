#include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
    Cipher cipher(argv[1], argv[2]);

    cipher.eval();
    cipher.stage();
    cipher.encrypt();
    
    return 0;
}