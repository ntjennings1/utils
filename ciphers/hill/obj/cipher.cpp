/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Hill cipher.
 * 
 * The Hill cipher is an encryption algorithm that uses
 * polyalphabetic substitution and linear algebra to
 * encrypt/decrypt text.
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
 * Gets the plaintext matrix.
 * 
 * @return ptmat A vector of string vectors representing the plaintext.
 */
vector<vector<string>> Cipher::getPTMat()
{
    return this->ptmat;
}

/**
 * Sets the plaintext matrix.
 * 
 * @param ptmat A vector of string vectors representing the plaintext.
 */
void Cipher::setPTMat(vector<vector<string>>& ptmat)
{
    this->ptmat = ptmat;
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
 * Gets the key matrix.
 * 
 * @return kmat A vector of string vectors representing the key.
 */
vector<vector<string>> Cipher::getKMat()
{
    return this->kmat;
}

/**
 * Sets the key matrix.
 * 
 * @param kmat A vector of string vectors representing the key.
 */
void Cipher::setKMat(vector<vector<string>>& kmat)
{
    this->kmat = kmat;
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
 * @return table A vector of string vectors representing the table.
 */
vector<vector<string>>& Cipher::getTable()
{
    return this->table;
}

/**
 * Sets the cipher table.
 * 
 * @param table A vector of string vectors representing the table.
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

    vector<string> order = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "11", "12", "13", "14", "15", "16",
        "17", "18", "19", "20", "21", "22", "23", "24",
        "25"
    };

    this->addRow(chars);
    this->addRow(order);
}

/**
 * Adds a row to the table.
 * 
 * @param row A string vector representing a row.  
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
 * Matricizes vectors.
 * 
 * @param vec A string vector representing some vector.
 * @param indicator A string representing the type of vector being passed.
 * @return mtemp A vector of string vectors representing a temporary matrix.
 */
vector<vector<string>> Cipher::matricize(vector<string> vec, string indicator)
{
    vector<string> rtemp;
    vector<vector<string>> mtemp;
    double len = sqrt(this->getKey().size());
    int j = 0;

    if (indicator == "k")
    {
        for (int i = 0; i < vec.size(); i ++)
        {
            string temp = "";
            temp = temp + vec[i];

            if (j == len - 1)
            {
                rtemp.push_back(temp);
                mtemp.push_back(rtemp);
                rtemp.clear();
                j = 0;
            }
            else
            {
                rtemp.push_back(temp);

                j = j + 1;
            }
        }
    }
    if (indicator == "p")
    {
        for (int i = 0; i < vec.size(); i ++)
        {
            string temp = "";
            temp = temp + vec[i];

            rtemp.push_back(temp);
            mtemp.push_back(rtemp);
            rtemp.clear();
        }
    }
    
    return mtemp;
}

vector<vector<string>> Cipher::transpose(vector<string>& vec)
{

}

vector<vector<string>> Cipher::identify(vector<string> mat)
{

}

vector<vector<string>> Cipher::invert(vector<string> mat)
{

}

/**
 * Performs matrix multiplication.
 * 
 * @param mat A vector of string vectors representing some matrix.
 * @param vec A string vector representing some vector.
 * @return otemp A vector of string vectors representing a temporary output matrix.
 */
vector<vector<string>> Cipher::mult(vector<vector<string>> mat, vector<vector<string>> vec)
{
    vector<vector<string>> otemp;

    for (int i = 0; i < mat.size(); i ++)
    {
        int sum = 0;
        vector<string> rtemp; 

        for (int j = 0; j < vec.size(); j ++)
        {
            int add = stoi(mat[i][j]) * stoi(vec[j][0]);
            sum = sum + add;
        }
        string temp = "";
        temp = temp + to_string(sum);

        rtemp.push_back(temp);
        otemp.push_back(rtemp);
        rtemp.clear();
    }

    return otemp;
}

void Cipher::decrypt()
{

}

/**
 * Encrypts the plaintext using the key.
 * 
 * @return null
 */
void Cipher::encrypt()
{
    string ctemp = "";
    vector<vector<string>> temp;
    vector<string> otemp;
    string out = "";

    temp = this->mult(this->getKMat(), this->getPTMat());
    
    for (const auto& row : temp){
        for (const auto& el : row){
            otemp.push_back(to_string(stoi(el) % 26));
        }
    }

    for (int i = 0; i < temp.size(); i ++)
    {
        string ctemp = "";
        ctemp = ctemp + otemp[i];

        for (int j = 0; j < this->getTable()[0].size(); j ++)
        {
            if (j == stoi(ctemp))
            {
                string check = "";
                check = check + this->getTable()[0][j];

                out = out + check;
            }

        }
    }

    this->setCiphertext(out);
    cout << this->getCiphertext() << endl;
}

/**
 * Locates characters in the cipher table.
 * 
 * @param indicator A string representing the locating scheme.
 * @return otemp A string vector representing a temporary output vector.
 */
vector<string> Cipher::locate(string indicator)
{
    vector<string> otemp;

    if (indicator == "p")
    {
        for (int i = 0; i < this->getPlaintext().size(); i ++)
        {
            string loc = "";
            string temp = "";
            temp = temp + this->getPlaintext()[i];

            for (int j = 0; j < this->getTable()[0].size(); j ++)
            {
                string check = "";
                check = check + this->getTable()[0][j];

                if (temp == check)
                {
                    loc = loc + this->getTable()[1][j];
                    otemp.push_back(loc);
                }  
            }
        }
    }
    
    if (indicator == "k")
    {
        for (int i = 0; i < this->getKey().size(); i ++)
        {
            string loc = "";
            string temp = "";
            temp = temp + this->getKey()[i];

            for (int j = 0; j < this->getTable()[0].size(); j ++)
            {
                string check = "";
                check = check + this->getTable()[0][j];

                if (temp == check)
                {
                    loc = loc + this->getTable()[1][j];
                    otemp.push_back(loc);
                }  
            }
        }
    }

    return otemp;
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
    
    vector<string> ptemp = this->locate("p");
    vector<string> ktemp = this->locate("k");

    vector<vector<string>> tptemp = this->matricize(ptemp, "p");
    vector<vector<string>> tktemp = this->matricize(ktemp, "k");

    this->setPTMat(tptemp);
    this->setKMat(tktemp);
}

/**
 * Evaluates the cipher key and plaintext.
 * 
 * @return null
 */
void Cipher::eval()
{
    double root = sqrt(this->getKey().size());
    if (root != this->getPlaintext().size())
    {
        cout << "Input length error" << endl;
        exit(0);
    }
    
    string ptemp = ""; 
    ptemp = ptemp + this->getPlaintext();
    transform(ptemp.begin(), ptemp.end(), ptemp.begin(), ::tolower);
    this->setPlaintext(ptemp);
    
    string ktemp = ""; 
    ktemp = ktemp + this->getKey();
    transform(ktemp.begin(), ktemp.end(), ktemp.begin(), ::tolower);
    this->setKey(ktemp);
}