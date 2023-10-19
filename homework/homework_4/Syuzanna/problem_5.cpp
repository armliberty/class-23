   #include <cmath> // std::pow
   #include <iostream>
   #include <string>
   #include <vector>

    template <typename T>
    T input(const std::string& msg) {
        if (!msg.empty()) {
            std::cout << msg << ": ";
        }
    T size;
    while(size<1)
    std::cin >> size;
    return size;
    }
    template <>
    std::string input(const std::string& msg) {
        if (!msg.empty()) {
            std::cout << msg << ": ";
        }
    std::string value;
    std::getline(std::cin, value);
    return value;
    }
    template <>
    std::vector<std::string> input(size){
        std::vector<std::string> vector(size);
        for(int i=0; i<size; ++i){
            vector[i]=input <std::string>("Input string");
            return std::vector[i];
        }    
    }

    
    template <typename T>
    void print(const T&, const std::string& msg = "");
    void print(const std::vector<std::string>&, const std::string& msg = "");

    void makeSet(std::vector<std::string>&);
    std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);

    std::vector<std::string> inputStringSet(auto size) {
        std::vector<std::string> strings(size);
        strings = input<std::vector<std::string>>("Input strings");
        makeSet(strings);
        return strings;
    }
   
   int main() {
       const auto size = input<size_t>("Input the string count");
       const auto stringSet = inputStringSet(size);
       print (std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
       const auto subsets = computeSubsets(stringSet);
       print(subsets.size(), "Computed powerset cardinality");
       std::cout << "Computed powerset: ";
       for (const auto& s : subsets) {
           print(s);
       } 
   }

  

 template <typename T>
void print(const T& value, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}


void print(const std::vector<std::string>& subsets, const std::string& msg = ""){
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    for(int i=0;i<substes.size();++i)
        std::cout<<subsets[i]<<"  "<<std::endl;
}




void makeSet(std::vector<std::string>& stringSet){
    for (int i = 0; i < stringSet.size(); ++i) {
        for (int j = i + 1; j < stringSet.size(); ++j) {
           if (stringSet[i] == stringSet[j]) {
               stringSet.erase(stringSet.begin()+j);
           }
        }
    }    
 
}

void add1(std::vector<short> & Binary){
    for(int i=0; i<Binary.size();++i){
        int h=1;
        while((Binary.size()-h)>-1){   
            Binary[Binary.size()-h]= Binary[Binary.size()-h]+1;
            if(Binary[Binary.size()-h]>1){
                Binary[Binary.size()-1]=0;
                h++;
                Binary[Binary.size()-h]+1;
            }   
        }
    }


}

bool areAllSet(std::vector<short> & Binary){
    int k=0;
    for(int i=0; i<Binary.size();++i)
        if(Binary[i]==1)
            k++;
    if(k==Binary.size())   
         return 0;
    else
         return 1;       

}

std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> stringSet){
    int rows = pow(2, stringSet.size()) - 1;
    int colums = stringSet.size();
    std::vector<std::vector<std::string>> subsets(rows, std::vector<std::string>(colums));
    std::vector<short> Binary(stringSet.size());
    for(int i=0; i<Binary.size(); ++i)
        Binary[i]=0;
    void add1(std::vector<short> & Binary);
    while(!areAllSet(Binary)){
        add1(Binary);
        std::vector<std::string> subset;
        for(int i=0; i<Binary.size();++i){
            if(Binary[i])
                 subset.push_back(stringSet[i]);  
        }
        subsets.push_back(subset);   
    }        
    return subsets;
}



