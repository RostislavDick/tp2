#include "Keeper.h"
#include "Percussion.h"
#include "Stringed.h"
#include "Wind.h"
#include <iostream>

int main() {
    Keeper keeper;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add instrument\n";
        std::cout << "2. Remove instrument\n";
        std::cout << "3. Print all instruments\n";
        std::cout << "4. Save to file\n";
        std::cout << "5. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
            case 1: {
                int typeChoice;
                std::cout << "Select instrument type:\n";
                std::cout << "1. Percussion\n";
                std::cout << "2. Stringed\n";
                std::cout << "3. Wind\n";
                std::cout << "Enter your choice: ";
                std::cin >> typeChoice;
                std::cout << "\n";

                Instrument* instrument = nullptr;
                if (typeChoice == 1) {
                    instrument = new Percussion();
                } else if (typeChoice == 2) {
                    instrument = new Stringed();
                } else if (typeChoice == 3) {
                    instrument = new Wind();
                } else {
                    std::cerr << "Invalid instrument type!\n";
                    break;
                }

                instrument->input();
                keeper.addInstrument(instrument);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                std::cout << "\n";
                keeper.removeInstrument(index);
                break;
            }
            case 3:
                keeper.printAll();
                break;
            case 4: {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                std::cout << "\n";
                keeper.saveToFile(filename);
                break;
            }
            case 5: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                std::cout << "\n";
                keeper.loadFromFile(filename);
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                std::cout << "\n";
        }
    } while (choice != 0);

    return 0;
}
