# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(INTERFACE_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Interface)
SET(INTERFACE_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Interface)

SET(INTERFACE_SOURCE
        ${INTERFACE_SRC_PATH}/Button.cpp
        ${INTERFACE_SRC_PATH}/Listener.cpp)

SET(INTERFACE_HEADER
        ${INTERFACE_INC_PATH}/Button.hpp
        ${INTERFACE_INC_PATH}/Listener.hpp)

# Adding source to the target
TARGET_SOURCES(${TARGET_COMPILE}
        PRIVATE
        ${INTERFACE_SOURCE}
        ${INTERFACE_HEADER})

# Copying files
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${INTERFACE_SOURCE} ${PUB_SRC_PATH}/Interface/
        COMMAND ${CMAKE_COMMAND} -E copy ${INTERFACE_HEADER} ${PUB_INC_PATH}/Interface/
        COMMENT "[INFO] Copying Interface files ...")