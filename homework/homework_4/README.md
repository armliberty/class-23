1. Using pumping lemma prove the irregularity of language L={0<sup>n</sup> : n=2<sup>k</sup> ∀k∈Z<sup>+</sup> (i.e. n is a power of 2)}.

2. Using pumping lemma prove the irregularity of language L={x<sub>1</sub>x<sub>2</sub>...x<sub>n</sub> :  x<sub>1</sub>x<sub>2</sub>...x<sub>n</sub>=x<sub>n</sub>x<sub>n-1</sub>...x<sub>1</sub> ∀n>=0 ∧ n=2k ∧ x<sub>i</sub>∈Σ (i.e even-length palindromes)}.

   Hint: apply the lemma to a<sup>k</sup>bba<sup>k</sup>∈L, where a,b∈Σ.

3. Using pumping lemma prove the irregularity of language L={x<sub>1</sub>x<sub>2</sub>...x<sub>n</sub> :  x<sub>1</sub>x<sub>2</sub>...x<sub>n</sub>=x<sub>n</sub>x<sub>n-1</sub>...x<sub>1</sub> ∀n>=0 ∧ n=2k+1 ∧ x<sub>i</sub>∈Σ (i.e odd-length palindromes)}.

   Hint: apply the lemma to a<sup>k</sup>ba<sup>k</sup>∈L, where a,b∈Σ.

4. Implement the following functions that check whether the given argument is palindrome:
   ```cpp
   bool isPalindrome(const std::string&);
   bool isPalindrome(int);
   ```

5. Design an algorithm based on the [powerset cardinality proof](https://en.wikipedia.org/wiki/Power_set#Representing_subsets_as_functions) for returning all subsets of a given set, and implement in the following code:
   ```cpp
   #include <iostream>
   #include <string>
   #include <vector>

   template <typename T>
   T input(const std::string& msg = "");
   template <>
   std::string input(const std::string& msg = "");
   template <>
   std::vector<std::string> input();
   template <typename T>
   void print(const T&, const std::string& msg = "");
   void print(const std::vector<std::string>&, const std::string& msg = "");

   void makeSet(std::vector<std::string>&);
   std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);

   std::vector<std::string> inputStringSet() {
       auto strings = input<std::vector<std::string>>("Input strings);
       makeSet(strings);
       return strings;
   }
   
   int main() {
       const auto size = input<size_t>("Input the string count");
       const auto stringSet = inputStringSet();
       print(std::pow(2, stringSet.size(), "Expected powerset cardinality));
       const auto subsets = computeSubsets(stringSet);
       print(subsets.size(), "Computed powerset cardinality");
       std::cout << "Computed powerset: "
       for (const auto& s : subsets) {
           print(s);
       }
   }
    
   /*
    * Here comes your code
    */
   ```
