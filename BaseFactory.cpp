#include "BaseFactory.h"
#include "op.hpp"
#include "mult.hpp"

Base * parseOperator(char c, Base* op1, Base* op2) {
    // TODO Fill this out
    if (c == '*')
        return new Mult(op1, op2);
    else if(c == '+')
	return new Add(op1, op2);
    else if(c == '/')
        return new Div(op1, op2);
    else if(c == '-')
        return new Sub(op1, op2);
    else if(c == '^')
        return new Pow(op1, op2);
    else
	return nullptr;
}

bool isOperator(char c) {
    // TODO Finish this
    return c == '*' || c == '-' || c == '+' || c == '/' || c == '^';
}

bool isNumber(char c) {
    // FIXME STUB
    if ((c >= '0') && (c <= '9'))
        return true;
    else 
	return false;
}

Base * BaseFactory::parse(char **input, int length) {
    char* charArray = input[0];

    Base* lastOperand = nullptr;
    char lastOperator = 0;

    for (int i = 0; charArray[i] != 0; ++i) {
        char c = charArray[i];

        if (isOperator(c)) {
            lastOperator = c;
        }
        else if (isNumber(c)) {
            // Convert the character to a number
            int val = c - '0';

            Op* op = new Op(val);

            if (lastOperator) {
                lastOperand = parseOperator(lastOperator, lastOperand, op);
                lastOperator = 0;
            }
            else {
                lastOperand = op;
            }
        }
    }

    return lastOperand;
}
