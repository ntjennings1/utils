#include "cipher.h"

Cipher::Cipher(string ptext, string key)
{
    this->ptext = ptext;
    this->key = key;
}

string Cipher::getPlaintext()
{
    return this->ptext;
}

void Cipher::setPlaintext(string ptext)
{
    this->ptext = ptext;
}

string Cipher::getKey()
{
    return this->key;
}

void Cipher::setKey(string key)
{
    this->key = key;
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
    
    while (this->getTable().size() < 26)
    {
        vector<string> row = this->getTable()[this->getTable().size() - 1];
        row = this->makeShifts(row);
        this->addRow(row);
    }

}

void Cipher::addRow(vector<string>& row)
{
    table.push_back(row);
}

void Cipher::rowInit(vector<string>& row)
{
    int len = this->getTable()[0].size(); 
    
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

vector<string> Cipher::makeShifts(vector<string>& row)
{
    vector<string> temp;
    this->rowInit(temp);

    for (int i = 0; i < this->getTable()[0].size(); i ++)
    {
        if (i + 1 == this->getTable()[0].size())
        {
            temp[i] = this->getTable()[this->getTable().size() - 1][0];
        }
        else
        {
            temp[i] = this->getTable()[this->getTable().size() - 1][i + 1];
        }
    }

    return temp;
}

void Cipher::fixKey()
{
    int i = 0;
    string temp = this->getKey();
    
    while (temp.size() < this->getPlaintext().size())
    {
        if (i == this->getKey().size())
        {
            i = 0;
        }

        temp = temp + this->getKey()[i];
        i = i + 1;
    }
    this->setKey(temp);

}

void Cipher::decrypt()
{
    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string ptemp = "";
        ptemp = ptemp + this->getPlaintext()[i];
        string ktemp= "";
        ktemp = ktemp + this->getKey()[i];

        for (int j = 0; j < this->getTable().size(); j ++)
        {
            if (this->getTable()[j][0] == ktemp)
            {
                for (int h = 0; h < this->getTable()[0].size(); h ++)
                {
                    if (this->getTable()[j][h] == ptemp)
                    {
                        cout << this->getTable()[0][h]; 
                    }
                }
            }
        }
    }
}

void Cipher::encrypt()
{
    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string ptemp = "";
        ptemp = ptemp + this->getPlaintext()[i];
        string ktemp= "";
        ktemp = ktemp + this->getKey()[i];

        for (int j = 0; j < this->getTable().size(); j ++)
        {
            if (this->getTable()[j][0] == ptemp)
            {
                for (int h = 0; h < this->getTable()[0].size(); h ++)
                {
                    if (this->getTable()[0][h] == ktemp)
                    {
                        cout << this->getTable()[j][h]; 
                    }
                }
            }
        }
    }
}

void Cipher::stage()
{
    this->tableInit();
    this->showTable();

}

void Cipher::eval()
{
    if (this->getKey().size() < this->getPlaintext().size())
    {
        this->fixKey();
    }
    else if (this->getKey().size() == this->getPlaintext().size())
    {
        ;
    }
    else
    {
        cout << "Key length must be <= to the plaintext length.";
    }
    cout << this->getKey() << endl;
}