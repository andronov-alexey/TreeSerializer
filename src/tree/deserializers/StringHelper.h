#pragma once

#include <vector>
#include <string>
#include <sstream>

class StringHelper {
public:
	static
	std::vector<std::string> split(const std::string & _string, const char _delimeter) {
		std::stringstream ss(_string);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(ss, token, _delimeter)) {
			tokens.push_back(token);
		}

		return tokens;
	}
};
