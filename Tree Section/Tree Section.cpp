// Tree Section.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;

void print(Node* node) {
    if (!node)
    {
        return;
    }
    cout << node->data << ' ';
    print(node->left);
    print(node->right);
}

int main()
{
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    root->left = node2;
    root->right = node3;
    node2->right = node4;
    print(root);
}


