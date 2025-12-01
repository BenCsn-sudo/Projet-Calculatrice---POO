#pragma once

#include <vector>
#include <string>
#include "Token.h" // Le compilateur le trouvera dans src/components grâce au Makefile

class Lexer {
private:
	// Méthode interne pour lire un nombre entier complet
	int readInteger(std::string expr, std::string &num);
public:
	// Transforme le texte en liste de Tokens
	std::vector<Token *> tokenize(std::string expr);
};
