#include "systems/ColorBlind.hpp"

namespace systems
{
ColorBlind::ColorBlind(ecs::EntityManager &entityManager, display::IDisplay &display)
    : m_entityManager(entityManager), m_display(display)
{
}

void ColorBlind::update(float dt)
{
    m_countdown = std::max(0.0f, m_countdown - dt);
    if (m_display.isKeyPressed(display::Key::K_C) && m_countdown == 0.0f) {
        m_colorBlind++;
        if (m_colorBlind > m_maxColorBlind) {
            m_colorBlind = 0;
        }

        m_display.setColorBlindness(static_cast<display::ColorBlindness>(m_colorBlind));
        m_countdown = 0.2f;
    }
}

} // namespace systems