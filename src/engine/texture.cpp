#include <engine/texture.hpp>

#include <iostream>

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace My {

    Texture::Texture(size_t tex_unit)
        : m_tex_unit(tex_unit) {
        glCreateTextures(GL_TEXTURE_2D, 1, &m_tex);

        if (tex_unit > 15) {
            std::cerr << "FATAL: you reached maximum number of texture units!" << std::endl;
            std::abort();
        }
        
        glActiveTexture(GL_TEXTURE0 + tex_unit);
        glBindTexture(GL_TEXTURE_2D, m_tex);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    void Texture::Bind() {
        glActiveTexture(GL_TEXTURE0 + m_tex_unit);
        glBindTexture(GL_TEXTURE_2D, m_tex);
    }
    
    void Texture::Load(std::string_view filepath) {
        int width, height, nrChannels;
        unsigned char *data = stbi_load(filepath.data(), &width, &height, &nrChannels, 0);
        if (!data) {
            std::cerr << "FATAL: failed to load texture image!" << std::endl;
            std::abort();
        }
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    
        stbi_image_free(data);
    }
}
