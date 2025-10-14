# Vernam Cipher
This utility is used to simulate the Vernam cipher.

## About
The Vernam cipher is an encryption algorithm that works to conceal message identity by substituting the characters in the message for other characters. This is implemented through a regular system, with a key, to produce an encoded message that alters the state of the plaintext units. Created by Gilbert Sandford Vernam, the Vernam cipher simply alters the plaintext units and not the position of the units.

Here we will study the implementation of the Vernam cipher. By finding a binary representation of a character in the text and the key, then calculating the exclusive-OR (XOR) between them, one can find a substitute character for the ciphertext. Apply this to all characters in the plaintext and key in order to find the entire encrypted message.

## Cipher Features

The encryption algorithms in this repository will have the following features:

1. Plaintext Validation
2. Cipher key validation
3. Output stream

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\vernam
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your pattern, key, and plain text. Also, make sure all input variables are surrounded by double quotes.

```
encrypt.exe "PLAINTEXT" "CIPHER_KEY"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your pattern, key, and plain text. Also, make sure all input variables are surrounded by double quotes.

```
.\decrypt.exe "CIPHERTEXT" "CIPHER_KEY"
```

## Acknowledgements
```
Noah Jennings 
    TC 
    ntjennings1@gmail.com
    Virginia Beach, VA
```

## Sources

Also, I would like to recognize external organizations and websites that contributed to the content in this repository:

1. [Gilber Vernam](https://en.wikipedia.org/wiki/Gilbert_Vernam)
2. [Vernam Cipher in Cryptography](https://www.geeksforgeeks.org/computer-networks/vernam-cipher-in-cryptography/)