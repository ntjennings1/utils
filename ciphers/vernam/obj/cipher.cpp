/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Vernam cipher.
 * 
 * The Vernam cipher is an algorithm that uses substitution,
 * and the binary XOR to encrypt/decrypt text.
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
 * @param ptext A string representing the plaintext.
 */
void Cipher::setPlaintext(string ptext)
{
    this->ptext = ptext;
}

/**
 * Gets the cipher key.
 * 
 * @return key A string representing the cipher key.
 */
string Cipher::getKey()
{
    return this->key;
}

/**
 * Sets the cipher key.
 * 
 * @param key A string representing the cipher key.
 */
void Cipher::setKey(string key)
{
    this->key = key;
}

/**
 * Gets the cipher table.
 * 
 * @return table A vector of string vectors used to represent the cipher table.
 */
vector<vector<string>> Cipher::getTable()
{
    return this->table;
}

/**
 * Sets the ciphertable.
 * 
 * @param table A vector of string vectors used to represent the cipher table.
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
 * Initializes the cipher table.
 * 
 * @return null
 */
void Cipher::tableInit()
{
    vector<string> prow;
    vector<string> krow;

    for (const auto& el : this->getPlaintext())
    {
        string temp = "";
        temp = temp + el;
        
        prow.push_back(temp);
    }
    for (const auto& el : this->getKey())
    {
        string temp = "";
        temp = temp + el;

        krow.push_back(temp);
    }
    
    this->addRow(prow);
    this->addRow(krow);

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
 * Calculates the binary representation of some input.
 * 
 * @param input A character to be converted to binary.
 */
string Cipher::findBinary(char& input)
{
    string out = ""; 
    input = toupper(input); 
    int pos = static_cast<int>(input) - 65;

    if (pos == 0)
    {
        out = "0";
    }
    else
    {
        while (pos > 0)
        {
            int bit = pos%2;
            out.push_back('0' + bit);
            pos /= 2;
        }
    }

    while (out.size() < 5)
    {
        string add = "0";
        out = out + add; 
    }

    reverse(out.begin(), out.end());
    return out;

}

/**
 * Converts some binary representation to string.
 * 
 * @param input A binary representation.
 */
string Cipher::findString(string& input)
{
    string c;
    int sum = 0;
    int add = 0;
    for (int i = 0; i < input.size(); i ++)
    {
        if (input[i] == '1')
        {
            switch(i)
            {
                case 0:
                    add = pow(2, 4);
                    sum = sum + add;
                    break;

                case 1:
                    add = pow(2, 3);
                    sum = sum + add;
                    break;

                case 2:
                    add = pow(2, 2);
                    sum = sum + add;
                    break;

                case 3:            
                    add = pow(2, 1);
                    sum = sum + add;
                    break;

                case 4:
                    add = pow(2, 0);
                    sum = sum + add;
                    break;
            }
        }

    }
    
    sum = sum + 65;
    c = c + static_cast<char>(sum);
    return c;
}

/**
 * Finds the exclusive-OR between two strings.
 * 
 * @param one A string representing the plaintext/ciphertext.
 * @param two A string rperesenting the key.
 * @param i A integer representing a position.
 */
string Cipher::exor(string one, string two, int i)
{
    string out = "";

    string pbin = findBinary(this->getPlaintext()[i]);
    string kbin = findBinary(this->getKey()[i]);    

    for (int j = 0; j < pbin.size(); j ++)
    {
        if (pbin[j] == kbin[j])
        {
            out = out + "0";
        }
        else
        {
            out = out + "1";
        }
    }
    
    return out;
}

/**
 * Decrypts the ciphertext using the key.
 * 
 * @return null
 */
void Cipher::decrypt()
{
    string out = "";

    for (int i = 0; i < this->getTable()[0].size(); i ++)
    {
        string temp = "";
        temp = this->exor(this->getPlaintext(), this->getKey(), i);
        out = out + findString(temp);
    }

    this->setCiphertext(out);
    cout << this->getCiphertext();

}

/**
 * Encrypts the plaintext using the pattern.
 * 
 * @return null
 */
void Cipher::encrypt()
{
    string out = "";

    for (int i = 0; i < this->getTable()[0].size(); i ++)
    {    
        string temp = "";
        temp = this->exor(this->getPlaintext(), this->getKey(), i);
        out = out + findString(temp);
    }

    this->setCiphertext(out);
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
    //this->showTable();
}

/**
 * Evaluates the length of the plaintext/ciphertext and the key.
 * 
 * @return null
 */
void Cipher::eval()
{
    if (this->getPlaintext().size() == this->getKey().size())
    {
        stage();
    }
    else
    {
        cout << "Plaintext and key must have similar lengths.." << endl;
        exit(0);
    }
}