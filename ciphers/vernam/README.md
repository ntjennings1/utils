# Vernam Cipher
This utility is used to simulate the Vernam cipher.

## About


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

    Noah Jennings 
        TC 
        ntjennings1@gmail.com
        Virginia Beach, VA
        
    TC 
        th3orycc@gmail.com
        Virginia Beach, VA

## Sources

Also, I would like to recognize external organizations and websites that contributed to the content in this repository:

1. [The Vernam Cipher](https://en.wikipedia.org/wiki/Gilbert_Vernam)
