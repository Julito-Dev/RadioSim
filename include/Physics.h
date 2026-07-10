# pragma once
# include "Neutron.h"
# include "FuelAtom.h"
# include <random>
# include <vector>
# include <algorithm>
# include "constants.h"
# include <cmath>


class Physics {
    public:
        static bool attemptFission(const Neutron& neutron, const FuelAtom& fuel, std::mt19937& rng) {
            std::uniform_real_distribution<float> dist(0.0f, 1.0f);

            float roll = dist(rng);

            float probability = fuel.getFissionProb();


            if (neutron.isThermal()) {
                probability *= 1.2f;
            }

            else {
                probability *= 0.6f;
            }
            
            probability = std::clamp(probability, 0.0f, 1.0f);

            return roll < probability;
        }

        static std::vector<Neutron> spawnFissionNeutrons(const FuelAtom& fuel, std::mt19937& rng){
            std::vector<Neutron> newNeutrons;
            int count = fuel.getNeutronReleased();

            std::uniform_real_distribution<float> angles(0.0f, 2.0f * M_PI);

            for (int i = 0; i<count ; i++){
                float angle = angles(rng);
                Vector2d initialDirection(std::cos(angle), std::sin(angle)); //Unitary Vector
                Vector2d initialVel = initialDirection * PhysicsConstants::FAST_NEUTRON_SPEED;  //Magnitude equals to fast_neutron_speed
                
                newNeutrons.push_back(Neutron(fuel.getPosition(), initialVel));

            }
            return newNeutrons;
        }
    
};