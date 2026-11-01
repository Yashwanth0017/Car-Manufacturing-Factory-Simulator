#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==================== CAR CLASSES ====================

class Car {
private:
    int id;
    string model, type, status, colour;

public:
    Car(int i, string m, string t) {
        id = i;
        model = m;
        type = t;
        status = "Created";
        colour = "Not Painted";
    }

    int getId() { return id; }
    string getType() { return type; }
    string getStatus() { return status; }

    void setStatus(string s) {
        status = s;
    }

    void paintCar(string c) {
        colour = c;
        status = "Painted";
    }

    void qualityCheck(bool passed) {
        if (passed)
            status = "Quality Checked";
        else
            status = "Rejected";
    }

    void finishCar() {
        if (status == "Quality Checked")
            status = "Finished";
    }

    void display() {
        cout << "\nCar ID: " << id;
        cout << "\nModel: " << model;
        cout << "\nType: " << type;
        cout << "\nProduction Status: " << status;
        cout << "\nColour: " << colour << "\n";
    }

    virtual void showFeatures() {
        cout << "General car features\n";
    }

    virtual ~Car() {}
};

class NormalCar : public Car {
public:
    NormalCar(int id, string model)
        : Car(id, model, "Normal Car") {}

    void showFeatures() override {
        cout << "Normal Car: Standard engine and battery\n";
    }
};

class SportsCar : public Car {
public:
    SportsCar(int id, string model)
        : Car(id, model, "Sports Car") {}

    void showFeatures() override {
        cout << "Sports Car: Sports engine and sporty body design\n";
    }
};

class ElectricCar : public Car {
public:
    ElectricCar(int id, string model)
        : Car(id, model, "Electric Car") {}

    void showFeatures() override {
        cout << "Electric Car: Electric motor and electric battery\n";
    }
};

// ==================== INVENTORY CLASS ====================

class Inventory {
private:
    int normalEngines, sportsEngines, electricMotors;
    int batteries, electricBatteries;
    int tyres, doors, lights, seats, windows;
    int steeringWheels, bumpers, mirrors;
    int chassis, bodyPanels, bonnets, roofs;
    int sportsChassis, sportsBodyPanels, sportsBonnets, sportsRoofs;

public:
    Inventory() {
        normalEngines = 5;
        sportsEngines = 3;
        electricMotors = 5;
        batteries = 10;
        electricBatteries = 5;
        tyres = 40;
        doors = 30;
        lights = 40;
        seats = 40;
        windows = 40;
        steeringWheels = 10;
        bumpers = 20;
        mirrors = 20;
        chassis = 10;
        bodyPanels = 40;
        bonnets = 10;
        roofs = 10;
        sportsChassis = 5;
        sportsBodyPanels = 20;
        sportsBonnets = 5;
        sportsRoofs = 5;
    }

    void displayInventory() {
        cout << "\n===== FACTORY INVENTORY =====\n";
        cout << "Normal Engines: " << normalEngines << "\n";
        cout << "Sports Engines: " << sportsEngines << "\n";
        cout << "Electric Motors: " << electricMotors << "\n";
        cout << "Standard Batteries: " << batteries << "\n";
        cout << "Electric Batteries: " << electricBatteries << "\n";
        cout << "Tyres: " << tyres << "\n";
        cout << "Doors: " << doors << "\n";
        cout << "Lights: " << lights << "\n";
        cout << "Seats: " << seats << "\n";
        cout << "Windows: " << windows << "\n";
        cout << "Steering Wheels: " << steeringWheels << "\n";
        cout << "Bumpers: " << bumpers << "\n";
        cout << "Mirrors: " << mirrors << "\n";
        cout << "Standard Chassis: " << chassis << "\n";
        cout << "Standard Body Panels: " << bodyPanels << "\n";
        cout << "Standard Bonnets: " << bonnets << "\n";
        cout << "Standard Roofs: " << roofs << "\n";
        cout << "Sports Chassis: " << sportsChassis << "\n";
        cout << "Sports Body Panels: " << sportsBodyPanels << "\n";
        cout << "Sports Bonnets: " << sportsBonnets << "\n";
        cout << "Sports Roofs: " << sportsRoofs << "\n";
    }

    void addStock() {
        int choice, quantity;

        cout << "\n===== ADD STOCK =====\n";
        cout << "1. Normal Engine\n";
        cout << "2. Sports Engine\n";
        cout << "3. Electric Motor\n";
        cout << "4. Standard Battery\n";
        cout << "5. Electric Battery\n";
        cout << "6. Tyres\n";
        cout << "7. Doors\n";
        cout << "8. Lights\n";
        cout << "9. Seats\n";
        cout << "10. Windows\n";
        cout << "11. Steering Wheels\n";
        cout << "12. Bumpers\n";
        cout << "13. Mirrors\n";
        cout << "14. Standard Chassis\n";
        cout << "15. Standard Body Panels\n";
        cout << "16. Standard Bonnets\n";
        cout << "17. Standard Roofs\n";
        cout << "18. Sports Chassis\n";
        cout << "19. Sports Body Panels\n";
        cout << "20. Sports Bonnets\n";
        cout << "21. Sports Roofs\n";
        cout << "Select part: ";
        cin >> choice;

        if (choice < 1 || choice > 21) {
            cout << "Invalid part selection!\n";
            return;
        }

        cout << "Enter quantity to add: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity!\n";
            return;
        }

        switch (choice) {
            case 1: normalEngines += quantity; break;
            case 2: sportsEngines += quantity; break;
            case 3: electricMotors += quantity; break;
            case 4: batteries += quantity; break;
            case 5: electricBatteries += quantity; break;
            case 6: tyres += quantity; break;
            case 7: doors += quantity; break;
            case 8: lights += quantity; break;
            case 9: seats += quantity; break;
            case 10: windows += quantity; break;
            case 11: steeringWheels += quantity; break;
            case 12: bumpers += quantity; break;
            case 13: mirrors += quantity; break;
            case 14: chassis += quantity; break;
            case 15: bodyPanels += quantity; break;
            case 16: bonnets += quantity; break;
            case 17: roofs += quantity; break;
            case 18: sportsChassis += quantity; break;
            case 19: sportsBodyPanels += quantity; break;
            case 20: sportsBonnets += quantity; break;
            case 21: sportsRoofs += quantity; break;
        }

        cout << "Stock updated successfully!\n";
    }

    void displayLowStock() {
        const int threshold = 5;
        bool lowStockFound = false;

        cout << "\n===== LOW STOCK ALERTS =====\n";
        cout << "Low-stock threshold: fewer than "
             << threshold << " units\n\n";

#define CHECK_STOCK(item, label) \
        if (item < threshold) { \
            cout << "LOW STOCK: " << label << " (" << item << ")\n"; \
            lowStockFound = true; \
        }

        CHECK_STOCK(normalEngines, "Normal Engines")
        CHECK_STOCK(sportsEngines, "Sports Engines")
        CHECK_STOCK(electricMotors, "Electric Motors")
        CHECK_STOCK(batteries, "Standard Batteries")
        CHECK_STOCK(electricBatteries, "Electric Batteries")
        CHECK_STOCK(tyres, "Tyres")
        CHECK_STOCK(doors, "Doors")
        CHECK_STOCK(lights, "Lights")
        CHECK_STOCK(seats, "Seats")
        CHECK_STOCK(windows, "Windows")
        CHECK_STOCK(steeringWheels, "Steering Wheels")
        CHECK_STOCK(bumpers, "Bumpers")
        CHECK_STOCK(mirrors, "Mirrors")
        CHECK_STOCK(chassis, "Standard Chassis")
        CHECK_STOCK(bodyPanels, "Standard Body Panels")
        CHECK_STOCK(bonnets, "Standard Bonnets")
        CHECK_STOCK(roofs, "Standard Roofs")
        CHECK_STOCK(sportsChassis, "Sports Chassis")
        CHECK_STOCK(sportsBodyPanels, "Sports Body Panels")
        CHECK_STOCK(sportsBonnets, "Sports Bonnets")
        CHECK_STOCK(sportsRoofs, "Sports Roofs")

#undef CHECK_STOCK

        if (!lowStockFound)
            cout << "All inventory items have sufficient stock.\n";
        else
            cout << "\nPlease use Add Stock to replenish these items.\n";
    }

    bool assembleCar(string type) {
        int requiredDoors = 0;
        int requiredWindows = 0;
        int requiredSeats = 0;

        if (type == "Normal Car") {
            requiredDoors = 4;
            requiredWindows = 6;
            requiredSeats = 5;

            if (normalEngines < 1 || batteries < 1) {
                cout << "Not enough engine or battery stock!\n";
                return false;
            }
        }
        else if (type == "Sports Car") {
            requiredDoors = 2;
            requiredWindows = 4;
            requiredSeats = 2;

            if (sportsEngines < 1 || batteries < 1) {
                cout << "Not enough engine or battery stock!\n";
                return false;
            }

            if (sportsChassis < 1 || sportsBodyPanels < 1 ||
                sportsBonnets < 1 || sportsRoofs < 1) {
                cout << "Not enough sports body parts!\n";
                return false;
            }
        }
        else if (type == "Electric Car") {
            requiredDoors = 4;
            requiredWindows = 6;
            requiredSeats = 5;

            if (electricMotors < 1 || electricBatteries < 1) {
                cout << "Not enough motor or battery stock!\n";
                return false;
            }
        }
        else {
            cout << "Invalid car type!\n";
            return false;
        }

        if (tyres < 4 || doors < requiredDoors || lights < 4 ||
            seats < requiredSeats || windows < requiredWindows ||
            steeringWheels < 1 || bumpers < 2 || mirrors < 2) {
            cout << "Not enough common parts!\n";
            return false;
        }

        if (type != "Sports Car" &&
            (chassis < 1 || bodyPanels < 1 || bonnets < 1 || roofs < 1)) {
            cout << "Not enough standard body parts!\n";
            return false;
        }

        if (type == "Normal Car") {
            normalEngines--;
            batteries--;
        }
        else if (type == "Sports Car") {
            sportsEngines--;
            batteries--;
            sportsChassis--;
            sportsBodyPanels--;
            sportsBonnets--;
            sportsRoofs--;
        }
        else {
            electricMotors--;
            electricBatteries--;
        }

        tyres -= 4;
        doors -= requiredDoors;
        lights -= 4;
        seats -= requiredSeats;
        windows -= requiredWindows;
        steeringWheels--;
        bumpers -= 2;
        mirrors -= 2;

        if (type != "Sports Car") {
            chassis--;
            bodyPanels--;
            bonnets--;
            roofs--;
        }

        cout << "Car assembled successfully!\n";
        return true;
    }
};

// ==================== DASHBOARD AND REPORTS ====================

void showProductionDashboard(vector<Car>& cars) {
    int normalCount = 0, sportsCount = 0, electricCount = 0;
    int createdCount = 0, assembledCount = 0, paintedCount = 0;
    int qualityCheckedCount = 0, finishedCount = 0, rejectedCount = 0;

    for (Car &c : cars) {
        if (c.getType() == "Normal Car") normalCount++;
        else if (c.getType() == "Sports Car") sportsCount++;
        else if (c.getType() == "Electric Car") electricCount++;

        if (c.getStatus() == "Created") createdCount++;
        else if (c.getStatus() == "Assembled") assembledCount++;
        else if (c.getStatus() == "Painted") paintedCount++;
        else if (c.getStatus() == "Quality Checked") qualityCheckedCount++;
        else if (c.getStatus() == "Finished") finishedCount++;
        else if (c.getStatus() == "Rejected") rejectedCount++;
    }

    cout << "\n===== PRODUCTION DASHBOARD =====\n";
    cout << "Total Cars Created: " << cars.size() << "\n";
    cout << "\n--- Cars by Type ---\n";
    cout << "Normal Cars: " << normalCount << "\n";
    cout << "Sports Cars: " << sportsCount << "\n";
    cout << "Electric Cars: " << electricCount << "\n";
    cout << "\n--- Current Production Status ---\n";
    cout << "Created: " << createdCount << "\n";
    cout << "Assembled: " << assembledCount << "\n";
    cout << "Painted: " << paintedCount << "\n";
    cout << "Quality Checked: " << qualityCheckedCount << "\n";
    cout << "Finished: " << finishedCount << "\n";
    cout << "Rejected: " << rejectedCount << "\n";
}

void manageProductionTarget(vector<Car>& cars, int& productionTarget) {
    int targetChoice;

    cout << "\n===== PRODUCTION TARGET MANAGEMENT =====\n";
    cout << "Current production target: "
         << productionTarget << " cars\n";
    cout << "1. Set new target\n";
    cout << "2. View target progress\n";
    cout << "Choose option: ";
    cin >> targetChoice;

    if (targetChoice == 1) {
        int newTarget;
        cout << "Enter new production target: ";
        cin >> newTarget;

        if (newTarget > 0) {
            productionTarget = newTarget;
            cout << "Production target updated successfully!\n";
        }
        else {
            cout << "Target must be greater than zero.\n";
        }
    }
    else if (targetChoice == 2) {
        int finished = 0;

        for (Car &c : cars) {
            if (c.getStatus() == "Finished")
                finished++;
        }

        cout << "Finished cars: " << finished << "\n";
        cout << "Production target: " << productionTarget << "\n";

        double progress = (finished * 100.0) / productionTarget;
        cout << "Target progress: " << progress << "%\n";

        if (finished >= productionTarget)
            cout << "Production target achieved!\n";
        else
            cout << "Cars remaining to reach target: "
                 << productionTarget - finished << "\n";
    }
    else {
        cout << "Invalid option!\n";
    }
}

void showFinishedCarRevenueReport(vector<Car>& cars) {
    int normalFinished = 0, sportsFinished = 0, electricFinished = 0;

    for (Car &c : cars) {
        if (c.getStatus() == "Finished") {
            if (c.getType() == "Normal Car") normalFinished++;
            else if (c.getType() == "Sports Car") sportsFinished++;
            else if (c.getType() == "Electric Car") electricFinished++;
        }
    }

    const long long normalPrice = 1500000;
    const long long sportsPrice = 3500000;
    const long long electricPrice = 2000000;

    long long totalRevenue =
        normalFinished * normalPrice +
        sportsFinished * sportsPrice +
        electricFinished * electricPrice;

    cout << "\n===== FINISHED CAR REVENUE REPORT =====\n";
    cout << "Normal Cars Finished: " << normalFinished
         << " | Sample unit price: Rs. " << normalPrice << "\n";
    cout << "Sports Cars Finished: " << sportsFinished
         << " | Sample unit price: Rs. " << sportsPrice << "\n";
    cout << "Electric Cars Finished: " << electricFinished
         << " | Sample unit price: Rs. " << electricPrice << "\n";
    cout << "Total Finished Cars: "
         << normalFinished + sportsFinished + electricFinished << "\n";
    cout << "Estimated Revenue: Rs. " << totalRevenue << "\n";
    cout << "Note: Prices are sample values for this simulation.\n";
}

// ==================== MAIN PROGRAM ====================

int main() {
    vector<Car> cars;
    int choice, nextId = 1;
    Inventory inv;
    int productionTarget = 20;

    do {
        cout << "\n===== FACTORY PRODUCTION AND MANAGEMENT =====\n";
        cout << "1. Create Car\n";
        cout << "2. View All Cars\n";
        cout << "3. View Inventory\n";
        cout << "4. Add Stock\n";
        cout << "5. Manufacture Car\n";
        cout << "6. Paint Car\n";
        cout << "7. Quality Check\n";
        cout << "8. Finish Car\n";
        cout << "9. Production Dashboard\n";
        cout << "10. Low Stock Alerts\n";
        cout << "11. View Car Features (Polymorphism)\n";
        cout << "12. Production Target Management\n";
        cout << "13. Finished Car Revenue Report\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string model, type;
            int t;

            cout << "Enter car model: ";
            getline(cin >> ws, model);

            cout << "1. Normal Car\n";
            cout << "2. Sports Car\n";
            cout << "3. Electric Car\n";
            cout << "Select type: ";
            cin >> t;

            if (t == 1)
                type = "Normal Car";
            else if (t == 2)
                type = "Sports Car";
            else if (t == 3)
                type = "Electric Car";
            else {
                cout << "Invalid car type!\n";
                continue;
            }

            cars.emplace_back(nextId, model, type);
            cout << "Car created successfully! ID: " << nextId << "\n";
            nextId++;
        }
        else if (choice == 2) {
            if (cars.empty())
                cout << "No cars created yet.\n";
            else {
                for (Car &c : cars)
                    c.display();
            }
        }
        else if (choice == 3) {
            inv.displayInventory();
        }
        else if (choice == 4) {
            inv.addStock();
        }
        else if (choice == 5) {
            if (cars.empty()) {
                cout << "Create a car first!\n";
                continue;
            }

            for (Car &c : cars)
                c.display();

            int id;
            cout << "Enter Car ID to manufacture: ";
            cin >> id;

            bool found = false;

            for (Car &c : cars) {
                if (c.getId() == id) {
                    found = true;

                    if (c.getStatus() != "Created") {
                        cout << "This car has already been manufactured!\n";
                    }
                    else if (inv.assembleCar(c.getType())) {
                        c.setStatus("Assembled");
                    }

                    break;
                }
            }

            if (!found)
                cout << "Car ID not found!\n";
        }
        else if (choice == 6) {
            if (cars.empty()) {
                cout << "Create a car first!\n";
                continue;
            }

            for (Car &c : cars)
                c.display();

            int id;
            cout << "Enter Car ID to paint: ";
            cin >> id;

            bool found = false;

            for (Car &c : cars) {
                if (c.getId() == id) {
                    found = true;

                    if (c.getStatus() != "Assembled") {
                        cout << "Only assembled cars can be painted!\n";
                    }
                    else {
                        int colourChoice;
                        string colour;

                        cout << "1. Red\n";
                        cout << "2. Blue\n";
                        cout << "3. Black\n";
                        cout << "4. White\n";
                        cout << "5. Silver\n";
                        cout << "Select colour: ";
                        cin >> colourChoice;

                        switch (colourChoice) {
                            case 1: colour = "Red"; break;
                            case 2: colour = "Blue"; break;
                            case 3: colour = "Black"; break;
                            case 4: colour = "White"; break;
                            case 5: colour = "Silver"; break;
                            default:
                                cout << "Invalid colour selection!\n";
                                break;
                        }

                        if (colourChoice >= 1 && colourChoice <= 5) {
                            c.paintCar(colour);
                            cout << "Car painted successfully in "
                                 << colour << "!\n";
                        }
                    }

                    break;
                }
            }

            if (!found)
                cout << "Car ID not found!\n";
        }
        else if (choice == 7) {
            if (cars.empty()) {
                cout << "Create a car first!\n";
                continue;
            }

            for (Car &c : cars)
                c.display();

            int id;
            cout << "Enter Car ID for quality check: ";
            cin >> id;

            bool found = false;

            for (Car &c : cars) {
                if (c.getId() == id) {
                    found = true;

                    if (c.getStatus() != "Painted") {
                        cout << "Only painted cars can undergo quality inspection!\n";
                    }
                    else {
                        int result;

                        cout << "1. Pass Inspection\n";
                        cout << "2. Fail Inspection\n";
                        cout << "Select result: ";
                        cin >> result;

                        if (result == 1) {
                            c.qualityCheck(true);
                            cout << "Quality inspection passed!\n";
                        }
                        else if (result == 2) {
                            c.qualityCheck(false);
                            cout << "Quality inspection failed. Car rejected!\n";
                        }
                        else {
                            cout << "Invalid inspection result!\n";
                        }
                    }

                    break;
                }
            }

            if (!found)
                cout << "Car ID not found!\n";
        }
        else if (choice == 8) {
            if (cars.empty()) {
                cout << "Create a car first!\n";
                continue;
            }

            for (Car &c : cars)
                c.display();

            int id;
            cout << "Enter Car ID to finish: ";
            cin >> id;

            bool found = false;

            for (Car &c : cars) {
                if (c.getId() == id) {
                    found = true;

                    if (c.getStatus() == "Quality Checked") {
                        c.finishCar();
                        cout << "Car production completed successfully!\n";
                    }
                    else {
                        cout << "Car must pass quality inspection first!\n";
                    }

                    break;
                }
            }

            if (!found)
                cout << "Car ID not found!\n";
        }
        else if (choice == 9) {
            showProductionDashboard(cars);
        }
        else if (choice == 10) {
            inv.displayLowStock();
        }
        else if (choice == 11) {
            int typeChoice;

            cout << "\n===== VIEW CAR FEATURES =====\n";
            cout << "1. Normal Car\n";
            cout << "2. Sports Car\n";
            cout << "3. Electric Car\n";
            cout << "Select car type: ";
            cin >> typeChoice;

            if (typeChoice == 1) {
                NormalCar demo(0, "Feature Preview");
                Car &selectedCar = demo;
                selectedCar.showFeatures();
            }
            else if (typeChoice == 2) {
                SportsCar demo(0, "Feature Preview");
                Car &selectedCar = demo;
                selectedCar.showFeatures();
            }
            else if (typeChoice == 3) {
                ElectricCar demo(0, "Feature Preview");
                Car &selectedCar = demo;
                selectedCar.showFeatures();
            }
            else {
                cout << "Invalid car type!\n";
            }
        }
        else if (choice == 12) {
            manageProductionTarget(cars, productionTarget);
        }
        else if (choice == 13) {
            showFinishedCarRevenueReport(cars);
        }
        else if (choice == 14) {
            cout << "Exiting factory simulator...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 14);

    return 0;
}