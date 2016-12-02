# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Define path shortcuts
SET(PHYSIC_SRC_PATH ${CMAKE_SOURCE_DIR}/Source/Physic)
SET(PHYSIC_INC_PATH ${CMAKE_SOURCE_DIR}/Include/Physic)

set(PHYSIC_SOURCE "")

set(PHYSIC_HEADER
        ${PHYSIC_INC_PATH}/Vec2.hpp
        ${PHYSIC_INC_PATH}/Vec2.inl
        ${PHYSIC_INC_PATH}/PhysicsComponent.hpp)

# Adding source to the target
target_sources(${TARGET_COMPILE}
        PRIVATE
        ${PHYSIC_SOURCE}
        ${PHYSIC_HEADER})

# Copying files
add_custom_command(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PHYSIC_SOURCE} ${PUB_SRC_PATH}/Physic/
        COMMAND ${CMAKE_COMMAND} -E copy ${PHYSIC_HEADER} ${PUB_INC_PATH}/Physic/
        COMMENT "[INFO] Copying Phsyic files ...")