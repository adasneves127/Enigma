#pragma once


class reflector{
    public:
    reflector();
    ~reflector();
    void setReflector(char* mapping);
    char getReflectorOutput(char input);
    private:
    char* reflectorMapping;
};