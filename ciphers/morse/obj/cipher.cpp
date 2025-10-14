/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of Morse Code.
 * 
 * Morse Code is an algorithm that uses polyalphabetic
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
vector<vector<string>>& Cipher::getTable()
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
                otemp = otemp + ",";
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
        string etemp = "";
        etemp = etemp + this->getPlaintext()[i];

        if (etemp == " ")
        {
            otemp = otemp + "*";
            otemp = otemp + ",";
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

/**
 * Stages the cipher table.
 * 
 * @return null
 */
void Cipher::stage()
{
    this->tableInit();
}

/**
 * Evaluates the plaintext.
 * 
 * @return null
 */
void Cipher::eval()
{

    string temp = this->getPlaintext();
    
    for (char &c : temp)
    {
        if (std::isalnum(c))
        {
            c = std::tolower(c);
        }
        else
        {
            cout << "Check plaintext. Invalid characters read." << endl;
            exit(0);
        }
    }
    this->setPlaintext(temp);

}