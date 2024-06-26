#ifndef CAR_HPP
#define CAR_HPP

#include "vehicle.hpp"
#include "vehicleType.hpp"

class car : public vehicle {
public:
    car(){}
    vehicleType getType(){
        return vehicleType::Car;
    }
};

#endif // CAR_HPP
