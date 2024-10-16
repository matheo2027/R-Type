#pragma once

#include <string>
#include <memory>

namespace display
{

enum Key
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_SPACE,
};

struct ITexture
{
    ITexture(const std::string &path) : m_path(path) {}
    virtual ~ITexture() = default;

    const std::string &getPath() const { return m_path; }
    
    std::string m_path;
};

class IDisplay
{
    public:
        virtual ~IDisplay() = default;
        
        virtual void init(int width, int height, const std::string &title) = 0;

        virtual void update() = 0;
        virtual void clear() = 0;

        virtual bool isOpen() const = 0;
        virtual void close() = 0;

        virtual void draw(std::shared_ptr<ITexture> &texture, float x, float y) = 0;

        virtual bool isKeyPressed(Key key) const = 0;
        virtual bool isKeyReleased(Key key) const = 0;

        virtual std::shared_ptr<ITexture> createTexture(const std::string &path) = 0;
};

}