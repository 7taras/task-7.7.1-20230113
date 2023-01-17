#include "IntegerArray.h"
#include <iostream>
#include <stdexcept>

IntegerArray::IntegerArray(int lenght) : m_lenght(lenght)
{	
	if (lenght <= 0)
	{
		throw bad_length("Error. Attempt to exceed implementation defined length limit");
	}
	m_data = new int[lenght] {};	
}

IntegerArray::IntegerArray(const IntegerArray& a)
{
	reallocate(a.size());

	for (int index{ 0 }; index < m_lenght; ++index)
	{
		m_data[index] = a.m_data[index];
	}
}

IntegerArray::~IntegerArray()
{
	delete[] m_data;
}

void IntegerArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_lenght = 0;
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= m_lenght)
	{
		//delete[] m_data;
		throw bad_range("Error. Attempt to access elements out of defined range");
	}	
	return m_data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
	{
		return *this;
	}

	reallocate(a.size());

	for (int index{ 0 }; index < m_lenght; ++index)
	{
		m_data[index] = a.m_data[index];
	}
	return *this;
}

int IntegerArray::size() const
{
	return m_lenght;
}

void IntegerArray::reallocate(int newLenght)
{
	erase();
	if (newLenght <= 0) 
	{
		return;
	}
	m_data = new int[newLenght] {};
	m_lenght = newLenght;
}

void IntegerArray::resize(int newLenght)
{
	if (newLenght == m_lenght)
	{
		return;
	}
	if (newLenght <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLenght] {};

	if (m_lenght > 0)
	{
		int elementsToCopy{ newLenght > m_lenght ? m_lenght : newLenght };
		for (int index{ 0 }; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}
	}

	delete[] m_data;
	m_data = data;
	m_lenght = newLenght;
}

void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0 || index > m_lenght)
	{
		//delete[] m_data;
		throw bad_range("Error. Attempt to access elements out of defined range");
	}

	int* data{ new int[m_lenght + 1] };
	for (int before{ 0 }; before < index; ++before)
	{
		data[before] = m_data[before];
	}
	data[index] = value;
	for (int after{ index }; after < m_lenght; ++after)
	{
		data[after + 1] = m_data[after];
	}
	delete[] m_data;
	m_data = data;
	++m_lenght;
}

void IntegerArray::remove(int index)
{	
	if (index < 0 || index >= m_lenght)
	{
		//delete[] m_data;
		throw bad_range("Error. Attempt to access elements out of defined range");
	}

	if (m_lenght == 1)
	{
		erase();
		return;
	}

	int* data{ new int[m_lenght - 1] };
	for (int before{ 0 }; before < index; ++before)
	{
		data[before] = m_data[before];
	}
	for (int after{ index + 1 }; after < m_lenght; ++after)
	{
		data[after - 1] = m_data[after];
	}
	delete[] m_data;
	m_data = data;
	--m_lenght;
}

void IntegerArray::print()
{
	for (auto index = 0; index < size(); ++index)
	{
		std::cout << m_data[index] << ' ';
	}
	std::cout << std::endl;
}

void IntegerArray::push_back(int value)
{
	insertBefore(value, m_lenght);
}

void IntegerArray::pop_back()
{
	if (m_lenght <= 0)
	{
		return;
	}
	
	remove(m_lenght - 1);
}

void IntegerArray::push_front(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::pop_front()
{
	if (m_lenght <= 0)
	{
		return;
	}

	remove(0);
}

int IntegerArray::find(int value)
{
	for (auto index = 0; index < size(); ++index)
	{
		if (m_data[index] == value)
		{
			return index;
		}
	}
	return -1;
}