#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class MenuItem {
public:
    string name;
    float price;
    string description;

    MenuItem(string n, float p, string d) : name(n), price(p), description(d) {}
};

class Menu {
public:
    vector<MenuItem> items;

    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    void removeItem(const string& itemName) {
        items.erase(remove_if(items.begin(), items.end(),
            [itemName](const MenuItem& item) { return item.name == itemName; }), items.end());
    }

    void displayMenu() {
        for (const auto& item : items) {
            cout << item.name << " - $" << item.price << " - " << item.description << endl;
        }
    }
};

class User {
public:
    string name;
    bool isAdmin;

    User(string n, bool admin) : name(n), isAdmin(admin) {}
};

void addNewItemToMenu(Menu& menu) {
    string name, description;
    float price;

    cout << "Введите название нового блюда: ";
    cin >> name;
    cout << "Введите цену нового блюда: ";
    cin >> price;
    cout << "Введите описание нового блюда: ";
    cin.ignore();
    getline(cin, description);

    menu.addItem(MenuItem(name, price, description));
    cout << "Новый элемент добавлен в меню!\n";
}

void removeItemFromMenu(Menu& menu) {
    string itemName;
    cout << "Введите название блюда для удаления: ";
    cin >> itemName;

    menu.removeItem(itemName);
    cout << "Блюдо удалено из меню!\n";
}

void buyItem(Menu& menu) {

    string itemName;
    cout << "Введите название блюда, которое вы хотите купить: ";
    cin >> itemName;

    for (auto& item : menu.items) {
        if (item.name == itemName) {
            cout << "Вы купили " << item.name << " за $" << item.price << ". Приятного аппетита!\n";
            return;
        }
    }

    cout << "Блюдо не найдено в меню.\n";
}

int main() {
    setlocale(LC_ALL, "Rus");
    Menu menu;
    menu.addItem(MenuItem("Бургер", 5.99, "Вкусный говяжий бургер."));
    menu.addItem(MenuItem("Картофель Фри", 2.49, "Хрустящий золотистый картофель."));
    menu.addItem(MenuItem("Газировка", 1.50, "Освежающий газированный напиток."));

    string name;
    int choce;
    cout << "Введите ваше имя: ";
    cin >> name;

    bool isAdmin = (name == "admin");
    User user(name, isAdmin);
    while (true)
    {
        if (user.isAdmin) {
            cout << "=== Меню Администратора ===" << endl;
            menu.displayMenu();
            cout << "Выберите пункт:" << endl;
            cout << "1.Добавить новый продукт" << endl;
            cout << "2.Изменить продукт" << endl;
            cin >> choce;
            if (choce == 1) { addNewItemToMenu(menu); continue; }
            if (choce == 2) { removeItemFromMenu(menu); continue; }
            menu.displayMenu();
        }
        else {
            cout << "=== Меню Клиента ===" << endl;
            menu.displayMenu();
            buyItem(menu);
        }
    }
    return 0;
}