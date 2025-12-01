#include "Operators.h"

using namespace std;

void UnaryOp::interpret(stack<int>& operands) {
	if (operands.empty()) throw runtime_error("Opérande manquant pour opérateur unaire");
	int right = operands.top();
	operands.pop();
	operands.push(compute(right));
}

void BinaryOp::interpret(stack<int>& operands) {
	if (operands.size() < 2) throw runtime_error("Opérande manquante pour opérateur binaire");
	int right = operands.top(); operands.pop();
	int left = operands.top(); operands.pop();
	operands.push(compute(left, right));
}

int DivBinaryOp::compute(int left, int right) {
	if (right == 0) throw runtime_error("Division par zero");
	return left / right;
}
