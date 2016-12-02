# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(LOCATION_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Physic/Location)
SET(LOCATION_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Physic/Location)

set(LOCATION_SOURCE
        ${LOCATION_SRC_PATH}/StationaryLocation.cpp
        ${LOCATION_SRC_PATH}/TransformableLocation.cpp)

set(LOCATION_HEADER
        ${LOCATION_INC_PATH}/Location.hpp
        ${LOCATION_INC_PATH}/StationaryLocation.hpp
        ${LOCATION_INC_PATH}/TransformableLocation.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${LOCATION_SOURCE}
        ${LOCATION_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${LOCATION_SOURCE} ${PUB_SRC_PATH}/Physic/Location/
        COMMAND ${CMAKE_COMMAND} -E copy ${LOCATION_HEADER} ${PUB_INC_PATH}/Physic/Location/
        COMMENT "[INFO] Copying Location files ...")