// ================================================================
// Lab: Inheritance in C++
// Course: Object-Oriented Programming for Engineers
// File: MainProgram.cpp
// ================================================================

#include <iostream>
#include <string>
#include <sstream>

// ================================================================
// CLASS DEFINITIONS
// ================================================================

// ----------------------------------------------------------------
// Base Class: Vehicle
// ----------------------------------------------------------------

class Vehicle {
protected:
    std::string make;
    int year;
    double fuelLevel;

public:
    Vehicle(std::string make, int year, double fuelLevel);

    std::string getMake() const;
    int getYear() const;
    double getFuelLevel() const;

    void refuel(double amount);

    virtual std::string describe() const = 0;

    virtual ~Vehicle();
};

// ----------------------------------------------------------------
// Derived Class: Car
// ----------------------------------------------------------------

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(std::string make, int year, double fuelLevel, int numDoors);

    int getNumDoors() const;

    std::string describe() const override;
};

// ----------------------------------------------------------------
// Derived Class: Truck
// ----------------------------------------------------------------

class Truck : public Vehicle {
private:
    double payloadTons;

public:
    Truck(std::string make, int year, double fuelLevel, double payloadTons);

    double getPayloadTons() const;

    std::string describe() const override;
};

// ================================================================
// FUNCTION IMPLEMENTATIONS
// ================================================================

// ----------------------------------------------------------------
// Vehicle member function implementations
// ----------------------------------------------------------------

Vehicle::Vehicle(std::string make, int year, double fuelLevel)
    : make(make), year(year), fuelLevel(fuelLevel) {
}

std::string Vehicle::getMake() const {
    return make;
}

int Vehicle::getYear() const {
    return year;
}

double Vehicle::getFuelLevel() const {
    return fuelLevel;
}

void Vehicle::refuel(double amount) {
    if (amount <= 0) {
        return;
    }

    fuelLevel += amount;

    if (fuelLevel > 100.0) {
        fuelLevel = 100.0;
    }
}

Vehicle::~Vehicle() {
}

// ----------------------------------------------------------------
// Car member function implementations
// ----------------------------------------------------------------

Car::Car(std::string make, int year, double fuelLevel, int numDoors)
    : Vehicle(make, year, fuelLevel), numDoors(numDoors) {
}

int Car::getNumDoors() const {
    return numDoors;
}

std::string Car::describe() const {
    std::ostringstream oss;

    oss << "Car: " << make
        << " (" << year << "), "
        << numDoors << " doors, fuel: "
        << fuelLevel << "%";

    return oss.str();
}

// ----------------------------------------------------------------
// Truck member function implementations
// ----------------------------------------------------------------

Truck::Truck(std::string make, int year, double fuelLevel, double payloadTons)
    : Vehicle(make, year, fuelLevel), payloadTons(payloadTons) {
}

double Truck::getPayloadTons() const {
    return payloadTons;
}

std::string Truck::describe() const {
    std::ostringstream oss;

    oss << "Truck: " << make
        << " (" << year << "), payload: "
        << payloadTons << "t, fuel: "
        << fuelLevel << "%";

    return oss.str();
}

// ================================================================
// MAIN
// ================================================================

int main() {
    // --- Basic usage demo ---
    Car   c("Toyota", 2020, 75.5, 4);
    Truck t("Ford",   2018, 60.0, 5.5);

    std::cout << c.describe() << "\n";
    std::cout << t.describe() << "\n";

    // Polymorphism via base pointer
    Vehicle* v1 = &c;
    Vehicle* v2 = &t;
    std::cout << v1->describe() << "\n";
    std::cout << v2->describe() << "\n";

    // Refuel demo
    c.refuel(20.0);
    std::cout << "After refuel: " << c.getFuelLevel() << "%\n";

    return 0;
}
