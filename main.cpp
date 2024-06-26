#include "parkingLot.hpp"
#include "Car.hpp"
#include "Bike.hpp"
#include <thread>
#include <vector>

void parkVehicles(parkingLot* lot, std::vector<vehicle*>& vehicles) {
    for (auto v : vehicles) {
        lot->parkVehicle(v);
    }
}

void unParkVehicles(parkingLot* lot, std::vector<vehicle*>& vehicles) {
    for (auto v : vehicles) {
        lot->unParkVehicle(v);
    }
}

int main() {
    parkingLot* lot = parkingLot::getInstance();
    
    level* lvl1 = new level(1, 10);
    level* lvl2 = new level(2, 10);
    
    lot->addLevel(lvl1);
    lot->addLevel(lvl2);
    
    vehicle *car1 = new car();
    vehicle *car2 = new car();
    vehicle *bike1 = new bike();
    vehicle *bike2 = new bike();

    std::vector<vehicle*> vehicles1 = { car1,car2 };
    std::vector<vehicle*> vehicles2 = { bike1, bike2 };

    std::thread t1(parkVehicles, lot, std::ref(vehicles1));
    std::thread t2(parkVehicles, lot, std::ref(vehicles2));

    t1.join();
    t2.join();

    lot->displayAvailability();

    std::thread t3(unParkVehicles, lot, std::ref(vehicles1));
    // std::thread t4(unParkVehicles, lot, std::ref(vehicles2));

    t3.join();
    // t4.join();

    lot->displayAvailability();
    
    return 0;
}
