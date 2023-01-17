#pragma once
#include <stdexcept>

class bad_range : public std::exception
{
public:
	bad_range(const char* text) : m_text(text)
	{
	}
	~bad_range()
	{
	}
	const char* what() const noexcept
	{
		return m_text;
	}
private:
	const char* m_text;
};


class bad_length : public std::exception
{
public:
	bad_length(const char* text) : m_text(text)
	{
	}
	~bad_length()
	{
	}
	const char* what() const noexcept
	{
		return m_text;
	}
private:
	const char* m_text;
};

