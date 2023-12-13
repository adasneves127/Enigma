#include "rotor.h"
#include <iostream>


rotor::rotor(){
    rotorPosition = 0;
    rotorMapping = new char[26];
}

rotor::~rotor(){
    delete[] rotorMapping;
}

void rotor::setRotor(int rotorNumber){
    switch(rotorNumber){
        case 1:
            setRotorMapping("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
            break;
        case 2:
            setRotorMapping("AJDKSIRUXBLHWTMCQGZNPYFVOE");
            break;
        case 3:
            setRotorMapping("BDFHJLCPRTXVZNYEIWGAKMUSQO");
            break;
        case 4:
            setRotorMapping("ESOVPZJAYQUIRHXLNFTGKDCMWB");
            break;
        case 5:
            setRotorMapping("VZBRGITYUPSDNHLXAWMJQOFECK");
            break;
        default:
            break;
    }
}

int rotor::rotateRotor(){
    rotorPosition++;
    char temp = rotorMapping[0];
    for(int j = 0; j < 25; j++){
        rotorMapping[j] = rotorMapping[j+1];
    }
    rotorMapping[25] = temp;
    if(rotorPosition == 26){
        rotorPosition = 0;
        return 1;
    }
    return 0;
}

int rotor::getRotorPosition(){
    return rotorPosition;
}

char rotor::getRotorForward(char input){
    if(input - 'A' > 25 or input - 'A' < 0) return input;
    return rotorMapping[input - 'A'];
}

char rotor::getRotorBackward(char input){
    for (int i = 0; i < 26; i++){
        if (rotorMapping[i] == input){
            return i + 'A';
        }
    }
    return input;
}

void rotor::setRotorMapping(const char* mapping){
    for(int i = 0; i < 26; i++){
        rotorMapping[i] = mapping[i];
    }
}

int rotor::setRotorPosition(int position){
    int next_rotate = 0;
    while(rotorPosition != position){
        next_rotate += rotateRotor();
    }
    return next_rotate;
}