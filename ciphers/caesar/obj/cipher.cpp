/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Caesar cipher.
 * 
 * The Caesar cipher is an algorithm that uses permutation,
 * order, and patterns to encrypt/decrypt text.
 */
Cipher::Cipher(string ptext, string keys, string pattern)
{
    grabKeys(keys);
    grabPattern(pattern);
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
 * Gets the cipher keys.
 * 
 * @return keys A string vector describing the cipher keys.
 */
vector<string> Cipher::getKeys()
{
    return this->keys;
}

/**
 * Sets the cipher keys.
 * 
 * @param keys A string vector describing the cipher keys.
 */
void Cipher::setKeys(vector<string> keys)
{
    this->keys = keys; 
}

/**
 * Gets the cipher pattern.
 * 
 * @return patter A string vector describing the cipher pattern.
 */
vector<string> Cipher::getPattern()
{
    return this->pattern;
}

/**
 * Sets the cipher pattern.
 * 
 * @param pattern A string vector describing the cipher pattern.
 */
void Cipher::setPattern(vector<string> pattern)
{
    this->pattern = pattern;
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
void Cipher::setTable(vector<vector<string>>& table)
{
    this->table = table;
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
    
    for (int i=1; i <= len; i++)
    {
        row.push_back("-");
    }
}

/**
 * Seperates individual cipher keys from input.
 * 
 * @param keys An input string representing the keys.
 */
void Cipher::grabKeys(string keys)
{
    vector<string> temp;
    stringstream ss(keys);
 
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        temp.push_back(substr);
    }

    this->setKeys(temp);
}

/**
 * Creates cipher pattern from input string.
 * 
 * @param pattern An input string representing the pattern.
 */
void Cipher::grabPattern(string pattern)
{
    vector<string> temp;
    stringstream ss(pattern);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        temp.push_back(substr);
    }

    this->setPattern(temp);
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
 * Shifts cipher table rows based on the keys.
 * 
 * @return null
 */
void Cipher::makeShifts()
{
    for (const auto& key : this->getKeys())
    {
        vector<string> crow;
        //vector<string> orow;
        int shift = 0;
        int len = this->getTable()[0].size();

        shift = stoi(key);
        this->rowInit(crow);
        //this->rowInit(orow);

        for (int i=0; i < len; i++)
        {
            int j = i + shift;

            if (j >= len)
            {  
                for (int c=1; c <= shift; c++)
                {
                    crow[len - c] = this->getTable()[0][shift - c];
                    //orow[len - c] = this->getTable()[1][shift - c];
                }        
                this->addRow(crow);
                //this->addRow(orow);
                break;
            }
            else
            {
                crow[i] = this->getTable()[0][j]; 
                //orow[i] = this->getTable()[1][j];
            }
        }
    }
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
    vector<string> order = {
        "1","2","3","4","5","6","7","8","9","10","11",
        "12","13","14","15","16","17","18","19","20",
        "21","22","23","24","25","26"
    };

    this->addRow(chars);
    this->addRow(order);

}

/**
 * Decrypts the ciphertext using the pattern.
 * 
 * @return null
 */
void Cipher::decrypt()
{
    int len = this->getPlaintext().size();
    int j = 0;
    string temp = "";

    for (int i = 0; i < len; i ++)
    {
        string c = "";
        c = c + this->getPlaintext()[i];

        if (isspace(this->getPlaintext()[i]))
        {
            temp = temp + " ";
        }
        else
        {     
            if (j == this->getPattern().size())
            {
                j = 0;
            }
            
            int ciph = stoi(this->getPattern()[j]);
            int pos = 0;

            for (int h = 0; h < this->getTable()[0].size(); h ++)
            {
                if (this->getTable()[ciph+1][h] == c)
                {
                    pos = h;
                    temp = temp + this->getTable()[0][pos];
                    break; 
                }
            }
            
            j = j + 1;
        }
    }

    cout << temp << endl;
}

/**
 * Encrypts the plaintext using the pattern.
 * 
 * @return null
 */
void Cipher::encrypt()
{
    int len = this->getPlaintext().size();
    int j = 0; 
    string temp = "";
    
    for (int i = 0; i < len; i ++)
    {

        if (isspace(this->getPlaintext()[i]))
        {
            temp = temp + " ";
        }
        else
        {     
            if (j == this->getPattern().size())
            {
                j = 0;
            }

            int p = stoi(to_string(this->getPlaintext()[i])) - 97;   
            int ciph = stoi(this->getPattern()[j]);

            temp = temp + this->getTable()[ciph+1][p];
            
            j = j + 1;
        }
    }

    this->setCiphertext(temp);
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
    this->makeShifts();
    //this->showTable();
}

/**
 * Evaluates the cipher key and the plaintext.
 * 
 * @return null
 */
void Cipher::eval()
{
    ;
}