// Name : AMNA ALI ( ID : aa09863) (Section: L4/T4)

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_RIDES = 100;
const int MAX_DRIVERS = 50;
const int START_RIDE_ID = 100001;

// Struct Definition
struct Ride {
    string riderName;
    int rideID = 1000001;
    string driverName;
    string pickupLocation;
    string dropoffLocation;
    double distance = 0.0;
    double fare = 0.0;
    string status; // "Ongoing", "Completed", "Cancelled"
};

// Global Variables
Ride rideDetails[MAX_RIDES];
int rideCount = 0; // Keeps track of total rides
string Drivers[MAX_DRIVERS];
int driverCount = 0; // Keeps track of total drivers
int nextRideID = START_RIDE_ID; // generating unique ride IDs

// =================  HELPER FUNCTIONS =================

bool DriverExists(string name) { 
    for (int i = 0; i < driverCount; i++) {
        if (Drivers[i] == name) {
            return true;
        }
    }
    return false;
}

bool isValidName(string name) {
    if (name.length() < 3 || name.length() > 30) {
        return false;
    }
    for (int i = 0; i< name.length(); i++) {
        char a = name[i];
        if (!isalpha(a) && a != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidLocation(string str) {
    if (str.empty()) return false;
    for (int i = 0; i < str.length(); i++) {
        char a = str[i];
        if (!isalpha(a) && a != ' ') {
            return false;
        }
    }
    return true;
}

// ================= Function Definitions =================

int IsAvailable(string driverName, Ride rides[]) {
    // TODO: Searches through the array 
    //       Checks if the given driverName has an Ongoing ride
    //       If the given driverName has an Ongoing ride returns 1, otherwise returns 0
    for (int i = 0; i< rideCount; i++) {
        if (rides[i].driverName == driverName && rides[i].status == "Ongoing") {
            return 1;
            }
        }
        return 0; 
    }

double GetFare(double distance) {
    //TODO: Calculate and return the fare based on the given scheme
    //      Distance < 2KM : 50 + (50 * distance)
    //      2KM < Distance < 5KM : 150 + (80 * (distance - 2)) 
    //      Distance > 5KM : 390 + (100 * (distance - 5))
    if (distance < 2) {
        return 50 + (50 * distance);
    } 
    else if (distance >= 2 && distance <= 5) {
        return 150 + (80 * (distance - 2));
    } 
    else {
        return 390 + (100 * (distance - 5));
    }
}

// Prompts user for ride details and returns a Ride struct
Ride BookRide(string name) {
    // TODO: Prompt user for pickup, drop-off, distance
    //       Displays all available drivers. Hint use the IsAvailable function and the Drivers array.
    //       Prompts the user to select a driver
    //       Calculates the fare by calling the GetFare function.
    //       Set ride status to "Ongoing" and generate Ride ID
    //       If there is no driver avaliable then output an error message, generate a Ride ID, set ride status to "Cancelled" and driverName to ""
    Ride newRide;
    newRide.riderName = name;
    cout << "Kindly enter pickup location: ";
    cin.ignore();
    getline(cin, newRide.pickupLocation);
    // validation check 1:  making sure that pickup location is valid
    while (!isValidLocation(newRide.pickupLocation)) {
        cout << "Invalid location. Kindly use only letters and spaces: ";
        getline(cin, newRide.pickupLocation);
    }
    cout << "Kindly enter dropoff location: ";
    getline(cin, newRide.dropoffLocation);
    // validation check 2:  making sure that dropoff location is valid
    while (!isValidLocation(newRide.dropoffLocation)) {
        cout << "Invalid location. Kindly use only letters and spaces: ";
        getline(cin, newRide.dropoffLocation);
    }
    // validation check 3:  making sure that piickup and dropoff location are not same
    while (newRide.pickupLocation == newRide.dropoffLocation) {
        cout << "Pickup and dropoff locations cannot be the same. Please enter a different dropoff location: ";
        getline(cin, newRide.dropoffLocation);
        while (!isValidLocation(newRide.dropoffLocation)) {
            cout << "Invalid location. Kindly use only letters and spaces: ";
            getline(cin, newRide.dropoffLocation);
        }
    }
    cout << "Kindly enter distance (in km): ";
    cin >> newRide.distance;
    // validation check 4:  making sure that distance is positive (dist > 0)
    while (newRide.distance <= 0) {
        cout << "Distance must be positive. Kindly enter again: ";
        cin >> newRide.distance;
    }
    newRide.fare = GetFare(newRide.distance);
    int availableDrivers = 0;
    int driverNum[MAX_DRIVERS];
    // made an array driver num to map the choice of the user back in drivers array
    cout << "\nAvailable Drivers:\n";
    for (int i = 0; i < driverCount; i++) {
        if (!IsAvailable(Drivers[i], rideDetails)) {
            cout << (availableDrivers + 1) << ". " << Drivers[i] << endl;
            driverNum[availableDrivers] = i;
            availableDrivers++;
        }
    }
    // validation check 5: case where there are no drivers available available 
    if (availableDrivers == 0) {
        newRide.rideID = nextRideID++;
        cout << "No drivers available so ride cancelled with ID " << newRide.rideID<<" .\n";
        newRide.driverName = "";
        newRide.status = "Cancelled";
        return newRide;
    }
    int choice;
    cout << "Select a driver (1-" << availableDrivers << "): ";
    cin >> choice;
    // validation check 6: driver choice is in range 
    while (choice < 1 || choice > availableDrivers) {
        cout << "Invalid selection. Please choose between 1 and " << availableDrivers << ": ";
        cin >> choice;
    }
    newRide.driverName = Drivers[driverNum[choice - 1]];
    newRide.rideID = nextRideID++;
    newRide.status = "Ongoing";
    cout << "Ride booked successfully! Your Ride ID is: " << newRide.rideID << endl;
    return newRide;
}

// Displays rides that match the given name (rider or driver)
void ViewRides(string name, Ride rides[], string status = "") {
    // TODO: Loop through the array and print rides where name matches riderName or driverName
    //       Displays all rides for that name regardless of status if status is ""
    //       Displays rides for that name and status if a status value was passed
    bool found = false;
    cout << "\n";
    cout << left << setw(10) << "Ride ID" << setw(15) << "Rider" << setw(15) << "Driver" 
         << setw(15) << "Pickup" << setw(15) << "Dropoff" << setw(10) << "Distance" 
         << setw(10) << "Fare" << setw(12) << "Status" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i<rideCount; i++) {
        if ((rides[i].riderName == name || rides[i].driverName == name) && 
            (status == "" || rides[i].status == status)) {
            cout << left << setw(10) << rides[i].rideID << setw(15) << rides[i].riderName 
                 << setw(15) << rides[i].driverName << setw(15) << rides[i].pickupLocation 
                 << setw(15) << rides[i].dropoffLocation << setw(10) << fixed << setprecision(2) << rides[i].distance 
                 << setw(10) << fixed << setprecision(2) << rides[i].fare << setw(12) << rides[i].status << endl;
            found = true;
        }
    }
    // validation check 7: msg displayed if there are no view rides available
    if (!found) {
        if (status == "") {
            cout << "No rides found for " << name << endl;
        } 
        else {
            cout << "No " << status << " rides found for " << name << endl;
        }
    }
    cout << endl;
}

// Displays ongoing rides for the user, prompts for Ride ID, and returns it
int ChangeStatus(string name, Ride rides[], int count) {
    // TODO: Show ongoing rides for the name. Hint: Call ViewRides and use the third parameter 
    //       Ask user to enter the Ride ID to update
    //       Return the Ride ID so status can be updated in main
    ViewRides(name, rides, "Ongoing");
    int rideID;
    cout << "Enter the Ride ID to update: ";
    cin >> rideID;
    // validation check 8: if the ride ID exists and belongs to the user
    bool valid = false;
    for (int i = 0; i < count; i++) {
        if (rides[i].rideID == rideID && 
            (rides[i].riderName == name || rides[i].driverName == name) &&
            rides[i].status == "Ongoing") {
            valid = true;
            break;
        }
    }
    if (!valid) {
        cout << "Invalid Ride ID\n";
        return -1; 
    }
    return rideID;
}

// Sums up the fare of all rides assigned to a driver
double CalculateTotal(string driverName, Ride rides[]) {
    // TODO: Add up fares of rides where driverName matches and status is "Completed"
    double total = 0.0;
    for (int i = 0; i < rideCount; i++) {
        if (rides[i].driverName == driverName && rides[i].status == "Completed") {
            total += rides[i].fare;
        }
    }
    return total;
}

// ================= Main Function =================
// TODO:
    // - Display main menu
    // - Ask the user if they are a Rider (1) or Driver (2)
    // - Prompt for name
    // - If the user is a Driver and the name is not in the Drivers list add it to the list
    // - Based on role, display the appropriate menu
    // - Use the provided functions to implement menu options
    // - Ensure ride count does not exceed MAX_RIDES
    // - Validate menu inputs

int main() {
    int role;
    string name;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "Welcome to the Ride Booking Simulation program!\n";
        cout << "Are you a Rider (1) or a Driver (2)? Kindly enter your role: ";
        cin >> role;
        //validation check 9: making sure that valid role num is input
        if (role != 1 && role != 2) {
            cout << "Invalid option! please try again.\n";
            continue;
        }
        // validation check 10 : considering names with spaces such as 'John Doe'
        cout << "Kindly enter your name: ";
        cin.ignore();
        getline(cin, name);
        // validation check 11: if the ride ID exists and belongs to the user
        while (!isValidName(name)) {
            cout << "Invalid name! Name must be letters & spaces & between 3 and 30 characters. \n";
            cout << "Please enter your name again: ";
            getline(cin, name);
        }
        if (role == 2 && !DriverExists(name)) {
            if (driverCount < MAX_DRIVERS) {
                Drivers[driverCount++] = name;
                cout << "New driver added to the system.\n";
            } 
            else {
                // validation check 12 : drivers list is full with 50 names
                cout << "Driver list is full so cannot add new drivers.\n";
            }
        }
        if (role == 1) {
            int riderChoice = 0;
            while (riderChoice != 5 && !exitProgram){
                cout << "\nWelcome " << name << ", Please select an option:\n";
                cout << "1. Book a ride\n";
                cout << "2. View my rides\n";
                cout << "3. View all rides\n";
                cout << "4. Cancel a ride\n";
                cout << "5. Return to main menu\n";
                cout << "0. Exit from main menu\n";
                cout << "Please enter your choice: ";
                cin >> riderChoice;
                switch (riderChoice) {
                    case 1: 
                        if (rideCount < MAX_RIDES) {
                            rideDetails[rideCount] = BookRide(name);
                            rideCount++;
                        } 
                        else { // validation check 13 : max rides aree 100 at capacity
                            cout << "Cannot book more rides as system is at full.\n";
                        }
                        break;
                    case 2: 
                        ViewRides(name, rideDetails, "Ongoing");
                        break;
                    case 3: 
                        ViewRides(name, rideDetails);
                        break;
                    case 4: 
                        if (rideCount > 0) {
                            int rideID = ChangeStatus(name, rideDetails, rideCount);
                            if (rideID != -1) {
                                for (int i = 0; i < rideCount; i++) {
                                    if (rideDetails[i].rideID == rideID) {
                                        rideDetails[i].status = "Cancelled";
                                        cout << "Ride " << rideID << " has been cancelled.\n";
                                        break;
                                    }
                                }
                            }
                        } else {
                            cout << "No rides to cancel.\n";
                        }
                        break;
                    case 5: 
                        cout << "Returned to main menu.\n";
                        break;
                    case 0: 
                        cout << "Thanks a lot for using the program !\n";
                        exitProgram = true;
                        break;
                    default:
                        cout << "Invalid option! Please try again.\n";
                }
            } 
        } else if (role == 2) {
            int driverChoice = 0;
            while (driverChoice != 5 && !exitProgram) {
                cout << "\nWelcome " << name << ", Please select an option:\n";
                cout << "1. View assigned rides\n";
                cout << "2. Mark ride as completed\n";
                cout << "3. View all rides\n";
                cout << "4. Calculate total fare\n";
                cout << "5. Return to main menu\n";
                cout << "0. Exit from main menu\n";
                cout << "Please enter your choice: ";
                cin >> driverChoice;
                switch (driverChoice) {
                    case 1:
                        ViewRides(name, rideDetails, "Ongoing");
                        break;
                    case 2:
                        if (rideCount > 0) {
                            int rideID = ChangeStatus(name, rideDetails, rideCount);
                            if (rideID != -1) {
                                for (int i = 0; i < rideCount; i++) {
                                    if (rideDetails[i].rideID == rideID) {
                                        rideDetails[i].status = "Completed";
                                        cout << "Ride " << rideID << " marked as completed.\n";
                                        break;
                                    }
                                }
                            }
                        } else {
                            cout << "No rides to update.\n";
                        }
                        break;
                    case 3: 
                        ViewRides(name, rideDetails);
                        break;
                    case 4: 
                        {
                            double total = CalculateTotal(name, rideDetails);
                            cout << "Total fare earned from completed rides: PKR " << fixed << setprecision(2) << total << endl;
                        }
                        break;
                    case 5: 
                        cout << "Returned to main menu.\n";
                        break;
                    case 0: 
                        cout << "Thanks a lot for using the program. \n";
                        exitProgram = true;
                        break;
                    default:
                        cout << "Invalid option! Kindly try again.\n";
                }
            } 
        }
    }
    return 0;
}