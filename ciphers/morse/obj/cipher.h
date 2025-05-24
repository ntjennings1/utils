#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Cipher{

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

    private:
        string ptext = "";
        vector<vector<string>> table;
        string ctext = "";
};

#endif