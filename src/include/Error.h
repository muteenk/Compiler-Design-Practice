#include <iostream>

typedef enum ErrorType{
	Test
} Err_Type;


std::string getErrorFromEnum(Err_Type t)
{
  switch (t)
  {
  case Test: return "test";
  default: return "BAD ERR";
  }
}
