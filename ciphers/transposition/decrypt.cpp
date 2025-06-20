/**
 * All imports. 
 */
#include <iostream>
#include <string>
#include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

/**
 * Runs the decryption algorithm.
 * 
 * @param argc The amount of available arguments.
 * @param argv A list of the available arguments.
 */
int main(int argc, char* argv[])
{

   Cipher cipher(argv[1], argv[2]);

   cipher.stage();
   cipher.transpose();
   cipher.decrypt();

   return 0;  

}