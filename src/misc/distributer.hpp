#pragma once

namespace Misc {

    class Distributer {
    public:
        static Distributer& Get() {
            static Distributer d;

            return d;
        }

        void CalculateFrameTime();

        inline double DeltaTime() { return dt; }
        
    private:
        Distributer() = default;
        
        double dt = 0, last_frame = 0, current_frame;
    };
    
}
