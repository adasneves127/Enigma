#pragma once

class plugboard{
    public:
    plugboard();
    ~plugboard();
    void setPlugboard(char* mapping);
    char getPlugboardOutput(char input);
    private:
    char** plugboardMapping;
};