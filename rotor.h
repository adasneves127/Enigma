#pragma once


class rotor{
    public:
    rotor();
    ~rotor();
    void setRotor(int rotorNumber);
    int rotateRotor();
    int getRotorPosition();
    char getRotorForward(char input);
    char getRotorBackward(char input);
    void setRotorMapping(char* mapping);
    int setRotorPosition(int position);
    private:
    int rotorPosition;
    char* rotorMapping;

};