//Vahe Tsaturyan
#include <iostream>
#include <string>

using namespace std;

std::string input(const std::string& input) {
    std::string value;
    std::getline(std::cin, value);
    return value;
}

bool hasAA(std::string& string){
	for(int i  = 0; i < string.size()-1;++i)
	{
		if(string[i] == string[i+1]=='a')
		{
			return true;
		}
	}
}

bool firstSimbolIsB(std::string& string){
	return string[string.size()-1] == 'b';

}

int main()
{
	const std::string str = input("ababzb");
	if(!hasAA(str) && firstSimbolIsB(str)){
		std::cout<<"true" <<endl;
		
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}