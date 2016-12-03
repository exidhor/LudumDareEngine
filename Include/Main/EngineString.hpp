/// \file    EngineString.hpp
/// \date    01/12/2016
/// \brief   Contains all strings of the engine
/// \author  Aredhele
/// \version 0.1.0

#ifndef __ENGINE_STRING_HPP
#define __ENGINE_STRING_HPP

/// \class  EngineString
/// \brief  Contains all strings of the engine
class EngineString
{
public:

    // Type shortcut
    using CSTR = const char *;

    // Declaration of all strings about error
    static constexpr CSTR ENGINE_FAILURE_START = "[engine] Cannot start the engine before initialization.";
    static constexpr CSTR ENGINE_FAILURE_INIT  = "[engine] Cannot initialized, engine already initialized.";

    // Container key error
    static constexpr CSTR ENGINE_FAILURE_CKNF  = "[engine] Unable to find the key in the container";
    static constexpr CSTR ENGINE_FAILURE_CKAE  = "[engine] The key already exists in the container";
    static constexpr CSTR ENGINE_FAILURE_FNF   = "[engine] Unable to load resource, file not found";
};

#endif // __ENGINE_STRING_HPP
