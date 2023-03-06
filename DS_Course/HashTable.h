#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct PhoneEntry
{
	const static int LIMIT = 200000;
	string name;
	string phoneNum;

	PhoneEntry(string n, string pNum) {
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
class HashTable //Phone entry hash table expamle
{
private:
	int tableSize;
	vector<vector<PhoneEntry>> table;

public:
	HashTable(int size) {
		tableSize = size;
		table.resize(tableSize);
	}
	void put(PhoneEntry phone) {
		int idx = phone.hash() % tableSize;

		for (int i = 0; i < (int) table[idx].size(); i++)
		{
			if (table[idx][i].name == phone.name) {
				table[idx][i] = phone;
				
			}			
		}
		table[idx].push_back(phone);
	}
	bool remove(PhoneEntry phone) {
		int idx = phone.hash() % tableSize;
		for (int i = 0; i < (int)table[idx].size(); i++)
		{
			if (table[idx][i].name == phone.name) {
				swap(table[idx][i], table[idx].back());
				table[idx].pop_back();
				return true;
			}
		}
		return false;
	}
	bool get(PhoneEntry& phone) {
		int idx = phone.hash() % tableSize;
		for (int i = 0; i < (int)table[idx].size(); i++)
		{
			if (table[idx][i].name == phone.name) {
				phone = table[idx][i];
				return true;
			}
		}
		return false;
	}
	void printAll() {
		for (int i = 0; i < (int)table.size(); i++)
		{
			cout << i << ": \n";
			for (int j = 0; j < table[i].size(); j++)
			{
				table[i][j].print();
			}
			cout << endl;
		}
	}
};

