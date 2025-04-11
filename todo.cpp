#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i] = nullptr;
    }

}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0; i < size; i++){
        delete[] tasks[i];
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int str_size = 0;
    while(str[str_size]!='\0'){
        str_size++;
    }
    return str_size;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int src_size = string_length(src);
    for(int i = 0; i<src_size; i++){
        dest[i] = src[i];
    }
    dest[src_size] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size>=MAX_TASKS){
        throw std::range_error("Too many adds");
    }
    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index<0 || index>=size){
        throw std::out_of_range("Out of range");
    }
    
    for(int i=index; i<size; i++){
        tasks[i] = tasks[i+1];
    }
    tasks[size-1] = nullptr;
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    
    static const char* return_task[MAX_TASKS];
    

    for(int i=0; i<size; i++){
        return_task[i] = tasks[i];
    }
    return return_task;
}