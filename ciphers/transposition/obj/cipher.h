#ifndef CIPHER_H
#define CIPHER_H

/**
 * All imports.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;


/**
 * Implementation of the Transposition cipher. 
 * 
 * The Transposition cipher is an encryption algorithm that uses 
 * permutation and order to encrypt/decrypt text.
 * 
 */
class Cipher{
    /**
     * All public methods relevant to the encryption algorithm.
     */
    public:
        Cipher(string key, string ptext);
        string getKey();
        
        void setKey(string key);
        string getPlaintext();
        void setPlaintext(string ptext);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>>& table);
        int getRows();
        void setRows(int rows);
        
        void rowInit(int len, vector<string>& row);
        void showTable(); 
        void showRow(vector<string>& row);
        void addKey();
        void addPlaintext();
        void addRow(vector<string>& row); 
        void order();
        void blockify();
        vector<vector<string>> tempSetup();
        void transpose();
        void encrypt();
        void decrypt();
        void stage();

    /**
     * All private characteristics of the encryption algorithm.
     */
    private:
        string key = ""; 
        string ptext = "";
        int rows = 0;
        string ctext = "";
        vector<vector<string>> table; 

}; 

#endif