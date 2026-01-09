#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <iostream>

class Texture
{
public:
    unsigned int ID;
    bool error;
    bool isBinded;
    Texture(const char* path, bool alpha = false);
    void bind(unsigned int unit = 0);
    // void unbind();
};

#endif // TEXTURE_HPP