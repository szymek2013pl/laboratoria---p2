#include "DroneFleet.hpp"

DroneFleet::DroneFleet(int capacity) : fleet{nullptr}, capacity{capacity}, size{0} {

    fleet = new std::unique_ptr<Drone> [capacity];

}

DroneFleet::~DroneFleet() {

    delete [] fleet;

}

void DroneFleet::add_drone(std::string model, int battery) {

    fleet[size] = std::make_unique<Drone>(model, battery);
    size++;

}

void DroneFleet::print_fleet() const {

    std::cout << "Active drones in system: " << Drone::get_active_drones() << std::endl;

    for (int i = 0; i < size; i++) {

        fleet[i]->print();

    }

}

DroneFleet::DroneFleet(const DroneFleet& other) : capacity{other.capacity}, size{other.size} {

    fleet = new std::unique_ptr<Drone> [capacity];

    for (int i = 0; i < size; i++) {

        fleet[i] = std::make_unique<Drone>(*(other.fleet[i]));

    }

}

DroneFleet& DroneFleet::operator=(const DroneFleet& other) {

    if (this == &other) {

        return *this;

    }

    if (capacity != other.capacity) {

        delete [] fleet;
        fleet = new std::unique_ptr<Drone> [other.capacity];
        capacity = other.capacity;

    }

    for (int i = 0; i < other.size; i++) {

        fleet[i] = std::make_unique<Drone>(*(other.fleet[i]));

    }

    capacity = other.capacity;
    size = other.size;

    return *this;

}

DroneFleet::DroneFleet(DroneFleet&& other) : capacity{other.capacity}, size{other.size} {

    fleet = other.fleet;

    other.capacity = 0;
    other.size = 0;
    other.fleet = nullptr;

}

DroneFleet& DroneFleet::operator=(DroneFleet&& other) {

    if (this == &other) {

        return *this;

    }

    delete [] fleet;

    capacity = other.capacity;
    size = other.size;
    fleet = other.fleet;

    other.capacity = 0;
    other.size = 0;
    other.fleet = nullptr;

    return *this;


}
