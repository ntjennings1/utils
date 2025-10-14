#ifndef CIPHER_H
#define CIPHER_H

/**
 * All imports.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Implementation of Morse Code.
 * 
 * Morse Code is an algorithm that uses polyalphabetic
 * substitution to encrypt/decrypt text.
 * 
 */
class Cipher{

    /**
     * All public methods relevant to the cipher.
     */
    public:
        Cipher(string ptext);
        
        string getPlaintext();
        void setPlaintext(string ptext);
        vector<vector<string>>& getTable();
        void setTable(vector<vector<string>> table);
        string getCiphertext();
        void setCiphertext(string ctext);

        void tableInit();
        void addRow(vector<string> & row);
        void showTable();

        void decrypt();
        void encrypt();
        void stage();
        void eval();

    /**
     * All private characteristics of the encryption algorithm.
     */
    private:
        string ptext = "";
        vector<vector<string>> table;
        string ctext = "";
};

#endif