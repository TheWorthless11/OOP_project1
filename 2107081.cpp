#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;

class Product {
private:
    char productName[20];
    float productPrice;
    int quantity;

    friend void showProductList(const Product productItems[], int numProducts);

public:
    void get();
    void show() const;
    int stchk(char nm[30]);
    void withd(int qty);
    void stockUp(int qty);
};

class Supplier {
public:
    static void addProduct(Product productItems[], int& numProducts);
    static void stockUp(Product productItems[], int numProducts);
    static void removeProduct(Product productItems[], int& numProducts);
};

class Buyer {
public:
    static void purchaseProduct(Product productItems[], int numProducts);
};

class Staff {
public:
    static void stockUp(Product productItems[], int numProducts);
};

const int MAX_PRODUCTS = 100;
Product productItems[MAX_PRODUCTS];
int numProducts = 0;

void Product::withd(int qty) {
    if (quantity >= qty) {
        quantity -= qty;
        cout << "\n\nStock updated.\n";
        cout << "\n\nTotal price to be paid: " << productPrice * qty;
        cout << "\n";
    } else {
        cout << "\n\nInsufficient stock";
        cout << "\n";
    }
    getch();
}

void Product::stockUp(int qty) {
    quantity += qty;
    cout << "\n\nStock updated.";
    cout << "\n";
    getch();
}

int Product::stchk(char nm[30]) {
    if (strcmp(nm, productName) == 0)
        return 0;
    else
        return 1;
}

void Product::get() {
    cin >> productName >> productPrice >> quantity;
}

void Product::show() const {
    cout << "\n" << productName << "\t\t\t" << quantity << "\t\t\t" << productPrice;
        cout << "\n";
}

void Supplier::addProduct(Product productItems[], int& numProducts) {
    cout << "\nEnter the No. of Products that you wish to add: ";
    int n;
    cin >> n;

    if (numProducts + n <= MAX_PRODUCTS) {
        for (int i = 0; i < n; i++) {
            cout << "\n\nInput the name, price and the quantity of item respectively\n\n";
            productItems[numProducts].get();
            numProducts++;
            cout << "\n\nItem updated";
            cin.ignore(); // Ignore newline character
        }
        cout << "\n\nStock Updated!!";
    } else {
        cout << "\n\nMaximum product limit reached. Cannot add more products.";
    }
    cout << "\n";
    cin.ignore(); // Ignore newline character
}

void Supplier::stockUp(Product productItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the product's name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (productItems[i].stchk(temp) == 0) {
            productItems[i].stockUp(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    cin.get();
    cin.get();
}

void Supplier::removeProduct(Product productItems[], int& numProducts) {
    int i = 0;
    char temp[30];
    cout << "\n\t\t\t\tDelete Record";
    cout << "\n\nEnter the name of the product:";
    cin >> temp;

    for (i = 0; i < numProducts; i++) {
        if (productItems[i].stchk(temp) == 0) {
            productItems[i].show();
            cout << "\n\n\t\tRecord deleted";
            cout << "\n";
            numProducts--;
            for (int j = i; j < numProducts; j++) {
                productItems[j] = productItems[j + 1];
            }
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    getch();
}

void Buyer::purchaseProduct(Product productItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the product's name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (productItems[i].stchk(temp) == 0) {
            productItems[i].withd(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }

    cin.get();
    getch();
}

void Staff::stockUp(Product productItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the product's name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (productItems[i].stchk(temp) == 0) {
            productItems[i].stockUp(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!\n";
    }

    cin.get();
    cin.get();
}

void showProductList(const Product productItems[], int numProducts) {
    int i = 1;
   cout << "\n------------------------------------------------------------------";
cout << "\n\n-----------------\tTHE STOCK ITEMS ARE\t------------------";
cout << "\n\n------------------------------------------------------------------\n";
cout << "\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
cout << "\n\n------------------------------------------------------------------\n";

    for (i = 0; i < numProducts; i++) {
        productItems[i].show();
    }

    if (i == 0) {
        cout << "\n\n\t\t\t!!Empty record room!!";
        getch();
    }
}

int main() {
     int i, j;
    cout << "|------------ WELCOME TO STORE MANAGEMENT ------------|\n\n\n";
    getch();
    mainmenu:
    cout << "STORE MANAGEMENT SYSTEM\n";
    cout << "------------------------------------------\n";
    cout << "   1. Supplier Menu\n   2. Buyer Menu\n   3. Staff Menu\n";
    cout << "------------------------------------------\n";
    cout << "Enter Your Choice: ";
    cin >> j;

    if (j == 1) {
        char pass[10];
        cout << "\n\n\t\t\t\t\tEnter the password letter by letter: ";

        for (int z = 0; z < 8; z++) {
            pass[z] = getch();

            for (i = 1; i <= 1; i++) {
                cout << "*";
            }
        }

        if (strcmp(pass, "supplier") == 0) {
            cout << "\n\n\nCongrats!!Access Granted!!\n\n";
            getch();

        suppliermenu:
             cout << "------------------------------------------\n";
            cout << "   SUPPLIER MENU\n";
            cout << "1. Add new product\n2. Display stock\n3. Stock up\n4. Remove an item\n5. Return to main menu\n6. Exit\n";
            cout << "------------------------------------------\n";
            cout << "Enter your Choice: ";
            cin >> i;

            if (i == 1) {
                Supplier::addProduct(productItems, numProducts);
                getch();
                goto suppliermenu;
            } else if (i == 2) {
                showProductList(productItems, numProducts);
                getch();
                goto suppliermenu;
            } else if (i == 3) {
                Supplier::stockUp(productItems, numProducts);
                goto suppliermenu;
            } else if (i == 4) {
                Supplier::removeProduct(productItems, numProducts);
                getch();
                goto suppliermenu;
            } else if (i == 5) {
                goto mainmenu;
            } else {
                getch();
                exit(0);
            }
        } else {
            cout << "\n\n\nAuthorised Personnel Only\n\n";
            getch();
            exit(0);
        }
    } else if (j == 2) {
    buyermenu:
         cout << "------------------------------------------\n";
        cout << "   BUYER MENU\n";
        cout << "1. Purchase\n2. Display stock\n3. Return to main menu\n4. Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter your Choice: ";
        cin >> i;

        if (i == 1) {
            Buyer::purchaseProduct(productItems, numProducts);
            getch();
            goto buyermenu;
        } else if (i == 2) {
            showProductList(productItems, numProducts);
            getch();
            goto buyermenu;
        } else if (i == 3) {
            goto mainmenu;
        } else {
            getch();
            exit(0);
        }
    } else if (j == 3) {
        cout << "\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
        char pass[6];

        for (int z = 0; z < 5; z++) {
            pass[z] = getch();

            for (i = 1; i <= 1; i++) {
                cout << "*";
            }
        }
cout<<"\n";
        if (strcmp(pass, "staff") == 0) {
        staffmenu:
             cout << "------------------------------------------\n";
            cout << "   STAFF MENU\n";
            cout << "1. Display stock\n2. Stock up\n3. Return to main menu\n4. Exit\n";
            cout << "------------------------------------------\n";
            cout << "Enter your Choice: ";
            cin >> i;
            if (i == 1) {
                showProductList(productItems, numProducts);
                getch();
                goto staffmenu;
            } else if (i == 2) {
                Staff::stockUp(productItems, numProducts);
                goto staffmenu;
            } else if (i == 3) {
                goto mainmenu;
            } else {
                cout << "\n\n\n\t\t\tThank You!!";
                getch();
                exit(0);
            }
        } else {
            cout << "\n\nSorry!! Access Denied..\n\n";
            getch();
            exit(0);
        }
    }

    getch();
}
