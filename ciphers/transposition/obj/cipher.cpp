/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of the transposition cipher. 
 * 
 * The transposition cipher is an encryption algorithm that uses 
 * permutation and order to encrypt plaintext to ciphertext. 
 * 
 */
Cipher::Cipher(string key, string ptext)
{
    this->key = key;
    this->ptext = ptext;  
}

/**
 * Gets the cipher key.
 * 
 * @return key A string representing the cipher key. 
 */
string Cipher::getKey(){
    return key; 
}

/**
 * Sets the cipher key.
 * 
 * @param key A string representing the cipher key.
 */
void Cipher::setKey(string key){
    this->key = key;
}

/**
 * Gets the plaintext.
 * 
 * @return ptext A string representing the plaintext.
 */
string Cipher::getPlaintext(){
    return ptext;
}

/**
 * Sets the plaintext.
 * 
 * @param ptext A string representing the plaintext.
 */
void Cipher::setPlaintext(string ptext){
    this->ptext = ptext;
}

/**
 * Gets the ciphertext.
 * 
 * @return ctext A string representing the ciphertext.
 */
string Cipher::getCiphertext(){
    return ctext;
}

/**
 * Sets the ciphertext.
 * 
 * @param ctext A string representing the ciphertext.
 */
void Cipher::setCiphertext(string ctext){
    this->ctext = ctext; 
}

/**
 * Gets the cipher table.
 * 
 * @return table A vector of string vectors describing the cipher table.
 */
vector<vector<string>> Cipher::getTable(){
    return table; 
}

/**
 * Sets the cipher table.
 * 
 * @param table A vector of string vectors with plaintext.
 */
void Cipher::setTable(vector<vector<string>>& table){
    this->table = table; 
}

/**
 * Initializes a row.
 * 
 * @param len An integer describing the length of the table.
 * @param row A string vector with plaintext.
 */
void Cipher::rowInit(int len, vector<string>& row){
    int i = 0;
    for (i; i < len; i ++){
        row.push_back("-");
    }
}

/**
 * Shows the cipher table.
 */
void Cipher::showTable(){

    cout << endl;
    for (const auto& row : this->getTable()){
        for (const auto& el : row){
            cout << el << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Show a specified row.
 * 
 * @param row A string vector with plaintext.
 */
void Cipher::showRow(vector<string>& row){

    for (const auto& el : row){
        cout << el << " ";
    }
    cout << endl;
}

/**
 * Put the key into the table.
 */
void Cipher::addKey(){

    vector<string> row;

    for(const auto& element : this->getKey()){
        string el (1, element);
        row.push_back(el);
    }

    this->addRow(row); 
}

/**
 * Put the plaintext into the table.
 */
void Cipher::addPlaintext(){

    int i = 0; 
    vector<string> row; 
    string temp = this->getPlaintext(); 

    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
    cout << temp << endl;; 

    for (const auto& element : temp){
        string el(1, element);
        if (i == (this->getKey().length() - 1)){
            row.push_back(el);
            this->addRow(row);
            row.clear();
            i = 0;
        }
        else{
            row.push_back(el);
            i = i+1;
        } 
    }

    if (row.size() == this->getKey().length()){
        this->addRow(row);
    }
    else{
        while (row.size() < this->getKey().length()){
            row.push_back("*");
        }
        this->addRow(row);
    }
}

/**
 * Add a row to the table.
 * 
 * @param row A vector of string vectors.  
 */
void Cipher::addRow(vector <string>& row){
    table.push_back(row); 
}

/**
 * Find the order of characters in the key.
 */
void Cipher::order(){
  
    vector<string> row; 
    string temp1 = this->getKey();
    string temp2 = this->getKey();
    int len = this->getKey().length(); 
    int col = 0;
    int i = 0;
    int index = 0;
    int id = 1;
    
    sort(temp1.begin(), temp1.end());
    this->rowInit(len, row);

    for (col; col < len; col++){
        for (i; i < len; i++){
            if (temp1[col] == temp2[i]){
                temp2[i] = '-';
                row[i] = to_string(id);
                id = id + 1;
                break;
            }
        }
        i = 0;
    }
    cout << endl;
    this->addRow(row);
}

/**
 * Split the ciphertext into blocks.
 */
void Cipher::blockify(){
    int i = 0;
    int index = 0;
    int len = 5; 
    string temp = "";
    
    while (index < this->getCiphertext().length()){

        if (i == len){
            temp.append(" "); 
            i = 0; 
        }
        temp = temp + this->getCiphertext()[index];
        index = index + 1;
        i = i + 1;
    }

    this->setCiphertext(temp); 
    cout << this->getCiphertext() << endl;

}

/**
 * Encrypt the plaintext using the key.
 */
void Cipher::encrypt(){
    int id = 1; 
    int col = 0;
    int row = 2; 
    int len = this->getKey().length();
    int depth = this->getTable().size();
    string temp = " ";

    while (col < len){
        if (this->getTable()[1][col] == to_string(id)){
            for (row; row < depth; row++){
                //cout << this->getTable()[row][col] << " "; 
                temp.append(this->getTable()[row][col]); 
            }
            //sleep(1);
            row = 2; 
            col = 0; 
            id = id + 1;
        }
        else{
            col = col + 1;
        }
    }
    
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '*'), temp.end());
    this->setCiphertext(temp); 

    this->blockify();

    cout << "Plaintext encrypted" << endl;
}

/**
 * Stage the cipher table.
 */
void Cipher::stage(){

    this->addKey();
    this->order();
    this->addPlaintext();
    this->showTable();
}

/**
 * Provide a short description of the cipher being used.
 */
void Cipher::describe(){
    cout << "Description:\n";
    cout << "This is the tranposition cipher method.\n";
    cout << "For this iteration we will use the key:\n" + this->getKey() + "\n";
    cout << "To encrypt this plaintext:\n" + this->getPlaintext() + "\n";
    cout << "";
    cout << "";
}