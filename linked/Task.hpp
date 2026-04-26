#pragma once
#include "Subtask.hpp"

struct SubtaskNode {
    Subtask data;
    SubtaskNode* next;
    SubtaskNode(const Subtask& data) : data(data), next(nullptr) {}
};

class Task {

    private:

        SubtaskNode* head;
        std::string description;
    
    public:

        Task(const std::string& description);
        Task();
        ~Task();

        Task(const Task& other);
        Task& operator=(const Task& other);
        
        Task(Task&& other);
        Task& operator=(Task&& other);

        void add_subtask(const Subtask& subtask);
        void complete_subtask(unsigned int index);
        bool is_completed() const;
        void clear();
        void print() const;

};
