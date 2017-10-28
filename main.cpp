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
#include <string>
#include "Adjektivendungen.h"
using namespace std;


int main(int argc, const char * argv[]) {
    Adjektivendungen adj;
    
    cout << "Wilkommen! This is the Adjective Ending Calculator.\n";
    cout << "How many sentences do you want to modify? ";
    string num_sentences = "";
    getline(cin, num_sentences);
    int num_sent = stoi(num_sentences);
    for (int i = 0; i < num_sent; ++i) {
        vector<string> user_sentence = adj.get_sentence();
        vector<int> info = adj.get_noun_information();
        
        vector<int> adjectives;
        adj.get_adjective(adjectives, (int) user_sentence.size());
        
        string ending = adj.get_ending(info);
        
        cout << "\nHere is your sentence: ";
        
        
        for (int word_pos = 0; word_pos < adjectives.size(); word_pos++) {
            user_sentence[adjectives[word_pos]] += ending;
        }
        for (int i = 0; i < user_sentence.size(); i++) {
            cout << user_sentence[i] << " ";
        }
        cout << endl;
        cin.clear();
        cin.ignore();
    }
    
    return 0;
}
