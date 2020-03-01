#include <iostream>
#include <string>
#include <list>
#include <stdio.h>

////////////////////////////////////////////// задание 1 время выполнения - 2 часа

std::string binary_str(int number)
{
	std::string str;
	size_t number_size = sizeof(number) * 8;
	str.resize(number_size);
	int min = 0;
	if (number < 0)
		min = -1;
	size_t current_index = number_size - 1;
	while( number != min)
	{
		if ((number&1) == 0)
			str[current_index] = '0';
		else
			str[current_index] = '1';
		number = number>>1;
		current_index--;
	}
	char filler = min == 0 ? '0' : '1';
	while( current_index != 0 ){
		str[current_index] = filler;
		current_index--;
	}
	str[0] = filler;
	return str;
}

void printBinaryFromat(int number)
{
	std::cout << binary_str(number) << std::endl;
}

///////////////////////////////////////////// задание 2 время выполнения - 1 час
void RemoveDups(char* str)
{
	int change = 0;
	if (str != nullptr)
	{
		int i = 0;
		for(; str[i] != '\0'; i++)
		{
			if ( str[i] == str[i+1])
				change++;
			else
				str[i-change] = str[i];
		}
		str[i-change] = str[i];
	}
}

///////////////////////////////////////////// задание 3 время выполнения - 3 часа
// структуру ListNode модифицровать нельзя
struct ListNode {
	ListNode *      prev;
	ListNode *      next;
	ListNode *      rand; // указатель на произвольный элемент данного списка, либо NULL
	std::string     data;
};

class List {
public:
	~List()
	{
		clear();
	}
	void Serialize   (FILE * file)  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
	{
		if (head != nullptr){
			for (ListNode* curr = head; curr != nullptr; curr = curr->next)
			{
				fwrite(curr->data.data(), sizeof(char), curr->data.size(), file);
			}
		}
	}
	void Deserialize (FILE * file)  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
	{
		clear();
		char buffer[unit_lengt];
		size_t buffer_size =  fread(&buffer, sizeof(char), unit_lengt, file);
		head = new ListNode();
		tail = head;
		if (buffer_size != 0){
			tail->data.append(buffer, buffer_size);
			m_size++;
			while ( buffer_size == unit_lengt )
			{
				buffer_size =  fread(&buffer, sizeof(char), unit_lengt, file);
				append(buffer, buffer_size);
			}
		}
	}
	size_t size() { return m_size; }
	bool isEmpty()
	{
		return m_size == 0;
	}
private:
	ListNode *      head = nullptr;
	ListNode *      tail = nullptr;
	void clear()
	{
		ListNode* currentNode = head; // initialize current node to root
		while (currentNode != nullptr)
		{
			ListNode* nextNode = currentNode->next;    // get next node
			delete currentNode;                         // delete current
			currentNode = nextNode;                     // set current to "old" next
		}
		head = nullptr;
		tail = nullptr;
		m_size = 0;
	}
	void append(char * data, size_t data_size)
	{
		m_size++;
		ListNode* new_tall = new ListNode();
		new_tall->data.reserve(data_size);
		new_tall->data.append(data, data_size);
		tail->next = new_tall;
		new_tall->prev = tail;
		tail = new_tall;
	}
	size_t	m_size = 0;
	const size_t unit_lengt = 256;
};

int main(void)
{
	return 0;
}
