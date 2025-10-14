/**
 * All imports.
 */
#include "cipher.h"

/**
 * Implementation of a Transposition cipher. 
 * 
 * This Transposition cipher is an algorithm that uses 
 * permutation and order to encrypt/decrypt text. 
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
    return this->key; 
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
    return this->ptext;
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
    return this->ctext;
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
    return this->table; 
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
 * Gets the number of rows.
 * 
 * @return rows The number of expected rows. 
 */
int Cipher::getRows(){
    return this->rows;
}

/**
 * Sets the number of rows.
 * 
 * @param rows The number of expected rows. 
 */
void Cipher::setRows(int rows){
    this->rows = rows;
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
 * 
 * @return null
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
 * Shows a specified row.
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
 * Puts the key into the table.
 * 
 * @return null
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
 * Puts the plaintext into the table.
 * 
 * @return null
 */
void Cipher::addPlaintext(){

    int i = 0; 
    int id = 0; 
    vector<string> row; 
    string temp = this->getPlaintext(); 
    int len = this->getKey().length();

    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
    
    for (const auto& element : temp){
        string el(1, element);
        if (i == (len - 1)){
            row.push_back(el);
            this->addRow(row);
            row.clear();
            i = 0;
        }
        else{
            row.push_back(el);
            i = i + 1;
        } 
        id = id + 1; 
    }

    if (row.size() == len){
        this->addRow(row);
    }
    if (id != temp.length() || row.size() > 0){
        while (row.size() < this->getKey().length()){
            row.push_back("*");
        }
        this->addRow(row);
    }
}

/**
 * Adds a row to the table.
 * 
 * @param row A string vector.  
 */
void Cipher::addRow(vector <string>& row){
    table.push_back(row); 
}

/**
 * Finds the order of characters in the key.
 * 
 * @return null
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
    this->addRow(row);
}

/**
 * Split the ciphertext into blocks.
 * 
 * @return null
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
        if (this->getCiphertext()[index] == '*'){
            i = i - 1;
        }
        temp = temp + this->getCiphertext()[index];
        index = index + 1;
        i = i + 1;
    }

    this->setCiphertext(temp); 
    cout << this->getCiphertext() << endl;

}

/**
 * Creates a temporary table. 
 * 
 * @return temp_table A temporary vector of string vectors.
 */
vector<vector<string>> Cipher::tempSetup(){

    string temp = this->getPlaintext(); 
    int len = this->getKey().length();
    vector<vector<string>> temp_table;

    temp_table.push_back(this->getTable()[0]);
    temp_table.push_back(this->getTable()[1]);

    vector<string> orow; 
    this->rowInit(len, orow);
    for (int ord = 1; ord <= len; ord++){
        orow[ord-1] = to_string(ord); 
    }
    temp_table.push_back(orow);

    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
    this->setRows(temp.length() / this->getKey().length());
    for (int i = 0; i < this->getRows(); i++){
        vector<string> row; 
        this->rowInit(len, row);
        temp_table.push_back(row); 
    }

    return temp_table;
}

/**
 * Transposes the ciphertext in the cipher table.
 * 
 * @return null
 */
void Cipher::transpose(){
    
    int id = 0; 
    int cid = 0; 
    string temp = this->getPlaintext(); 
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());

    vector<vector<string>> temp_table;
    temp_table = tempSetup();
       
    for (int j = 0; j < temp.length(); j++){
        if (id == this->getRows()){
            cid = cid + 1; 
            id = 0; 
        }
        temp_table[id+3][cid] = temp[j];
        id = id + 1; 
    }

    this->setTable(temp_table);       
}

/**
 * Decrypts the ciphertext using the key.
 * 
 * @return null
 */
void Cipher::decrypt(){

    string temp ="";
    vector <vector <string>> temp_table;
    temp_table = this->getTable(); 

    for (int i=0; i < this->getKey().length(); i++){

        int row = 0;
        int col = 0; 
        string el = this->getTable()[2][i]; 
        
        for (int j=0; j <this->getKey().length(); j++){
            
            string elem = this->getTable()[1][j];

            if (el == elem){
                temp_table[2][col] = "0";
                while (row < this->getRows()){
                    temp_table[row+3][col] = this->getTable()[row+3][i];
                    row = row + 1; 
                }
                row = 0;
                col = 0;
            }
            else{
                col = col + 1;
            }
        }
    }

    this->setTable(temp_table);
    
    for (int r = 0; r < this->getTable().size(); r++){
        if (r > 2){
            for (int l = 0; l < this->getKey().length(); l++){
                temp.append(this->getTable()[r][l]);
            }
        }
    }

    this->setCiphertext(temp);
    cout << this->getCiphertext() << endl;
}

/**
 * Encrypts the plaintext using the key.
 * 
 * @return null
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
                temp.append(this->getTable()[row][col]); 
            }
            row = 2; 
            col = 0; 
            id = id + 1;
        }
        else{
            col = col + 1;
        }
    }
    
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    //temp.erase(remove(temp.begin(), temp.end(), '*'), temp.end());
    this->setCiphertext(temp); 

    this->blockify();

}

/**
 * Stages the cipher table.
 * 
 * @return null
 */
void Cipher::stage(){

    this->addKey();
    this->order();
    this->addPlaintext();
    //this->showTable();
}

/**
 * Evaluates the cipher key and plaintext.
 * 
 * @return null
 */
void Cipher::eval()
{
    ;
}