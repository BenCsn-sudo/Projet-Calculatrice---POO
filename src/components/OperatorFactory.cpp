#include "OperatorFactory.h"
#include "Operators.h"
#include <stdexcept>

using namespace std;

Expression* OperatorFactory::build(TokenType tokenType, OperatorType operatorType) {
	switch (operatorType) {
		case OperatorType::UNARY:
			switch (tokenType) {
				case TokenType::PLUSOPERATOR:  return new PlusUnaryOp();
				case TokenType::MINUSOPERATOR: return new MinusUnaryOp();
				default: throw runtime_error("Opérateur unaire inconnus");
			}
		case OperatorType::BINARY:
			switch (tokenType) {
				case TokenType::PLUSOPERATOR:  return new PlusBinaryOp();
				case TokenType::MINUSOPERATOR: return new MinusBinaryOp();
				case TokenType::STAROPERATOR:  return new StarBinaryOp();
				case TokenType::SLASHOPERATOR: return new DivBinaryOp();
				default: throw runtime_error("Opérateur binaire inconnus");
			}
		default:
			throw runtime_error("Type d'opérateur inconnus");
	}
}
