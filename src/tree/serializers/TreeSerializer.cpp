#include "TreeSerializer.h"

#include <cassert>

#include "FormatConfig.h"

TreeSerializer::TreeSerializer(const char _delimeter)
	: m_delimeter(_delimeter)
{
}

std::string TreeSerializer::serialize(const std::shared_ptr<Node> & _root) {
	std::string rawData;

	if (_root->isValid()) {
		_serializeTree(_root, rawData);
	}

	return rawData;
}

void TreeSerializer::_serializeTree(const std::shared_ptr<Node> & _node, std::string & _data) {
	_data += _serializeNode(_node) + m_delimeter;

	for (const std::shared_ptr<Node> & child : _node->getChildren()) {
		_serializeTree(child, _data);
	}

	_data += FormatConfig::CHILDREN_LIST_END + m_delimeter;
}

std::string TreeSerializer::_serializeNode(const std::shared_ptr<Node> & _node) const {
	switch (_node->getType()) {
		case Node::Type::INTEGER: {
			int value = std::any_cast<int>(_node->getValue());
			return _removeTrailingZeroes(std::to_string(value));
		}
		case Node::Type::DOUBLE: {
			double value = std::any_cast<double>(_node->getValue());
			return _removeTrailingZeroes(std::to_string(value));
		}
		case Node::Type::STRING: {
			return '\"' + std::any_cast<std::string>(_node->getValue()) + '\"';
		}
		default: {
			assert(false && "Node serialization of this type is not implemented");
			return std::string();
		}
	}
}

std::string TreeSerializer::_removeTrailingZeroes(std::string _source) const {
	return _source.erase(_source.find_last_not_of('0') + 1, std::string::npos);
}
