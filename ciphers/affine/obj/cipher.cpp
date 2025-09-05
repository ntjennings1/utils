#include "cipher.h"

Cipher::Cipher(string ptext)
{
    this->ptext = ptext;
}

string Cipher::getPlaintext()
{
    return this->ptext;
}

void Cipher::setPlaintext(string ptext)
{
    this->ptext = ptext;
}

string Cipher::getCiphertext()
{
    return this->ctext;
}

void Cipher::setCiphertext(string ctext)
{
    this->ctext = ctext;
}

vector<vector<string>> Cipher::getTable()
{
    return this->table;
}

void Cipher::setTable(vector<vector<string>> table)
{
    this->table = table;
}

void Cipher::tableInit()
{
    vector<string> chars = {
        "a","b","c","d","e","f","g","h","i","j","k",
        "l","m","n","o","p","q","r","s","t","u","v",
        "w","x","y","z"
    };

    vector<string> ord = {
        "0","1","2","3","4","5","6","7","8","9","10",
        "11","12","13","14","15","16","17","18","19","20","21",
        "22","23","24","25"
    };

    this->addRow(chars);
    this->addRow(ord);
}

void Cipher::addRow(vector<string>& row)
{
    table.push_back(row);
}

void Cipher::showTable()
{
    for (const auto& row : this->getTable()){
        for (const auto& el : row){
            cout << el << " " ;
        }
        cout << endl;
    }
}

void Cipher::decrypt()
{
    ;
}

void Cipher::encrypt()
{
    ;
}

void Cipher::stage()
{
    this->tableInit();
    this->showTable();
}