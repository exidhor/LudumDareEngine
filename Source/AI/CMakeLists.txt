# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(AI_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/AI)
SET(AI_INC_PATH ${CMAKE_SOURCE_DIR}/Include/AI)

set(AI_SOURCE
        ${AI_SRC_PATH}/MathHelper.cpp
        ${AI_SRC_PATH}/SteeringOutput.cpp)

set(AI_HEADER
        ${AI_INC_PATH}/MathHelper.hpp
        ${AI_INC_PATH}/SteeringOutput.hpp
        ${AI_INC_PATH}/SteeringBehavior.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${AI_SOURCE}
        ${AI_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${AI_SOURCE} ${PUB_SRC_PATH}/AI/
        COMMAND ${CMAKE_COMMAND} -E copy ${AI_HEADER} ${PUB_INC_PATH}/AI/
        COMMENT "[INFO] Copying AI files ...")