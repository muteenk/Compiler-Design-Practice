#include "./include/Token.h"
#include "./ErrorHandler.h"
#define MAX_TOK_LEN 25
#include <vector>

class Lexer{

    std::string codeStream = "";
    std::vector<Token> tokenStream;
    int currIndex;
    int currLine;

    public:
        Lexer(std::string code){
            codeStream += code;
            currIndex = 0;
            currLine = 1;
        }

        std::string getIdentifier(); //creates identifier
        std::string getNumber(); // creates Number (int or float)

        // Helpers
        char getNextTok();
        std::vector<Token> tokenizer();
};


// ------------- Token Creators ---------------- //


// Create Identifier
std::string Lexer::getIdentifier(){
    std::string identifier = "";
    int charCount = 0;

    while((codeStream[currIndex] >= 'a' && codeStream[currIndex] <= 'z') || (codeStream[currIndex] >= 'A' && codeStream[currIndex] <= 'Z') || (codeStream[currIndex] >= '0' && codeStream[currIndex] <= '9') || codeStream[currIndex] == '_'){
        if (charCount > MAX_TOK_LEN){
            ErrorHandler er("Lexical Error", "Exceeded Token Length", currLine, currIndex);
        }
        identifier += codeStream[currIndex];        
        charCount++;
        currIndex++;
    }

    return identifier;
}


// Create Number
std::string Lexer::getNumber(){

    std::string number = "";
    int charCount = 0;

    while((codeStream[currIndex] >= '0' && codeStream[currIndex] <= '9') || codeStream[currIndex] == '.'){
        if (charCount > MAX_TOK_LEN){
            ErrorHandler er("Lexical Error", "Exceeded Token Length", currLine, currIndex);
        }
        number += codeStream[currIndex];
        charCount++;
        currIndex++;
    }


    return number;

}






// ----------- Operational Methods ------------------- //


char Lexer::getNextTok(){
    if (currIndex+1 < codeStream.length()){
        return codeStream[currIndex+1];
    }
    return '\0';
}


std::vector<Token> Lexer::tokenizer(){

    while (currIndex < codeStream.length()){
        
        Token newToken;

        if((codeStream[currIndex] >= 'a' && codeStream[currIndex] <= 'z') || (codeStream[currIndex] >= 'A' && codeStream[currIndex] <= 'Z')){
            newToken.setToken(T_ID, getIdentifier());
            tokenStream.push_back(newToken);
            continue;
        }
        else if (codeStream[currIndex] >= '0' && codeStream[currIndex] <= '9'){
            newToken.setToken(T_NUM, getNumber());
            tokenStream.push_back(newToken);
            continue;
        }
        else if (codeStream[currIndex] == '='){
            if (getNextTok() == '='){
                newToken.setToken(T_EQUAL, "==");
                currIndex++;    
            }
            else{
                newToken.setToken(T_ASSIGN, "=");
            }

            tokenStream.push_back(newToken);
        }
        else if (codeStream[currIndex] == '+'){
            if (getNextTok() == '+'){
                newToken.setToken(T_INC, "++");
                currIndex++;    
            }
            else{
                newToken.setToken(T_ADD, "+");
            }

            tokenStream.push_back(newToken);
        }
        else if (codeStream[currIndex] == '-'){
            if (getNextTok() == '-'){
                newToken.setToken(T_DEC, "--");
                currIndex++;    
            }
            else{
                newToken.setToken(T_SUB, "-");
            }

            tokenStream.push_back(newToken);
        }
        else{
            ErrorHandler err("Lexical Error", "Invalid Character", currLine, currIndex);
        }

        currIndex++;

    }


    return tokenStream;

}