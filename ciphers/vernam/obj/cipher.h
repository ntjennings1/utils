#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Cipher{
    public:
        Cipher(string ptext, string key);
        string getPlaintext();
        void setPlaintext(string ptext);
        string getKey();
        void setKey(string key);
        vector<vector<string>> getTable();
        void setTable(vector<vector<string>>& table);
        string getCiphertext();
        void setCiphertext(string ctext);

        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
        void tableInit();
        void showTable();
        string findBinary(char& input);
        string findString(string& input);
        string exor(string one, string two, int i);
        void decrypt();
        void encrypt();
        void stage();
        void eval();
    private:
        string ptext = "";
        string key = "";
        vector<vector<string>> table;
        string ctext = "";
};

#endif