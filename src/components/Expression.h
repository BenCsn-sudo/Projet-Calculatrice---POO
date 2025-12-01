#pragma once
#include <stack>
#include <iostream>

class Expression {
public:
	virtual ~Expression() = default;
	virtual void interpret(std::stack<int>& operands) = 0;
};
