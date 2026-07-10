# pragma once
# include "Vector2d.h"

class FuelAtom {
    private:
        Vector2d position;
        bool consumed;

        float crossSection;
        float fissionProbability;
        int neutronReleased;

    public:
        FuelAtom(Vector2d pos, float crossSection, float fissionProb, int neutronReleased):
            position(pos), consumed(false), crossSection(crossSection), fissionProbability(fissionProb), neutronReleased(neutronReleased) {}
        
        Vector2d getPosition() const {
            return position;
        }

        float getCrossSection() const {
            return crossSection;
        }

        float getFissionProb() const {
            return fissionProbability;
        }

        int getNeutronReleased() const {
            return neutronReleased;
        }

        bool isConsumed() const {
            return consumed;
        }

        void consume() {
            consumed = true;
        }
};

