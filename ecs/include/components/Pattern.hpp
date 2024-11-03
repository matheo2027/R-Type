#ifndef PATTERN_HPP
#define PATTERN_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Pattern
 * @brief Représente un pattern de mouvement pour un ennemi.
 *
 * Ce composant définit la direction et la vitesse du mouvement de l'ennemi.
 */
struct Pattern : public Component {
    float directionX; ///< La direction du mouvement sur l'axe X.
    float directionY; ///< La direction du mouvement sur l'axe Y.
    float speed;      ///< La vitesse du mouvement.
    float amplitude;  ///< L'amplitude du mouvement vertical.
    float frequency;  ///< La fréquence du mouvement vertical.
    float elapsedTime; ///< Le temps écoulé pour calculer le mouvement vertical.

    /**
     * @brief Constructeur du composant Pattern.
     *
     * @param directionX La direction du mouvement sur l'axe X.
     * @param directionY La direction du mouvement sur l'axe Y.
     * @param speed La vitesse du mouvement.
     * @param amplitude L'amplitude du mouvement vertical.
     * @param frequency La fréquence du mouvement vertical.
     */
    Pattern(float directionX = 0, float directionY = 0, float speed = 0, float amplitude = 0, float frequency = 0)
        : directionX(directionX), directionY(directionY), speed(speed), amplitude(amplitude), frequency(frequency), elapsedTime(0) {}
};

}

#endif // PATTERN_HPP