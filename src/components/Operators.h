#pragma once
#include "Expression.h"
#include <stdexcept>

// Classes de base

class UnaryOp : public Expression {
public:
	virtual int compute(int right) = 0;
	void interpret(std::stack<int>& operands) override;
};

class BinaryOp : public Expression {
public:
	virtual int compute(int left, int right) = 0;
	void interpret(std::stack<int>& operands) override;
};

// Implémentations concrètes

class PlusUnaryOp : public UnaryOp {
	int compute(int right) override { return right; }
};

class MinusUnaryOp : public UnaryOp {
	int compute(int right) override { return -right; }
};

class PlusBinaryOp : public BinaryOp {
	int compute(int left, int right) override { return left + right; }
};

class MinusBinaryOp : public BinaryOp {
	int compute(int left, int right) override { return left - right; }
};

class StarBinaryOp : public BinaryOp {
	int compute(int left, int right) override { return left * right; }
};

class DivBinaryOp : public BinaryOp {
	int compute(int left, int right) override { return left / right; }
};
