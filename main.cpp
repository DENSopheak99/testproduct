#include <iostream>
#include "Product.hpp"
#include "ProductService.hpp"

using namespace std;

void menu()
{
    cout << "1. Add" << endl;
    cout << "2. Get all" << endl;
    cout << "3. Get by id" << endl;
    cout << "4. Delete by id" << endl;
    cout << "5. Update by id" << endl;
    cout << "0. Exit" << endl;
}

ProductService productService;

int main()
{
    system("cls");

    int op;
    do
    {
        menu();
        cout << "Enter an option -> ";
        cin >> op;

        if (op == 0)
        {
            cout << "Exiting..." << endl;
            return 0;
        }

        switch (op)
        {
        case 1:
        {
            system("cls");
            int id, qty;
            string name;
            double price;
            cout << "Enter id: ";
            cin >> id;
            if (productService.existById(id))
            {
                cout << "Product with id: " << id << " already exists" << endl;
                break;
            }
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter qty: ";
            cin >> qty;

            Product p(id, name, price, qty);
            productService.addProduct(p);
            break;
        }
        case 2:
        {
            system("cls");
            productService.getAllProduct();
            break;
        }
        case 3:
        {
            system("cls");
            int id;
            cout << "Enter an id: ";
            cin >> id;
            productService.getProductById(id);
            break;
        }
        case 4:
        {
            system("cls");
            int id;
            cout << "Enter product id to delete:";
            cin >> id;
            if (!productService.existById(id))
            {
                cout << "Product with id: " << id << " does not exist" << endl;
                break;
            }
            productService.deleteProductById(id);
            break;
        }
        case 5:
        {
            system("cls");
            int id;
            cout << "Enter product id to delete:";
            cin >> id;
            if (!productService.existById(id)){
                cout << "Product with id: " << id << " does not exist" << endl;
                break;
            }
            string name;
            double price;
            int qty;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new price: ";
            cin >> price;
            cout << "Enter new qty: ";
            cin >> qty;
            productService.updateProductById(id, name, price, qty);
            break;
        }
        default:
            cout << "Invalid option!" << endl;
        }

    } while (op != 0);

    return 0;
}
