# pragma once
# include "Particle.h"
# include "constants.h"

class Neutron : public Particle {
    public:
        Neutron( Vector2d pos, Vector2d vel):
            Particle(pos, vel, PhysicsConstants::NEUTRON_MASS) {}
};
