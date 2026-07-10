# pragma once
# include "Vector2d.h"

class Particle {
    protected:
            Vector2d position;
            Vector2d velocity;
            bool active;
            float mass;
    
    public:
    
    Particle(Vector2d pos, Vector2d vel, float mass):
        position(pos), velocity(vel), active(true), mass(mass) {}

        virtual ~Particle() = default;

        virtual void move(float deltatime) {
            position += velocity * deltatime;
        }

    Vector2d getPosition() const {
        return position;
    }

    Vector2d getVelocity() const {
        return velocity;
    }

    float getMass() const{
        return mass;
    }
    
    bool isActive() const{
        return active;
    }

    void deactivate() {
        active = false;
    }


    float getKinectEnergy() const {
        float speed = velocity.magnitude();
        return 0.5f *mass * speed *speed;
    }
};