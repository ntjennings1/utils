#include <iostream>
#include <string>
#include <unistd.h>
#include "./obj/cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
   string key; 
   string ptext;

   Cipher cipher(argv[1], argv[2]);

   cipher.describe();
   cipher.stage();
   cipher.encrypt();

   sleep(1);

   return 0;  

}