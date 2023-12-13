#include "reflector.h"

reflector::reflector(){
    reflectorMapping = new char[26];
}

reflector::~reflector(){
    delete[] reflectorMapping;
}

void reflector::setReflector(const char* mapping){
    for(int i = 0; i < 26; i++){
        reflectorMapping[i] = mapping[i];
    }
}

char reflector::getReflectorOutput(char input){
    if(input - 'A' > 25 or input - 'A' < 0) return input;
    return reflectorMapping[input - 'A'];
}
