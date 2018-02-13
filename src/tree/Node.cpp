#include "Node.h"

Node::Node()
	: m_type(Type::UNKNOWN)
{
}

bool Node::isValid() const {
	return m_type != Type::UNKNOWN;
}

std::any Node::getValue() const {
	return m_data;
}

Node::Type Node::getType() const {
	return m_type;
}

void Node::addChild(const std::shared_ptr<Node> & _child) {
	m_children.push_back(_child);
}

std::vector<std::shared_ptr<Node>> Node::getChildren() const {
	return m_children;
}
