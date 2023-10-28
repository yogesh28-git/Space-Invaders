#pragma once

namespace Gameplay
{
    namespace Interface
    {
        class ITest
        {
        public:
            virtual void initialize() = 0;
            virtual void update() = 0;
            virtual void render() = 0;

            virtual ~ITest() { }
        };
    }
}