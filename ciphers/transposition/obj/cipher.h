#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

class Cipher{
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
        
        void rowInit(int len, vector<string>& row);
        void showTable(); 
        void showRow(vector<string>& row);
        void addKey();
        void addPlaintext();
        void addRow(vector<string>& row); 
        void blockify();
        void encrypt();
        void order();
        void stage();
        void describe();
    private:
        string key = ""; 
        string ptext = "";
        string ctext = "";
        vector<vector<string>> table; 

}; 

#endif