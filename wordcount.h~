#include <iostream>
#include <string>
#include <vector>

class Wordcount{
	public:
		/**
		 * This is the default contructor for Wordcount. Initializes m_count to 0
		 */
		Wordcount();
		/*
		 * This constructor asks for the word.
		 * @param word This word will become the value of m_word
		 */
		Wordcount(std::string word);

		/**
		 * This will change the current m_word to the new word specified.
		 * @param word This word will become the value of m_word
		 */
		void set_word(std::string word);
		/**
		 * This function will add the count of the word by one and add the value of the line number it was one.
		 * @param line_number the line_number that will be added.
		 */
		void add_count(int line_number);

		/**
		 * This will print the word, the count, and the line numbers it was one.
		 */
		void print() const;
		/**
		 * This will return the value of m_word
		 * @return this will return the vale of m_word
		 */
		std::string print_word() const;

	
	private:
		std::string m_word;
		std::vector<int> m_line_number;
		int m_count;
};
