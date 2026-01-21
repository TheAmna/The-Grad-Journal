#ifndef RACETRACK_H
#define RACETRACK_H

#include "MarioKartRacer.h"

class RaceTrack {
private:
    MarioKartRacer** racers;
    int maxRacers;
    int currentRacerCount;
    const static int TRACK_SIZE = 100;

public:
    // Constructors & Destructor
    RaceTrack(int maxR = 8);
    RaceTrack(const RaceTrack& other);
    ~RaceTrack();

    // Assignment operator
    RaceTrack& operator=(const RaceTrack& other);

    // Member functions
    bool addRacer(const MarioKartRacer& racer);
    void moveRacer(int racerID, double deltaX, double deltaY);
    MarioKartRacer* findRacer(int racerID) const;
    void updateLap(int racerID);
    void displayAllRacers() const;
    int getCurrentRacerCount() const { return currentRacerCount; }
    MarioKartRacer** getRacers() const { return racers; }
};

#endif