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
    // Return a char* of plugboard pairs
    std::string plugPairs;
    for(int i = 0; i < 26; i++){
        bool inPairs = false;
        if(plugboardMapping[i] == ' ') continue;
        for(int j = 0; j < plugPairs.length(); j++){
            if(plugboardMapping[i] == plugPairs[j]) 
                inPairs = true;
        }
        if(inPairs) continue;
        std::cout << (char)(i + 'A') << " " << plugboardMapping[i] << std::endl;
        plugPairs.push_back('\t');
        plugPairs.push_back((char)(i + 'A'));
        plugPairs.push_back(plugboardMapping[i]);
        plugPairs.push_back('\n');
    }
    if(plugPairs.length() == 0) return (char*) "(No Plugs Set)\n";
    return (char*)plugPairs.c_str();
}