#ifndef CIPHER_H
#define CIPHER_H

/**
 * All imports.
 */
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std; 

/**
 * Implementation of the Caesar cipher.
 * 
 * The Caesar cipher is an algorithm that uses permutation,
 * order, and patterns to encrypt/decrypt text.
 */
class Cipher{

    /**
     * All public methods relevant to the encryption algorithm.
     */
    public:
        Cipher(string ptext, string keys, string pattern);
        
        string getPlaintext();
        void setPlaintext(string ptext);
        vector<string> getKeys();
        void setKeys(vector<string> keys);
        vector<string> getPattern();
        void setPattern(vector<string> pattern);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>>& table);

        void tableInit();
        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
        void showTable();
        void makeShifts();
        void grabKeys(string keys);
        void grabPattern(string pattern);

        void decrypt();
        void encrypt();
        void stage();
        void eval();

    /**
     * All private characteristics of the encryption algorithm.
     */
    private:
        string ptext = "";
        vector<string> keys;
        vector<string> pattern;
        vector<vector <string>> table; 
        string ctext = "";
};

#endif