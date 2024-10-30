/**
 * @file gfx.hpp
 * @brief Contains interfaces for texture handling and display management, as well as key enumerations.
 */

#pragma once

#include <string>
#include <filesystem>
#include "type.hpp"

namespace gfx
{
/**
 * @brief Enum representing key codes used for input handling.
 */
enum key
{
    K_UP = 0,    ///< Up arrow key
    K_DOWN,      ///< Down arrow key
    K_LEFT,      ///< Left arrow key
    K_RIGHT,     ///< Right arrow key
    K_SPACE,     ///< Space bar key
    K_ESC,       ///< Escape key
    K_A,         ///< Key 'A'
    K_B,         ///< Key 'B'
    K_C,         ///< Key 'C'
    K_D,         ///< Key 'D'
    K_E,         ///< Key 'E'
    K_F,         ///< Key 'F'
    K_G,         ///< Key 'G'
    K_H,         ///< Key 'H'
    K_I,         ///< Key 'I'
    K_J,         ///< Key 'J'
    K_K,         ///< Key 'K'
    K_L,         ///< Key 'L'
    K_M,         ///< Key 'M'
    K_N,         ///< Key 'N'
    K_O,         ///< Key 'O'
    K_P,         ///< Key 'P'
    K_Q,         ///< Key 'Q'
    K_R,         ///< Key 'R'
    K_S,         ///< Key 'S'
    K_T,         ///< Key 'T'
    K_U,         ///< Key 'U'
    K_V,         ///< Key 'V'
    K_W,         ///< Key 'W'
    K_X,         ///< Key 'X'
    K_Y,         ///< Key 'Y'
    K_Z          ///< Key 'Z'
};

/**
 * @class ITexture
 * @brief Interface for texture management.
 */
class ITexture
{
public:
    /**
     * @brief Constructs a texture from a file path.
     * @param path Path to the texture file.
     */
    ITexture(const std::filesystem::path &path) : m_path(path) {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~ITexture() = default;

    /**
     * @brief Retrieves the path of the texture.
     * @return Const reference to the path.
     */
    const std::filesystem::path &getPath() const
    {
        return m_path;
    }

protected:
    std::filesystem::path m_path; ///< Path to the texture file
};

/**
 * @class IDisplay
 * @brief Interface for managing the display and rendering operations.
 */
class IDisplay
{
public:
    /**
     * @brief Constructs a display window with specified width, height, and title.
     * @param width Width of the display window.
     * @param height Height of the display window.
     * @param title Title of the display window.
     */
    IDisplay(u32 width, u32 height, std::string &title) : m_width(width), m_height(height) {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~IDisplay() = default;

    /**
     * @brief Updates the display.
     */
    virtual void update() = 0;

    /**
     * @brief Clears the display.
     */
    virtual void clear() = 0;

    /**
     * @brief Checks if the display window is still running.
     * @return True if running, false otherwise.
     */
    virtual bool isRunning() const = 0;

    /**
     * @brief Closes the display window.
     */
    virtual void close() = 0;

    /**
     * @brief Draws a texture at a specified position.
     * @param texture Texture to be drawn.
     * @param x X-coordinate of the position.
     * @param y Y-coordinate of the position.
     */
    virtual void draw(const ITexture &texture, u32 x, u32 y) = 0;

    /**
     * @brief Draws text at a specified position.
     * @param text Text to be drawn.
     * @param x X-coordinate of the position.
     * @param y Y-coordinate of the position.
     */
    virtual void draw(const std::string &text, u32 x, u32 y) = 0;

    /**
     * @brief Checks if a specific key is currently pressed.
     * @param key Key code to check.
     * @return True if the key is pressed, false otherwise.
     */
    virtual bool getKeyDown(u8 key) const = 0;

    /**
     * @brief Retrieves the width of the display window.
     * @return Width of the display.
     */
    u32 getWidth() const
    {
        return m_width;
    }

    /**
     * @brief Retrieves the height of the display window.
     * @return Height of the display.
     */
    u32 getHeight() const
    {
        return m_height;
    }

protected:
    u32 m_width;  ///< Width of the display
    u32 m_height; ///< Height of the display
};

} // namespace gfx
