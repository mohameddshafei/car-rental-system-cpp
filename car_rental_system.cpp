#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string brand;
    string model;
    double dailyPrice;
    bool isAvailable;

public:
    Vehicle() {
        vehicleID = 0;
        brand = "";
        model = "";
        dailyPrice = 0.0;
        isAvailable = true;
    }

    Vehicle(int id, string br, string mo, double price) {
        vehicleID = id;
        brand = br;
        model = mo;
        dailyPrice = price;
        isAvailable = true;
    }

    ~Vehicle() {}

    int getID() {
        return vehicleID;
    }

    string getModel() {
        return model;
    }

    bool available() {
        return isAvailable;
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    double getPrice() {
        return dailyPrice;
    }

    void updateDetails(string br, string mo, double price) {
        brand = br;
        model = mo;
        dailyPrice = price;
    }

    void display() {
        cout << "ID: " << vehicleID << ", Brand: " << brand << ", Model: " << model;
        cout << ", Price/Day: $" << dailyPrice << ", Available: ";
        if (isAvailable)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    bool compareModel(string mo) {
        if (model == mo) {
            return true;
        } else {
            return false;
        }
    }
};

class Customer {
private:
    int customerID;
    string name;
    string phone;

public:
    Customer() {
        customerID = 0;
        name = "";
        phone = "";
    }

    Customer(int id, string n, string p) {
        customerID = id;
        name = n;
        phone = p;
    }

    ~Customer() {}

    int getID() { return customerID; }

    void display() {
        cout << "Customer ID: " << customerID << ", Name: " << name << ", Phone: " << phone << endl;
    }
};

class RentalSystem {
private:
    Vehicle* vehicles;
    Customer* customers;
    int vehicleCount;
    int customerCount;
    int vehicleCapacity;
    int customerCapacity;

public:
    RentalSystem() {
        vehicleCapacity = 1000;
        customerCapacity = 1000;
        vehicles = new Vehicle[vehicleCapacity];
        customers = new Customer[customerCapacity];
        vehicleCount = 0;
        customerCount = 0;
    }

    ~RentalSystem() {
        delete[] vehicles;
        delete[] customers;
    }

    void addVehicle() {
        if (vehicleCount >= vehicleCapacity) {
            cout << "Vehicle limit reached." << endl;
            return;
        }

        string brand, model;
        double price;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Daily Price: ";
        cin >> price;

        vehicles[vehicleCount] = Vehicle(vehicleCount + 1, brand, model, price);
        vehicleCount++;
        cout << "Vehicle added successfully." << endl;
    }

    void updateVehicleDetails() {
        int id;
        cout << "Enter Vehicle ID to update: ";
        cin >> id;

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i].getID() == id) {
                string brand, model;
                double price;
                cout << "Enter new Brand: ";
                cin >> brand;
                cout << "Enter new Model: ";
                cin >> model;
                cout << "Enter new Daily Price: ";
                cin >> price;
                vehicles[i].updateDetails(brand, model, price);
                cout << "Vehicle details updated." << endl;
                return;
            }
        }
        cout << "Vehicle not found." << endl;
    }

    void searchVehicleByModel() {
        string model;
        cout << "Enter model to search: ";
        cin >> model;

        bool found = false;
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i].compareModel(model)) {
                vehicles[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "No vehicles found with that model." << endl;
    }

    void bookVehicle() {
        int id;
        cout << "Enter Vehicle ID to book: ";
        cin >> id;

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i].getID() == id && vehicles[i].available()) {
                vehicles[i].setAvailability(false);
                cout << "Vehicle booked successfully." << endl;
                return;
            }
        }

        cout << "Vehicle not available or not found." << endl;
    }

    void checkAvailability() {
        cout << "Available Vehicles:" << endl;
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i].available()) {
                vehicles[i].display();
            }
        }
    }

    void createCustomerAccount() {
        if (customerCount >= customerCapacity) {
            cout << "Customer limit reached." << endl;
            return;
        }

        string name, phone;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phone;

        customers[customerCount] = Customer(customerCount + 1, name, phone);
        customerCount++;
        cout << "Customer account created." << endl;
    }

    void generateInvoice() {
        int vehicleID, days;
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Number of Days: ";
        cin >> days;

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i].getID() == vehicleID) {
                double total = vehicles[i].getPrice() * days;
                cout << "Invoice Generated:" << endl;
                cout << "Vehicle Model: " << vehicles[i].getModel() << endl;
                cout << "Days: " << days << ", Total: $" << total << endl;
                return;
            }
        }

        cout << "Vehicle not found." << endl;
    }
};

int main() {
    RentalSystem system;
    int choice;

    while (true) {
        cout << endl << "Car Rental System" << endl;
        cout << "Please choose an option:" << endl;
        cout << "1. Add New Vehicle" << endl;
        cout << "2. Update Vehicle Details" << endl;
        cout << "3. Search Vehicle by Model" << endl;
        cout << "4. Book a Vehicle" << endl;
        cout << "5. Check Vehicle Availability" << endl;
        cout << "6. Create Customer Account" << endl;
        cout << "7. Generate Invoice" << endl;
        cout << "8. Exit Program" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (choice == 1) {
            system.addVehicle();
        }
        else if (choice == 2) {
            system.updateVehicleDetails();
        }
        else if (choice == 3) {
            system.searchVehicleByModel();
        }
        else if (choice == 4) {
            system.bookVehicle();
        }
        else if (choice == 5) {
            system.checkAvailability();
        }
        else if (choice == 6) {
            system.createCustomerAccount();
        }
        else if (choice == 7) {
            system.generateInvoice();
        }
        else if (choice == 8) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

}
