#include "calculator.h"
#include <stdexcept>
#include <limits>

int int_max = std::numeric_limits<int>::max();
int int_min = std::numeric_limits<int>::min();

int Calculator::add(int a, int b) {
    // TODO
    if(a==int_max && b>0){
        throw std::overflow_error("Add overflow");
    }
    if(a==int_min && b<0){
        throw std::overflow_error("Add underflow");
    }
    
    return a+b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if(a==int_max && b<0){
        throw std::overflow_error("Subtraction overflow");
    }
    if(a==int_min && b>0){
        throw std::overflow_error("Subtraction underflow");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if(a==int_max/2 + 1){
        throw std::overflow_error("Multiplication overflow");
    }
    else if(a==int_min/2){
        throw std::overflow_error("Multiplication underflow");
    }
    return a*b;
} 

int Calculator::div(int a, int b) {
    // TODO
    if(b==0){
        throw std::invalid_argument("Division by zero");
    }
    else if( a==int_min){
        throw std::overflow_error("Division overflow");
    }
    return a/b;
}