#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
class Texture
{
    public:
        Texture(std::string texname);
    public:
        void Load(std::string filePath);
        void CreateTexture();
        std::string getFileName();
        unsigned int getID();
        unsigned int getWidth();
        unsigned int getHeight();
        unsigned char *getData();

    private:
        int m_width, m_height, m_numChannels;
        unsigned int m_ID;
        unsigned char *m_data;
        std::string m_filename;
        std::string m_texname; //potentially useful identifier, will remove if proven wrong
};

#endif