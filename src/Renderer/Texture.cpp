#include "Texture.hpp"
#include <stb_image/stb_image.h>
#include <filesystem>
#include <iostream>
#include <glad/glad.h>


Texture::Texture(std::string texname)
{
    //could also check if file exists here?
    m_data = nullptr;
    m_width = m_height = m_numChannels = 0;
    m_texname = texname;
}

void Texture::Load(std::string filePath)
{
    std::filesystem::path pathName = filePath.c_str();
    if(!(std::filesystem::exists(pathName))){
        std::cout << pathName.c_str() << " does not exist" << std::endl;
        return;
    }
    //check file extension to determine whether to flip image
    std::cout << "Loading " << getFileName().c_str() << std::endl;
    m_data = stbi_load(getFileName().c_str(), &m_width, &m_height, &m_numChannels, 0);
    if(m_data == nullptr) //test this out
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}

void Texture::CreateTexture()
{
    //check if data member has 'data' 
    if(m_data == nullptr)
    {
        std::cout << "Texture Data is Null" << std::endl;
        return;
    }
    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, getID());
    //tex params, check to see if these are what i'd want
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

std::string Texture::getFileName()
{
    return m_filename;
}

unsigned int Texture::getID()
{
    return m_ID;
}

unsigned int Texture::getWidth()
{
    return m_width;
}

unsigned int Texture::getHeight()
{
    return m_height;
}

unsigned char *Texture::getData()
{
    return m_data;
}

