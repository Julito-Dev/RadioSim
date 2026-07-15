# RadioSim

A 2D nuclear reactor simulation in C++ with a Python/Pygame visualizer.

Neutrons are placed inside a reactor core filled with fuel atoms. Each tick, neutrons move and may collide with fuel atoms — triggering either absorption or fission. Fission events release new fast neutrons, creating a chain reaction.

## Requirements

- **CMake** 3.14+
- C++17 compiler (GCC, Clang, or MSVC)
- Python 3 with `pygame` (`pip install pygame`)
- Visualizer runs automatically after simulation completes

## Build & Run

```sh
cmake -G "MinGW Makefiles" -B build
cmake --build build
./build/bin/reactor-sim
```

## Project Structure

```
├── CMakeLists.txt
├── include/
│   ├── Vector2d.h          # 2D vector math
│   ├── Particle.h          # Base particle class
│   ├── Neutron.h           # Neutron (fast/thermal)
│   ├── FuelAtom.h          # Fuel atom with fission properties
│   ├── Reactor.h           # Reactor core logic
│   ├── Physics.h           # Fission and collision physics
│   ├── simulationRecorder.h # JSON export for visualization
│   └── constants.h         # Physical constants
├── src/
│   └── main.cpp            # Entry point & simulation setup
├── visualizer/
│   └── main.py             # Pygame visualizer
└── simulation.json         # Generated simulation output
```

## How it Works

The reactor simulates neutron transport on a 2D plane:

- **Neutrons** move each tick; they can escape the boundary, be absorbed, or cause fission
- **Fuel atoms** have a fission probability and release a set number of neutrons when split
- **Chain reaction** depends on neutron speed — thermal neutrons are more likely to cause fission than fast ones
- **Simulation data** is exported as JSON and rendered frame by frame with Pygame
