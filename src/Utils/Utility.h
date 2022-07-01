#pragma once
#include <math.h>
#include <string>
#include <vector>
#include <random>

template<typename T>
T getRandomInRange(T a, T b)
{
    static std::random_device rd;
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<T> uni(a, b);
	return uni(rng);
}

class StringList
{
public:
	StringList();
	bool contains(const std::string& string) const;
	StringList& operator<<(const std::string& string);
	std::vector<std::string>::iterator begin();
	std::vector<std::string>::iterator end();
	std::vector<std::string>::const_iterator begin() const;
	std::vector<std::string>::const_iterator end() const;
private:
	std::vector<std::string> m_strings;
};
