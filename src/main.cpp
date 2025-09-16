#include <iostream>
#include <memory>
#include <vector>

// Demonstrates raw memory handling
void rawMemoryExample() {
    std::cout << "=== Raw Memory Example ===\n";

    // Allocate memory for a single integer
    int* number = new int(42);
    std::cout << "Single value: " << *number << '\n';
    delete number; // Free the memory

    // Allocate memory for an array
    int size = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    // Print array using range-based loop
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << '\n';
    }

    delete[] arr; // Free the array
}

// Demonstrates smart pointers (preferred in modern C++)
void smartPointerExample() {
    std::cout << "\n=== Smart Pointer Example ===\n";

    // unique_ptr for single ownership
    auto numPtr = std::make_unique<int>(100);
    std::cout << "unique_ptr value: " << *numPtr << '\n';

    // shared_ptr for shared ownership
    auto sharedNum = std::make_shared<int>(200);
    {
        auto sharedNum2 = sharedNum; // Both share ownership
        std::cout << "shared_ptr value: " << *sharedNum << '\n';
        std::cout << "use_count inside scope: " << sharedNum.use_count() << '\n';
    } // sharedNum2 goes out of scope here

    std::cout << "use_count after scope: " << sharedNum.use_count() << '\n';

    // Using smart pointer with arrays (vector is even better)
    auto arrPtr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        arrPtr[i] = i * 20;
        std::cout << "arrPtr[" << i << "] = " << arrPtr[i] << '\n';
    }
}

// Demonstrates modern alternative: std::vector
void vectorExample() {
    std::cout << "\n=== std::vector Example (Modern Best Practice) ===\n";

    std::vector<int> values = {0, 10, 20, 30, 40};
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << "values[" << i << "] = " << values[i] << '\n';
    }
}

int main() {
    rawMemoryExample();
    smartPointerExample();
    vectorExample();

    return 0;
}
