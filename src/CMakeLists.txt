project(ComplexTree)
cmake_minimum_required(VERSION 3.10)

set(INCLUDE_DIRS
	tree/include
)

set(TREE_HEADERS
	${INCLUDE_DIRS}/Node.h
	${INCLUDE_DIRS}/TreeDrawer.h
	${INCLUDE_DIRS}/FormatConfig.h
)
source_group("tree\\include" FILES ${TREE_HEADERS})

set(TREE_SOURCES
	tree/FormatConfig.cpp
	tree/Node.cpp
	tree/TreeDrawer.cpp
)
source_group("tree" FILES ${TREE_SOURCES})

list(APPEND TREE_SOURCES ${TREE_HEADERS})

set(SOURCES
	main.cpp
	OptionsReader.h
	OptionsReader.cpp
)

set(SERIALIZER_SOURCES
	tree/serializers/TreeSerializer.h
	tree/serializers/TreeSerializer.cpp
)
source_group("tree\\serializers" FILES ${SERIALIZER_SOURCES})

set(DESERIALIZER_SOURCES
	tree/deserializers/INodeDeserializer.h
	tree/deserializers/NodeDeserializers.h
	tree/deserializers/TreeDeserializer.h
	tree/deserializers/TreeDeserializer.cpp
	tree/deserializers/StringHelper.h
)
source_group("tree\\deserializers" FILES ${DESERIALIZER_SOURCES})

add_executable(${PROJECT_NAME}
	${TREE_SOURCES}
	${SOURCES}
	${SERIALIZER_SOURCES}
	${DESERIALIZER_SOURCES}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
