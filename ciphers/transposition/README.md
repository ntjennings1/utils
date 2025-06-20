# Transposition Cipher
This utility is used to simulate the Columnar Transposition cipher. 

## About
This transposition cipher is an encryption method which scrambles the positions of characters without changing the characters themselves. This is implemented through a regular system, with a key, to produce an encoded message that alters the linear order of the plaintext units. Also known as a Permutation Cipher, transpositions ciphers simply alters plaintext unit positions and not the units themselves. 

Here we will study the Columnar Transposition Cipher. This is where the plaintext is written out in rows of a fixed length (the length of the key) and then read back column by column. The order in which the columns are read back is determined by the alphabetical order of the letters in the key. 

## Uses

Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\transposition
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your own key and plain text. 

Also, make sure all input variables are surrounded by double quotes.

```
.\encrypt.exe "CIPHER_KEY" "PLAIN_TEXT"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your own key and cipher text. Also, make sure they are surrounded by double quotes.

```
.\decrypt.exe "CIPHER_KEY" "CIPHERTEXT"
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

1. [The Transposition Cipher](https://en.wikipedia.org/wiki/Transposition_cipher)