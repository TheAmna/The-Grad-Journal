#include "MarioKartRacer.h"
#include <iostream>

// Initialize static member
int MarioKartRacer::totalRacers = 0;

// Default constructor
MarioKartRacer::MarioKartRacer() : name(nullptr), racerID(0), position(nullptr), 
                                  lapCount(0), hasSpecialItem(false) {
    name = new char[1];
    name[0] = '\0';
    
    position = new double[2];
    position[0] = 0.0;
    position[1] = 0.0;
    
    totalRacers++;
}

// Parameterized constructor
MarioKartRacer::MarioKartRacer(const char* name, int id, double x, double y) 
    : racerID(id), lapCount(0), hasSpecialItem(false) {
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    
    position = new double[2];
    position[0] = x;
    position[1] = y;
    
    totalRacers++;
}

// Copy constructor
MarioKartRacer::MarioKartRacer(const MarioKartRacer& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    
    racerID = other.racerID;
    
    position = new double[2];
    position[0] = other.position[0];
    position[1] = other.position[1];
    
    lapCount = other.lapCount;
    hasSpecialItem = other.hasSpecialItem;
    
    totalRacers++;
}

// Destructor
MarioKartRacer::~MarioKartRacer() {
    delete[] name;
    delete[] position;
    totalRacers--;
}

// Copy assignment operator
MarioKartRacer& MarioKartRacer::operator=(const MarioKartRacer& other) {
    if (this != &other) {
        // Delete old memory
        delete[] name;
        delete[] position;
        
        // Copy new data
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        
        racerID = other.racerID;
        
        position = new double[2];
        position[0] = other.position[0];
        position[1] = other.position[1];
        
        lapCount = other.lapCount;
        hasSpecialItem = other.hasSpecialItem;
    }
    return *this;
}

void MarioKartRacer::setPosition(double x, double y) {
    position[0] = x;
    position[1] = y;
}

void MarioKartRacer::displayRacer() const {
    std::cout << "Racer: " << name << " (ID: " << racerID 
              << ") - Position: (" << position[0] << ", " << position[1] 
              << ") - Laps: " << lapCount 
              << " - Special Item: " << (hasSpecialItem ? "Yes" : "No") 
              << std::endl;
}

// Operator Overloading

// Prefix ++ operator (increment lap)
MarioKartRacer& MarioKartRacer::operator++() {
    lapCount++;
    return *this;
}

// Prefix -- operator (decrement lap, minimum 0)
MarioKartRacer& MarioKartRacer::operator--() {
    if (lapCount > 0) {
        lapCount--;
    }
    return *this;
}

// + operator (combine positions)
MarioKartRacer MarioKartRacer::operator+(const MarioKartRacer& other) const {
    MarioKartRacer result("CombinedRacer", -1, 0, 0);
    result.position[0] = this->position[0] + other.position[0];
    result.position[1] = this->position[1] + other.position[1];
    return result;
}

// == operator (compare by ID)
bool MarioKartRacer::operator==(const MarioKartRacer& other) const {
    return this->racerID == other.racerID;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const MarioKartRacer& racer) {
    os << "Racer: " << racer.getName() << " (ID: " << racer.getRacerID() 
       << ") - Position: (" << racer.getPosition()[0] << ", " << racer.getPosition()[1] 
       << ") - Laps: " << racer.getLapCount();
    return os;
}