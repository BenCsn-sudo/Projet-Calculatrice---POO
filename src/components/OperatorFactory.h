#pragma once
#include "Expression.h"
#include "Token.h"

enum class OperatorType { UNARY, BINARY };

class OperatorFactory {
public:
	static Expression* build(TokenType tokenType, OperatorType operatorType);
};
