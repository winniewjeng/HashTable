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
    
    h.addItem("Issac", "Newton");
    h.addItem("Georgiana", "Kleege");
    h.addItem("Andrew", "Jackson");
    h.addItem("Alexander", "Hamilton");
    h.addItem("Christopher", "Columbus");
    h.addItem("Elizabeth", "Bennet");
    h.addItem("Aaron", "Burr");
    h.addItem("Angelica", "Schulyer");
    h.addItem("Daveed", "Diggs");
    h.addItem("Percy", "Jackson");
    h.addItem("Agustus", "Waters");
    h.addItem("Sherlock", "Holmes");
    h.addItem("John", "Green");
    h.addItem("Jude", "Socrates");
    h.addItem("Forrest", "Gump");
    h.addItem("James", "Madison");
    h.addItem("Harry", "Potter");
    h.addItem("Benjamin", "Button");
    h.addItem("Ryan", "Reynold");
    h.addItem("Francis", "Nolan");
    h.addItem("Gon", "Freecss");
    h.addItem("Ariel", "Lin");
    h.addItem("Hilary", "Duff");
    h.addItem("Winnie", "Jeng");
    h.addItem("Brian", "Kennedy");
    h.addItem("Emma", "Watson");
    h.addItem("Neil", "Armstrong");
    

//    cout << h.countItemsInBucket(2) << endl;
//    cout << h.countItemsInBucket(4) << endl;
    h.print();
    
    return 0;
}
