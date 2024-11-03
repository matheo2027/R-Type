/**
 * @file IDisplay.hpp
 * @brief Interface for display management in a game.
 *
 * This file contains the definition of the IDisplay interface and the ITexture structure,
 * which are used for handling textures and display operations in a graphical application.
 */

#pragma once

#include <string>
#include <memory>

namespace display
{

/**
 * @enum Key
 * @brief Enumeration for key input representation.
 *
 * This enumeration defines the keys that can be checked for input in the application.
 */
enum Key
{
    K_UP,    ///< Represents the up arrow key.
    K_DOWN,  ///< Represents the down arrow key.
    K_LEFT,  ///< Represents the left arrow key.
    K_RIGHT, ///< Represents the right arrow key.
    K_SPACE, ///< Represents the spacebar key.
    K_C,     ///< Represents the 'C' key.
};

/**
 * @enum MouseButton
 * @brief Enumeration for mouse button input representation.
 *
 * This enumeration defines the mouse buttons that can be checked for input in the application.
 */
enum MouseButton
{
    LEFT,   ///< Represents the left mouse button.
    RIGHT,  ///< Represents the right mouse button.
    MIDDLE, ///< Represents the middle mouse button.
};

enum ColorBlindness
{
    NONE,
    PROTANOPIA, // red color blindness
    DEUTERANOPIA, // green color blindness
    TRITANOPIA // blue color blindness
};

/**
 * @struct ITexture
 * @brief Represents a texture in the application.
 *
 * The ITexture structure is used to store texture information and provide access
 * to the texture's file path.
 */
struct ITexture
{
    /**
     * @brief Constructor for ITexture.
     * @param path The file path of the texture.
     */
    ITexture(const std::string &path) : m_path(path) {}

    /**
     * @brief Destructor for ITexture.
     */
    virtual ~ITexture() = default;

    /**
     * @brief Get the path of the texture.
     * @return The file path of the texture.
     */
    const std::string &getPath() const { return m_path; }

    std::string m_path; ///< The file path of the texture.
};

/**
 * @class IDisplay
 * @brief Interface for managing the display and rendering in a graphical application.
 *
 * The IDisplay interface defines the methods required for initializing, updating,
 * drawing, and handling input for a graphical display.
 */
class IDisplay
{
    public:
        /**
         * @brief Destructor for IDisplay.
         */
        virtual ~IDisplay() = default;

        /**
         * @brief Initialize the display.
         * @param width The width of the display.
         * @param height The height of the display.
         * @param title The title of the window.
         */
        virtual void init(int width, int height, const std::string &title) = 0;

        /**
         * @brief Update the display.
         *
         * This method is called to update the display for rendering.
         */
        virtual void update() = 0;

        /**
         * @brief Clear the display.
         *
         * This method is called to clear the display for the next frame.
         */
        virtual void clear() = 0;

        /**
         * @brief Check if the display is open.
         * @return True if the display is open; otherwise, false.
         */
        virtual bool isOpen() const = 0;

        /**
         * @brief Close the display.
         *
         * This method is called to close the display window.
         */
        virtual void close() = 0;

        /**
         * @brief Draw a texture on the display.
         * @param texture A shared pointer to the texture to draw.
         * @param x The x-coordinate where the texture should be drawn.
         * @param y The y-coordinate where the texture should be drawn.
         */
        virtual void draw(std::shared_ptr<ITexture> &texture, float x, float y) = 0;

        /**
         * @brief Check if a key is currently pressed.
         * @param key The key to check.
         * @return True if the key is pressed; otherwise, false.
         */
        virtual bool isKeyPressed(Key key) const = 0;

        /**
         * @brief Check if a key was released.
         * @param key The key to check.
         * @return True if the key was released; otherwise, false.
         */
        virtual bool isKeyReleased(Key key) const = 0;

        /**
         * @brief Create a texture from a file path.
         * @param path The file path of the texture.
         * @return A shared pointer to the created texture.
         */
        virtual std::shared_ptr<ITexture> createTexture(const std::string &path) = 0;

        /**
         * @brief Check if a mouse button is currently pressed.
         * @param button The mouse button to check.
         * @return True if the mouse button is pressed; otherwise, false.
         */
        virtual bool isMouseButtonPressed(MouseButton button) const = 0;

        /**
         * @brief Check if a mouse button was released.
         * @param button The mouse button to check.
         * @return True if the mouse button was released; otherwise, false.
         */
        virtual void getMousePosition(float &x, float &y) const = 0;

        /**
         * @brief Set the color blindness mode.
         * @param mode The color blindness mode to set.
         */
        virtual void setColorBlindness(ColorBlindness mode) = 0;
};

}
