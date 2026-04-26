#ifndef DRONEFLEET_HPP
#define DRONEFLEET_HPP

#include <memory>

#include "Drone.hpp"

class DroneFleet {

    private:

        std::unique_ptr<Drone>* fleet;
        int capacity;
        int size;
    
    public: 

        DroneFleet(int capacity);

        void add_drone(std::string model, int battery);
        void print_fleet() const;

        ~DroneFleet();

        DroneFleet(const DroneFleet& other);
        DroneFleet& operator=(const DroneFleet& other);

        DroneFleet(DroneFleet&& other);
        DroneFleet& operator=(DroneFleet&& other);

};

#endif
