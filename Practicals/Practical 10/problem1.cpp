#include <iostream>
#include <string>
#include <vector>

int main() {
    const int tableSize = 10;
    std::vector<std::string> parking(tableSize);
    int vehicleCount;

    std::cout << "Number of vehicles: ";
    if (!(std::cin >> vehicleCount) || vehicleCount < 0) {
        std::cerr << "Enter a non-negative number of vehicles.\n";
        return 1;
    }

    for (int i = 0; i < vehicleCount; ++i) {
        std::string registration;
        std::cout << "Registration number " << i + 1 << ": ";
        std::cin >> registration;

        if (registration.empty() || registration.back() < '0' ||
            registration.back() > '9') {
            std::cout << "Registration must end in a digit. Vehicle not parked.\n";
            continue;
        }

        const int startingSlot = registration.back() - '0';
        bool parked = false;

        for (int offset = 0; offset < tableSize; ++offset) {
            const int slot = (startingSlot + offset) % tableSize;
            if (parking[slot].empty()) {
                parking[slot] = registration;
                parked = true;
                break;
            }
        }

        if (!parked) {
            std::cout << "Parking lot is full. Vehicle " << registration
                      << " could not be parked.\n";
        }
    }

    std::cout << "\nFinal parking slots:\n";
    for (int slot = 0; slot < tableSize; ++slot) {
        std::cout << "Slot " << slot << ": ";
        if (parking[slot].empty()) {
            std::cout << "Empty";
        } else {
            std::cout << parking[slot];
        }
        std::cout << '\n';
    }

    return 0;
}
