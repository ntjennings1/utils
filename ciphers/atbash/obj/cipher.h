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
 * Implementation of the Atbash cipher. 
 * 
 * The Atbash cipher is an encryption algorithm that uses 
 * monoalphabetic substitution to encrypt/decrypt text.
 * 
 */
class Cipher{

    /**
     * All public methods relevant to the encryption algorithm.
     */
    public:
        Cipher(string ptext);

        string getPlaintext();
        void setPlaintext(string ptext);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>> table);

        void tableInit();
        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
        void showTable();

        void decrypt();
        void encrypt();
        void stage();

    /**
     * All private characteristics of the encryption algorithm.
     */
    private:
        string ptext = "";
        vector<vector<string>> table;
        string ctext = "";
};

#endif