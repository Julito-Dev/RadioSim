# pragma once
# include "Particle.h"
# include "constants.h"

class Proton : public Particle {
    private:
        float charge;

    public:

        Proton(Vector2d pos, Vector2d vel):
            Particle(pos, vel, PhysicsConstants::PROTON_MASS), charge(1.0f) {}

        float getCharge() const {
            return charge;
        }
};