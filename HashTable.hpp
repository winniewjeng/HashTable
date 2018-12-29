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
    
    int Hash(string key) {
        int hash = 0;
        int bucket;
        
        for (int i = 0; i < key.length(); i++) {
            
        }
    }
    
};


#endif /* HashTable_hpp */
