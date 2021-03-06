# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(MEMORY_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Memory)
SET(MEMORY_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Memory)

SET(MEMORY_SOURCE "")

SET(MEMORY_HEADER
        ${MEMORY_INC_PATH}/Container.hpp
        ${MEMORY_INC_PATH}/Container.inl
        ${MEMORY_INC_PATH}/Resource.hpp
        ${MEMORY_INC_PATH}/Resource.inl
        ${MEMORY_INC_PATH}/PoolAllocator.inl
        ${MEMORY_INC_PATH}/PoolAllocator.hpp)

# Adding source to the target
TARGET_SOURCES(${TARGET_COMPILE}
        PRIVATE
        ${MEMORY_SOURCE}
        ${MEMORY_HEADER})

# Copying files
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${MEMORY_HEADER} ${PUB_INC_PATH}/Memory/
        COMMENT "[INFO] Copying Memory files ...")