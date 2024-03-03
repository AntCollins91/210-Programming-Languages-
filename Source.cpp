#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class ItemTracker {
private:
    map<string, int> frequencyMap;

public:
    // Constructor to read data from input file and populate frequency map
    ItemTracker() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");
        string item;

        while (inputFile >> item) {
            frequencyMap[item]++;
        }

        inputFile.close();
    }

    // Menu option 1: Search for a specific item and return its frequency
    void searchItem() {
        string searchItem;
        cout << "Enter the item to search for: ";
        cin >> searchItem;

        cout << "Frequency of " << searchItem << ": " << frequencyMap[searchItem] << endl;
    }

    // Menu option 2: Print frequency of all items
    void printAllItemsFrequency() {
        cout << "Frequency of all items:" << endl;
        for (const auto& pair : frequencyMap) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Menu option 3: Print histogram of item frequencies
    void printHistogram() {
        cout << "Histogram:" << endl;
        for (const auto& pair : frequencyMap) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Save data to backup file
    void saveDataToFile() {
        ofstream outputFile("frequency.dat");
        for (const auto& pair : frequencyMap) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
        cout << "Data saved to frequency.dat" << endl;
    }
};

int main() {
    ItemTracker tracker;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Search for item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Save data to file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.searchItem();
            break;
        case 2:
            tracker.printAllItemsFrequency();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            tracker.saveDataToFile();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
