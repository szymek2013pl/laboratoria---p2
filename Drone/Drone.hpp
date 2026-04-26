#ifndef DRONE_HPP
#define DRONE_HPP

#include <string>
#include <iostream>

class Drone {

    private:

        std::string model;
        int battery_level;
        static int active_drones;
    
    public:

        Drone(std::string model, int battery_level = 100);
        ~Drone();

        void print() const;
        static int get_active_drones() {

            return active_drones;

        }

        Drone(const Drone& other);

};

#endif
