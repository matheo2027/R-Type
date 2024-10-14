#pragma once

#include <string>
#include <filesystem>

#include "type.hpp"

namespace gfx
{
    enum key
    {
        K_UP = 0,
        K_DOWN,
        K_LEFT,
        K_RIGHT,
        K_SPACE,
        K_ESC,
        K_A,
        K_B,
        K_C,
        K_D,
        K_E,
        K_F,
        K_G,
        K_H,
        K_I,
        K_J,
        K_K,
        K_L,
        K_M,
        K_N,
        K_O,
        K_P,
        K_Q,
        K_R,
        K_S,
        K_T,
        K_U,
        K_V,
        K_W,
        K_X,
        K_Y,
        K_Z
    };

    class ITexture
        {
        public:
            ITexture(const std::filesystem::path &path) : m_path(path) {}
            virtual ~ITexture() = default;
            const std::filesystem::path &getPath() const { return m_path; }

        protected:
            std::filesystem::path m_path;
        };

    class IDisplay
    {
        public:
            IDisplay(u32 width, u32 height, std::string &title) : m_width(width), m_height(height) {}
            virtual ~IDisplay() = default;
            virtual void update() = 0;
            virtual void clear() = 0;
            virtual bool isRunning() const = 0;
            virtual void close() = 0;
            virtual void draw(const ITexture &texture, u32 x, u32 y) = 0;
            virtual void draw(const std::string &text, u32 x, u32 y) = 0;
            virtual bool getKeyDown(u8 key) const = 0;
            u32 getWidth() const { return m_width; }
            u32 getHeight() const { return m_height; }

        protected:
            u32 m_width;
            u32 m_height;
    };
}
