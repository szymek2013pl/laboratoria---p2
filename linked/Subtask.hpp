#ifndef SUBTASK_HPP
#define SUBTASK_HPP

#include <string>
#include <iostream>

class Subtask {

    private:

        std::string description;
        unsigned int priority;
        bool completed;
    
    public:

        Subtask(const std::string& description, unsigned int priority = 0, bool completed = false);

        void mark_completed();
        bool is_completed() const;
        unsigned int get_priority() const;
        void print() const;

};

#endif
