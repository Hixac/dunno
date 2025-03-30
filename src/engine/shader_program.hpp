#pragma once

#include <string>
#include <string_view>
#include <map>
#include <glm/glm.hpp>

namespace My {

    class Program {
    public:
        Program();
        ~Program();

        void Attach(unsigned int shader_id);
        void LinkAll();
        void Use();

        void SetVarFloat(const std::string& v, float f);
        void SetVarMat4(const std::string& v, const glm::mat4& m);
        void SetVarInt(const std::string& v, int i);

    private:
        void DetectVarLocation(std::string_view name);
        
        std::map<std::string, int> m_vars;
        unsigned int m_randid;
    };
    
}
