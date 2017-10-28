//
//  Adjektivendungen.cpp
//  German Adjective Endings
//
//  Created by Aditi Ramaswamy on 10/10/16.
//  Copyright (c) 2016 Aditi Ramaswamy. All rights reserved.
//

#include "Adjektivendungen.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

vector<string> Adjektivendungen::get_sentence() {
    vector<string> sentence_components;
    string sentence;
    int num_words = 1;
    cout << "First, enter your sentence (do not put a space after the last word, and do not press the delete key): ";
    getline(cin, sentence);
    
    // calculates number of words in sentence
    for (int ind = 0; ind < sentence.length(); ind++) {
        if (sentence.at(ind) == ' ') {
            num_words++;
        }
    }
    
    // breaks sentence into individual components
    istringstream sentence_stream(sentence);
    string word;
    for (int count = 0; count < num_words; count++) {
        sentence_stream >> word;
        sentence_components.push_back(word);
    }
    
    return sentence_components;
}

void Adjektivendungen::get_adjective(vector<int> &adjectives, int sent_length) {
    assert(sent_length > 0);
    int adj_index = 0;
    cout << "\nNow, enter the number of  adjectives you wish to modify: ";
    int num_adj = 0;
    cin >> num_adj;
    cout << "\nNow, enter the positions of the adjectives you wish to find the correct endings for (using 0-indexing): ";
    for (int ind = 0; ind < num_adj; ind++) {
        cin >> adj_index;
        assert(adj_index <= sent_length - 1);
        adjectives.push_back(adj_index);
    }
}

vector<int> Adjektivendungen::get_noun_information() {
    vector<int> noun_info;
    int determiner, gender, n_case;
    
    // checks for presence of der, das, die, etc
    cout << "\nIs a determiner present? (1 is Yes and 0 is No): ";
    cin >> determiner;
    noun_info.push_back(determiner);
    
    // gender of noun will influence its ending
    cout << "\nNoun gender (1 for feminine, 2 for masculine, 3 for neutral, 4 for plural): ";
    cin >> gender;
    noun_info.push_back(gender);
    
    // case of noun will influence its ending
    cout << "\nNoun case (1 for nominative, 2 for accusative, 3 for dative, 4 for genitive): ";
    cin >> n_case;
    noun_info.push_back(n_case);
    
    return noun_info;
}

string Adjektivendungen::get_ending(vector<int> &info) {
    assert(info.size() == 3);
    string end;
    
    // uses information from get_noun_information to determine ending
    
    bool determiner_present = 0;
    if (info[0] == 1) {
        determiner_present = true;
    } else {
        determiner_present = false;
    }
    
    int given_gender = info[1];
    
    int given_case = info[2];
    
    // clean up efficiency
    switch (given_case) {
        case 1:
            if (determiner_present) {
                if (given_gender != 4) {
                    end = "e";
                } else {
                    end = "en";
                }
            } else {
                if (given_gender == 1 || given_gender == 4) {
                    end = "e";
                } else if (given_gender == 2) {
                    end = "er";
                } else {
                    end = "es";
                }
            }
            break;
            
        case 2:
            if (determiner_present) {
                if (given_gender == 1 || given_gender == 3) {
                    end = "e";
                } else {
                    end = "en";
                }
            } else {
                if (given_gender == 1 || given_gender == 4) {
                    end = "e";
                } else if (given_gender == 2) {
                    end = "en";
                } else {
                    end = "es";
                }
            }
            break;
            
        case 3:
            if (determiner_present) {
                end = "en";
            } else {
                if (given_gender == 2 || given_gender == 3) {
                    end = "em";
                } else if (given_gender == 1) {
                    end = "er";
                } else {
                    end = "en";
                }
            }
            break;
            
        case 4:
            if (determiner_present) {
                end = "en";
            } else {
                if (given_gender == 1 || given_gender == 4) {
                    end = "er";
                } else {
                    end = "en";
                }
            }
            break;
    }
    return end;
}
