#include "HashTable.h"

//convert/hash key into index
 int Table::hash(int key) const
{
	return key % capacity;
}

//find the next hash index
 int Table::next_index(int index) const
{
	return ((index + 1) % capacity);
}

//check if the key is -1 (NEVER_USED)
 bool Table::is_vacant(int index) const
{
	return array[index].key == NEVER_USED;
}

//constructor
 Table::Table(int cap)
{
	capacity = cap;
	used = 0;
	array.resize(capacity);
	for (int i = 0; i < capacity; i++)
		array[i].key = NEVER_USED;

}

 int Table::size() const
{
	return used;
}

 bool Table::insert(const Pair& entry)
{
	int index = 0;
	if (!find_index(entry.key, index))
	{
		index = hash(entry.key);
		while (!is_vacant(index))
			index = next_index(index);
		++used;

	}

	array[index] = entry;

	return true;

}

bool Table::remove(int key)
{
	int index = 0;

	if (find_index(key, index))
	{
		array[index].key = PREVIOUSLY_USED;
		--used;
		return true;
	}

	return false;
}

bool Table::find_index(const int key, int& index) const
{
	int count = 0;

	index = hash(key);

	while ((count < capacity) && (!is_vacant(index)) && array[index].key != key)
	{
		++count;
		index = next_index(index);
	}

	return (array[index].key == key);
}

void Table::display(int index) const
{
	std::cout << "\n\tStudent record found at index #" << index;
	std::cout << "\n\t\tStudentID    : " << array[index].value.GetID();
	std::cout << "\n\t\tName         : " << array[index].value.GetName();
	std::cout << "\n\t\tMajor        : " << array[index].value.GetMajor();
	std::cout << "\n\t\tGPA          : " << array[index].value.GetGPA() << '\n';
}

std::ostream& operator<<(std::ostream& outs, const Table& obj)
{
	if (obj.size() != 0)
	{
		outs << "\n\t\tRecord(s):";
		for (int i = 0; i < obj.capacity; i++)
			if (obj.array[i].value.GetID() > 0)
				outs << "\n\t\t[" << std::setw(2) << i << "] - " << obj.array[i].value.GetID() << ", " << obj.array[i].value.GetName() << ", " << obj.array[i].value.GetMajor() << ", " << obj.array[i].value.GetGPA();
			//else
			//	outs << "\n\t\t[" << std::setw(2) << i << "] - empty";
	}
	else
		outs << "\n\t\tERROR: No record found.";
	return outs;
}