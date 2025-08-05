#include <iostream>
#include <map>
#include <ctime>
using namespace std;

struct Vehicle {
    string number;
    time_t entryTime;
};

class Parking {
    map<string, time_t> parkedVehicles;

public:
    void enterVehicle() {
        string num;
        cout << "Enter vehicle number: ";
        cin >> num;
        parkedVehicles[num] = time(0);
        cout << "Vehicle entered.\n";
    }

    void exitVehicle() {
        string num;
        cout << "Enter vehicle number: ";
        cin >> num;
        if (parkedVehicles.count(num)) {
            time_t now = time(0);
            double hours = difftime(now, parkedVehicles[num]) / 3600;
            double charge = hours * 10; // ₹10 per hour
            cout << "Vehicle exited. Time: " << hours << " hrs. Charge: ₹" << charge << "\n";
            parkedVehicles.erase(num);
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    void viewParked() {
        for (auto& v : parkedVehicles)
            cout << v.first << " - Parked since " << ctime(&v.second);
    }
};

int main() {
    Parking p;
    int choice;
    do {
        cout << "\n1. Enter Vehicle\n2. Exit Vehicle\n3. View Parked\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) p.enterVehicle();
        else if (choice == 2) p.exitVehicle();
        else if (choice == 3) p.viewParked();
    } while (choice != 4);
}
