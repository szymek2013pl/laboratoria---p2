#include "Drone.hpp"

Drone::Drone(std::string model, int battery_level) : model{model}, battery_level{battery_level} {

    active_drones++;

}

Drone::~Drone() {

    active_drones--;

}

void Drone::print() const {

    std::cout << "[Drone:" << model << ", Bat: " << battery_level << "%]" << std::endl;

}

Drone::Drone(const Drone& other) : model{other.model}, battery_level{other.battery_level} {}

int Drone::active_drones = 0;
