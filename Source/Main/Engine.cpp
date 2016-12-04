#include <iostream>
#include "Main/World.hpp"
#include "Main/Engine.hpp"

// Initializing the static attribute
GameEngine * Engine::pGameEngineInstance = nullptr;

void Engine::Shutdown()
{
    pGameEngineInstance->m_isRunning = false;
}

void Engine::SetGameEngineInstance(GameEngine * pInstance)
{
    pGameEngineInstance = pInstance;
}

sf::Font * Engine::GetFont(const std::string& key)
{
    return pGameEngineInstance->m_fontContainer.GetResource(key);
}

sf::SoundBuffer * Engine::GetSoundBuffer(const std::string& key)
{
    return pGameEngineInstance->m_soundBufferContainer.GetResource(key);
}

sf::Texture * Engine::GetTexture(const std::string& key)
{
    return pGameEngineInstance->m_textureContainer.GetResource(key);
}

sf::Font * Engine::LoadFont(const std::string& key, const std::string& path)
{
    sf::Font * _font = pGameEngineInstance->m_fontContainer.LoadResource(key);

    if(nullptr == _font)
        return nullptr;

    if(!_font->loadFromFile(GetCompletePath(path)))
        std::cerr << EngineString::ENGINE_FAILURE_FNF << std::endl;

    return _font;
}

sf::SoundBuffer * Engine::LoadSoundBuffer(const std::string& key, const std::string& path)
{
    sf::SoundBuffer * _soundBuffer =
            pGameEngineInstance->m_soundBufferContainer.LoadResource(key);

    if(nullptr == _soundBuffer)
        return nullptr;

    if(!_soundBuffer->loadFromFile(GetCompletePath(path)))
        std::cerr << EngineString::ENGINE_FAILURE_FNF << std::endl;

    return _soundBuffer;
}

sf::Texture * Engine::LoadTexture(const std::string& key, const std::string& path)
{
    sf::Texture * _texture =
            pGameEngineInstance->m_textureContainer.LoadResource(key);

    if(nullptr == _texture)
        return nullptr;

    if(!_texture->loadFromFile(GetCompletePath(path)))
        std::cerr << EngineString::ENGINE_FAILURE_FNF << std::endl;

    return _texture;
}

void Engine::UnloadFont(const std::string& key)
{
    pGameEngineInstance->m_fontContainer.UnloadResource(key);
}

void Engine::UnloadSoundBuffer(const std::string& key)
{
    pGameEngineInstance->m_soundBufferContainer.UnloadResource(key);
}

void Engine::UnloadTexture(const std::string& key)
{
    pGameEngineInstance->m_textureContainer.UnloadResource(key);
}

sf::RenderWindow * Engine::GetWindow()
{
    return pGameEngineInstance->m_pWindow;
}

void Engine::Register(GameObject * gameObject)
{
    pGameEngineInstance->m_pWorld->Register(gameObject);
}

bool Engine::Unregister(GameObject * gameObject)
{
    return pGameEngineInstance->m_pWorld->Unregister(gameObject);
}

void Engine::GetLayer(int layer, std::vector<GameObject*> & output) const
{
    pGameEngineInstance->m_pWorld->GetLayer(layer, output);
}

std::string Engine::GetCompletePath(std::string const& path)
{
    return DEFAULT_TEXTURE_PATH + path;
}