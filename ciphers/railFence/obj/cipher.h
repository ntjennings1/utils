#ifndef CIPHER_H
#define CIPHER_H

/**
 * All imports.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

/**
 * Implementation of the Railfence cipher. 
 * 
 * The Railfence cipher is an algorithm that uses
 * transposition to encrypt/decrypt text.
 * 
 */
class Cipher{

    /**
     * All public methods relevant to the encryption algorithm.
     */
    public:
        Cipher(string ptext, int rails);

        string getPlaintext();
        void setPlaintext(string ptext);
        int getRails();
        void setRails(int rails);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>>& getTable();
        void setTable(vector<vector<string>> table);

        void tableInit();
        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
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
        int rails = 0;
        vector<vector<string>> table;
        string ctext = "";

};

#endif