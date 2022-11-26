#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Author : Carlos Ravago
//
// Due Date : 11/28/2022
//
// Programming Assignment Number 7
//
// Fall 2022 - CS 3358 - 07
//
// Instructor: Husain Gholoom.
//
// Creates and manipulates a string hash table from a text file via
// insert, search, and delete functions

class hashTable{
    private:
    int hash_pos;
    string stringArr[27];
    public:
    hashTable();
    void insert(string );
    void makeArr(string );
    void search(string );
    int Hash(string );
    int reHash(int );
    void Delete(string );
    void Display();
};

int main()
{
    hashTable hTable;
    string readText;
    ifstream fileRead("Word.txt");

    cout << "Hashing Program\n\n";
    cout << "------------------------------\n\n";

    cout << "A. Creates a string array of size 27. Assigning - to each\n";
    cout << "   location in the array indicating that the array is empty.\n";
    cout << "B. Populates 26 elements of the array with words\n";
    cout << "C. If a collision occurs, linear probing will find the next\n";
    cout << "   available position / location.\n";
    cout << "D. The generated array will be displayed in 7 lines.\n";
    cout << "   Each line contains 4 words separated by a tab spaces.\n\n";

    cout << "The Generated Array.\n";

    while(getline(fileRead, readText)){
        hTable.makeArr(readText);
    }

    hTable.Display();

    cout << "\n\n\n";

    cout << "Searching for a word ( Zulu ) in the table.\n";
    hTable.search("Zulu");

    cout << "Searching for a word ( Hulu ) in the table.\n";
    hTable.search("Hulu");

    cout << "Inserting a New word ( Mayday ) in the table.\n";
    hTable.insert("Mayday");

    cout << "Inserting a New word ( Bonanza ) in the table.\n";
    hTable.insert("Bonanza");

    cout << "\n\n\nThe Table After the words were inserted:\n\n";
    hTable.Display();

    cout << "\n\n\nDelete the word ( Zulu ) from the table.\n";
    hTable.Delete("Zulu");

    cout << "\n\nDelete the word name ( Delta ) from the table.\n";
    hTable.Delete("Delta");

    cout << "\n\nDelete the word name ( Bonanza ) from the table.\n";
    hTable.Delete("Bonanza");

    cout << "\n\n\nThe Table After 2 word was deleted:\n\n";
    hTable.Display();

    cout << "\n\n\n\nThis hashing program was implemented by\n";
    cout << "Carlos Ravago\n";
    cout << "11-21-2022";


    fileRead.close();
    return 0;
}

hashTable::hashTable(){
    //Initializes the array
    for(int i = 0; i < 27; i++){
        stringArr[i] = "-";
    }
}

//Fill the array so that the insert function can work independently
//If there was only one function to insert the 26 elements first
//then the program will display 26 messages meant for ops D and E
void hashTable::makeArr(string input){
    int count = 0;
    hash_pos = Hash(input); //Ex: Alpha has a hash position of 5
    if(hash_pos >= 27){
        hash_pos = 0;
    }
    while(stringArr[hash_pos] != "-"){
            hash_pos = reHash(hash_pos);
            if(hash_pos >= 27){
                hash_pos = 0;
            }
            count++;
            if(count >= 27){
                cout << "The word" << input << " was not inserted. ";
                cout << "Table is Full.\n";
                break;
            }
    }

    if(stringArr[hash_pos] == "-"){
        stringArr[hash_pos] = input;
    }
}
//Looks for an empty slot in the array.
//Keeps rehashing the hashing position until it finds an empty space denoting -
void hashTable::insert(string input){
    int count = 0;
    hash_pos = Hash(input); //Ex: Alpha has a hash position of 5
    if(hash_pos >= 27){
        hash_pos = 0;
    }
    while(stringArr[hash_pos] != "-"){
            hash_pos = reHash(hash_pos);
            if(hash_pos >= 27){ //If the reHash is over 27, then set hash_pos = 0
                hash_pos = 0;
            }
            count++;
            if(count >= 27){
                cout << "The word ( " << input << " ) was not inserted. ";
                cout << "Table is Full.\n";
                break;
            }
    }

    if(stringArr[hash_pos] == "-"){
        stringArr[hash_pos] = input;
        cout << "The word ( " << input << " ) is inserted in location ";
        cout << hash_pos << endl << endl;
    }
}

//Uses the hashing and rehashing functions to traverse the array to find the
//targeted element
void hashTable::search(string target){
    int linearProbing = 0;
    hash_pos= Hash(target);
    if(hash_pos >= 27){
        hash_pos = 0;
    }
    while(stringArr[hash_pos] != target){
        hash_pos = reHash(hash_pos);
        if(hash_pos >= 27){
            hash_pos = 0;
        }
        linearProbing++;
        if(linearProbing >= 27){
            cout << "The word ( " << target << " ) was not found in the table";
            cout << "\n\n";
            break;
        }
    }

    if(stringArr[hash_pos] == target){
        cout << "The word ( " << target << " ) was found in location ";
        cout << hash_pos << endl << endl;
    }

    cout << "The number of linear probes when each number is hashed and ";
    cout << "collision occurred when searching for the\n";
    cout << "word ( " << target << " ) in the array is " << linearProbing << "\n\n";
}
//Uses the hashing and rehashing functions to find and delete the targeted
//element
void hashTable::Delete(string target){
    int linearProbing = 0;
    hash_pos = Hash(target);
    if(hash_pos >= 27){
        hash_pos = 0;
    }
    while(stringArr[hash_pos] != target){
        hash_pos = reHash(hash_pos);
        if(hash_pos >= 27){
            hash_pos = 0;
        }
        linearProbing++;
        if(linearProbing >= 27){
            cout << "The word ( " << target << " ) is not found";
            cout << "\n\n";
            break;
        }
    }

    if(stringArr[hash_pos] == target){
        stringArr[hash_pos] = "-";
        cout << "The word ( " << target << " ) is deleted\n\n";
    }

    cout << "The number of linear probes when each number is hashed and ";
    cout << "collision occurred when deleting for the\n";
    cout << "word ( " << target << " ) in the array is " << linearProbing << "\n\n";
}

int hashTable::Hash(string key){
    return key.length(); //Returns the length of the string as a hashed index
}

int hashTable::reHash(int key){
    return key+1; //Returns the current hashing position + 1
}

void hashTable::Display(){
    int rows = 7;
    int colms = 4;
    //Displays the array as a table
    for(int row = 0; row < rows; row++){
        for(int colm = 0; colm < colms; colm++){
            cout << stringArr[row*colms+colm] << "\t";
        }
        cout << "\n";
    }
}

