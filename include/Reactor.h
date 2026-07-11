# pragma once
# include <vector>
# include "Neutron.h"
# include "FuelAtom.h"
# include <random>
# include "Vector2d.h"
# include "Physics.h"
# include <iostream>


class Reactor {
    private:
        std::vector<Neutron> neutrons;
        std::vector<FuelAtom> fuealAtoms;
        std::mt19937 rng;  // Random numbers generator 
        float collisionRadius; // distance to "crash"
    

    public:

        Reactor(unsigned int seed, float collisionRadius):
        rng(seed), collisionRadius(collisionRadius) {}


        void addNeutron(Neutron neutron){
            neutrons.push_back(neutron);
        }

        void addFuelAtom(FuelAtom fuel){
            fuealAtoms.push_back(fuel);
        }

        void step(float deltaTime){

            std::vector<Neutron> pendingNeutrons;

            // 1. phase: Move all neutrons in the reactor

            for(auto& neutron: neutrons){
                neutron.move(deltaTime);
            }

            // 2. Phase: Check for collision neutron-atom

            for(auto& neutron: neutrons){
                for (auto& fatom: fuealAtoms){
                    if(neutron.isActive() && !fatom.isConsumed()){
                        Vector2d posNeutron = neutron.getPosition();
                        Vector2d posFatom = fatom.getPosition();

                        float distance = posNeutron.distanceTo(posFatom);

                        if (distance <= collisionRadius){
                            // collision 
                           bool collision = Physics::attemptFission(neutron, fatom, rng);

                           if(collision){
                                
                            std::vector<Neutron> spawnedNeutrons = Physics::spawnFissionNeutrons(fatom, rng);
                            for(auto& newNeutron: spawnedNeutrons){
                                pendingNeutrons.push_back(newNeutron);
                            }

                            neutron.deactivate();
                            fatom.consume();
                            break;
                           }

                           else {                       //if not collision (Neutron is absorbed)
                                neutron.deactivate();
                                break;
                           }
                        }
                    }
                }  
            }

            for(auto& pendingNeutron: pendingNeutrons){    //Copy the pendingNeuntrons vector to neutrons vector.
                neutrons.push_back(pendingNeutron);
            }
        }

        int getActiveNeutrons() const {
            int count = 0;
            for(const auto& neutron: neutrons){
                if (neutron.isActive()){
                    count++;
                }
            }

            return count;
        }

        int getConsumedAtomCount() const {
            int consumedCount = 0;
            for(const auto& fatom: fuealAtoms){
                if (fatom.isConsumed()){
                    consumedCount++;
                }
            }
            
            return consumedCount;
        }

        void printNeutronPositions() const {
            for (const auto& n : neutrons) {
                if (n.isActive()) {
                    std::cout << "  Neutron en: ";
                    n.getPosition().print();
                    std::cout << "\n";
                }
            }
        }
};