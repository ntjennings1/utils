# Atbash Cipher
This utility is used to simulate the Atbash cipher.

## About
The Atbash cipher is an encryption algorithm that works to conceal message identity by 
substituting the characters in the message for other characters. This is implemented
through a regular system, producing an encoded message that alters the state of the
plaintext units and not their positions.

Here we will study the implementation of the Atbash cipher. Create a table with two rows;
one containing the letters of the alphabet, and the other containing the letters in reverse
order. By finding the position of the text units in each row, one can map plaintext units
to their ciphertext counterpart and vice versa. 

## Cipher Features

The encryption algorithms in this repository will have the following features:

1. Plaintext Validation
3. Output stream

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\atbash
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter plain text surrounded by double quotes.
```
encrypt.exe "PLAINTEXT"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter plain text surrounded by double quotes.

```
.\decrypt.exe "CIPHERTEXT"
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

1. [The Atbash Cipher](https://en.wikipedia.org/wiki/Atbash)
