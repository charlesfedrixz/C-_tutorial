#include <iostream>
#include <vector>
using namespace std;

class Car
{
public:
    // Data members
    string brand;
    int speed;

    // Member function to display car information
    void displayInfo() const
    { // Marked as const
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }

    // Member function to fill car details
    void fillDetails()
    {
        cout << "Enter car brand: ";
        cin >> brand;
        cout << "Enter car speed: ";
        cin >> speed;
    }
};

int main()
{
    vector<Car> cars; // Vector to store multiple Car objects
    int numCars;

    cout << "How many cars do you want to enter? ";
    cin >> numCars;

    // Loop to fill details for each car
    for (int i = 0; i < numCars; i++)
    {
        Car car;
        car.fillDetails();   // Fill the details for each car
        cars.push_back(car); // Add the car to the vector
    }

    cout << "\nCar details:\n";
    // Display information for each car
    for (const auto &car : cars)
    {
        car.displayInfo(); // Display the information for each car
    }

    return 0;
}
