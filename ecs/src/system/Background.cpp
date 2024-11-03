#include <limits>
#include "systems/Background.hpp"
#include "components/Background.hpp"
#include "components/Position.hpp"
#include "components/Texture.hpp"

namespace systems {

Background::Background(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

void Background::update(float dt)
{
    float rightmostX = -std::numeric_limits<float>::max();
    
    // Premier passage : trouver la position la plus à droite
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto background = m_entityManager.getComponent<component::Background>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);
        
        if (background && position) {
            rightmostX = std::max(rightmostX, position->x);
        }
    }

    // Deuxième passage : mettre à jour les positions
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto background = m_entityManager.getComponent<component::Background>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);
        
        if (background && position) {
            // Déplacement vers la gauche
            position->x -= background->speed * dt;

            // Si l'image sort complètement de l'écran par la gauche
            if (position->x <= -background->width) {
                // On la replace derrière le background le plus à droite
                position->x = rightmostX + background->width;
            }
        }
    }
}

}