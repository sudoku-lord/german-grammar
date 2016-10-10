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
using namespace std;

vector<string> Adjektivendungen::get_sentence() {
    vector<string> sentence_components;
    string sentence;
    int num_words = 1;
    cout << "First, enter your sentence (do not put a space after the last word, and do not press the delete key): ";
    getline(cin, sentence);
    
    for (int ind = 0; ind < sentence.length(); ind++) {
        if (sentence.at(ind) == ' ') {
            num_words++;
        }
    }
    
    istringstream sentence_stream(sentence);
    
    string word;
    for (int count = 0; count < num_words; count++) {
        sentence_stream >> word;
        sentence_components.push_back(word);
    }
    
    return sentence_components;
}

string Adjektivendungen::get_adjective() {
    string adjective;
    
    cout << "\nNow, enter the adjective you wish to find the correct ending for: ";
    cin >> adjective;
    return adjective;
}

vector<string> Adjektivendungen::get_noun_information() {
    vector<string> noun_info;
    string determiner, gender, n_case;
    
    cout << "\nIs a determiner present? (Yes or No): ";
    cin >> determiner;
    noun_info.push_back(determiner);
    
    cout << "\nNoun gender (Fem for feminine, Mas for masculine, Neu for neutral, Plu for plural): ";
    cin >> gender;
    noun_info.push_back(gender);
    
    cout << "\nNoun case (Nom for nominative, Akk for accusative, Dat for dative, Gen for genitive): ";
    cin >> n_case;
    noun_info.push_back(n_case);
    
    return noun_info;
}

string Adjektivendungen::get_ending() {
    string end;
    vector<string> info = get_noun_information();
    
    bool determiner_present = 0;
    if (info.at(0) == "Yes") {
        determiner_present = true;
    } else {
        determiner_present = false;
    }
    
    string given_gender = info.at(1);
    
    int given_case = 0;
    if (info.at(2) == "Nom") {
        given_case = 1;
    } else if (info.at(2) == "Akk") {
        given_case = 2;
    } else if (info.at(2) == "Dat") {
        given_case = 3;
    } else if (info.at(2) == "Gen") {
        given_case = 4;
    }
    
    switch (given_case) {
        case 1:
            if (determiner_present) {
                if (given_gender != "Plu") {
                    end = "e";
                } else {
                    end = "en";
                }
            } else {
                if (given_gender == "Fem" || given_gender == "Plu") {
                    end = "e";
                } else if (given_gender == "Mas") {
                    end = "er";
                } else {
                    end = "es";
                }
            }
            break;
            
        case 2:
            if (determiner_present) {
                if (given_gender == "Fem" || given_gender == "Neu") {
                    end = "e";
                } else {
                    end = "en";
                }
            } else {
                if (given_gender == "Fem" || given_gender == "Plu") {
                    end = "e";
                } else if (given_gender == "Mas") {
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
                if (given_gender == "Mas" || given_gender == "Neu") {
                    end = "em";
                } else if (given_gender == "Fem") {
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
                if (given_gender == "Fem" || given_gender == "Plu") {
                    end = "er";
                } else {
                    end = "en";
                }
            }
            break;
    }
    
    return end;
}

