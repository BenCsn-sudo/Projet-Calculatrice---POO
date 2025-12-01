#include "ConsoleUI.h"
#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <string>

using namespace std;

void ConsoleUI::free_tokens(vector<Token *> vec) {
	for (Token *i : vec) {
		delete i;
    	}
}

void ConsoleUI::runTest(string expr, int expected) {
	Lexer lex;
	vector<Token *> tokens;

	try {
		tokens = lex.tokenize(expr);

		Parser parser(tokens);
		int res = parser.parse();

		cout << "Expr: " << expr << " | Resultat: " << res << " | Attendu: " << expected;

		if(res == expected) cout << " [OK]";
		else cout << " [FAIL]";

		cout << endl;
    	}
    	catch(exception& err) {
        	cout << "Erreur sur '" << expr << "': " << err.what() << endl;
    	}
    	free_tokens(tokens);
}


void ConsoleUI::runAllTests() {
	cout << "=== SUITE DE TESTS ===" << endl;

	// Tests nominaux
	runTest("(((-1)*2)+3)", 1);
	runTest("((1+2)*(3+4))", 21);
	runTest("(5*3)", 15);
	runTest("((4*6)+1)", 25);
	runTest("(((2+3)-10)*2)", -10);

	// Tests d'erreurs
	cout << "\n=== CAS D'ERREURS ===" << endl;
	runTest("", 0);
	runTest("(+)", 0);
	runTest("(5/0)", 0);
}
