//
//  main.cpp
//  HashTable
//
//  Created by Winnie Jeng on 12/28/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include "HashTable.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    HashTable h;
    // int index;
    // index = h.Hash("Winnie");
    h.addItem("Hector", "Achilles");
    
    cout << h.countItemsInBucket(2) << endl;
    cout << h.countItemsInBucket(13) << endl;
    h.print();
    
    return 0;
}
