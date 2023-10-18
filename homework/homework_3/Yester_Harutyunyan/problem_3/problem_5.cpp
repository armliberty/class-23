#include <iostream>

std::string input(const std::string& msg);
bool isLetter(char c);
bool isSymbol(char c);
bool is_valid(std::string email);
void print(bool ans,const std::string email);

int main() 
{ 
    const auto email = input("Input e-mail");
    print(is_valid(email),email);
	return 0; 
} 

void print(bool ans, const std::string email) {
    if (ans) { 
		std::cout << email << " : "
			<< "valid" << std::endl; 
	} 
	else { 
		std::cout << email << " : "
			<< "invalid" << std::endl; 
	} 
}
 
bool isLetter(char c) { 
	return ((c >= 'a' && c <= 'z') 
			|| (c >= 'A' && c <= 'Z')); 
} 

bool isDigit(char c) { 
	return ((c >= 0 && c <= 9)); 
} 

bool isSymbol(char c) {
    if (c == '_' | c == '.' | c == '-' | c == '+')
        return true;
    else 
    return false;
}

std::string input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);
    return value;
}

bool is_valid(std::string email) { 
	if (!isLetter(email[0]) | isSymbol(email[email.length()-1])) { 
		return 0; 
	} 
	int atSign = -1;
    int dot = -1; 

	for (int i = 0; i < email.length(); ++i) { 
        if (isSymbol(email[i])){
            if (isSymbol(email[i+1]) | email[i+1]== '@' | email[i-1] == '@'){
                return 0;
            }
        }

		if (email[i] == '@') { 

			atSign = i; 
		} else if (email[i] == '.') { 

			dot = i; 
		} 
	} 
    
	for (int i = 0; i< atSign; ++i) {
		if (!(isSymbol(email[i]) | isLetter(email[i]) | isDigit(email[i]))) {
			return 0;
		}
	}
	for (int i = atSign+1; i< dot; ++i) {
		if (!(email[i] == '-' | isLetter(email[i]) | isDigit(email[i]))) {
			return 0;
		}
	}
	for (int i = dot+1; i< email.length(); ++i) {
		if (!(isLetter(email[i]))) {
			return 0;
		}
	}

	if (email.length() - dot <= 2) {
		return 0;
	}
	std::cout<<email.length()<<" lll "<<dot<<std::endl;

	if (atSign == -1 || dot == -1) 
		return 0; 

	if (atSign > dot) 
		return 0; 
    std::cout<<"At"<<atSign<<" "<<"Dot"<<dot<<std::endl;

	return 1; 
} 

