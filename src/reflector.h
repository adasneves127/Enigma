#pragma once


class reflector{
    public:
    reflector();
    ~reflector();
    void setReflector(const char* mapping);
    char getReflectorOutput(char input);
    private:
    char* reflectorMapping;
};