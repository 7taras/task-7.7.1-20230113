#pragma once
class IntegerArray
{
private:
	int m_lenght {};
	int* m_data {};
public:
	IntegerArray() = default;
	IntegerArray(int lenght) : m_lenght(lenght)
	{
		if (lenght > 0)
		{
			m_data = new int[lenght] {};
		}
	}
};

