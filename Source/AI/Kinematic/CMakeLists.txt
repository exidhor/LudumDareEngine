# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(KINEMATIC_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/AI/Kinematic)
SET(KINEMATIC_INC_PATH ${CMAKE_SOURCE_DIR}/Include/AI/Kinematic)

set(KINEMATIC_SOURCE
        ${KINEMATIC_SRC_PATH}/Kinematic.cpp
        ${KINEMATIC_SRC_PATH}/KinematicPursue.cpp
        ${KINEMATIC_SRC_PATH}/KinematicSteering.cpp
        ${KINEMATIC_SRC_PATH}/KinematicBehaviors.cpp
        ${KINEMATIC_SRC_PATH}/TargetedKinematicSteering.cpp)

set(KINEMATIC_HEADER
        ${KINEMATIC_INC_PATH}/Kinematic.hpp
        ${KINEMATIC_INC_PATH}/KinematicPursue.hpp
        ${KINEMATIC_INC_PATH}/KinematicSteering.hpp
        ${KINEMATIC_INC_PATH}/KinematicBehaviors.hpp
        ${KINEMATIC_INC_PATH}/TargetedKinematicSteering.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${KINEMATIC_SOURCE}
        ${KINEMATIC_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${KINEMATIC_SOURCE} ${PUB_SRC_PATH}/AI/Kinematic
        COMMAND ${CMAKE_COMMAND} -E copy ${KINEMATIC_HEADER} ${PUB_INC_PATH}/AI/Kinematic
        COMMENT "[INFO] Copying Kinematic files ...")