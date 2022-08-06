class Node {
public:
	int data;
	int idx;
	Node* next;
	Node* prev;

	Node(int data, int idx);
};

class ArrayLinkedList
{
public:
	Node* head;
	Node* tail;
	int length;

private:
	void link(Node* first, Node* second);
	Node* embedAfter(Node* nodeBefore, int data, int idx);
	Node* getIdx(int idx, bool setMissing = false);

public:
	ArrayLinkedList();
	ArrayLinkedList(int length);
	void setValue(int value, int idx);
	int getValue(int idx);
	void print();
	void printNonZero();
	void add(ArrayLinkedList other);
};
