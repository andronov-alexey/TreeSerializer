#include "TreeDrawer.h"

#include <iostream>
#include <cassert>
#include <string>

void TreeDrawer::draw(const std::shared_ptr<Node> & _root) const {
	std::cout << "-------------------------start-----------------------------" << std::endl;

	_drawNode(_root);

	std::cout << "--------------------------end------------------------------" << std::endl;
};

void TreeDrawer::_drawNode(const std::shared_ptr<Node> & node, const std::string & _indent, bool _isLastChild) const {
	if (!node->isValid()) {
		return;
	}

	std::string treeNode;

	switch (node->getType()) {
		case Node::Type::INTEGER: {
			int value = std::any_cast<int>(node->getValue());
			treeNode = std::to_string(value);
			break;
		}
		case Node::Type::DOUBLE: {
			double value = std::any_cast<double>(node->getValue());
			treeNode = std::to_string(value);
			break;
		}
		case Node::Type::STRING: {
			treeNode = '\"' + std::any_cast<std::string>(node->getValue()) + "\"";
			break;
		}
		default: {
			assert(false && "Node drawing of this type is not implemented");
			break;
		}
	}

	std::cout << _indent + "+- " + treeNode << std::endl;

	for (size_t i = 0; i < node->getChildren().size(); i++) {
		_drawNode(
			node->getChildren()[i],
			_indent + (_isLastChild ? "   " : "|  "),
			i + 1 == node->getChildren().size()
		);
	}
}
