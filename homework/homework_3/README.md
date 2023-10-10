1. Write a LEX program that recognizes the following tokens:
    - Keywords: __if__, __else__, __while__, __for__, __int__, __double__
    - Identifiers: e.g. __abc2__, ___23fb__
    - Integer constants: e.g. __42__, __-23__, __+3__, __0__
    - Floating point constants: e.g. __0.2__, __-2.1, +2.1, __.2__, __2.__, __0.__, __.0__; Also in scientific notation: +2e10, -2.1e-10
    -  Operators: __+__, __-__, __*__, __/__, __%_, __=__, __==__, __<__, __>__, __>=__, __<=__.
    - Delimiters: __(__, __)__, __;__, __{__, __}__

2. Design an NFA that accepts the language (a ∪ b)*ab+a(a ∪ b)ab\* and convert it to DFA.

3. E-mail validator
    1. Write a regular expression for the language of e-mails.
    2. Write it in terms of formal operations: concatenation, union and Kleene star.
    3. Design an ε-NFA recognizing that language.
    4. Conver the ε-NFA into DFA.
    5. Implement the DFA in a C++ program that validates e-mail addresses.
