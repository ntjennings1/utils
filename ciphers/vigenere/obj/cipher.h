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
 * Implementation of the Vigenere cipher.
 * 
 * The Vigenere cipher is an algorithm that uses polyalphabetic
 * substitution to encrypt/decrypt text.
 */
class Cipher{

    /**
     * All public methods relevant to the encryption algorithm.
     */
    public:
        Cipher(string ptext, string key); 

        string getPlaintext();
        void setPlaintext(string ptext);
        string getKey();
        void setKey(string key);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>> table);
        
        void tableInit();
        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
        void showTable();
        vector<string> makeShifts(vector<string>& row);

        void fixKey();
        void decrypt();
        void encrypt();
        void stage();
        void eval();

    /**
     * All private characteristics of the encryption algorithm.
     */
    private:
        string ptext = "";
        string key = "";
        vector<vector<string>> table;
        string ctext = "";
};

#endif