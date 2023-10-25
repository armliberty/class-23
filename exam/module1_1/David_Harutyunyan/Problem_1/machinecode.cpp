#include <iostream>
#include <cstring>
#include <vector>

void findPattern(std::vector<std::string> text, std::vector<std::string> pattern);

int main()
{   std::string textValue;
    std::string patternValue;
    std::vector<std::string> text;
    std::vector<std::string> pattern;
    std::cout<<"Enter the text:";
    for(auto i = 0; i<text.size(); i++)
        {
            std::cin>>textValue; 
            text[i].push_back(textValue[i]);
        }
    std::cout<<"Enter the pattern:";
    for(auto i = 0; i<text.size(); i++)
        {
            std::cin>>patternValue; 
            pattern[i].push_back(patternValue[i]);
        }

    findPattern(text,pattern);

    
}

void findPattern(std::vector<std::string> text, std::vector<std::string> pattern)
{
   for (int i = 0; i <= text.size() - pattern.size(); i++)
   {
       int j = 0;

       while(j < pattern.size() && text[i + j] == pattern[j]) 
       {
            j++;
       }
       
       
       if(j == pattern.size()) std::cout << i << " ";
   }
}