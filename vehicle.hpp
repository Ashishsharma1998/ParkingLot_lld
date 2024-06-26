#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "vehicleType.hpp"

class vehicle {
public:
    virtual vehicleType getType()=0;
};

#endif // VEHICLE_HPP
