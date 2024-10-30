/**
 * @file main.cpp
 * @brief Main entry point for the ECS-based game.
 *
 * This file contains the main function that initializes the Entity-Component-System (ECS) architecture,
 * creates game entities such as players and enemies, and manages the game loop.
 * It also sets up the display using SFML for rendering graphics.
 */

#include <EntityManager.hpp>
#include <components/Position.hpp>
#include <display/SFMLDisplay.hpp>
#include <SystemManager.hpp>

#include <iostream>
#include <chrono>

/**
 * @brief The main function of the game.
 *
 * Initializes the EntityManager and SFMLDisplay, creates player and enemy entities,
 * and sets up their components including position, velocity, texture, and type.
 * It also creates a SystemManager to handle various game systems such as rendering,
 * movement, and player interactions.
 *
 * The game loop runs until the display is closed, updating the game state and rendering
 * the current frame.
 *
 * @return int Exit status of the program.
 */
int main()
{
    // Create the Entity Manager and Display
    ecs::EntityManager manager;
    display::SFMLDisplay display;

    // Create player entity and add components
    ecs::Entity player = manager.createEntity();
    manager.addComponent<component::Position>(player, 300, 300);
    manager.addComponent<component::Velocity>(player, 0, 0);

    // Load player texture and add to entity
    std::shared_ptr<display::ITexture> texture = display.createTexture("../assets/img/player.png");
    manager.addComponent<component::Texture>(player, texture);
    manager.addComponent<component::Player>(player, 100.0f);

    // Create enemy entity and add components
    ecs::Entity enemie = manager.createEntity();
    manager.addComponent<component::Position>(enemie, 700, 300);
    manager.addComponent<component::Velocity>(enemie, 0, 0);
    manager.addComponent<component::Enemie>(enemie, 100.0f);

    // Load enemy texture and add to entity
    texture = display.createTexture("../assets/img/enemie.png");
    manager.addComponent<component::Texture>(enemie, texture);
    manager.addComponent<component::Box>(enemie, 700, 300, 50, 50);

    // Create and initialize the System Manager with various systems
    ecs::SystemManager systemManager;
    systemManager.addSystem<systems::Render>(manager, display);
    systemManager.addSystem<systems::Player>(manager, display);
    systemManager.addSystem<systems::Movement>(manager);
    systemManager.addSystem<systems::Enemie>(manager);
    systemManager.addSystem<systems::Bullet>(manager);
    systemManager.addSystem<systems::Box>(manager);

    // Initialize the display with a window size and title
    display.init(800, 600, "ECS");

    // Start the game loop timer
    auto start = std::chrono::high_resolution_clock::now();

    // Main game loop
    while(display.isOpen()) {
        // Calculate delta time
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = now - start;
        float dt = elapsed.count();

        // Clear the display for the new frame
        display.clear();

        // Update game systems
        systemManager.update(dt);

        // Render the current frame
        display.update();

        // Reset the timer for the next frame
        start = now;
    }

    return 0;
}
