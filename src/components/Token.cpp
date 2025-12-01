#include "Token.h"

using namespace std;

bool Token::isType(TokenType type) {return this->type == type; }

// Vérifie si le token est un opérateur (+, -, *, /)
bool Token::isOperator() {
        switch (type) {
                case TokenType::PLUSOPERATOR:
                case TokenType::MINUSOPERATOR:
                case TokenType::STAROPERATOR:
                case TokenType::SLASHOPERATOR:
                return true;
        default:
                return false;
        }
}

string Token::toString() { return "(" + to_string(this->type) + ", " + value + ")"; }

