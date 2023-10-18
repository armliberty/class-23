#include <iostream>
#include <string>

bool isSymbol(const char&);
bool isEmail(const std::string&);

int main() {
	std::string email;
	std::cin >> email;
	if (isEmail(email)) {
		std::cout << "email is valid";
	}
	else {
		std::cout << "email is not valid";
	}
}


bool isSymbol(const char& email)
{
	if (email == '!' || email == '#' || email == '$' || email == '%' || email == '&' || email == '*' || email == '+' || email == '-' ||
		email == '/' || email == '=' || email == '?' || email == '^' || email == '_' || email == '`' || email == '|' || email == '}' || email == '~') {
		return true;
	}
	else {
		return false;
	}
}

bool isEmail(const std::string& email) {
	auto size = email.size();
	int i = 0;
	while ((isalpha(email[i]) || isdigit(email[i]) || isSymbol(email[i])) && i < size) {
		++i;
	}
	if (email[i] == '@' && i < size) {
		++i;
	}
	while ((isalpha(email[i]) || isdigit(email[i])) && i < size) {
		++i;
	}
	if (email[i] == '.' && i < size) {
		++i;
	}
	int length = 0;
	while ((isalpha(email[i]) || isdigit(email[i])) && i < size) {
		++i;
		++length;
	}
	if (i == size && length >= 2) {
		return true;
	}
	else return false;
}
