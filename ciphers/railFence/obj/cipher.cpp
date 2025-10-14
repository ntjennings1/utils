/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the Railfence cipher. 
 * 
 * The Railfence cipher is an algorithm that uses
 * transposition to encrypt/decrypt text.
 * 
 */
Cipher::Cipher(string ptext, int rails)
{
    this->ptext = ptext;
    this->rails = rails;
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
 * Gets the number of rails.
 * 
 * @return rails A integer representing the number of rails.
 */
int Cipher::getRails()
{
    return this->rails;
}

/**
 * Sets the number of rails.
 * 
 * @param rails A integer representing the number of rails.
 */
void Cipher::setRails(int rails)
{
    this->rails = rails;
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
    for (int i = 0; i < this->getRails(); i ++)
    {
        vector<string> row;

        this->rowInit(row);
        this->addRow(row);

    }
}

/**
 * Adds a row to the table.
 * 
 * @param row A string vector.  
 */
void Cipher::rowInit(vector<string>& row)
{
    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        row.push_back("-");
    }
}

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
    for (const auto& row : this->getTable())
    {
        for (const auto& el : row)
        {
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

    class Group{
        public:
            int visits = 0;
            vector<string> group;

            Group()
            {
                ;
            }

            int getVisits()
            {
                return visits;
            }

            void setVisits(int v)
            {
                visits = v;
            }

            vector<string>& getGroup()
            {
                return group;
            }

            void clear()
            {
                group.clear();
            }

            void add(string str)
            {
                group.push_back(str);
            }

            void show()
            {
                for (const auto& el : group)
                {
                    cout << el << " ";
                }

                cout << endl;
            }
        
    };

    int v = 0;
    Group group;
    vector<Group> groups;
    
    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string ctemp = "";
        ctemp = ctemp + this->getPlaintext()[i]; 

        if (ctemp == " ")
        {
            groups.push_back(group);
            group.clear();
        }
        else
        {
            group.add(ctemp);
        }
    }
    groups.push_back(group);

    int j = 0;
    int change = 0;
    string temp = "";

    this->eval();

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {        
        if (change == 0)
        {
            if (j == this->getRails() - 1)
            {
                change = change + 1;
                temp = temp + groups[j].getGroup()[groups[j].getVisits()]; //<< endl;
                groups[j].setVisits(groups[j].getVisits() + 1);
                j = j - 1;
            }
            else
            {
                temp = temp + groups[j].getGroup()[groups[j].getVisits()]; // << endl;
                groups[j].setVisits(groups[j].getVisits() + 1);
                j = j + 1;
            }
        }
        else
        {
            if (j == 0)
            {
                change = change - 1;
                temp = temp + groups[j].getGroup()[groups[j].getVisits()]; //<< endl;
                groups[j].setVisits(groups[j].getVisits() + 1);
                j = j + 1;
            }
            else
            {
                temp = temp + groups[j].getGroup()[groups[j].getVisits()]; //<< endl;
                groups[j].setVisits(groups[j].getVisits() + 1);
                j = j - 1;
            }
        }
    } 
    cout << temp << endl;
}

/**
 * Encrypts the plaintext using the key.
 * 
 * @return null
 */
void Cipher::encrypt()
{
    int j = 0;
    int change = 0;

    for (int i = 0; i < this->getPlaintext().size(); i ++)
    {
        string temp = "";
        temp = temp + this->getPlaintext()[i];

        if (change == 0)
        {
            if (j == this->getRails() - 1)
            {
                change = change + 1;
                this->getTable()[j][i] = temp;
                j = j - 1;
            }
            else
            {
                this->getTable()[j][i] = temp;
                j = j + 1;
            }         
            
        }
        else
        {
            if (j == 0)
            {
                change = change - 1;
                this->getTable()[j][i] = temp;   
                j = j + 1;
            }
            else
            {
                this->getTable()[j][i] = temp;
                j = j - 1;
            }

        }
        
    }

    for (int i = 0; i < this->getRails(); i ++)
    {
        for (int j = 0; j < this->getTable()[i].size(); j ++)
        {
            if (this->getTable()[i][j] != "-")
            {
                this->setCiphertext(this->getCiphertext() + this->getTable()[i][j]);
            }
        }
        this->setCiphertext(this->getCiphertext() + " ");
    }

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
    string str = this->getPlaintext();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    this->setPlaintext(str);
}