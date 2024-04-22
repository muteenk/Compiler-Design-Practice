#include <iostream>
#include <vector>
#include <fstream>
#include "./src/Lexer.h"
#include "./src/Parser.h"

int main(){

	std::ifstream sourceFile ("./examples/test.si");
	std::string s;

	if ( sourceFile.is_open() ){ 
		sourceFile >> s; 
	}

	sourceFile.close();

	Lexer lex(s);
	std::vector<Token> tokens = lex.tokenizer();
	Parser p(tokens);

	return 0;
}