#include "cipher.h"

Cipher::Cipher(string ptext, int rails)
{
    this->ptext = ptext;
    this->rails = rails;
}

string Cipher::getPlaintext()
{
    return this->ptext;
}

void Cipher::setPlaintext(string ptext)
{
    this->ptext = ptext;
}

int Cipher::getRails()
{
    return this->rails;
}

void Cipher::setRails(int rails)
{
    this->rails = rails;
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
    this->addRows();
}

void Cipher::addRows()
{
    for (int i = 0; i < this->getRails(); i ++)
    {
        vector<string> row;

        this->rowInit(row);
        this->addRow(row);

    }
}

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

void Cipher::stage()
{
    this->tableInit();
}

void Cipher::eval()
{
    string str = this->getPlaintext();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    this->setPlaintext(str);
}