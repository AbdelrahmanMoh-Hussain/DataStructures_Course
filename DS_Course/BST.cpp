#include "BST.h"

BST::BST(int value)
{
	data = value;
	left = right = nullptr;
}

void BST::insert(int value)
{
	if (value < data)
	{
		if (!left)
		{
			left = new BST(value);
		}
		else 
			left->insert(value);
	}
	else if (value > data)
	{
		if (!right)
		{
			right = new BST(value);
		}
		else
			right->insert(value);
	}
}

void BST::get_inorder(vector<int>& values)
{
	if (left)
		left->get_inorder(values);
	values.push_back(data);
	if (right)
		right->get_inorder(values);
}

void BST::traversalInorder()
{
	if (left)
	{
		left->traversalInorder();
	}
	cout << data << ' ';
	if (right)
	{
		right->traversalInorder();
	}
}


bool BST::search(int value)
{
	BST* current = this;
	while (current)
	{
		if (value == current->data)
		{
			return true;
		}

		if (value < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return false;
}

bool BST::isBST(int mn = INT_MIN, int mx = INT_MAX)
{
	//Fix problem
	bool status = data > mn && data < mx;
	if (!status)
	{
		return false;
	}
	bool left_bst = !left || left->isBST(mn, data);
	if (!left_bst)
	{
		return false;
	}
	bool right_bst = !right || right->isBST(data, mx);
	return right_bst;

	//Wrong Soltion
	//if ((left && data < left->data) || (right && data > right->data))
	//{
	//	return false;
	//}
	//if ((left && !left->isBST()) || (right &&!right->isBST()))
	//{
	//	return false;
	//}
	//return true;

	////Another Solution
	///*bool left_bst = !left || data > left->data && left->isBST();
	//bool right_bst = !right || data > right->data && right->isBST();
	//return left_bst && right_bst;*/
}

bool BST::isBST2()
{
	vector<int> values;
	get_inorder(values);

	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] <= values[i-1])
		{
			return false;
		}
	}
	return true;
}

int BST::kth_smallest(int& k)
{
	if (k == 0)
	{
		return -1;
	}

	if (left)
	{
		int res = left->kth_smallest(k);
		if (k == 0)
		{
			return res;
		}
	}

	--k;
	if (k == 0)
	{
		return data;
	}

	if (right)
	{
		return right->kth_smallest(k);
	}

	return -1;
}

pair<bool, int> BST::succesor(int target)
{
	vector<BST*> ancestors;
	if (!findChain(ancestors, target))
	{
		return make_pair( false, -1 );
	}

	BST* child = getNext(ancestors);
	if (child->right)
	{
		return make_pair(true, child->right->getMin());
	}

	BST* parent = getNext(ancestors);
	while (parent && parent->right == child)
	{
		child = parent;
		parent = getNext(ancestors);
	}
	if (parent)
	{
		return make_pair(true, parent->data);
	}

	return make_pair(false, -1);
}

void BST::insertParent(int value)
{
	//cout << this->data << endl;
	if (value < data)
	{
		if (!left)
		{
			left = new BST(value);
			left->parent = this;
			//cout << left->data << ' ' << left->parent->data << endl;
		}
		else
			left->insertParent(value);
	}
	else if (value > data)
	{
		if (!right)
		{
			right = new BST(value);
			right->parent = this;
			//cout << right->data << ' ' << right->parent->data << endl;
		}
		else
			right->insertParent(value);
	}
}

pair<bool, int> BST::succesorParent(int target)
{
	BST* node = findNode(target);
	if (!node)
	{
		return make_pair(false, -1);
	}

	if (node->right)
	{
		return make_pair(true, node->right->getMin());
	}

	
	while (node->parent && node->parent->data < node->data)
	{
		BST* temp = node->parent;
		node = temp;
		node->parent = temp->parent;
	}

	if (node->parent)
	{
		return make_pair(true, node->parent->data);
	}
	return make_pair(false, -1);
}

void BST::searchSuccesor(deque<int>& q, vector<int>& ans, vector<int>& traversal)
{
	if (q.empty())
	{
		return;
	}

	if (left && q.front() < data)
	{
		left->searchSuccesor(q, ans, traversal);
		if (q.empty())
		{
			return;
		}
	}

	if (!traversal.empty() && traversal.back() == q.front())
	{
		ans.push_back(data);
		q.pop_front();
		if (q.empty())
		{
			return;
		}
	}
	traversal.push_back(data);

	if (right && q.front() >= data)
	{
		right->searchSuccesor(q, ans, traversal);
	}
}

bool  BST::isDegenerate(vector<int>& preorder)
{
	int mn = 0, mx = 100000;
	for (int i = 0; i < preorder.size(); i++)
	{
		if (preorder[i] < mn || preorder[i] > mx )
		{
			return false;
		}

		if (preorder[i] > preorder[i - 1])
		{
			mn = preorder[i - 1] + 1;
		}
		if (preorder[i] < preorder[i - 1])
		{
			mx = preorder[i - 1] - 1;
		}
	}
	return true;

	//Another Soltion
	/*for (int i = 0; i < preorder.size() -1; i++)
	{
		int j = i + 1;
		bool bigger = false;
		if (preorder[i] < preorder[j])
		{
			bigger = true;
		}
		j++;
		for (; j < preorder.size(); j++)
		{
			if (bigger && preorder[i] > preorder[j])
			{
				return false;
			}
			else if (!bigger && preorder[i] < preorder[j])
			{
				return false;
			}
		}
	}
	return true;*/
}

void BST::deleteValue(int target)
{
	if (data == target && !left && !right)
	{
		return;
	}
	deleteNode2(target, this);
}

BST* BST::deleteNodePre(int target, BST* node)
{
	if (!node)
	{
		return nullptr;
	}
	if (target < data)
	{
		node->left = deleteNodePre(target, node->left);
	}
	else if (target > data)
	{
		node->right = deleteNodePre(target, node->right);
	}
	else
	{
		BST* temp = node;
		if (!node->left && !node->right)
		{
			node = nullptr;
		}
		if (!node->right)
		{
			node->specialDelete(node->left);
		}
		if (!node->left) {
			node->specialDelete(node->right);
		}
		else
		{
			int mx = node->left->getMax();
			node->data = mx;
			node->left = deleteNodePre(mx, node->left);
			temp = nullptr;
		}

		if (temp)
		{
			delete temp;
		}
	}

	return node;
}

BST* BST::deleteNode2(int target, BST* node)
{
	if (!node)
	{
		return nullptr;
	}

	if (target < node->data)
	{
		node->left = deleteNode(target, node->left);
	}
	else if (target > node->data)
	{
		node->right = deleteNode(target, node->right);
	}
	else
	{
		BST* tmp = node;
		if (!node->left && !node->right)
		{
			node = nullptr;
		}
		else if (!node->right)
		{
			node = node->left;
		}
		else if (!node->left)
		{
			node = node->right;
		}
		else if (right && left)
		{
			//New code without recursion
			BST* cur = node->right;
			BST* par = nullptr;
			while (cur && cur->left)
			{
				par = cur;
				cur = cur->left;
			}

			node->data = cur->data;
			if (!cur->left && !cur->right)
			{
				parent->right = nullptr;
				delete cur;
			}
			else
			{
				par->left = cur->right;
			}
			tmp = nullptr;
		}

		if (tmp)
		{
			delete tmp;
		}
	}
	return node;
}

//Utalaits
BST* BST::getNext(vector<BST*>& ancestors)
{
	if (ancestors.size() == 0)
	{
		return nullptr;
	}
	BST* node = ancestors.back();
	ancestors.pop_back();
	return node;
}

BST* BST::findNode(int value)
{
	BST* current = this;
	while (current)
	{
		if (value == current->data)
		{
			return current;
		}

		if (value < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return nullptr;
}

int BST::getMin()
{
	/*if (!left)
	{
		return data;
	}
	return left->getMin();*/

	//Another soltion
	BST* current = this;
	while (current && current->left)
	{
		current = current->left;
	}
	return current->data;
}

int BST::getMax()
{
	BST* current = this;
	while (current && current->right)
	{
		current = current->right;
	}
	return current->data;
}

BST* BST::minNode()
{
	BST* current = this;
	while (current && current->left)
	{
		current = current->left;
	}
	return current;
}

bool BST::findChain(vector<BST*>& ancestors, int target)
{
	ancestors.push_back(this);
	if (target == data)
	{
		return true;
	}
	if (target < data)
	{
		return left && left->findChain(ancestors, target);
	}
	return right && right->findChain(ancestors, target);;
}

BST* BST::deleteNode(int target, BST* node)
{
	if (!node)
	{
		return nullptr;
	}

	if (target < node->data)
	{
		node->left = deleteNode(target, node->left);
	}
	else if (target > node->data)
	{
		node->right = deleteNode(target, node->right);
	}
	else
	{
		BST* tmp = node;
		if (!node->left && !node->right)
		{
			node = nullptr;
		}
		else if (!node->right)
		{
			node = node->left;
		}
		else if (!node->left)
		{
			node = node->right;
		}
		else if (right && left)
		{
			int mn = node->right->minNode()->data;
			node->right = deleteNode(mn, node->right);
			node->data = mn;
			tmp = nullptr;
		}

		if (tmp)
		{
			delete tmp;
		}
	}
	return node;
}

void BST::specialDelete(BST* child)
{
	data = child->data;
	left = child->left;
	right = child->right;
	delete child;
}
