#include <iostream>
#include <string>
#include <set>

std::set<char> symbols = {'!', '#', '$', '%', '&', '*', '+', '-', '/', '=', '?', '^', '_', '`', '|', '}', '~'};

bool isValidEmail(const std::string&);

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


bool isEmail(const std::string& email) {
	auto size = email.size();
	int i = 0;

	while ((isalpha(email[i]) || isdigit(email[i]) || symbols.count(email[i])) && i < size) {++i;}

	if (email[i] == '@' && i < size) {++i;}

	while ((isalpha(email[i]) || isdigit(email[i])) && i < size) {++i;}

	if (email[i] == '.' && i < size) {++i;}

	int length = 0;

	while ((isalpha(email[i]) || isdigit(email[i])) && i < size){
		++i;
		++length;
	}

	if (i == size && length >= 2) return true;
	else return false;
}