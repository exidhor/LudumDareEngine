# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(MAIN_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Main)
SET(MAIN_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Main)

set(MAIN_SOURCE
        ${MAIN_SRC_PATH}/GameEngine.cpp)

set(MAIN_HEADER
        ${MAIN_INC_PATH}/GameEngine.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${MAIN_SOURCE}
        ${MAIN_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${MAIN_SOURCE} ${PUB_SRC_PATH}/Main/
        COMMAND ${CMAKE_COMMAND} -E copy ${MAIN_HEADER} ${PUB_INC_PATH}/Main/
        COMMENT "[INFO] Copying Main files ...")