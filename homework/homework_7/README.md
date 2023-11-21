1. Construct PDA for the following languages

    1.1 L = { w | w ∈ {0, 1}* ∧ w contains at least three 1s }

    1.2 L = { w | w ∈ {0, 1}∗ ∧ w = w<sup>R</sup> ∧ the length of w is odd }

    1.3 L = = { a<sup>n</sup>b<sup>m</sup>c<sup>k</sup> | n, m, k ∈ Z<sup>+</sup> ∧ n + m = k }

    1.3 L = { a<sup>n</sup>b<sup>m</sup>a<sup>n</sup> | m,n ∈ Z<sup>+</sup> }

2. CFG => PDA construction

    2.1 Using the CFG => PDA construction proof method, construct PDA for the grammar G = (V, Σ, R, S) with V = {S, T, X} and Σ = {a, b}, where P is:

        S → aTXb

        T → XTS | ε

        X → a | b

    2.2 Convert the resulting PDA to a PDA with character-based push operation, instead of string-based pushing.
