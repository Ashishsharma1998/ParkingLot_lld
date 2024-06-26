#ifndef PARKINGSPOT_HPP
#define PARKINGSPOT_HPP

#include "vehicle.hpp"
#include "vehicleType.hpp"
#include "GlobalLock.hpp"
#include <iostream>
#include <mutex>

class parkingSpot {
private:
    int spotNumber;
    vehicleType vehicletype;
    vehicle* parkedVehicle;

public:
    parkingSpot(int spot, vehicleType type) {
        spotNumber = spot;
        vehicletype = type;
        parkedVehicle = nullptr;
    }

    bool isAvailable() {
        return parkedVehicle == nullptr;
    }

    void parkVehicle(vehicle* vehicle) {
        if (isAvailable() && vehicle->getType() == vehicletype) {
            parkedVehicle = vehicle;
        } else {
            std::cout << "Parking spot is not available\n";
        }
    }

    void unParkVehicle() {
        parkedVehicle = nullptr;
    }

    vehicleType getVehicleType() {
        return vehicletype;
    }

    vehicle* getParkedVehicle() {
        return parkedVehicle;
    }

    int getSpotNumber() {
        return spotNumber;
    }
};

#endif // PARKINGSPOT_HPP
