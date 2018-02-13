project(ComplexTree)
cmake_minimum_required(VERSION 3.10)

add_definitions(
	-DUNICODE
	-D_UNICODE
)

FILE(GLOB DOC_FILES "README.md" "docs/*")
add_custom_target(docs SOURCES ${DOC_FILES})

add_subdirectory(src)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ComplexTree)
