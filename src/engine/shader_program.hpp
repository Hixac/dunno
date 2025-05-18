#pragma once

#include <string>
#include <string_view>
#include <map>
#include <filesystem>

#include <glm/glm.hpp>

namespace My {

    class Program {
    public:
        Program();
        ~Program();

        void Source(std::vector<std::filesystem::path> vert_path, std::vector<std::filesystem::path> frag_path);
        
        void Attach(unsigned int shader_id);
        void LinkAll();
        void Use() const;

        void SetVarFloat(const std::string& v, float f);
        void SetVarMat4(const std::string& v, const glm::mat4& m);
        void SetVarInt(const std::string& v, int i);

    private:
        void DetectVarLocation(std::string_view name);
        
        std::map<std::string, int> m_vars;
        unsigned int m_randid;
    };

    static auto create_shader_program() {
        return std::make_shared<Program>();
    }

    
}
