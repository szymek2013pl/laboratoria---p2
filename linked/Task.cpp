#include "Task.hpp"

Task::Task(const std::string& description) : head{nullptr}, description{description} {}

Task::~Task() {

    clear();

}

void Task::add_subtask(const Subtask& subtask) {

    SubtaskNode* new_node = new SubtaskNode(subtask); 

    if (this->head == nullptr || subtask.get_priority() > this->head->data.get_priority()) {

        new_node->next = head;
        head = new_node;
        return;

    }

    SubtaskNode * curr = head;

    while (curr->next != nullptr && curr->next->data.get_priority() >= subtask.get_priority()) {

        curr = curr->next;

    }

    new_node->next = curr->next;
    curr->next = new_node;
    
}

void Task::complete_subtask(unsigned int index) {

    SubtaskNode * curr = head;
    
    for (unsigned int i = 0; i < index; i++) {

        curr = curr->next;

    }

    curr->data.mark_completed();

}

bool Task::is_completed() const {

    SubtaskNode * curr = head;

    while (curr!= nullptr) {

        if (curr->data.is_completed() == false) {

            return false;

        }

        curr = curr->next;

    }

    return true;

}

void Task::clear() {

    while (head != nullptr) {

        SubtaskNode * temp = head;
        head = head->next;
        delete temp;

    }

}

void Task::print() const{

    std::string s = "";
    
    if (is_completed()) {

        s = "[x]";

    }

    else {

        s = "[ ]";

    }
    
    std::cout << s << " " << this->description << std::endl;

    SubtaskNode * curr = head;

    while (curr != nullptr) {

        std::cout << "- ";
        curr->data.print();
        curr = curr->next;

    }

}

Task::Task() : head{nullptr}, description{""} {}

Task::Task(const Task& other) : head{nullptr}, description{other.description} {

    head = new SubtaskNode(other.head->data);

    SubtaskNode* current_new = head;
    SubtaskNode* current_other = other.head->next;

    while (current_other != nullptr) {

        current_new->next = new SubtaskNode(current_other->data);
        
        current_new = current_new->next;
        current_other = current_other->next;

    }

}

Task& Task::operator=(const Task& other) {

    if (this == &other) {

        return *this;

    }

    this->clear();

    description = other.description;
    head = new SubtaskNode(other.head->data);

    SubtaskNode* current_new = head;
    SubtaskNode* current_other = other.head->next;

    while (current_other != nullptr) {

        current_new->next = new SubtaskNode(current_other->data);
        
        current_new = current_new->next;
        current_other = current_other->next;

    }

    return *this;

}

Task::Task(Task&& other) : head{other.head}, description{std::move(other.description)} {

    other.head = nullptr;

}

Task& Task::operator=(Task&& other) {

    if (this == &other) {

        return *this;

    }

    clear();

    head = other.head;
    description = std::move(other.description);

    other.head = nullptr;

    return *this;

}
