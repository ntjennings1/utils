/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Vigenere cipher.
 * 
 * The Caesar cipher is an encryption algorithm that uses
 * polyalphabetic substitution to encrypt/decrypt text.
 */
Cipher::Cipher(string ptext, string key)
{
    this->ptext = ptext;
    this->key = key;
}

/**
 * Gets the plaintext.
 * 
 * @return ptext A string representing the plaintext.
 */
string Cipher::getPlaintext()
{
    return this->ptext;
}

/**
 * Sets the plaintext.
 * 
 * @param ptext A string representing the plantext.
 */
void Cipher::setPlaintext(string ptext)
{
    this->ptext = ptext;
}

/**
 * Gets the cipher keys.
 * 
 * @return keys A string vector describing the cipher keys.
 */
string Cipher::getKey()
{
    return this->key;
}

/**
 * Sets the cipher keys.
 * 
 * @param keys A string vector describing the cipher keys.
 */
void Cipher::setKey(string key)
{
    this->key = key;
}

/**
 * Gets the ciphertext.
 * 
 * @return ctext A string representing the ciphertext.
 */
string Cipher::getCiphertext()
{
    return this->ctext;
}

/**
 * Sets the ciphertext.
 * 
 * @param ctext A string representing the ciphertext.
 */
void Cipher::setCiphertext(string ctext)
{
    this->ctext = ctext;
}

/**
 * Gets the cipher table.
 * 
 * @return table A vector of string vectors describing the cipher table.
 */
vector<vector<string>> Cipher::getTable()
{
    return this->table;
}

/**
 * Sets the cipher table.
 * 
 * @param table A vector of string vectors describing the cipher table.
 */
void Cipher::setTable(vector<vector<string>> table)
{
    this->table = table;
}

/**
 * Initializes the cipher table.
 */
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

/**
 * Adds a row to the table.
 * 
 * @param row A string vector.  
 */
void Cipher::addRow(vector<string>& row)
{
    table.push_back(row);
}

/**
 * Initializes a row.
 * 
 * @param row A string vector with plaintext.
 */
void Cipher::rowInit(vector<string>& row)
{
    int len = this->getTable()[0].size(); 
    
    for (int i = 0; i < len; i++)
    {
        row.push_back("-");
    }
}

/**
 * Shows the cipher table.
 */
void Cipher::showTable()
{
    for (const auto& row : this->getTable()){
        for (const auto& el : row){
            cout << el << " " ;
        }
        cout << endl;
    }
}

/**
 * Shifts cipher table rows based on the previous entry.
 */
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

/**
 * Fixes the cipher key to math the length of the plaintext.
 */
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

/**
 * Decrypts the ciphertext using the key.
 */
void Cipher::decrypt()
{
    string otemp = "";

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
                        otemp = otemp + this->getTable()[0][h]; 
                    }
                }
            }
        }
    }

    cout << otemp;
}

/**
 * Encrypts the plaintext using the key.
 */
void Cipher::encrypt()
{
    string otemp = "";

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
                        otemp = otemp + this->getTable()[j][h];
                    }
                }
            }
        }
    }

    this->setCiphertext(otemp);
    cout << this->getCiphertext();
}

/**
 * Stages the cipher table.
 */
void Cipher::stage()
{
    this->tableInit();
    //this->showTable();

}

/**
 * Evaluates the lengths of the cipher key and plaintext.
 */
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
        exit(0);
    }
}