#pragma once

#include <memory>
#include <string>

#include "Node.h"

class TreeSerializer {
public:
	TreeSerializer(const char _delimeter);

	std::string serialize(const std::shared_ptr<Node> & _root);

private:
	void _serializeTree(const std::shared_ptr<Node> & _node, std::string & _data);
	std::string _serializeNode(const std::shared_ptr<Node> & _node) const;
	std::string _removeTrailingZeroes(std::string _source) const;

private:
	const char m_delimeter;
};
