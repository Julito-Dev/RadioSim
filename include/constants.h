# pragma once

namespace PhysicsConstants {
    constexpr float NEUTRON_MASS = 1.0f;   

    // Typical velocity of neutrons inside a reactor (relative, not real m/s)
    // "Fast" neutron (just released by fision) are more faster.
    // than "thermal" neutrons (already stopped by the moderator)
    constexpr float FAST_NEUTRON_SPEED = 10.0f;
    constexpr float THERMAL_NEUTRON_SPEED = 1.0f;
}