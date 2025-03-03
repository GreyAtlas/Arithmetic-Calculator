#ifndef USERHANDER_H_
#define USERHANDER_H_

#include <iostream>
#include <string>

class UserHandler {
    public:
        static double getVariableValueFromUser(const std::string& variableName);
};

#endif