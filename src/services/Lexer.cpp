#include "Lexer.h"
#include <stdexcept>
#include <cctype> // pour isdigit

using namespace std;

int Lexer::readInteger(string expr, string &num) {
	int i;
	for (i = 0; i < expr.length() && isdigit(expr[i]); ++i) {
		num += expr[i];
	}
	return i - 1;
}

vector<Token *> Lexer::tokenize(string expr) {
	Token *curr;
	vector<Token *> tokens;

	for (int i = 0; i < expr.length(); ++i) {
		if (isdigit(expr[i])) {
		        string num;
		        i += readInteger(&expr[i], num);
		        curr = new Token(TokenType::INTEGER, num);
		} else {
	        	switch (expr[i]) {
			        case '(': curr = new Token(TokenType::LPARENTHESIS, "("); break;
			        case ')': curr = new Token(TokenType::RPARENTHESIS, ")"); break;
			        case '+': curr = new Token(TokenType::PLUSOPERATOR, "+"); break;
			        case '-': curr = new Token(TokenType::MINUSOPERATOR, "-"); break;
			        case '*': curr = new Token(TokenType::STAROPERATOR, "*"); break;
			        case '/': curr = new Token(TokenType::SLASHOPERATOR, "/"); break;
			        case ' ':
			        case '\t':
			        case '\n':
			          continue;
		        default:
          			throw runtime_error("Caractere inconnu: " + string(1, expr[i]));
        		}
		}
      		tokens.push_back(curr);
    	}
    	return tokens;
}
