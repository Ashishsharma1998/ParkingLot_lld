#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "parkingSpot.hpp"
#include <vector>
#include <iostream>
#include <mutex>

class level {
private:
    int floor;
    std::vector<parkingSpot*> parkingSpots;

public:
    level(int lvl, int numSpots) {
        floor = lvl;
        parkingSpots.assign(numSpots, nullptr);
        for (int i = 0; i < numSpots; i++) {
            if (i % 2 == 0) {
                parkingSpots[i] = new parkingSpot(i, Car);
            } else {
                parkingSpots[i] = new parkingSpot(i, Bike);
            }
        }
    }

    ~level() {
        for (auto spot : parkingSpots) {
            delete spot;
        }
    }

    bool parkVehicle(vehicle* vehicle) {
        
        for (auto spot : parkingSpots) {
            if (spot->isAvailable() && spot->getVehicleType() == vehicle->getType()) {
                spot->parkVehicle(vehicle);
                return true;
            }
        }
        return false;
    }

    bool unParkVehicle(vehicle* vehicle) {
        for (auto spot : parkingSpots) {
            if (!spot->isAvailable() && spot->getParkedVehicle() == vehicle) {
                spot->unParkVehicle();
                return true;
            }
        }
        return false;
    }

    void displayAvailability() {
       
        std::cout << "Level " << floor << " availability\n";
        for (auto spot : parkingSpots) {
            std::cout << "Spot " << spot->getSpotNumber() << " : " << (spot->isAvailable() ? "available\n" : "occupied\n");
        }
    }
};

#endif // LEVEL_HPP
