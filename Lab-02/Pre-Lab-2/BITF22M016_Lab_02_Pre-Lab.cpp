#include <iostream>
using namespace std;


class Pharmacy
{
private:
    int Id;
    string medName;
    string Manufacturer;
    string salesPerson;
    int buyPrice;
    int sellPrice;
    int Quantity;

public:
    Pharmacy() {}

    Pharmacy(int id, string name, string producer, string seller, int buy, int sell, int amount)
    {
        Id = id;
        medName = name;
        Manufacturer = producer;
        salesPerson = seller;
        buyPrice = buy;
        sellPrice = sell;
        Quantity = amount;
    }

    void setId(int id)
    {
        Id = id;
    }
    void setMedName(string name)
    {
        medName = name;
    }
    void setManufacturer(string producer)
    {
        Manufacturer = producer;
    }
    void setSalesPerson(string seller)
    {
        salesPerson = seller;
    }
    void setBuyPrice(int buy)
    {
        buyPrice = buy;
    }
    void setSellPrice(int sell)
    {
        sellPrice = sell;
    }
    void setQuantity(int amount)
    {
        Quantity = amount;
    }

    void displayAllData()
    {
        cout << "ID: #" << Id << endl;
        cout << "Medicine Name: " << medName << endl;
        cout << "Manufacturer: " << Manufacturer << endl;
        cout << "Sales Person: " << salesPerson << endl;
        cout << "Buying Price: Rs." << buyPrice << endl;
        cout << "Selling Price: Rs." << sellPrice << endl;
        cout << "Quantity: " << Quantity << endl;
    }
};

void addData(Pharmacy *pharmacyArray, int numPharmacies)
{
    int id, buy, sell, amount;
    string name, producer, seller;

    cout << "\nEnter details for the new medicine:\n";
    cout << "ID: #";
    cin >> id;
    cin.ignore();
    cout << "Medicine Name: ";
    getline(cin, name);
    cout << "Manufacturer: ";
    getline(cin, producer);
    cout << "Sales Person: ";
    getline(cin, seller);
    cout << "Buying Price: Rs.";
    cin >> buy;
    cout << "Selling Price: Rs.";
    cin >> sell;
    cout << "Quantity: ";
    cin >> amount;

    pharmacyArray[numPharmacies] = Pharmacy(id, name, producer, seller, buy, sell, amount);
    cout << "Medicine data added successfully!\n";
}

void updateData(Pharmacy *pharmacyArray, int numPharmacies)
{
    int pharmacyIndex;
    cout << "Enter the medicine index to update (1 to " << numPharmacies << "): ";
    cin >> pharmacyIndex;

    if (pharmacyIndex >= 1 && pharmacyIndex <= numPharmacies)
    {
        int id, buy, sell, amount;
        string name, producer, seller;

        cout << "\nEnter new details for Medicine " << pharmacyIndex << ":\n";
        cout << "ID: #";
        cin >> id;
        cin.ignore();
        cout << "Medicine Name: ";
        getline(cin, name);
        cout << "Manufacturer: ";
        getline(cin, producer);
        cout << "Sales Person: ";
        getline(cin, seller);
        cout << "Buying Price: Rs.";
        cin >> buy;
        cout << "Selling Price: Rs.";
        cin >> sell;
        cout << "Quantity: ";
        cin >> amount;

        pharmacyArray[pharmacyIndex - 1] = Pharmacy(id, name, producer, seller, buy, sell, amount);
        cout << "Pharmacy data updated successfully!\n";
    }
    else
    {
        cout << "Invalid pharmacy index!\n";
    }
}

int main()
{
    int numPharmacies;
    cout << "Enter the number of pharmacies: ";
    cin >> numPharmacies;

    Pharmacy *pharmacyArray = new Pharmacy[numPharmacies];

    for (int i = 0; i < numPharmacies; ++i)
    {
        int id, buy, sell, amount;
        string name, producer, seller;

        cout << "\nEnter details for Pharmacy " << i + 1 << ":\n";
        cout << "ID: #";
        cin >> id;
        cin.ignore();
        cout << "Medicine Name: ";
        getline(cin, name);
        cout << "Manufacturer: ";
        getline(cin, producer);
        cout << "Sales Person: ";
        getline(cin, seller);
        cout << "Buying Price: Rs.";
        cin >> buy;
        cout << "Selling Price: Rs.";
        cin >> sell;
        cout << "Quantity: ";
        cin >> amount;

        pharmacyArray[i] = Pharmacy(id, name, producer, seller, buy, sell, amount);
    }

    int choice;
    do
    {
        cout << "\nOptions:\n";
        cout << "1. Display all pharmacy data\n";
        cout << "2. Add new pharmacy data\n";
        cout << "3. Update pharmacy data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < numPharmacies; ++i)
            {
                cout << "\nDetails for Pharmacy " << i + 1 << ":\n";
                pharmacyArray[i].displayAllData();
            }
            break;

        case 2:
            addData(pharmacyArray, numPharmacies);
            numPharmacies++;
            break;

        case 3:
            updateData(pharmacyArray, numPharmacies);
            break;

        case 4:
            cout << "You chose exit.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    delete[] pharmacyArray;

    return 0;
}
