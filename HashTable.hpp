//
//  HashTable.hpp
//  HashTable
//
//  Created by Winnie Jeng on 12/28/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class hash {
    private:
    static const int table_size = 1000;
    
    struct node {
        string first_name;
        string last_name;
        node* next;
    };
    
    // hash table is an array with table size amount of bucket (index)
    // each bucket has a pointer that can point to an item
    node* HashTable[table_size];
    
    
    public:
    
    hash() {
        for (int i = 0; i < table_size; i++) {
            // create new node for each index of hash table
            HashTable[i] = new node;
            // initialize each node
            HashTable[i]->first_name = "empty";
            HashTable[i]->last_name = "empty";
            HashTable[i]->next = nullptr;
        }
    }
    
    // hash function -- convert key string into hash to store inside bucket
    int Hash(string key) {
        int hash = 0;
        int bucket; // index of the HashTable array
        
        for (int i = 0; i < key.length(); i++) {
            hash += (int)key[i];
        }
        
        cout << "hash = " << hash << endl;
        
        bucket = hash % 100;
        
        return bucket;
    }
    
    void addItem(string first_name, string last_name) {
        // bucket hold location in hash table where i can store the name
        // calls hash function to assign it a location
        int bucket = Hash(first_name);
        
        // if hashtable is empty at index bucket, assign the arguements there
        if(HashTable[bucket]->first_name == "empty") {
            HashTable[bucket]->first_name = first_name;
            HashTable[bucket]->last_name = last_name;
        }
        // if hashtable is occupied at index bucket, create linked list chaining
        else {
            node* new_node = new node;
            new_node->first_name = first_name;
            new_node->last_name = last_name;
            new_node->next = nullptr;
            
            // get a walker at the top bucket of the HashTable
            node* walker = HashTable[bucket];
            // traverse walker down the HashTable
            while (walker!=nullptr) {
                walker = walker->next;
            }
            // "chain" the new_node to the end of the linked list
            walker->next = new_node;
        }
        
    }
};


#endif /* HashTable_hpp */
