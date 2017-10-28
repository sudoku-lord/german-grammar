//
//  Adjektivendungen.h
//  German Adjective Endings
//
//  Created by Aditi Ramaswamy on 10/10/16.
//  Copyright (c) 2016 Aditi Ramaswamy. All rights reserved.
//

#ifndef __German_Adjective_Endings__Adjektivendungen__
#define __German_Adjective_Endings__Adjektivendungen__

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#endif /* defined(__German_Adjective_Endings__Adjektivendungen__) */

class Adjektivendungen {
public:
    // reads in sentence with adjectives which need to be modified
    std::vector<std::string> get_sentence();
    // gets adjective to be modified
    void get_adjective(std::vector<int> &adjectives, int sent_length);
    // gets case and gender of noun, finds out whether there is a determiner
    std::vector<int> get_noun_information();
    // modifies adjective
    std::string get_ending(std::vector<int> &info);
    
};
