#include "./include/Error.h"
#include <stdlib.h>


class ErrorHandler
{
    private:
        std::string errorDomain;
        std::string error;
        int lineOfError, errorIndex;

    public:
        ErrorHandler(std::string domain, std::string val, int lineNumber, int index){
            errorDomain = domain;
            error = val;
            lineOfError = lineNumber;
            errorIndex = index;
            throwError();
        }

        void throwError(){
            std::cout << error << "\n At line " << lineOfError << " at index " << errorIndex << std::endl;
            exit(1);
        }
};




