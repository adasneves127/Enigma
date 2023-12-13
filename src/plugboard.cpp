#include "plugboard.h"
#include <iostream>

plugboard::plugboard(){
    plugboardMapping = new char[26];
}

plugboard::~plugboard(){
    delete[] plugboardMapping;
}

void plugboard::setPlugboard(const char* mapping){
    for(int i = 0; i < 26; i++){
        plugboardMapping[i] = mapping[i];
    }
}

char plugboard::getPlugboardOutput(char input){
    if(input - 'A' > 25 or input - 'A' < 0) return input;
    if(plugboardMapping[input - 'A'] == ' ') return input;
    return plugboardMapping[input - 'A'];
}
