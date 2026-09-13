#include <iostream>
#include <vector>
using namespace std;


class Item {
protected:
    int id;
    string name;
    int quantity;

public:
    void setData(int i, string n, int q) {
        id = i;
        name = n;
        quantity = q;
    }

    int getId() {
        return id;
    }

    void updateQty(int q) {
        quantity = q;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
    }
};


class Product : public Item {
private:
    float price;

public:
    void setProduct(int i, string n, int q, float p) {
        setData(i, n, q);
        price = p;
    }

    void display() {
        cout << "\nProduct Details\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }
};


int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\n--- Inventory Management ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display All\n";
        cout << "3. Search Product\n";
        cout << "4. Update Quantity\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Product temp;
            int id, qty;
            string name;
            float price;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Price: ";
            cin >> price;

            temp.setProduct(id, name, qty, price);
            products.push_back(temp);

            cout << "Product added successfully\n";
        }

        else if (choice == 2) {
            if (products.size() == 0) {
                cout << "No products available\n";
            } else {
                for (int i = 0; i < products.size(); i++) {
                    products[i].display();
                }
            }
        }

        else if (choice == 3) {
            int id, found = 0;
            cout << "Enter ID to search: ";
            cin >> id;

            for (int i = 0; i < products.size(); i++) {
                if (products[i].getId() == id) {
                    products[i].display();
                    found = 1;
                }
            }

            if (found == 0) {
                cout << "Product not found\n";
            }
        }

        else if (choice == 4) {
            int id, qty, found = 0;
            cout << "Enter ID to update: ";
            cin >> id;

            for (int i = 0; i < products.size(); i++) {
                if (products[i].getId() == id) {
                    cout << "Enter new quantity: ";
                    cin >> qty;
                    products[i].updateQty(qty);
                    cout << "Quantity updated\n";
                    found = 1;
                }
            }

            if (found == 0) {
                cout << "Product not found\n";
            }
        }

    } while (choice != 5);

    cout << "Program ended\n";
    return 0;
}