//
//  main.cpp
//  German Adjective Endings
//
//  Created by Aditi Ramaswamy on 10/10/16.
//  Copyright (c) 2016 Aditi Ramaswamy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "Adjektivendungen.h"
using namespace std;


int main(int argc, const char * argv[]) {
    Adjektivendungen adj;
    
    cout << "Wilkommen! This is the Adjective Ending Calculator.\n";
    vector<string> user_sentence = adj.get_sentence();
    
    
    string user_adjective = adj.get_adjective();
    string ending = adj.get_ending();
    
    cout << "\nHere is your sentence: ";

    for (int word_pos = 0; word_pos < user_sentence.size(); word_pos++) {
        if (user_sentence.at(word_pos) == user_adjective) {
            user_sentence.at(word_pos).append(ending);
        }
        cout << user_sentence.at(word_pos) << " ";
    }
    cout << endl;
    
    return 0;
}
