#include <iostream>
#include <string>
#include "rotor.h"

int main(){
    std::string s = "Hello World";
    rotor* r[3];
    r[0] = new rotor();
    r[1] = new rotor();
    r[2] = new rotor();

    // Set the rotors. Ask the user for the rotor number.
    int rotorNumber;
    std::cout << "Enter the first rotor number: ";
    std::cin >> rotorNumber;
    r[0]->setRotor(rotorNumber);

    std::cout << "Enter the second rotor number: ";
    std::cin >> rotorNumber;
    r[1]->setRotor(rotorNumber);

    std::cout << "Enter the third rotor number: ";
    std::cin >> rotorNumber;
    r[2]->setRotor(rotorNumber);

    // Set the rotor positions. Ask the user for the rotor positions.
    int rotorPosition;
    std::cout << "Enter the first rotor position: ";
    std::cin >> rotorPosition;
    r[0]->setRotorPosition(rotorPosition % 26);

    std::cout << "Enter the second rotor position: ";
    std::cin >> rotorPosition;
    r[0]->setRotorPosition(rotorPosition % 26);

    std::cout << "Enter the third rotor position: ";
    std::cin >> rotorPosition;
    r[0]->setRotorPosition(rotorPosition % 26);

    // Set the plugboard. Ask the user for the plugboard mapping.
    // Plugboard pairs are separated by a space. For example, "AB CD EF".
    std::string plugboardMapping;
    std::cout << "Enter the plugboard mapping (Ex. AB CD EF): ";
    std::cin >> plugboardMapping;
    char plugboardMappingArray[26];
    for(int i = 0; i < 26; i++){
        char x = plugboardMapping[i];
        if(x == ' '){
            continue;
        }
        plugboardMappingArray[x - 'A'] = plugboardMapping[i+1];
        plugboardMappingArray[plugboardMapping[i+1] - 'A'] = plugboardMapping[i];
    }

}