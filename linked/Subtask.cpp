#include "Subtask.hpp"

Subtask::Subtask(const std::string& description, unsigned int priority, bool completed) : description{description}, priority{priority}, completed{completed} {}

void Subtask::mark_completed() {

    completed = true;

}

bool Subtask::is_completed() const{

    return completed;

}

unsigned int Subtask::get_priority() const {

    return priority;

}

void Subtask::print() const {

    std::string s = "";
    
    if (completed == false) {

        s += "[ ]";

    } 

    else {

        s += "[x]";

    }

    s += " P: ";
    s += std::to_string(priority);
    s += ", ";
    s += description;

    std::cout << s << std::endl;

}
