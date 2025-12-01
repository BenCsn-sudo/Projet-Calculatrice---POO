#include "Parser.h"
#include "OperatorFactory.h"
#include <stdexcept>
#include <string>

using namespace std;

Parser::Parser(vector<Token *> tokens) : tokens(tokens), idx(0) {}

Token *Parser::next() {
	if (idx < tokens.size()) return tokens[idx++];
	throw runtime_error("Unexpected end of expression");
}

void Parser::rewind() {
	if(idx > 0) idx--;
}

void Parser::reset() {
	idx = 0;
	while(!operators.empty()) { delete operators.top(); operators.pop(); }
	while(!operands.empty()) { operands.pop(); }
}

int Parser::parse() {
	reset();
	consumeBaseExpression();
	if (operands.empty()) throw runtime_error("No result produced");
	return operands.top();
}

// Grammaire

void Parser::consumeLeftParenthesis() {
	Token *curr = next();
	if (!curr->isType(TokenType::LPARENTHESIS)) throw runtime_error("Expected '('");
}

void Parser::consumeRightParenthesis() {
	Token *curr = next();
	if (!curr->isType(TokenType::RPARENTHESIS)) throw runtime_error("Expected ')'");
	solve(); // Une parenthèse fermante déclenche le calcul immédiat
}

bool Parser::consumeBinop() {
	Token *curr = next();
	if (curr->isOperator()) {
		// On délègue la création à la Factory
		Expression* expr = OperatorFactory::build(curr->getType(), OperatorType::BINARY);
		operators.push(expr);
		return true;
	}
	rewind();
	return false;
}

bool Parser::consumeUnop() {
	Token *curr = next();
	if (curr->isType(TokenType::PLUSOPERATOR) || curr->isType(TokenType::MINUSOPERATOR)) {
		Expression* expr = OperatorFactory::build(curr->getType(), OperatorType::UNARY);
		operators.push(expr);
		return true;
	}
	rewind();
	return false;
}

bool Parser::consumeLitteral() {
	Token *curr = next();
	if (curr->isType(TokenType::INTEGER)) {
		operands.push(stoi(curr->getValue()));
		return true;
	}
	rewind();
	return false;
}

void Parser::consumeBaseExpression() {
	if (consumeLitteral()) return;	// C'est juste un nombre
	consumeLeftParenthesis();
	consumeExpression();		// On regarde l'expression
	consumeRightParenthesis();
}

void Parser::consumeExpression() {
	if (consumeUnop()) {
		consumeBaseExpression();
		return;
    	}
	consumeBaseExpression();		// On lit le therme de gauche
	if (consumeBinop()) {			// On cherche un opérateur
        	consumeBaseExpression();	// On lit le therme de droite
    	}
}

void Parser::solve() {
	if (!operators.empty()) {
		Expression *expr = operators.top();	// Prend le dernier opérateur
		operators.pop();

		// L'opérateur prend les nombres d'operands calcule et remet le résultat sur la pile
		expr->interpret(operands);

		delete expr; // On nettoie l'opérateur (il sert plus)
    	}
}
