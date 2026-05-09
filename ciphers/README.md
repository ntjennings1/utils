# Ciphers

Various encryption algorithms created for machines on a network.

## Software Requirements

The open-source frameworks below were used to implement these encryption algorithms. Using different versions may not provide the same results. 

```
    - GCC 6.3.0
    - G++ 6.3.0
```

## Available Algorithms

This repository will have the following encryption algorithms:

1. Caesar cipher
2. Transposition cipher
3. Vernam cipher
4. Vigenere cipher

## Cipher Features

The encryption algorithms in this repository will have the following features:

### 1. Cipher Table

Encryption and decryption will rely on cipher tables; vectors created within the respective ciphers. Shifting and layout depends on the chosen algorithm.

#### 1a. Transpositional

For transposition ciphers, rows in the table are as follows: letter index, original letter, letter post-shift (ex. key=1).

| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| A | B | C | D | E | F | G | H | I | J  | K  | L  | M  | N  | O  | P  | Q  | R  | S  | T  | U  | V  | W  | X  | Y  | Z  |
| B | C | D | E | F | G | H | I | J | K  | L  | M  | N  | O  | P  | Q  | R  | S  | T  | U  | V  | W  | X  | Y  | Z  | A  |

### 2. Plaintext Validation
- This feature only accepts plaintext containing specific characters.

### 3. Cipher key validation
- This feature only accepts cipher keys containing specific characters.

### 4. Output stream
- This feature returns the plaintext/ciphertext on the console.

## Acknowledgements
```
Noah Jennings 
    ntjennings1@gmail.com
    Virginia Beach, VA
```