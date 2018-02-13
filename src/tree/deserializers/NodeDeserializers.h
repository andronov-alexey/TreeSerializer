#pragma once

#include <memory>
#include <string>
#include <cctype>

#include "INodeDeserializer.h"

template <typename T>
class NodeDeserializer;

template <>
class NodeDeserializer<int> : public INodeDeserializer {
public:
	std::shared_ptr<Node> deserialize(const std::string & _token) const override {
		bool isDigitsOnly = true;
		for (size_t i = 0; isDigitsOnly && i < _token.size(); i++) {
			isDigitsOnly &= (std::isdigit(_token[i]) != 0);
		}

		if (isDigitsOnly) {
			int value = std::stoi(_token);
			return std::make_shared<Node>(Node::Type::INTEGER, value);
		}

		return std::make_shared<Node>();
	};
};

template <>
class NodeDeserializer<double> : public INodeDeserializer {
public:
	std::shared_ptr<Node> deserialize(const std::string & _token) const override {
		if (_token.find('.') != std::string::npos) {
			double value = std::stod(_token);
			return std::make_shared<Node>(Node::Type::DOUBLE, value);
		}

		return std::make_shared<Node>();
	};
};

template <>
class NodeDeserializer<std::string> : public INodeDeserializer {
public:
	std::shared_ptr<Node> deserialize(const std::string & _token) const override {
		if (_token.size() > 1 &&
			_token[0] == '\"' &&
			_token[_token.size() - 1] == '\"'
		) {
			std::string value = _token.substr(1, _token.size() - 2);
			return std::make_shared<Node>(Node::Type::STRING, value);
		}

		return std::make_shared<Node>();
	};
};
