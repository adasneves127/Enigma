#include "reflector.h"

reflector::reflector(){
    reflectorMapping = new char[26];
}

reflector::~reflector(){
    delete[] reflectorMapping;
}

void reflector::setReflector(char* mapping){
    for(int i = 0; i < 26; i++){
        reflectorMapping[i] = mapping[i];
    }
}

char reflector::getReflectorOutput(char input){
    return reflectorMapping[input - 'A'];
}
