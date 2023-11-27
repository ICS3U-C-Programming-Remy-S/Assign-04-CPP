// Copyright (c) 2021 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Nov, 26, 2023
// This program will ask the user for two whole
// min and max and will find all the perfect numbers between them

#include <cmath>
#include <iostream>

int main() {
    // Declare min and max int and str
    std::string userMinStr;
    int userMinInt;
    std::string userMaxStr;
    int userMaxInt;
    bool perfectNumbersFound = false;

    do {
        // Get user min and max as str and message about program
        std::cout << "This program will ask for two whole numbers ";
        std::cout << " and it will find all perfect ";
        std::cout << " numbers between those two whole ";
        std::cout << " numbers and use the same min and max to exit.\n";
        std::cout << "Please enter your min number: ";
        std::cin >> userMinStr;
        std::cout << "Please enter your max number: ";
        std::cin >> userMaxStr;

        // Try to convert userMinStr to int
        try {
            userMinInt = std::stoi(userMinStr);

            // Try to convert userMaxStr to int
            try {
                userMaxInt = std::stoi(userMaxStr);

                // Convert userMinStr to float
                float userMinFloat = std::stof(userMinStr);

                // Convert userMaxStr to float
                float userMaxFloat = std::stof(userMaxStr);

                // Check if user numbers are not whole numbers
                if (userMinInt != userMinFloat || userMaxInt != userMaxFloat) {
                    std::cout << userMinFloat << " and " << userMaxFloat <<
                    " are not whole numbers." << std::endl;
                } else if (userMinInt < 0 || userMaxInt < 0) {
                    // Check if user numbers are negative
                    std::cout << "\n"
                              << userMinInt << ", " << userMaxInt <<
                              " are not positive min and max.\n";
                } else if (userMinInt > userMaxInt) {
                    // Check if min is greater than max
                    std::cout << "\n"
                              << userMinInt << ", " << userMaxInt <<
                              " are not valid min and max.\n";
                } else if (userMinInt < userMaxInt) {
                    // Counter loop until max
                    for (int counter = userMinInt; counter <= userMaxInt;
                    counter++) {
                        // variables to compare decimal to int
                        double sqrtCounterAsDouble = sqrt(counter);
                        int sqrtCounterAsInt = static_cast<int>(sqrt(counter));
                        // Check if the square root of counter is whole
                        if (counter == 0) {
                            counter = counter + 1;
                        } else if (sqrtCounterAsDouble == sqrtCounterAsInt) {
                            std::cout << counter << ", ";
                            perfectNumbersFound = true;
                        }
                    }
                    if (perfectNumbersFound == false) {
                        // Case for no perfect numbers found
                        std::cout << "There are no perfect numbers between " <<
                        userMinInt << " and " << userMaxInt << "\n";
                    } else {
                        std::cout << "are all the perfect numbers between " <<
                        userMinInt << " and " << userMaxInt << "\n";
                    }
                }
            } catch (std::invalid_argument) {
                // Message for invalid user max
                std::cout << "\n"
                          << userMaxStr << " is not a valid max.\n";
            }
        } catch (std::invalid_argument) {
            // Message for invalid user min
            std::cout << "\n"
                      << userMinStr << " is not a valid min.\n";
        }
    } while (userMinInt != userMaxInt);
}
