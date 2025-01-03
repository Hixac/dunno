#pragma once

namespace My {

    class Program {
    public:
        Program();
        ~Program();

        void Attach(unsigned int shader_id);
        void LinkAll();
        void Use();
        
    private:
        unsigned int m_randid;
    };
    
}
