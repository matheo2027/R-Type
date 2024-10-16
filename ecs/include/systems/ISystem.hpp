#pragma once

namespace systems
{

class ISystem
{
    public:
        virtual ~ISystem() = default;

        virtual void update(float dt) = 0;
};

} // namespace systems