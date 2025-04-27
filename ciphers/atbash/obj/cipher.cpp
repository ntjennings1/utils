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

    this->addRow(chars);

    vector<string> row;
    this->rowInit(row);

    for (int i = 0; i < 26; i ++)
    {
        row[i] = chars[chars.size() - 1 - i];
    }

    this->addRow(row);  
}

void Cipher::addRow(vector<string>& row)
{
    table.push_back(row);
}

void Cipher::rowInit(vector<string>& row)
{
    int len = 26; 
    
    for (int i = 0; i < len; i++)
    {
        row.push_back("-");
    }
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
    string otemp = "";

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        for (int j = 0; j < this->getTable()[0].size(); j ++)
        {
            string ctemp = "";
            ctemp = ctemp + this->getPlaintext()[i];
            if (this->getTable()[1][j] == ctemp)
            {
                otemp = otemp + this->getTable()[0][j];
            }
        }
    }

    cout << otemp;
}

void Cipher::encrypt()
{
    string otemp = "";

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        for (int j = 0; j < this->getTable()[0].size(); j ++)
        {
            string ctemp = "";
            ctemp = ctemp + this->getPlaintext()[i];
            if (this->getTable()[0][j] == ctemp)
            {
                otemp = otemp + this->getTable()[1][j];
            }
        }
    }

    this->setCiphertext(otemp);
    cout << this->getCiphertext();
}

void Cipher::stage()
{
    this->tableInit();
}