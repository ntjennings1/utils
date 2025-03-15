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

vector<vector<string>> Cipher::getTable()
{
    return this->table;
}

void Cipher::setTable(vector<vector<string>>& table)
{
    this->table = table;
}

string Cipher::getCiphertext()
{
    return this->ctext;
}

void Cipher::setCiphertext(string ctext)
{
    this->ctext = ctext;
}

void Cipher::addRow(vector<string>& row)
{
    table.push_back(row);
}

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

void Cipher::showTable()
{
    for (const auto& row : this->getTable()){
        for (const auto& el : row){
            cout << el << " " ;
        }
        cout << endl;
    }
}

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
    cout << "Char: " << input << endl;
    cout << "Binary: " << out << endl;
    return out;

}

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

    cout << sum << endl;
    //if (sum >= 26)
    //{
    //    sum = sum - 26;
    //}
    
    sum = sum + 65;
    c = c + static_cast<char>(sum);
    cout << "Character: " << c << endl;
    return c;
}

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
    
    cout << "XOR: " << out << endl << endl;
    return out;
}

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

void Cipher::stage()
{
    this->tableInit();
    //this->showTable();
}

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