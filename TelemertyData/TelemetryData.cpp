#include "TelemetryData.hpp"

TelemetryData::TelemetryData() : timestamp{0}, type{SensorType::BATTERY}, value{0.0}, is_critical{false} {}

TelemetryData::TelemetryData(unsigned int timestamp, SensorType type, double value, bool is_critical) : timestamp{timestamp}, type{type}, value{value}, is_critical{is_critical} {}

void TelemetryData::print() const {

    std::string s = "";
    std::string t = "";

    switch(this->type) {

        case SensorType::BATTERY : t = "BATTERY"; break;
        case SensorType::GPS : t = "GPS"; break;
        case SensorType::GYROSCOPE : t = "GYROSCOPE"; break;
        case SensorType::TEMPERATURE : t = "TEMPERATURE"; break;

    }

    if (this->is_critical == true) {

        s += "[!] T: ";

    }

    else {

        s += "[ ] T: ";

    }

    s += std::to_string(this->timestamp);
    s += "ms, Sensor: ";

    s += t;
    
    s += ", Value: ";
    s += std::to_string(this->value);

    std::cout << s << std::endl;

}
