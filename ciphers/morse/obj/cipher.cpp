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

vector<vector<string>>& Cipher::getTable()
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
        "w","x","y","z", "0", "1", "2", "3", "4", "5",
        "6", "7", "8", "9"
    };

    vector<string> order = {
        "._", "_...", "_._.", "_..", ".", ".._.", "__.", "....",
        "..", ".___", "_._", "._..", "__", "_.", "___", ".__.",
        "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._",
        "_.__", "__..", "_____", ".____", "..___", "...__", "...._",
        ".....", "_....", "__...", "___..", "____."
    };

    this->addRow(chars);
    this->addRow(order);
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
    
    string otemp = "";
    string etemp = "";

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string temp = "";
        temp = temp + this->getPlaintext()[i];

        if (temp == ",")
        {
            for (int j = 0; j < this->getTable()[0].size(); j ++)
            {
                string ctemp = "";
                ctemp = ctemp + this->getTable()[1][j];

                if (ctemp == etemp)
                {
                    otemp = otemp + this->getTable()[0][j];
                }
            }
            etemp = "";
        }
        else
        {
            if (temp != "*")
            {
                etemp = etemp + temp;
            }
            else
            {
                otemp = otemp + " ";
                etemp.clear();
            }
        }            
    }

    this->setCiphertext(otemp);
    cout << this->getCiphertext() << endl;
}

void Cipher::encrypt()
{
    string otemp = "";

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string etemp = "";
        etemp = etemp + this->getPlaintext()[i];

        if (etemp == " ")
        {
            otemp = otemp + "*";
        }
        else
        {
            for (int j = 0; j < this->getTable()[0].size(); j ++)
            {
                string ctemp = "";
                ctemp = ctemp + this->getTable()[0][j];

                if (ctemp == etemp)
                {
                    otemp = otemp + this->getTable()[1][j];
                    otemp = otemp + ",";
                }
            }
        }
    }

    this->setCiphertext(otemp);
    cout << this->getCiphertext() << endl;

}

void Cipher::stage()
{
    this->tableInit();
}

void Cipher::eval()
{
    ;

}