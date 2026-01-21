#ifndef MARIOKARTRACER_H
#define MARIOKARTRACER_H

#include <iostream>
#include <cstring>

class MarioKartRacer {
private:
    char* name;
    int racerID;
    double* position; // [x, y] coordinates
    int lapCount;
    bool hasSpecialItem;
    static int totalRacers;

public:
    // Constructors & Destructor
    MarioKartRacer();
    MarioKartRacer(const char* name, int id, double x, double y);
    MarioKartRacer(const MarioKartRacer& other);
    ~MarioKartRacer();

    // Assignment operator
    MarioKartRacer& operator=(const MarioKartRacer& other);

    // Getters
    const char* getName() const { return name; }
    int getRacerID() const { return racerID; }
    const double* getPosition() const { return position; }
    int getLapCount() const { return lapCount; }
    bool getHasSpecialItem() const { return hasSpecialItem; }
    static int getTotalRacers() { return totalRacers; }

    // Setters
    void setPosition(double x, double y);
    void setHasSpecialItem(bool item) { hasSpecialItem = item; }

    // Member functions
    void displayRacer() const;

    // Operator Overloading
    MarioKartRacer& operator++();    // Prefix ++
    MarioKartRacer& operator--();    // Prefix --
    MarioKartRacer operator+(const MarioKartRacer& other) const;
    bool operator==(const MarioKartRacer& other) const;
};

// Non-member operator overload
std::ostream& operator<<(std::ostream& os, const MarioKartRacer& racer);

#endif