#include "BinaryTree.h"
#include <iostream>
#include<algorithm>
#include <assert.h>
#include <math.h>
using namespace std;

int BinaryTree::getNodeLevel(int value)
{
	int level = 0;
	BinaryTree* current = this;

	while (current)
	{
		if (current->data == value)
		{
			return level;
		}

		if (current->left && current->left->find(value))
		{
			current = current->left;
		}
		else if (current->right && current->right->find(value))
		{
			current = current->right;
		}
		level++;
	}
	return -1;
}

BinaryTree::BinaryTree(int value)
{
	data = value;
	left = right = nullptr;
}

void BinaryTree::inOrder()
{
	if (left)
	{
		left->inOrder();
	}
	cout << data << ' ';
	if (right)
	{
		right->inOrder();
	}
}

void BinaryTree::add(vector<Node> value , vector<char> path)
{
	assert(value.size() == path.size());
	BinaryTree* current = this;
	for (int i = 0; i < value.size(); i++)
	{
		if (path[i] == 'L')
		{
			if (!current->left)
			{
				current->left = new BinaryTree(value[i].data);
			}
			else
			{
				assert(current->left->data == value[i].data);
			}
			current = current->left;
		}
		else
		{
			if (!current->right)
			{
				current->right = new BinaryTree(value[i].data);
			}
			else
			{
				assert(current->right->data == value[i].data);
			}
			current = current->right;
		}
	}
}

int BinaryTree::max()
{
	int n1, n2, n3;
	n1 = n2 = n3 = 0;
	if (left)
	{
		n1 = left->max();
	}
	n2 = data;
	if (right)
	{
		n3 = right->max();
	}
	
	return std::max(n1, std::max(n2, n3));
}

int BinaryTree::getHeight()
{
	int height = 0;	
	if (!left && !right)
	{
		return 0;
	}

	height++;
	int leftHeight, rightHeight;
	leftHeight = rightHeight = 0;
	if (left)
	{
		leftHeight = left->getHeight();
	}
	if (right)
	{
		rightHeight = right->getHeight();
	}
	height += std::max(leftHeight, rightHeight);

	return height;

	//Another soltion
	/*int res = 0;
	if (left)
	{
		res = std::max(res, 1 + left->getHeight());
	}
	if (right)
	{
		res = std::max(res, 1 + right->getHeight());
	}
	return res;*/
}

int BinaryTree::countNodes()
{
	int nodesNum = 1;
	if (left)
	{
		nodesNum += left->countNodes();
	}
	if (right)
	{
		nodesNum += right->countNodes();
	}

	return nodesNum;
}

int BinaryTree::countLeafNodes()
{
	int leafNum = 0;
	if (!left && !right)
	{
		leafNum++;
	}

	if (left)
	{
		leafNum += left->countLeafNodes();
	}
	if (right)
	{
		leafNum += right->countLeafNodes();
	}
	return leafNum;
}

bool BinaryTree::find(int value)
{
	if (data == value)
	{
		return true;
	}

	if ((left && left->find(value)) || (right && right->find(value)))
	{
		return true;
	}
	return false;

	//Another soltion
	/*int res = value == data;
	if (!res && left)
	{
		res = left->find(value);
	}
	if (!res && right)
	{
		res = right->find(value);
	}
	return res;*/
}

bool BinaryTree::isPerfect(int h)
{
	if (h == -1)
	{
		h = getHeight();
	}

	if ((!left && right) || (left && !right))
	{
		return false;
	}
	if (!left && !right )
	{
		return h == 0;
	}
	
	return left->isPerfect(h - 1) && right->isPerfect(h - 1);

	//Another soltion
	//return (getHeight() == log2(countNodes() + 1) - 1);
}

void BinaryTree::clear()
{
	if (!this)
	{
		return;
	}
	left->clear();
	right->clear();
	delete this;
}

BinaryTree::~BinaryTree()
{
	clear();
}

void BinaryTree::inOrderIterative()
{
	stack<pair<BinaryTree*, bool>> nodes;
	nodes.push({ this, false });
	while (!nodes.empty())
	{
		BinaryTree* cur = nodes.top().first;
		bool done = nodes.top().second;
		nodes.pop();

		if (done)
		{
			cout << cur->data << ' ';
		}
		else
		{
			if (cur->right)
			{
				nodes.push({cur->right, false});
			}
			nodes.push({ cur, true });
			if (cur->left)
			{
				nodes.push({ cur->left, false });
			}
		}
	}
	cout << endl;
}

void BinaryTree::traverseLeftBoundry()
{
	BinaryTree* current = this;
	while (true)
	{
		cout << current->data << ' ';
		if (current->left)
		{
			current = current->left;
		}
		else
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				break;
			}
		}
	}

	//Another Soltion
	/*cout << data << ' ';
	
	if (left)
	{
		left->traverseLeftBoundry();
	}
	else if (right)
	{
		right->traverseLeftBoundry();
	}*/
}

int BinaryTree::getDiameter()
{
	return left->getHeight() + right->getHeight() + 2;
}

void BinaryTree::breadthTraversal()
{
	queue<BinaryTree*> q;
	q.push(this);
	while (!q.empty())
	{
		if (!q.front())
		{
			q.pop();
			continue;
		}
		q.push(q.front()->left);
		q.push(q.front()->right);
		cout << q.front()->data << ' ';
		q.pop();
	}
	cout << endl;
}

