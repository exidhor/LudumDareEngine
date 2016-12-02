# Ludum Dare 37
# Game Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-11-30
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Creating the test executable
ADD_EXECUTABLE(${TARGET_COMPILE} "")

# Adding main file
TARGET_SOURCES(${TARGET_COMPILE} PRIVATE
        ${CMAKE_SOURCE_DIR}/Source/Main.cpp
        ${CMAKE_SOURCE_DIR}/Source/Game.cpp
        ${CMAKE_SOURCE_DIR}/Include/Game.hpp)

# Linking libraries
IF(PLATFORM_WINDOWS)
    # Linking windows libraries
    TARGET_LINK_LIBRARIES(${TARGET_COMPILE} ${SFML_DEPENDENCIES} ${WIN32_DEPENDENCIES})

ELSEIF(PLATFORM_UNIX)
    # Linking unix libraries
    TARGET_LINK_LIBRARIES(${TARGET_COMPILE} ${SFML_DEPENDENCIES} ${UNIX_DEPENDENCIES})

ELSE()
    # An error occured
    MESSAGE(FATAL_ERROR "Plateform not set.")

ENDIF()

# Creating custom targets
ADD_CUSTOM_TARGET(${TARGET_PUBLISHING})

# Path shorcuts
SET(PUB_SRC_PATH  ${TARGET_PATH}/Engine/Source)
SET(PUB_INC_PATH  ${TARGET_PATH}/Engine/Include)
SET(TEMPLATE_PATH ${CMAKE_SOURCE_DIR}/Include/Template)

# Including all sources
INCLUDE(AI/CMakeLists.txt)
INCLUDE(Main/CMakeLists.txt)
INCLUDE(Physic/CMakeLists.txt)
INCLUDE(Physic/QuadTree/CMakeLists.txt)

# Setting target dependencies
# Because the published version must be
# the more recent one, the project has to be at least compiled
ADD_DEPENDENCIES(${TARGET_PUBLISHING} ${TARGET_COMPILE})

# Pre build commands
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Bin
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Res
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Doc
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Source
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Include
        COMMENT "[INFO] Creating project folders ..." VERBATIM)

# Creating all engine directories
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Source
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Include
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Source/AI
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Include/AI
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Source/Main
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Include/Main
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Source/Physic
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Include/Physic
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Source/Physic/QuadTree
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_PATH}/Engine/Include/Physic/QuadTree
        COMMENT "[INFO] Creating engine folders ..." VERBATIM)

# Moving shared files
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/Source/Main.cpp ${TARGET_PATH}/Source
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/Source/Game.cpp ${TARGET_PATH}/Source
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/Include/Game.hpp ${TARGET_PATH}/Include
        COMMENT "[INFO] Copying shared files ...")

# Copying CMake template project
ADD_CUSTOM_COMMAND(TARGET ${TARGET_PUBLISHING} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${TEMPLATE_PATH}/CMakeLists.txt ${TARGET_PATH}/
        COMMAND ${CMAKE_COMMAND} -E copy
        ${TEMPLATE_PATH}/Source/CMakeLists.txt ${TARGET_PATH}/Source
        COMMAND ${CMAKE_COMMAND} -E copy
        ${TEMPLATE_PATH}/Engine/CMakeLists.txt ${TARGET_PATH}/Engine/Source
        COMMENT "[INFO] Copying CMake template ...")