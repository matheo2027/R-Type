#define _USE_MATH_DEFINES
#include "SystemManager.hpp"
#include "network/SFMLSocket.hpp"
#include <chrono>
#include <thread>
#include <cmath>
#include <vector>
#include <functional>

struct Wave {
    float spawnTime;
    std::function<void(ecs::EntityManager&, systems::Server&)> createWave;
    bool spawned;
};

void createWave1(ecs::EntityManager &entityManager, systems::Server &server) {
    // Ligne horizontale d'ennemis qui se déplacent en zigzag
    for (int i = 0; i < 5; i++) {
        ecs::Entity enemie = entityManager.createEntity();
        entityManager.addComponent<component::Position>(enemie, 800 + (i * 100), 200);
        entityManager.addComponent<component::Velocity>(enemie, 0, 0);
        entityManager.addComponent<component::Enemie>(enemie, 100.0f);
        entityManager.addComponent<component::Box>(enemie, 800 + (i * 100), 200, 50, 50);
        entityManager.addComponent<component::Pattern>(enemie, -1.0f, 0.0f, 50.0f, 100.0f, 2.0f); // Pattern zigzag
        entityManager.addComponent<component::TextureServer>(enemie, "assets/img/enemie.png");
        server.spawnEntity(enemie, 800 + (i * 100), 200, "assets/img/enemie.png");
    }
}

void createWave2(ecs::EntityManager &entityManager, systems::Server &server) {
    // Formation en V qui descend
    for (int i = 0; i < 3; i++) {
        ecs::Entity enemie = entityManager.createEntity();
        entityManager.addComponent<component::Position>(enemie, 900 + (i * 80), 100 + (i * 60));
        entityManager.addComponent<component::Velocity>(enemie, 0, 0);
        entityManager.addComponent<component::Enemie>(enemie, 100.0f);
        entityManager.addComponent<component::Box>(enemie, 900 + (i * 80), 100 + (i * 60), 50, 50);
        entityManager.addComponent<component::Pattern>(enemie, -1.0f, 0.5f, 60.0f, 0.0f, 0.0f); // Pattern diagonal
        entityManager.addComponent<component::TextureServer>(enemie, "assets/img/enemie.png");
        server.spawnEntity(enemie, 900 + (i * 80), 100 + (i * 60), "assets/img/enemie.png");

        // Symétrie pour la formation en V
        ecs::Entity enemie2 = entityManager.createEntity();
        entityManager.addComponent<component::Position>(enemie2, 900 + (i * 80), 500 - (i * 60));
        entityManager.addComponent<component::Velocity>(enemie2, 0, 0);
        entityManager.addComponent<component::Enemie>(enemie2, 100.0f);
        entityManager.addComponent<component::Box>(enemie2, 900 + (i * 80), 500 - (i * 60), 50, 50);
        entityManager.addComponent<component::Pattern>(enemie2, -1.0f, -0.5f, 60.0f, 0.0f, 0.0f);
        entityManager.addComponent<component::TextureServer>(enemie2, "assets/img/enemie.png");
        server.spawnEntity(enemie2, 900 + (i * 80), 500 - (i * 60), "assets/img/enemie.png");
    }
}

void createWave3(ecs::EntityManager &entityManager, systems::Server &server) {
    // Formation circulaire qui tourne
    for (int i = 0; i < 8; i++) {
        ecs::Entity enemie = entityManager.createEntity();
        float angle = (i * 45) * M_PI / 180.0f;
        entityManager.addComponent<component::Position>(enemie, 1000, 300);
        entityManager.addComponent<component::Velocity>(enemie, 0, 0);
        entityManager.addComponent<component::Enemie>(enemie, 100.0f);
        entityManager.addComponent<component::Box>(enemie, 1000, 300, 50, 50);
        entityManager.addComponent<component::Pattern>(enemie, -1.0f, 0.0f, 40.0f, 60.0f, 1.0f + (i * 0.2f));
        entityManager.addComponent<component::TextureServer>(enemie, "assets/img/enemie.png");
        server.spawnEntity(enemie, 1000, 300, "assets/img/enemie.png");
    }
}

void createWave4(ecs::EntityManager &entityManager, systems::Server &server) {
    // Ligne qui serpente
    for (int i = 0; i < 6; i++) {
        ecs::Entity enemie = entityManager.createEntity();
        entityManager.addComponent<component::Position>(enemie, 1200 + (i * 80), 300);
        entityManager.addComponent<component::Velocity>(enemie, 0, 0);
        entityManager.addComponent<component::Enemie>(enemie, 100.0f);
        entityManager.addComponent<component::Box>(enemie, 1200 + (i * 80), 300, 50, 50);
        entityManager.addComponent<component::Pattern>(enemie, -1.0f, 0.0f, 70.0f, 100.0f, 1.5f + (i * 0.3f));
        entityManager.addComponent<component::TextureServer>(enemie, "assets/img/enemie.png");
        server.spawnEntity(enemie, 1200 + (i * 80), 300, "assets/img/enemie.png");
    }
}

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server port>" << std::endl;
        return 1;
    }

    int port = std::stoi(argv[1]);

    ecs::EntityManager entityManager;
    ecs::SystemManager systemManager;

    systemManager.addSystem<systems::Server>(entityManager, port);
    systems::Server &server = systemManager.getSystem<systems::Server>();

    ecs::Entity bg1 = entityManager.createEntity();
    entityManager.addComponent<component::Position>(bg1, 0, 0);
    entityManager.addComponent<component::Background>(bg1, 100.0f, 800.0f, 800.0f);
    entityManager.addComponent<component::TextureServer>(bg1, "assets/img/background.png");
    server.spawnEntity(bg1, 0, 0, "assets/img/background.png");

    ecs::Entity bg2 = entityManager.createEntity();
    entityManager.addComponent<component::Position>(bg2, 800, 0);
    entityManager.addComponent<component::Background>(bg2, 100.0f, 800.0f, 800.0f);
    entityManager.addComponent<component::TextureServer>(bg2, "assets/img/background.png");
    server.spawnEntity(bg2, 800, 0, "assets/img/background.png");

    std::vector<Wave> waves = {
        {3.0f, createWave1, false},   
        {20.0f, createWave2, false},
        {35.0f, createWave3, false},  
        {50.0f, createWave4, false} 
    };

    systemManager.addSystem<systems::Movement>(entityManager, server);
    systemManager.addSystem<systems::Player>(entityManager, server);
    systemManager.addSystem<systems::Background>(entityManager);
    systemManager.addSystem<systems::Enemie>(entityManager, server);
    systemManager.addSystem<systems::Bullet>(entityManager, server);
    systemManager.addSystem<systems::Box>(entityManager);

    auto lastTime = std::chrono::high_resolution_clock::now();
    const float targetFrameTime = 1.0f / 60.0f;
    float totalTime = 0.0f;

    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(currentTime - lastTime).count();
        totalTime += dt;

        for (auto& wave : waves) {
            if (!wave.spawned && totalTime >= wave.spawnTime) {
                wave.createWave(entityManager, server);
                wave.spawned = true;
                std::cout << "New wave spawned at time: " << totalTime << "s" << std::endl;
            }
        }

        systemManager.update(dt);

        float remainingTime = targetFrameTime - dt;
        if (remainingTime > 0) {
            std::this_thread::sleep_for(std::chrono::duration<float>(remainingTime));
        }
        lastTime = currentTime;
    }

    return 0;
}