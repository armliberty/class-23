
//Anna_Musayelyan
#include<iostream>
int finde_lcm(int a,int b) {
    int max_val = std::max(a, b);
    int lcm = max_val;

    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            return lcm;
        }
        lcm += max_val;
    }

    return lcm;
}
using TimeSig = std::pair<int,int>;
int computeOverlap(TimeSig timeSig1, TimeSig timeSig2) {
    int numerator1 = timeSig1.first;
    int denominator1 = timeSig1.second;
    int numerator2 = timeSig2.first;
    int denominator2 = timeSig2.second;

    int lcm = finde_lcm(denominator1,denominator2);
    int n1 = (lcm / denominator1) * numerator1;
    int n2 = (lcm / denominator2) * numerator2;

    int min = (n1 < n2) ? n1 : n2;
    return min;

}
int main() {
    TimeSig timeSig1;
    TimeSig timeSig2;

    std::cout << "Enter the first time signature (numerator denominator): ";
    std::cin >> timeSig1.first >> timeSig1.second;

    std::cout << "Enter the second time signature (numerator denominator): ";
    std::cin >> timeSig2.first >> timeSig2.second;
    
    int matchingBars = computeOverlap(timeSig1, timeSig2);
    
    std::cout << "The time signatures match every " << matchingBars << " bars." << std::endl;
    
    return 0;
}
