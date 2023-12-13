#include <iostream>
#include <string>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

rotor* r[3];
reflector* reflect;
plugboard* plugs;

const char* reflectorMap = "ZXJKMQRPUCDVEYWHFGTSILOBNA";


void setUpRotors();
void setRotations();
void setPlugs();
std::string sendPlugs(std::string s);
void printMsg(std::string s);

int main(){
    // Set up the rotors
    setUpRotors();

    // Set up the reflector
    reflect = new reflector();
    reflect->setReflector(reflectorMap);

    // Set up the plugboard
    plugs = new plugboard();
    setPlugs();

    // Get the message to encrypt
    std::string message;
    char messageBuf[100];
    std::cout << "Enter the message to encrypt: ";
    std::cin.getline( messageBuf, 100 );
    message = messageBuf;
    

    // Convert the message to uppercase
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }


    // Send the message through the plugboard
    message = sendPlugs(message);
    
    // Send through the rotors, reflector, and back through the rotors
    for(int i = 0; i < message.length(); i++){
        r[0]->rotateRotor();
        if(r[0]->getRotorPosition() == 0){
            r[1]->rotateRotor();
            if(r[1]->getRotorPosition() == 0){
                r[2]->rotateRotor();
            }
        }
        message[i] = r[0]->getRotorForward(message[i]);
        message[i] = r[1]->getRotorForward(message[i]);
        message[i] = r[2]->getRotorForward(message[i]);
        message[i] = reflect->getReflectorOutput(message[i]);
        message[i] = r[2]->getRotorBackward(message[i]);
        message[i] = r[1]->getRotorBackward(message[i]);
        message[i] = r[0]->getRotorBackward(message[i]);
    }



    // Send the message back through the plugboard
    message = sendPlugs(message);
    std::cout << "Encrypted message: " << message << std::endl;
}

void setUpRotors(){

    r[0] = new rotor();
    r[1] = new rotor();
    r[2] = new rotor();


    // Set the rotors. Ask the user for the rotor number.
    int rotorNumber;
    char buf[20];
    std::cout << "Enter the first rotor number: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[0]->setRotor(rotorNumber);

    std::cout << "Enter the second rotor number: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[1]->setRotor(rotorNumber);

    std::cout << "Enter the third rotor number: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[2]->setRotor(rotorNumber);

    setRotations();
}

void setRotations(){
    int rotorNumber;
    char buf[20];
    std::cout << "Enter the first rotor position: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[0]->setRotorPosition(rotorNumber);

    std::cout << "Enter the second rotor position: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[1]->setRotorPosition(rotorNumber);

    std::cout << "Enter the third rotor position: ";
    std::cin.getline(buf, 20);
    rotorNumber = std::stoi(buf);
    r[2]->setRotorPosition(rotorNumber);
}

void setPlugs(){
    // Get the plugboard mapping from the user
    // Plugboard map will be entered as a pair of characters. User can enter as few pairs as they want.
    char* plugboardMapping = new char[60];
    std::string plugboardMap;
    std::cout << "Enter the plugboard mapping (Ex. AB,CD,EF): ";
    std::cin.getline(plugboardMapping, 60);

    char plugMap[26];

    for(int i = 0; i < 26; i++){
        plugMap[i] = ' ';
    }

    // Convert the plugboard map to uppercase
    for(int i = 0; i < plugboardMap.length(); i++){
        plugboardMap[i] = toupper(plugboardMap[i]);
    }

    for(int i = 0; i < plugboardMap.length(); i++){
        if(plugboardMap[i] == ',') continue;
        plugMap[plugboardMap[i] - 'A'] = plugboardMap[i+1];
        plugMap[plugboardMap[i+1] - 'A'] = plugboardMap[i];
        i++;
    }

    // Set the plugboard mapping
    plugs->setPlugboard(plugMap);

}

std::string sendPlugs(std::string s){
    std::string returnString = "";
    for(int i = 0; i < s.length(); i++){
        returnString.push_back(plugs->getPlugboardOutput(s[i]));
    }
    return returnString;
}

void printMsg(std::string s){
    for(int i = 0; i < s.length(); i++){
        std::cout << i << ": " << s[i] << std::endl;
    }
    std::cout << std::endl;
}