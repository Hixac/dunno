#pragma once

#include <string_view>

namespace My {

    class Texture {
    public:
        Texture(size_t tex_unit = 0);
        ~Texture() = default;

        void Bind();
        void Load(std::string_view filepath);

    private:
        unsigned int m_tex_unit;
        unsigned int m_tex;
        unsigned char *m_file_bytes;
    };
    
}
