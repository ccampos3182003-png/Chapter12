#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "Student.h"



class Table
{
private:
	struct Pair
	{
		int key;
		Student value;
	};

private:

	static const int MAX = 40;
	static const int NEVER_USED = -1;
	static const int PREVIOUSLY_USED = -2;
	int capacity;

	std::vector<Pair> array;

	int used;

	//convert/hash key into index
	int hash(int key) const;

	//find the next hash index
	int next_index(int index) const;

	//check if the key is -1 (NEVER_USED)
	bool is_vacant(int index) const;

public:

	//constructor
	Table(int cap = MAX);

	int size() const;

	bool insert(const Pair& entry);

	bool remove(int key);

	bool find_index(const int key, int& index) const;

	void display(int index) const;

	friend std::ostream& operator<<(std::ostream& outs, const Table& obj);
};

std::ostream& operator<<(std::ostream& outs, const Table& obj);