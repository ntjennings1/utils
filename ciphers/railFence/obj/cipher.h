#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

class Cipher{

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
        void addRows();
        void rowInit(vector<string>& row);
        void addRow(vector<string>& row);
        void showTable();

        void decrypt();
        void encrypt();
        void stage();
        void eval();

    private:
        string ptext = "";
        int rails = 0;
        vector<vector<string>> table;
        string ctext = "";

};

#endif