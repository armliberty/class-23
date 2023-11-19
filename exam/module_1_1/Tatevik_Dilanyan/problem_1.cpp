#include <iostream>
#include <utility>

using TimeSig = std::pair<int, int>;

int gcd(int a, int b);

TimeSig inputTimeSig(const std::string& tact);

int computeOverlap(TimeSig timeSig1, TimeSig timeSig2);

int main() {
    TimeSig timeSig1 = inputTimeSig("Enter the first time signature :: ");
    TimeSig timeSig2 = inputTimeSig("Enter the second time signature :: ");

    int barsMatched = computeOverlap(timeSig1, timeSig2);

    std::cout << "They match every " << barsMatched << " bars." << std::endl;

    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int x = b;
        b = a % b;
        a = x;
    }
    return a;
}

TimeSig inputTimeSig(const std::string& tact) {
    TimeSig timeSig;
    std::cout << tact;
    std::cin >> timeSig.first;
    std::cin >> timeSig.second;
    return timeSig;
}

int computeOverlap(TimeSig timeSig1, TimeSig timeSig2) {
    int b1 = timeSig1.second;
    int b2 = timeSig2.second;

    int lcm = (b1 * b2) / gcd(b1, b2);

    return lcm b1;
}