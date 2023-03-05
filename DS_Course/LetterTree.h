#pragma once
#include<iostream>
using namespace std;

class LetterNode {
public:
	char value{};
	char child[26] {};
	bool endWord;

public:

};
class LetterTree
{
private:
	static const int MAX_SIZE = 26;
	LetterTree* child[MAX_SIZE]{0};
	bool isEndWord;

public:
	void insert(string s, int idx = 0) {
		if (idx = (int)s.size())
		{
			isEndWord = true;
		}
		else
		{
			int cur = s[idx] - 'a';
			if (child[cur] == 0)
			{
				child[cur] = new LetterTree();
			}
			child[cur]->insert(s, idx + 1);
		}
	}

	bool isWordExist(string s, int idx = 0) 
	{
		if (idx = (int)s.size())
		{
			return isEndWord;
		}

		int cur = s[idx] - 'a';
		if (!child[cur])
			return false;
		return child[cur]->isWordExist(s, idx + 1);
	}

	bool isPrefix(string s, int idx = 0) {
		if (idx = (int)s.size())
		{
			return true;
		}

		int cur = s[idx] - 'a';
		if (!child[cur])
			return false;
		return child[cur]->isWordExist(s, idx + 1);
	}
};

