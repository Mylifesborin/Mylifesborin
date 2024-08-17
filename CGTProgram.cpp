/*
 * CGTProgram.cpp
 *
 *  Date: June 25, 2024
 *  Author: Yakuba Conde
 */

// Standard input/output stream library
#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;                           // namespace

class ItemTracker {                            // ItemTracker class
    private:
        map<string, int> frequency;            // Map to track frequency of items

    public:
        ItemTracker() {                        // Constructor for in file and updates map
            ifstream infile("CS210_Project_Three_Input_File.txt"); // file stream
            string item;
            while (infile >> item) {           // Loop through every item
                frequency[item]++;             // Update frequency map for item
            }
        }

        int getFrequency(string item) {        // Returns frequency of given item
            return frequency[item];
        }

        void printList() {                     // Shows list of items and their frequencies
            for (auto const& [item, count] : frequency) {        // Range-based for loop through map
                cout << item << " " << count << endl;            // Print item and its frequency
            }
        }

        void printHistogram() {               // Prints out histogram of item frequencies
            for (auto const& [item, count] : frequency) {         // Range-based for loop through map
                cout << item << " ";                              // Print item
                for (int i = 0; i < count; i++) {                 // Loop through frequency count
                    cout << "*";                                  // Print asterisk for each count
                }
                cout << endl;                                     // Newline for next item
            }
        }

        void backupData() {                                      // Writes frequency map
            ofstream outfile("frequency.dat");                   // Output file stream
            for (auto const& [item, count] : frequency) {        // Range-based for loop through map
                outfile << item << " " << count << endl;         // Write item and its frequency to file
            }
        }
};

int main() {
    ItemTracker tracker;                     // Create ItemTracker object

    while (true) {                           // Infinite loop until user exits
        cout << "Menu Options:" << endl;     // Print menu options
        cout << "1. Look up item frequency" << endl;
        cout << "2. Print list of item frequencies" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit program" << endl;

        int choice;
        cin >> choice;                       // Read user choice

        switch (choice) {                    // Switch statement based on user option
            case 1: {                        // Look up item frequency
                string item;
                cout << "Enter item to look up frequency: ";
                cin >> item; // Read item from user
                cout << "Frequency of " << item << ": " << tracker.getFrequency(item) << endl; // Print frequency of item
                break;
            }
            case 2: {                         // Print list of item frequencies
                tracker.printList();          // Print list
                tracker.backupData();         // Write data to file
                break;
            }
            case 3: {                         // Print histogram of item frequencies
                tracker.printHistogram();     // Print histogram
                tracker.backupData();         // Write data to file
                break;
            }
            case 4: {                         // Exit program
                tracker.backupData();         // Write data to file
                return 0;                     // Exit program with code 0
            }
            default: {                        // Invalid choice
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
