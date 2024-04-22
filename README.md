# Compiler Design Practice

Writing a simple compiler to learn real world compiler development.
Feel free to contribute.


## Lexer

- Tokens Defined
    - Identifier (variable names [a-z A-Z _]+ [0 - 9])
    - Number Data ([0 - 9]+ [.] [0 - 9]+)
    - Assignment (=)
    - Equals (==)
    - Addition (+)
    - Increment (++)
    - Subtraction (-)
    - Decrement (--)




## Parser

### Grammar Defined

- Arithmetic Expression Grammar
    
    - ArithmeticExpressions -> identifier = ArithExp | ArithExp
    - ArithExp -> (ArithExp) | term - term | term + term | term
    - term -> factor * factor | factor / factor | factor++ | factor-- | factor
    - factor -> identifier | number
