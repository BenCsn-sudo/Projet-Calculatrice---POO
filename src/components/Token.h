#pragma once

#include <iostream>
#include <string>

// Enumération des types de symboles possibles
enum TokenType {
	INTEGER,
	PLUSOPERATOR,
	MINUSOPERATOR,
	STAROPERATOR,
	SLASHOPERATOR,
	LPARENTHESIS,
	RPARENTHESIS,
};

// Classe représentant un "mot" ou symbole lu (Ex: "42", "+", "(")
class Token {
private:
	TokenType type;
	std::string value;

public:
	Token(TokenType type, std::string value) : type(type), value(value) {}

	std::string getValue() { return value; }
	TokenType getType() { return type; }

	// Vérifie si le type correspond
	bool isType(TokenType type);

	// Vérifie si le token est un opérateur (+, -, *, /)
	bool isOperator();

	// Renvoie le type sous str
	std::string toString();
};

