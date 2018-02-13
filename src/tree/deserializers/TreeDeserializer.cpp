#include "TreeDeserializer.h"

#include <iostream>

#include "FormatConfig.h"
#include "StringHelper.h"
#include "NodeDeserializers.h"

TreeDeserializer::TreeDeserializer(const char _delimeter)
	: m_delimeter(_delimeter)
{
	m_deserializers.push_back(std::make_unique<NodeDeserializer<int>>());
	m_deserializers.push_back(std::make_unique<NodeDeserializer<double>>());
	m_deserializers.push_back(std::make_unique<NodeDeserializer<std::string>>());
}

std::shared_ptr<Node> TreeDeserializer::deserialize(const std::string & _data) {
	while (!m_stack.empty()) {
		m_stack.pop();
	}

	std::vector<std::string> tokens = StringHelper::split(_data, m_delimeter);

	if (tokens.empty()) {
		return std::make_shared<Node>();
	}

	std::shared_ptr<Node> root = _deserializeNode(tokens[0]);

	if (root->isValid()) {
		m_stack.push(root);
		_addNodeFromPosition(tokens, 1);
	}

	return root;
}

void TreeDeserializer::_addNodeFromPosition(const std::vector<std::string> & _tokens, const size_t _position) {
	if (_position >= _tokens.size()) {
		return;
	}

	if (_tokens[_position] != FormatConfig::CHILDREN_LIST_END) {
		std::shared_ptr<Node> node = _deserializeNode(_tokens[_position]);
		if (node->isValid() && !m_stack.empty()) {
			m_stack.top()->addChild(node);
			m_stack.push(node);
		} else {
			std::cerr << "Misformed node at position " << _position << std::endl;
			return;
		}
	} else {
		m_stack.pop();
	}

	_addNodeFromPosition(_tokens, _position + 1);
}

std::shared_ptr<Node> TreeDeserializer::_deserializeNode(const std::string & _token) const {
	for (const std::unique_ptr<INodeDeserializer> & deserializer : m_deserializers) {
		std::shared_ptr<Node> node = deserializer->deserialize(_token);
		if (node->isValid()) {
			return node;
		}
	}

	return std::make_shared<Node>();
}
