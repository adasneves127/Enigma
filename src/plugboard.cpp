#include "plugboard.h"

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


char* plugboard::getPlugboard(){
    std::string returnString = "";
    for(int i = 0; i < 26; i++){
        char x = this->plugboardMapping[i];
        char y = i + 'A';
        if(x != ' '){ 
            returnString.push_back(y);
            returnString.push_back(x);
            returnString.push_back('\n');
        }
    }

    if(returnString.length() == 0){
        returnString = "(none)\n";
    }
    return (char*)returnString.c_str();
}