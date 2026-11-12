
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class 1: Farmer
class Farmer
{
public:
    string name, village;

    void registerFarmer()
    {
        cout << "Enter farmer name: ";
        getline(cin, name);

        cout << "Enter village: ";
        getline(cin, village);

        ofstream file("farmer.txt");
        file << name << endl << village;
        file.close();

        cout << "Farmer registered successfully!\n";
    }

    void displayFarmer()
    {
        cout << "\nFarmer Name: " << name;
        cout << "\nVillage: " << village << endl;
    }
};

// Class 2: Crop
class Crop
{
public:
    string cropName, season;
    float area, yield;

    void addCrop()
    {
        cout << "Enter crop name: ";
        getline(cin, cropName);

        cout << "Enter season: ";
        getline(cin, season);

        cout << "Enter area in acres: ";
        cin >> area;

        cout << "Enter expected yield: ";
        cin >> yield;
        cin.ignore();

        ofstream file("crop.txt", ios::app);
        file << cropName << " " << season << " "
             << area << " " << yield << endl;
        file.close();

        cout << "Crop added successfully!\n";
    }

    void displayCrop()
    {
        cout << "\nCrop: " << cropName;
        cout << "\nSeason: " << season;
        cout << "\nArea: " << area << " acres";
        cout << "\nExpected Yield: " << yield << " quintals\n";
    }
};

// Class 3: Inheritance
class CerealCrop : public Crop
{
public:
    void displayType()
    {
        cout << "Crop Type: Cereal Crop\n";
        displayCrop();
    }
};

// Class 4: Field Management
class Field
{
public:
    string soilType;
    float area;

    void addField()
    {
        cout << "Enter soil type: ";
        getline(cin, soilType);

        cout << "Enter field area: ";
        cin >> area;
        cin.ignore();

        ofstream file("field.txt", ios::app);
        file << soilType << " " << area << endl;
        file.close();

        cout << "Field details saved!\n";
    }

    void displayField()
    {
        cout << "\nSoil Type: " << soilType;
        cout << "\nField Area: " << area << " acres\n";
    }
};

// Class 5: Unique Feature
class Irrigation
{
public:
    void checkWater()
    {
        float moisture, rainfall;

        cout << "Enter soil moisture (0-100): ";
        cin >> moisture;

        cout << "Enter expected rainfall (mm): ";
        cin >> rainfall;

        if (moisture < 0 || moisture > 100 || rainfall < 0)
        {
            cout << "Invalid input!\n";
        }
        else if (moisture < 30 && rainfall < 5)
        {
            cout << "Irrigation is recommended!\n";
        }
        else if (moisture < 30)
        {
            cout << "Check rainfall before irrigation.\n";
        }
        else if (moisture <= 60)
        {
            cout << "Soil moisture is moderate. Monitor the field.\n";
        }
        else
        {
            cout << "Sufficient moisture. Avoid extra watering.\n";
        }

        cin.ignore();
    }
};

// Class 6: Expense Management
class Expense
{
public:
    float total = 0;

    // Function overloading
    void addExpense(float amount)
    {
        total = total + amount;
    }

    void addExpense(float amount, string category)
    {
        total = total + amount;

        ofstream file("expense.txt", ios::app);
        file << category << ": Rs. " << amount << endl;
        file.close();
    }

    void enterExpense()
    {
        float amount;
        string category;

        cout << "Enter expense category: ";
        getline(cin, category);

        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore();

        if (amount > 0)
        {
            addExpense(amount, category);
            cout << "Expense added successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void showExpense()
    {
        cout << "Total Expenses: Rs. " << total << endl;
    }
};

// Class 7: Harvest Management
class Harvest
{
public:
    string crop;
    float quantity;

    void addHarvest()
    {
        cout << "Enter crop name: ";
        getline(cin, crop);

        cout << "Enter harvest quantity: ";
        cin >> quantity;
        cin.ignore();

        if (quantity > 0)
        {
            ofstream file("harvest.txt", ios::app);
            file << crop << " " << quantity << endl;
            file.close();

            cout << "Harvest details saved!\n";
        }
        else
        {
            cout << "Invalid quantity!\n";
        }
    }

    void showHarvest()
    {
        cout << "Crop: " << crop;
        cout << "\nQuantity: " << quantity << " quintals\n";
    }
};

// Main Function
int main()
{
    Farmer f;
    Crop c;
    CerealCrop cc;
    Field field;
    Irrigation irrigation;
    Expense expense;
    Harvest harvest;

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "          SMART KISAN\n";
        cout << "    FARM MANAGEMENT SYSTEM\n";
        cout << "================================\n";

        cout << "1. Farmer Registration\n";
        cout << "2. Add Crop Details\n";
        cout << "3. View Crop Details\n";
        cout << "4. Add Field Details\n";
        cout << "5. View Field Details\n";
        cout << "6. Smart Irrigation Advisor\n";
        cout << "7. Add Farming Expenses\n";
        cout << "8. View Total Expenses\n";
        cout << "9. Add Harvest Details\n";
        cout << "10. View Harvest Details\n";
        cout << "11. View Farmer Details\n";
        cout << "12. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            f.registerFarmer();
            break;

        case 2:
            c.addCrop();
            break;

        case 3:
            c.displayCrop();
            break;

        case 4:
            field.addField();
            break;

        case 5:
            field.displayField();
            break;

        case 6:
            irrigation.checkWater();
            break;

        case 7:
            expense.enterExpense();
            break;

        case 8:
            expense.showExpense();
            break;

        case 9:
            harvest.addHarvest();
            break;

        case 10:
            harvest.showHarvest();
            break;

        case 11:
            f.displayFarmer();
            break;

        case 12:
            cout << "\nThank you for using Smart Kisan!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 12);

    return 0;
}