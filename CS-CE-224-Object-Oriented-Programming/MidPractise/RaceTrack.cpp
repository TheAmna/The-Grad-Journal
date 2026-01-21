#include "RaceTrack.h"
#include <iostream>

// Constructor
RaceTrack::RaceTrack(int maxR) : maxRacers(maxR), currentRacerCount(0) {
    racers = new MarioKartRacer*[maxRacers];
    for (int i = 0; i < maxRacers; i++) {
        racers[i] = nullptr;
    }
}

// Copy constructor
RaceTrack::RaceTrack(const RaceTrack& other) 
    : maxRacers(other.maxRacers), currentRacerCount(other.currentRacerCount) {
    
    racers = new MarioKartRacer*[maxRacers];
    for (int i = 0; i < maxRacers; i++) {
        if (other.racers[i] != nullptr) {
            racers[i] = new MarioKartRacer(*(other.racers[i]));
        } else {
            racers[i] = nullptr;
        }
    }
}

// Destructor
RaceTrack::~RaceTrack() {
    for (int i = 0; i < currentRacerCount; i++) {
        delete racers[i];
    }
    delete[] racers;
}

// Assignment operator
RaceTrack& RaceTrack::operator=(const RaceTrack& other) {
    if (this != &other) {
        // Clean up existing memory
        for (int i = 0; i < currentRacerCount; i++) {
            delete racers[i];
        }
        delete[] racers;
        
        // Copy new data
        maxRacers = other.maxRacers;
        currentRacerCount = other.currentRacerCount;
        
        racers = new MarioKartRacer*[maxRacers];
        for (int i = 0; i < maxRacers; i++) {
            if (other.racers[i] != nullptr) {
                racers[i] = new MarioKartRacer(*(other.racers[i]));
            } else {
                racers[i] = nullptr;
            }
        }
    }
    return *this;
}

bool RaceTrack::addRacer(const MarioKartRacer& racer) {
    if (currentRacerCount >= maxRacers) {
        return false;
    }
    
    racers[currentRacerCount] = new MarioKartRacer(racer);
    currentRacerCount++;
    return true;
}

void RaceTrack::moveRacer(int racerID, double deltaX, double deltaY) {
    MarioKartRacer* racer = findRacer(racerID);
    if (racer != nullptr) {
        const double* currentPos = racer->getPosition();
        double newX = currentPos[0] + deltaX;
        double newY = currentPos[1] + deltaY;
        
        // Update position using setter
        const_cast<MarioKartRacer*>(racer)->setPosition(newX, newY);
        
        // Check if crossed finish line (simplified: when x > TRACK_SIZE)
        if (newX > TRACK_SIZE) {
            updateLap(racerID);
        }
    }
}

MarioKartRacer* RaceTrack::findRacer(int racerID) const {
    for (int i = 0; i < currentRacerCount; i++) {
        if (racers[i]->getRacerID() == racerID) {
            return racers[i];
        }
    }
    return nullptr;
}

void RaceTrack::updateLap(int racerID) {
    MarioKartRacer* racer = findRacer(racerID);
    if (racer != nullptr) {
        // Use the ++ operator we overloaded
        ++(*racer);
        racer->setHasSpecialItem(true); // Get special item after completing lap
    }
}

void RaceTrack::displayAllRacers() const {
    std::cout << "=== Race Track Status ===" << std::endl;
    for (int i = 0; i < currentRacerCount; i++) {
        racers[i]->displayRacer();
    }
    std::cout << "=========================" << std::endl;
}