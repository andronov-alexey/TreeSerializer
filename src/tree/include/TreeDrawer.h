#pragma once

#include "Node.h"

class TreeDrawer {
public:
	void draw(const std::shared_ptr<Node> & _root) const;

private:
	void _drawNode(const std::shared_ptr<Node> & node, const std::string & _indent = std::string(), bool _isLastChild = true) const;
};
