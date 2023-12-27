#include "InputHandler.hpp"
#include<iostream>
#include<string>
#include<limits>

  int InputHandler :: getIntInput(const std::string& prompt) {
        int userInput;
        while (true) {
            std::cout << prompt;
            if (std::cin >> userInput) {
                break;
            } else {
                // Invalid input, clear the input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer.\n";
            }
        }
        return userInput;
    }


         char InputHandler :: getStringInput(const std::string& prompt) {
        char userInput;
        while (true) {
            std::cout << prompt;
            if (std::cin >> userInput) {
                break;
            } else {
                // Invalid input, clear the input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid character.\n";
            }
        }
        return userInput;
    }