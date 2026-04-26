#ifndef TELEMETRYDATA_HPP
#define TELEMETRYDATA_HPP

#include <string>
#include <iostream>

enum class SensorType {

    GPS,
    TEMPERATURE,
    BATTERY,
    GYROSCOPE

};

class TelemetryData {

    private:

        unsigned int timestamp;
        SensorType type;
        double value;
        bool is_critical;

    public:

        TelemetryData();
        TelemetryData(unsigned int timestamp, SensorType type, double value, bool is_critical);

        void print() const;

        unsigned int get_timestamp() {

            return this->timestamp;

        }

        SensorType get_type() {

            return this->type;

        }

        double get_value() {

            return this->value;

        }

        bool get_critical() {

            return this->is_critical;

        }

};

#endif
