#include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
    int rails = std::atoi(argv[2]);

    Cipher cipher(argv[1], rails);

    cipher.eval();
    cipher.stage();
    cipher.encrypt();
    
    return 0;
}