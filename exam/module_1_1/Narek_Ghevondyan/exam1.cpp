#include <iostream>
#include <utility>
#include <algorithm>

using TimeSig = std::pair<int, int>;


int leastCommonMultiple(int a, int b) {
    return a * b / std::__gcd(a, b);
}

int computeOverlap(TimeSig timeSig1, TimeSig timeSig2) {
    int numerator1 = timeSig1.first;
    int denominator1 = timeSig1.second;
    int numerator2 = timeSig2.first;
    int denominator2 = timeSig2.second;

    int commonDenominator = leastCommonMultiple(denominator1, denominator2);

    int commonBeats1 = commonDenominator / denominator1;
    int commonBeats2 = commonDenominator / denominator2;

    int barsMatched = std::min(numerator1 * commonBeats1, numerator2 * commonBeats2);

    return barsMatched;
}

int main() {
 
    int numerator1;
    int denominator1;
    int numerator2;
    int denominator2;
    std::cout << "enter the numerator of the first ";
    std::cin >> numerator1;
    std::cout << "enter the denuminator of the first ";
    std::cin >> denominator1;
    std::cout << "enter the numerator of the second ";
    std::cin >> numerator2;
    std::cout << "enter the numerator of the second ";
    std::cin >> denominator2;


    TimeSig timeSig1 = std::make_pair(numerator1, denominator1);
    TimeSig timeSig2 = std::make_pair(numerator2, denominator2);

    int barsMatched = computeOverlap(timeSig1, timeSig2);

    std::cout << barsMatched << std::endl;


}



