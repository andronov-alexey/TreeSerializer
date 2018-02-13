#pragma once

#include <memory>
#include <string>
#include <stack>

#include "INodeDeserializer.h"

class TreeDeserializer {
public:
	TreeDeserializer(const char _delimeter);

	std::shared_ptr<Node> deserialize(const std::string & _data);

private:
	void _addNodeFromPosition(const std::vector<std::string> & _tokens, const size_t _position);
	std::shared_ptr<Node> _deserializeNode(const std::string & _token) const;

private:
	const char m_delimeter;
	std::stack<std::shared_ptr<Node>> m_stack;
	std::vector<std::unique_ptr<INodeDeserializer>> m_deserializers;
};
