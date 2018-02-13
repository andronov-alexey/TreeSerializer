#pragma once

#include <memory>
#include <string>

#include "Node.h"

class INodeDeserializer {
public:
	virtual std::shared_ptr<Node> deserialize(const std::string & _token) const = 0;
};
