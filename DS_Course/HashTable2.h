#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct PhoneEntry2
{
	const static int LIMIT = 200000;
	string name;
	string phoneNum;

	PhoneEntry2(string n, string pNum) {
		name = n;
		phoneNum = pNum;
	}
	int hash() {
		return hashString(name, LIMIT);
	}

	int hashString(string s, int n) {
		long long sum = 0;
		for (int i = 0; i < (int)s.size(); i++)
		{
			sum = sum * 26 + s[i] - 'a';
		}
		return abs(sum / n);
	}
	void print() {
		cout << "Name: " << name << "\tPhone number: " << phoneNum << endl;
	}
};
class HashTable2
{
private:
	int tableSize;
	vector<PhoneEntry2*> table;
	PhoneEntry2* deletedItem = new PhoneEntry2("", "");

public:
	HashTable2(int size) {
		tableSize = size;
		table.resize(size);
	}
	bool put(PhoneEntry2 phone) {
		int idx = phone.hash() % tableSize;

		for (int i = 0; i < tableSize; i++)
		{
			if (table[idx] == deletedItem || !table[idx]) {
				table[idx] = new PhoneEntry2(phone.name, phone.phoneNum);
				return true;
			}
			else if (table[idx]->name == phone.name) {
				table[idx]->phoneNum = phone.phoneNum;
				return true;
			}
			idx = (idx + 1) % tableSize;
		}
		return false;
	}
	bool remove(PhoneEntry2 phone) {
		int idx = phone.hash() % tableSize;

		for (int i = 0; i < tableSize; i++)
		{
			if (!table[idx])
			{
				break;
			}
			if (table[idx] != deletedItem && table[idx]->name == phone.name) {
				delete table[idx];
				table[idx] = deletedItem;
				return true;
			}
			idx = (idx + 1) % tableSize;
		}
		return false;
	}
	bool get(PhoneEntry2& phone) {
		int idx = phone.hash() % tableSize;

		for (int i = 0; i < tableSize; i++)
		{
			if (!table[idx])
			{
				break;
			}
			if (table[idx] != deletedItem && table[idx]->name == phone.name) {
				phone.phoneNum = table[idx]->phoneNum;
				return true;
			}
			idx = (idx + 1) % tableSize;
		}
		return false;
	}
	void printAll() {
		for (int i = 0; i < tableSize; i++)
		{
			cout << i << "";
			if (table[i] == deletedItem)
			{
				cout << "X ";
			}
			else if(!table[i])
			{
				cout << "E ";
			}
			else {
				table[i]->print();
			}
		}
	}
};

