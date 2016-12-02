# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(QUAD_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Physic/QuadTree)
SET(QUAD_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Physic/QuadTree)

set(QUAD_SOURCE "")

set(QUAD_HEADER
        ${QUAD_INC_PATH}/QuadTree.hpp
        ${QUAD_INC_PATH}/QuadTree.inl
        ${QUAD_INC_PATH}/QuadTreeNode.hpp
        ${QUAD_INC_PATH}/QuadTreeNode.inl
        ${QUAD_INC_PATH}/QuadTreeContainer.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${QUAD_SOURCE}
        ${QUAD_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${QUAD_HEADER} ${PUB_INC_PATH}/Physic/QuadTree
        COMMENT "[INFO] Copying QuadTree files ...")