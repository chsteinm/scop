#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <string>

class Texture
{
public:
    unsigned int ID;
    Texture(const char* path, bool alpha = false);
    void bind(unsigned int unit = 0);
};

#endif // TEXTURE_HPP