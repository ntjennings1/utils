# Caesar Cipher
This utility is used to simulate the Caesar cipher.

## About
The Caesar cipher is an encryption method which works to conceal message identity by substituting the characters in the message for other characters. This is implemented through a regular system, with a key and pattern, to produce an encoded message that alters the state of the plaintext units. Also known as the Shift cipher, the Caesar Cipher simply alters plaintext units and not the position of the units.

Here we will study the implementation of the Caesar cipher. By shifting the characters in the alphabet (according to a list of integer keys) one can create altered alphabets. Given multiple keys, the pattern (a list of integers representing which key to use iteratively) can map ciphertext units by grabbing the character at the position of each plaintext unit in the corresponding altered alphabet. 

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\caesar
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your pattern, key, and plain text. Also, make sure all input variables are surrounded by double quotes.

```
encrypt.exe "PLAINTEXT" "CIPHER_KEY_1, CIPHER_KEY_2, ..., CIPHER_KEY_N" "PATTERN_ITEM_1, PATTERN_ITEM_2, ..., PATTERN_ITEM_N"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your pattern, key, and plain text. Also, make sure all input variables are surrounded by double quotes.

```
.\decrypt.exe "CIPHERTEXT" "CIPHER_KEY_1, CIPHER_KEY_2, ..., CIPHER_KEY_N" "PATTERN_ITEM_1, PATTERN_ITEM_2, ..., PATTERN_ITEM_N"
```

## Acknowledgements

    Noah Jennings 
        TC 
        ntjennings1@gmail.com
        Virginia Beach, VA
        
    TC 
        th3orycc@gmail.com
        Virginia Beach, VA

## Sources

Also, I would like to recognize external organizations and websites that contributed to the content in this repository:

1. [The Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher)
