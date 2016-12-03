# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(COMPONENT_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Component)
SET(COMPONENT_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Component)

SET(COMPONENT_SOURCE "")

SET(COMPONENT_HEADER
        ${COMPONENT_INC_PATH}/GameObject.hpp)

# Adding source to the target
TARGET_SOURCES(${TARGET_COMPILE}
        PRIVATE
        ${COMPONENT_SOURCE}
        ${COMPONENT_HEADER})

# Copying files
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${COMPONENT_SOURCE} ${PUB_SRC_PATH}/Component/
        COMMAND ${CMAKE_COMMAND} -E copy ${COMPONENT_HEADER} ${PUB_INC_PATH}/Component/
        COMMENT "[INFO] Copying Component files ...")