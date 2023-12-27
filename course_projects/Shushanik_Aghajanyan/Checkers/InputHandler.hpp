#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include<string>

class InputHandler {
public:
    static int getIntInput(const std::string&);
    static char getStringInput(const std::string&); 

};

#endif //INPUT_HANDLER