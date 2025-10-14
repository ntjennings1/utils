/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Atbash cipher. 
 * 
 * The Atbash cipher is an algorithm that uses monoalphabetic
 * substitution to encrypt/decrypt text.
 * 
 */
Cipher::Cipher(string ptext)
{
    this->ptext = ptext;
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
 * 
 * @return null
 */
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

/**
 * Adds a row to the cipher table.
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
    int len = 26; 
    
    for (int i = 0; i < len; i++)
    {
        row.push_back("-");
    }
}

/**
 * Shows the cipher table.
 * 
 * @return null
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
 * Decrypts the ciphertext using the key.
 * 
 * @return null
 */
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

/**
 * Encrypts the plaintext using the key.
 * 
 * @return null
 */
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

/**
 * Stages the cipher table.
 * 
 * @return null
 */
void Cipher::stage()
{
    this->tableInit();
}