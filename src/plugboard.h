#pragma once

class plugboard{
    public:
    plugboard();
    ~plugboard();
    void setPlugboard(const char* mapping);
    char getPlugboardOutput(char input);
    char* getPlugboard();
    private:
    char* plugboardMapping;
};