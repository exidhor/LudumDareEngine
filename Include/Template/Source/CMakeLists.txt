# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Creating the executable target
ADD_EXECUTABLE(${TARGET_COMPILE} "")

# Getting sources
FILE(GLOB_RECURSE SOURCE_FILES *)

# Including engines sources
INCLUDE(${CMAKE_SOURCE_DIR}/Engine/Source/CMakeLists.txt)

# Adding files to the target
TARGET_SOURCES(${TARGET_COMPILE} PRIVATE ${SOURCE_FILES})

# Linking all static libraries
TARGET_LINK_LIBRARIES(${TARGET_COMPILE} ${SFML_LIB})