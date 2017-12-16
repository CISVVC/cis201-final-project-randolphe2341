#include "wordcount.h"


Wordcount::Wordcount()
{
	int m_count = 0;
}

Wordcount::Wordcount(std::string word)
{
	m_word = word;
}

void Wordcount::set_word(std::string word)
{
	m_word = word;
}

void Wordcount::add_count(int line_number)
{
	m_line_number.push_back(line_number);
	m_count++;
}

void Wordcount::print() const
{
	std::cout << m_word << " : " << m_count << " : ";
	for (int i = 0; i < m_line_number.size(); i++)
	{
		std::cout << m_line_number[i] << " ";
	}
	std::cout << std::endl;
}

std::string Wordcount::print_word() const
{
	return m_word;
}
