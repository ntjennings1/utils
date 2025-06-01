# Morse Code
This utility is used to simulate Morse Code.

## About

Morse Code is an encryption method which works to conceal message identity by substituting
the characters in the message for other characters. This is implemented through a regular
system to produce an encoded message that alters the state of the plaintext units. Even
with multiple implementations, Morse Code simply alters plaintext units and not the
position of the units.

Named after Samuel Morse, Morse Code is typically used in telecommunications and transmitted
by on-off keying of a medium on the electromagnetic spectrum. Morse Code can be utilized and
memorized with a dictionary that maps alphabetic characters to their corresponding sequence
composed of two different signal durations known as dots (dits) and dashed (dahs). By finding
each plaintext units respective signal sequence one can craft an encoded message.

## Cipher Features

The encryption algorithms in this repository will have the following features:

1. Plaintext Validation
2. Cipher key validation
3. Output stream

## Uses
Running this simulation is simple. Enter the source directory of this cipher algorithm: 

```
cd $UTILS_HOME\ciphers\morse
```

### Encryption
Run the following command to compile the C++ code into an executable:

```
g++ .\encrypt.cpp .\obj\cipher.cpp -o encrypt.exe
```

Then run the executable. Be sure to enter your key and plain text. Also, make sure all input variables are surrounded by double quotes.

```
encrypt.exe "PLAINTEXT"
```

### Decryption
Run the following command to compile the C++ code into an executable:

```
g++ .\decrypt.cpp .\obj\cipher.cpp -o decrypt.exe
```

Then run the executable. Be sure to enter your key and plain text. Also, make sure all input variables are surrounded by double quotes.

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

1. [Morse Code](https://en.wikipedia.org/wiki/Morse_code)
