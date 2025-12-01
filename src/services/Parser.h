#pragma once

#include <stack>
#include <vector>
#include "Token.h"
#include "Expression.h"

class Parser {
private:
	std::stack<Expression *> operators; // Pile des opérateurs (ex: +, *)
	std::stack<int> operands;           // Pile des nombres (ex: 1, 42)
	std::vector<Token *> tokens;        // La liste des mots à lire
	int idx;                            // Notre position actuelle dans la liste

	// Méthodes internes de la grammaire (Cachées à l'utilisateur)
	void consumeLeftParenthesis();
	void consumeRightParenthesis();
	bool consumeBinop();
	bool consumeUnop();
	bool consumeLitteral();
	void consumeBaseExpression();
	void consumeExpression();

	// Le coeur du calcul
	void solve();
	void reset();

public:
	Parser(std::vector<Token *> tokens);

	// Outils de navigation
	Token *next();
	void rewind();

	// La seule méthode publique dont l'utilisateur a besoin
	int parse();
};
