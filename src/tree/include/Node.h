#pragma once

#include <memory>
#include <vector>
#include <any>

class Node {
public:
	enum class Type {
		UNKNOWN,
		INTEGER,
		DOUBLE,
		STRING,
	};

public:
	template<typename T>
	Node::Node(Type _type, const T & _value)
		: m_type(_type)
		, m_data(std::make_any<T>(_value))
	{}

	Node();

	bool isValid() const;

	std::any getValue() const;

	Type getType() const;

	void addChild(const std::shared_ptr<Node> & _child);

	std::vector<std::shared_ptr<Node>> getChildren() const;

private:
	const Type m_type;
	const std::any m_data;
	std::vector<std::shared_ptr<Node>> m_children;
};
