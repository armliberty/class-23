#include <iostream>
#include <regex>



std::string E_mail;
const std::string pattern = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
std::smatch matches;
std::regex reg(pattern);


void printMsg(const std::string);


std::string inputIndentifire(std::string);


void findRegExp(std::string,const std::regex);
void findE_mailFromText(std::string,const std::regex);


int main(){
    findRegExp(inputIndentifire(E_mail),reg);
    return 0;
}

std::string inputIndentifire(std::string e_mail){
    printMsg("Input E-mail::");
    std::cin>>e_mail;
    return e_mail;
}

void printMsg(const std::string msg){
    std::cout<<msg;
}

void findRegExp(std::string e_mail,const std::regex regexp){
    if(std::regex_search(e_mail,matches,regexp)==true){
        printMsg("Is E-mail");
        matches.ready();
        printMsg("\n");
        e_mail=matches.suffix().str();
    }
    else{
        printMsg("Is Not E-mail");
    }
}

