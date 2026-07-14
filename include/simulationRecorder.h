#pragma once
#include "Reactor.h"
#include <vector>
#include <string>
#include <sstream>
# include <fstream>


class SimulationRecorder{
    private:
        std::vector<std::string> frames;

    public:

        std::string createNeutronJSON(const Reactor& reactor) {
            std::ostringstream JSON;
            JSON <<"[";

            bool first = true;
            for (const auto& n: reactor.getAllNeutrons()){
                
                if(!n.isActive()){
                    continue;
                }

                if (!first){
                    JSON <<",";
                }

                JSON << "{"
                << "\"x\": " << n.getPosition().x << ", " << "\"y\": " << n.getPosition().y 
                <<"}";
                first = false;
            }
            JSON << "]";

            return JSON.str();
        }

        std::string createFuelAtomJSON(const Reactor& reactor) {
            std::ostringstream FJSON;
            FJSON << "[";
            
            bool first = true;
            for(const auto& a: reactor.getAllFuelAtoms()){
                
                if (!first) {
                    FJSON << ",";
                }
                
                FJSON << "{"
                << "\"x\": " << a.getPosition().x << ", " << "\"y\": " << a.getPosition().y << ", " << "\"consumed\": " << (a.isConsumed() ? "true" : "false")
                << "}";
                
                first = false;
        }
        FJSON << "]";

        return FJSON.str();
    }
    
    std::string createFrame(int tick, const Reactor& reactor){
        std::ostringstream frame;
        frame<< "{\"tick\": " <<tick
        << ", \"neutrons\": " <<createNeutronJSON(reactor)
        << ", \"fuel_atoms\": " <<createFuelAtomJSON(reactor)
        <<"}";
        return frame.str();
    }

    void saveTofile(const std::string& path){
        std::ofstream file(path);
        file << "{\"frames\": [";
        for (size_t i = 0; i< frames.size(); i++){
            if (i>0){
            file << ", ";
        }
            file <<frames[i];
        }
    file << "]}";
    file.close();
        
    }
    void captureFrame(int tick, const Reactor& reactor) {
        frames.push_back(createFrame(tick,reactor));
    }
};