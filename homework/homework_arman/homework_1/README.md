1. Implement the following functions using Newton's method and compare the results with stdandard implementations in <cmath> module:
    ```
    double cubeRoot(double x, double delta);
    double sine(double x, double delta);
    ```

2. Write a function that check if an integer is prime:
    ```bool isPrime(int);```

3. Extend the algorithm of <code>isPrime</code> to return the prime factorization of an integer:
    ``` std:::vector<int> primeFactorize(int); ```

4. Design and implement the algorithm of greatest common divisor and lowest common multiple using <code>primeFactorize</code> function:
    ```
    int computeGCD(int a, int b);
    int computeLCM(int a, int b);
    ```

5. Implement Euclid's algorithm for GCD and LCM and compare the complexity with <code>primeFactorize</code>-based version.
