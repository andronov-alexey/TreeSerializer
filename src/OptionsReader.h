#pragma once

#include <string>
#include <map>

class OptionsReader {
public:
	OptionsReader(char * _arguments[], int _count);

	bool hasKey(const std::string & _key) const;

	std::string getValue(const std::string & _key) const;

private:
	std::map<std::string, std::string> m_options;
};
