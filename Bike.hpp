#ifndef BIKE_HPP
#define BIKE_HPP

#include "vehicle.hpp"
#include "vehicleType.hpp"

class bike : public vehicle {
public:
    bike(){}
    vehicleType getType(){
        return vehicleType::Bike;
    }
};

#endif // BIKE_HPP
