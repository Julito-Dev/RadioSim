# pragma once
# include "Particle.h"
# include "constants.h"

class Neutron : public Particle {
    public:
        Neutron( Vector2d pos, Vector2d vel):
            Particle(pos, vel, PhysicsConstants::NEUTRON_MASS) {}

        float getSpeed() const {
            return velocity.magnitude();
        }

        // 5.5 is the speed threshold for a neutral to be considered fast or not.
        bool isFast() const {
            return getSpeed() >= PhysicsConstants::FAST_THERMAL_THRESOLD;
        }

        bool isThermal() const {
            return getSpeed() < PhysicsConstants::FAST_THERMAL_THRESOLD;
        }
};
