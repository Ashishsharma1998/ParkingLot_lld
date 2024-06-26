#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include "level.hpp"
#include <vector>
#include <iostream>
#include <mutex>

class parkingLot {
private:
    static parkingLot* instance;
    std::vector<level*> levels;
    int cnt=0;
    parkingLot() {
        cnt++;
        std::cout<<"number of times constructor being called "<<cnt<<std::endl;
    }

public:
    static parkingLot* getInstance() {
        if(instance==nullptr){
            std::lock_guard<std::mutex> lock(GlobalLock::mtx);
            if (instance == nullptr) {
                instance = new parkingLot();
            }
        }
        return instance;
    }

    ~parkingLot() {
        for (auto lvl : levels) {
            delete lvl;
        }
    }

    void addLevel(level* lvl) {
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        levels.push_back(lvl);
    }

    bool parkVehicle(vehicle* vehicle) {
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        for (auto lvl : levels) {
            if (lvl->parkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }

    bool unParkVehicle(vehicle* vehicle) {
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        for (auto lvl : levels) {
            if (lvl->unParkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }

    void displayAvailability() {
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        for (auto lvl : levels) {
            lvl->displayAvailability();
        }
    }

    void healthCheck() {
        std::cout << "Health is fine\n";
    }
};

parkingLot* parkingLot::instance = nullptr;

#endif // PARKINGLOT_HPP
