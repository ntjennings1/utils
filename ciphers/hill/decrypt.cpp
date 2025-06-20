#include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
    Cipher cipher(argv[1], argv[2]);

    cipher.stage();
    cipher.decrypt();

    return 0;
}