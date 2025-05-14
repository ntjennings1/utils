#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h> 

using namespace std;

class Cipher{

    public:
        Cipher(string ptext, string key);

        string getPlaintext();
        void setPlaintext(string ptext);
        vector<vector<string>> getPTMat();
        void setPTMat(vector<vector<string>>& ptmat);
        string getKey();
        void setKey(string key);
        vector<vector<string>> getKMat();
        void setKMat(vector<vector<string>>& kmat);
        string getCiphertext();
        void setCiphertext(string ctext);
        vector<vector<string>>& getTable();
        void setTable(vector<vector<string>> table);

        vector<vector<string>> matricize(vector<string> vec, string indicator);
        vector<vector<string>> transpose(vector<string>& vec);
        vector<vector<string>> identify(vector<string> mat);
        vector<vector<string>> invert(vector<string> mat);
        vector<vector<string>> mult(vector<vector<string>> mat, vector<vector<string>> vec);

        void tableInit();
        void addRow(vector<string>& row);
        void showTable();

        void decrypt();
        void encrypt();
        vector<string> locate(string indicator);
        void stage();
        void eval();
        

    private:
        string ptext = "";
        vector<vector<string>> ptmat;
        string key = "";
        vector<vector<string>> kmat;
        vector<vector<string>> table;
        string ctext = "";

};

#endif