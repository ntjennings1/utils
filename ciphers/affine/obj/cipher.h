#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Cipher{

    public:
        Cipher(string ptext);

        string getPlaintext();
        void setPlaintext(string ptext);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>> table);

        void tableInit();
        void addRow(vector<string>& row);
        void showTable();

        void decrypt();
        void encrypt();
        void stage();

    private:
        string ptext = "";
        vector<vector<string>> table; 
        string ctext = "";

};

#endif