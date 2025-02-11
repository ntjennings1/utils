# Transposition Cipher
This utility is used to simulate a transposition cipher. 

## About
The transposition cipher, also known as a permutation cipher, is an encryption metho which scrambles the positions of characters without changing the characters themselves. This is implemented through with a regular system, aka a key, to produce an encoded message that alters the linear order of the plaintext units. 

Here we will study a columnar transposition. This is where the plaintext is written out in rows of a fixed length (the length of the key) and then read back column by column. The order in which the columns are read back is determined by the alphabetical order of the letters in the key. 

This system will supply us with ciphertext that is not easily deciphered even with the correct key.  

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

The run the executable. Be sure to enter your own key and plain text. Also, make sure they are surrounded by double quotes.

```
.\encrypt.exe "CIPHER_KEY" "PLAIN_TEXT"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

The run the executable. Be sure to enter your own key and cipher text. Also, make sure they are surrounded by double quotes.

```
.\decrypt.exe "CIPHER_KEY" "CIPHER_TEXT"
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