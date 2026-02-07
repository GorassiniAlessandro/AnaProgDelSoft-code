#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    static const int DEFAULT_CAPACITY = 100;

public:
    // Costruttore
    Stack();
    
    // Operazioni principali
    void push(const T& value);
    T pop();
    T top() const;
    bool empty() const;
    int size() const;
    
    // Destruttore
    ~Stack();
};

// Implementazione inline (template)

template <typename T>
Stack<T>::Stack() {
    data.reserve(DEFAULT_CAPACITY);
}

template <typename T>
Stack<T>::~Stack() {
    data.clear();
}

template <typename T>
void Stack<T>::push(const T& value) {
    data.push_back(value);
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: tentativo di pop su una pila vuota");
    }
    T value = data.back();
    data.pop_back();
    return value;
}

template <typename T>
T Stack<T>::top() const {
    if (empty()) {
        throw std::underflow_error("Stack empty: tentativo di accesso al top su una pila vuota");
    }
    return data.back();
}

template <typename T>
bool Stack<T>::empty() const {
    return data.empty();
}

template <typename T>
int Stack<T>::size() const {
    return data.size();
}

#endif
