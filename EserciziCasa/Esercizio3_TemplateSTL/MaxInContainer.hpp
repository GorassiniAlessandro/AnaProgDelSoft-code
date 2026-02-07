#ifndef MAXINCONTAINER_HPP
#define MAXINCONTAINER_HPP

#include <stdexcept>

/**
 * Template function che ritorna il massimo valore in un contenitore generico.
 * 
 * @param container Il contenitore (vector, list, deque, ecc.)
 * @return Il valore massimo contenuto nel contenitore
 * @throws std::invalid_argument se il contenitore è vuoto
 */
template <typename Container>
typename Container::value_type MaxInContainer(const Container& container) {
    if (container.empty()) {
        throw std::invalid_argument("Il contenitore è vuoto");
    }
    
    typename Container::value_type max_value = *container.begin();
    
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it > max_value) {
            max_value = *it;
        }
    }
    
    return max_value;
}

/**
 * Versione alternativa usando range-based for loop (C++11)
 */
template <typename T>
T MaxInContainer_V2(const std::vector<T>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("Il vettore è vuoto");
    }
    
    T max_value = vec[0];
    for (const auto& element : vec) {
        if (element > max_value) {
            max_value = element;
        }
    }
    
    return max_value;
}

/**
 * Versione usando std::max_element (STL algorithm)
 */
template <typename Container>
typename Container::value_type MaxInContainer_V3(const Container& container) {
    if (container.empty()) {
        throw std::invalid_argument("Il contenitore è vuoto");
    }
    
    auto it = std::max_element(container.begin(), container.end());
    return *it;
}

#endif
