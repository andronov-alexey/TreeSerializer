#include "OptionsReader.h"

#include <iostream>

OptionsReader::OptionsReader(char * _arguments[], int _count) {
	for (int i = 0; i < _count; i++) {
		std::string key = _arguments[i];
		bool isValidKey = !key.empty() && key[0] == '-';
		if (isValidKey) {
			std::string value;
			if (i + 1 < _count) {
				value = _arguments[i + 1];
				i++;
			}
			m_options[key] = value;
		} else {
			std::cerr << "Parameter '" << key << "' is not a valid option" << std::endl;
		}
	}
}

bool OptionsReader::hasKey(const std::string & _key) const {
	return m_options.count(_key) != 0;
}

std::string OptionsReader::getValue(const std::string & _key) const {
	return hasKey(_key) ? m_options.at(_key) : "";
}
