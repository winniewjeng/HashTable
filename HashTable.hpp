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

class HashTable {
private:
    static const int table_size = 10;
    
    struct node {
        string first_name;
        string last_name;
        node* next;
    };
    
    // hash table is an array with table size amount of bucket (index)
    // each bucket has a pointer that can point to an item
    node* table[table_size];
    
    
public:
    
    HashTable() {
        for (int i = 0; i < table_size; i++) {
            // create new node for each index of hash table
            table[i] = new node;
            // initialize each node
            table[i]->first_name = "empty";
            table[i]->last_name = "empty";
            table[i]->next = nullptr;
        }
    }
    
    // hash function -- convert key string into hash to store inside bucket
    int Hash(string key) {
        int hash = 0;
        int bucket; // index of the HashTable array
        
        for (int i = 0; i < key.length(); i++) {
            hash += (int)key[i];
        }
        
        //cout << "hash = " << hash << endl;
        
        bucket = hash % 10;
        
//        cout << " bucket = " << bucket << endl;
        
        return bucket;
    }
    
    void addItem(string first_name, string last_name) {
        // bucket hold location in hash table where i can store the name
        // calls hash function to assign it a location
        int bucket = Hash(first_name);
//        cout << last_name << "\n";
//         cout << "b: " <<bucket;
        // if hashtable is empty at index bucket, assign the arguements there
        if(table[bucket]->first_name == "empty") {
            table[bucket]->first_name = first_name;
            table[bucket]->last_name = last_name;
        }
        // if hashtable is occupied at index bucket, create linked list chaining
        else {
            node* new_node = new node;
            new_node->first_name = first_name;
            new_node->last_name = last_name;
            new_node->next = nullptr;
            
            // get a walker at the top bucket of the HashTable
            node* walker = table[bucket];
//            cout << " - Chaining " << last_name << " to " << walker->last_name << endl;
            // traverse walker down the HashTable
            while (walker->next!=nullptr) {
//                cout << walker->last_name << " ";
                walker = walker->next;
            }
            // "chain" the new_node to the end of the linked list
            walker->next = new_node;
        }
    }
    
    int countItemsInBucket(int bucket) {
        
        int count = 0;
        // no item is in bucket
        if (table[bucket]->first_name == "empty") {
            return count;
        }
        // count the number of items chained to bucket
        else {
            node* walker = table[bucket];
            
            while(walker!=nullptr){
                count++;
                walker = walker->next;
            }
        }
        return count;
    }
    
    void print() {
        int chainedNums;
        
        for (int i = 0; i < table_size; i ++) {
            chainedNums = countItemsInBucket(i);
            cout << i << ". ";
            //cout << chainedNums << endl;
            if (chainedNums != 1 && chainedNums != 0) {
//                cout << "django chained\n";
                node* walker = table[i];
                while(walker != nullptr) {
                    cout << walker->first_name << " " << walker->last_name << ", ";
                    walker = walker->next;
                }
            } else {
                cout << table[i]->first_name << " " << table[i]->last_name;
            }
            cout << endl;
        }
    }
};

#endif /* HashTable_hpp */
