#pragma once
#include "IntegerArrayExcp.h"

class IntegerArray
{
private:
	int m_lenght {};
	int* m_data {};
public:
	IntegerArray(int lenght);
	IntegerArray(const IntegerArray& a);
	~IntegerArray();
	
	// доступ по индексу
	int& operator[](int index);

	// копирование
	IntegerArray& operator=(const IntegerArray& a);

	// удаляет все элементы контейнера
	void erase();

	// возвращает число элементов в контейнере
	int size() const;
	
	// изменяет число элементов в контейнере
	void resize(int newLenght);
	
	// удаляет элемент с заданным индексом
	void remove(int index);

	// выводит строку значений всех элементов через пробел
	void print();

	// добавляет элемент в конец контейнера
	void push_back(int value);	

	// удаляет элемент в конце контейнера
	void pop_back();

	// добавляет элемент в начало контейнера
	void push_front(int value);

	// удаляет элемент в начале контейнера
	void pop_front();

	// возвращает индекс элемента с заданным значением
	int find(int value);

private:
	// создаёт новый контейнер
	void reallocate(int newLenght);

	// добавляет элемент по заданному индексу 
	void insertBefore(int value, int index);
};

