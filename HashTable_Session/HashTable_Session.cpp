// HashTable_Session.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "LinkedList.h"


// hash table class that consit of instering and deleting items 
class HashTable {

public:
    int bucket;
    std::vector<int> table;
    HashTable();
    HashTable(int value);
    void insertItem(int key);
    void deletItem(int key);
    int hashFunction(int x) const;
    void displayHash();
    std::vector<SingleLinkedList<int>> bucketlist;
};

HashTable::HashTable():bucket(0)
{
}

HashTable::HashTable(int value) :bucket(1) , bucketlist(value)
{
    this->bucket = value;
    std::vector<int> table(bucket);
   // std::vector<SingleLinkedList<int>> mylist(value);

}

void HashTable::insertItem(int key)
{
    int index = hashFunction(key);
    std::cout << " index : " << index << "Key : " << key << std::endl;
    bucketlist[index].add(key);
   
 
}

void HashTable::deletItem(int key)
{

    // classroom task , you finish this part

}

int HashTable::hashFunction(int x) const
{
    int ret = x % bucket;
    return (ret);
}

void HashTable::displayHash()
{
    for (int i = 0; i < bucket; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < bucket; i++) {
        std::cout << "i : "  << i <<  std::endl;
        bucketlist[i].printData();
    }
}


int main()
{
    int keys[] = { 15, 11, 27, 8, 12, 20 , 30, 22, 25, 102, 155, 25, 14 }; // want to add these elements to hash tabele // if there are strings or other types
    //then hash function needs to chnage and be more dynamic // 

    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable h(7);   // 7 is count of buckets in // i want to have a bucket of this size, this can change if you have larger dataset 

    for (int i = 0; i < n; i++)
        h.insertItem(keys[i]);

    // display the Hash table
    h.displayHash();
    

    return 0;
}