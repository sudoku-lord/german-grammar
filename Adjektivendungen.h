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
    std::vector<std::string> get_sentence();
    std::string get_adjective();
    std::vector<std::string> get_noun_information();
    std::string get_ending();
    
};
