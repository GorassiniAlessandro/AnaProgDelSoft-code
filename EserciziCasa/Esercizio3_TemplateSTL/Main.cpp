#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include "MaxInContainer.hpp"

int main() {
    std::cout << "=== Template e STL: MaxInContainer ===" << std::endl << std::endl;
    
    // Test 1: vector<int>
    std::cout << "--- Test 1: vector<int> ---" << std::endl;
    std::vector<int> int_vector = {15, 3, 42, 8, 99, 5, 27};
    
    std::cout << "Vettore: ";
    for (int val : int_vector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    try {
        int max_int = MaxInContainer(int_vector);
        std::cout << "Valore massimo (int): " << max_int << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    // Test 2: vector<float>
    std::cout << "--- Test 2: vector<float> ---" << std::endl;
    std::vector<float> float_vector = {3.14f, 2.71f, 9.99f, 1.41f, 8.5f};
    
    std::cout << "Vettore: ";
    std::cout << std::fixed << std::setprecision(2);
    for (float val : float_vector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    try {
        float max_float = MaxInContainer(float_vector);
        std::cout << "Valore massimo (float): " << max_float << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    // Test 3: vector<double>
    std::cout << "--- Test 3: vector<double> ---" << std::endl;
    std::vector<double> double_vector = {1.234, 5.678, 2.345, 9.876, 3.456};
    
    std::cout << "Vettore: ";
    std::cout << std::fixed << std::setprecision(3);
    for (double val : double_vector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    try {
        double max_double = MaxInContainer_V2(double_vector);
        std::cout << "Valore massimo (double) - V2: " << max_double << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    // Test 4: list<int>
    std::cout << "--- Test 4: list<int> ---" << std::endl;
    std::list<int> int_list = {7, 2, 11, 4, 25, 6};
    
    std::cout << "Lista: ";
    for (int val : int_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    try {
        int max_list = MaxInContainer_V3(int_list);
        std::cout << "Valore massimo (list) - V3 (std::max_element): " << max_list << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    // Test 5: Contenitore vuoto
    std::cout << "--- Test 5: Contenitore vuoto ---" << std::endl;
    std::vector<int> empty_vector;
    
    try {
        int max_empty = MaxInContainer(empty_vector);
        std::cout << "Valore massimo: " << max_empty << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore catturato: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Test completati!" << std::endl;
    
    return 0;
}
