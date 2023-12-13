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
    void setRotorMapping(const char* mapping);
    int setRotorPosition(int position);
    int getRotorNumber();
    private:
    int rotorPosition;
    char* rotorMapping;
    int rotorNumber;
};