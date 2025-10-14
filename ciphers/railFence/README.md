# Railfence Cipher
This utility is used to simulate the Railfence cipher.

## About
The Railfence cipher is an algorithm that works to conceal message identity by substituting the characters in the message for other characters. This is implemented through a regular system, with a key, producing an encoded message that alters the positions of the plaintext units and not their state.

Here we will study the implemetnation of the Railfence cipher. Create a table with a number of rows specified by the user and span plaintext units diagonally on successive 'rails'. By reading row contents horizontally, after operations, one can map plaintext characters to their ciphertext counterpart and vice versa.

## Cipher Features

The encryption algorithms in this repository will have the following features:

1. Plaintext Validation
3. Output stream

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\railfence
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your key and plaintext. Also, make sure all input variables are surrounded by double quotes.

```
encrypt.exe "PLAINTEXT" "#Rails"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your key and ciphertext. Also, make sure all input variables are surrounded by double quotes.

```
.\decrypt.exe "CIPHERTEXT" "#Rails"
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

1. [The Railfence cipher](https://en.wikipedia.org/wiki/Rail_fence_cipher)
2. [Railfence Cipher Encryption/Decryption](https://www.geeksforgeeks.org/dsa/rail-fence-cipher-encryption-decryption/)