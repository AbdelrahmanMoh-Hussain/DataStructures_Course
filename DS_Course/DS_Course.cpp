// DS_Course.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "ArrayStack.h"
#include"LinkedListStack.h"
//#include "TwoStackArray.h"
using namespace std;


int precedence(char op) {
	if (op == '+' || op == '-')
	{
		return 1;
	}
	else if (op == '*' || op == '/')
	{
		return 2;
	}
	else if (op == '^')
	{
		return 3;
	}
	return 0;
}

string infixtoPostfix(string& infix) {
	ArrayStack st(10);
	string postfix = "";
	infix += '-';
	st.push('#');
	for (int i = 0; i < infix.size(); i++)
	{
		if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'))
		{
			while (st.peek() != '(' && precedence(st.peek()) >= precedence(infix[i]) && !(st.peek() == '^' && infix[i] == '^'))
			{
				postfix += st.peek();
				st.pop();
			}
			st.push(infix[i]);
		}
		else if (infix[i] == '(')
		{
			/*string subInfix = "";
			for (int j = i + 1; j < infix.size(); j++)
			{
				i++;
				if (infix[i] == ')')
				{
					break;
				}
				subInfix += infix[i];
			}
			postfix += infixtoPostfix(subInfix);*/
			st.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (st.peek() != '(')
			{
				postfix += st.peek();
				st.pop();
			}
			st.pop();
		}
		else
		{
			postfix += infix[i];
		}
	}

	return postfix;
}

string infixtoPrefix(string infix)
{
	ArrayStack st(10);
	string reversedPrefix = "";
	for (int i = infix.size(); i >= 0; i--)
	{
		if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'))
		{
			while (!st.isEmpty())
			{
				if (precedence(st.peek()) > precedence(infix[i]) || precedence(st.peek()) == precedence(infix[i]) && infix[i] == '^')
				{
					reversedPrefix += st.peek();
					st.pop();
				}
				else
				{
					break;
				}
			}
			st.push(infix[i]);
		}
		else
		{
			reversedPrefix += infix[i];
		}
	}
	while (!st.isEmpty())
	{
		reversedPrefix += st.peek();
		st.pop();
	}
	string prefix = "";
	for (int i = reversedPrefix.size(); i >= 0; i--)
	{
		prefix += reversedPrefix[i];
	}
	return prefix;
}

int main()
{
	cout << infixtoPrefix("4^3^2") << endl;
}

