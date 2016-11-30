# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Getting sources
FILE(GLOB_RECURSE ENGINE_FILES *)

# Adding files to the target
TARGET_SOURCES(${TARGET_COMPILE} PRIVATE ${ENGINE_FILES})
