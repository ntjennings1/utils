# Virgenere Cipher
This utility is used to simulate the Vigenere cipher.

## About
The Vigenere cipher is an encryption algorithm that works to conceal message identity
by substituting the characters in the message for other characters. This is implemented through a regular system, with a key, to produce an encoded message that alters the state
of the plaintext units. Named after Blaise de Vigenere, the Vigenere cipher simply alters the plaintext units and not the position of the units.

Here we will study the implementation of the Vigenere cipher. By creating a table whose rows
consist of shifted alphabetic letters and incrementally comparing key/plaintext units to their
position in the table, one can find a substitute character for the ciphertext. Apply this to
all characters in the plaintext and key in order to find the entire encrypted message.

## Cipher Features

The encryption algorithms in this repository will have the following features:

1. Plaintext Validation
2. Cipher key validation
3. Output stream

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\vigenere
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your key and plain text. Also, make sure all input variables are surrounded by double quotes.

```
encrypt.exe "PLAINTEXT" "CIPHER_KEY"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your key and plain text. Also, make sure all input variables are surrounded by double quotes.

```
.\decrypt.exe "CIPHERTEXT" "CIPHER_KEY"
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

1. [The Vigenere Cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
