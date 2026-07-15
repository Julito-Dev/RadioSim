# include <iostream>
# include <vector>
# include <memory>
# include "../include/Particle.h"
# include "../include/Neutron.h"
# include "../include/FuelAtom.h"
# include "../include/constants.h"
# include "../include/Reactor.h"
# include "../include/simulationRecorder.h"

int main(){

    std::cout << "Loading simulation...\n";

    Reactor reactor(42, 1.8f, 25.0f);
    SimulationRecorder recorder;

    reactor.addNeutron(Neutron(Vector2d(0,0), Vector2d(7.0f, 5.0f)));
    reactor.addNeutron(Neutron(Vector2d(0,0), Vector2d(-5.0f, 8.0f)));
    reactor.addNeutron(Neutron(Vector2d(0,0), Vector2d(3.0f, -9.0f)));

    for (int x = -15; x <= 15; x++) {
        for (int y = -15; y <= 15; y++) {
            if ((x + y) % 2 == 0) {
                reactor.addFuelAtom(FuelAtom(Vector2d(x, y), 0.85f, 0.85f, 3));
            }
        }
    }

    float deltatime = 0.1f;   //increment this value to improve frames per second
    int totalTicks = 1000;     //increment this value to improve frames per second

    for (int tick = 0; tick < totalTicks; tick++){
        reactor.step(deltatime);
        recorder.captureFrame(tick, reactor);
    }

    recorder.saveTofile("simulation.json");
    std::system("python visualizer/main.py");
    return 0;
}
