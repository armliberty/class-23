1. Update the grammar of calculator in yacc and lex to support the following features:
    - Floating point numbers
    - Multiplication and division: __\<expr\> * \<expr\>__, __\<expr\> / \<expr\>__, __\<expr\> mod \<expr\>__
    - Trigonometric functions and logarithmic: __sin(\<expr\>)__, __cos(\<expr\>)__, __tan(\<expr\>)__,
    __lg(\<expr\>)__, __ln(\<expr\>)__, __lg2(\<expr\>)__, ___log(\<expr\>, \<expr\>)__ (using ```<math.h>``` library)

    Print error messages in case unaccepted values for the functions.

2. Write CFGs for [prefix (Polish)](https://en.wikipedia.org/wiki/Polish_notation) and [postfix (reverse Polish)](https://en.wikipedia.org/wiki/Reverse_Polish_notation) notations.

3. Write a CFG for L={x#y | x,y∈{0,1}* ∧ x≠y<sup>R</sup> } with Σ={0,1}.

4. Write a non-ambiguous CFG for L={x#y | x,y∈{a,b}* ∧ y<sup>R</sup> is prefix of x}.

5. Write a CFG for for L={a<sup>n</sup>ww<sup>R</sup>a<sup>n</sup> | n≥0 ∧ w∈{a,b}*}

6. Design a CFG for function prototypes in C with simple scalar built-in types. E.g.:
    ```c
    void funName(int arg1name, double arg2name);
    int funName();
    short funName(double argName);
    double funName(void);
    ```
    