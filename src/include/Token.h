#include <iostream>
#include <string.h>

typedef enum tokenType{
	T_ID,
	T_NUM,
	T_ASSIGN,
	T_EQUAL,
	T_ADD,
	T_INC,
	T_SUB,
	T_DEC,
	T_MUL,
	T_DIV,
	T_POW,
	T_LPAREN,
	T_RPAREN,
} T_Type;


class Token{
	T_Type tokenType;
	std::string value;

public:
	void setToken(T_Type type, std::string val);
	std::string getStringFromEnum(T_Type t);
	void showToken();
};



void Token::setToken(T_Type type, std::string val){
	tokenType = type;
	value = val;
}

std::string Token::getStringFromEnum(T_Type t)
{
  switch (t)
  {
  case T_ID: return "IDENTIFIER";
  case T_NUM: return "NUMBER";
  case T_ASSIGN: return "ASSIGNMENT_OP";
  case T_EQUAL: return "EQUAL";
  case T_ADD: return "ADD_OP";
  case T_INC: return "INCREMENT";
  case T_SUB: return "SUB_OP";
  case T_DEC: return "DECREMENT";
  case T_MUL: return "MUL_OP";
  case T_DIV: return "DIV_OP";
  case T_POW: return "POW_OP";
  case T_LPAREN: return "LPAREN";
  case T_RPAREN: return "RPAREN";
  default: return "BAD TOK";
  }
}

void Token::showToken(){
	std::cout << "< " << getStringFromEnum(tokenType) << ", " << value << " >" << std::endl;
}