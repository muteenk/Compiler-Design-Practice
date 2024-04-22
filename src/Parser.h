#include <iostream>
#include <vector>

class Parser{

    std::vector<Token> tokenStream;

    public:

        Parser(std::vector<Token> ts){
            tokenStream = ts;
            parse();
        }

        void parse();

};



void Parser::parse(){
    for(int i = 0; i < tokenStream.size(); i++){
        tokenStream[i].showToken();
    }
}