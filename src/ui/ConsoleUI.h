#pragma once
#include <string>
#include <vector>
#include "Token.h"

class ConsoleUI {
private:
	// Utilitaire pour nettoyer la mémoire des tokens
	void free_tokens(std::vector<Token *> vec);

	// Lance un test unique
	void runTest(std::string expr, int expected);

public:
	// Lance toute la batterie de tests
	void runAllTests();
};
