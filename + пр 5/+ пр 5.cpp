#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int number, double startBalance) {
        this->accountNumber = number;
        this->balance = startBalance;
        this->interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Средства успешно внесены." << endl;
        }
        else {
            cout << "Сумма для вклада должна быть больше 0." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Сумма для снятия должна быть больше 0." << endl;
            return false;
        }

        if (amount > this->balance) {
            cout << "Недостаточно средств для снятия." << endl;
            return false;
        }

        this->balance -= amount;
        cout << "Средства успешно сняты." << endl;
        return true;
    }

    double getBalance() const {
        return this->balance;
    }

    double getInterest() const {
        return this->balance * this->interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double newRate) {
        if (newRate >= 0.0) {
            this->interestRate = newRate;
            cout << "Процентная ставка успешно обновлена." << endl;
        }
        else {
            cout << "Процентная ставка не может быть отрицательной." << endl;
        }
    }

    int getAccountNumber() const {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount <= 0) {
        cout << "Сумма перевода должна быть больше 0." << endl;
        return false;
    }

    if (&from == &to) {
        cout << "Невозможно совершить перевод на тот же счет." << endl;
        return false;
    }

    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Перевод выполнен успешно." << endl;
        return true;
    }
    else {
        cout << "Ошибка при переводе средств." << endl;
        return false;
    }
}

void interactWithAccount(BankAccount& account) {
    int choice;
    double amount, newRate;
    BankAccount otherAccount(999, 0); // Создаем пустой другой счет

    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Внести средства на счет\n";
        cout << "2. Снять средства со счета\n";
        cout << "3. Получить текущий баланс\n";
        cout << "4. Рассчитать сумму начисленных процентов за месяц\n";
        cout << "5. Обновить процентную ставку\n";
        cout << "6. Получить номер банковского счета\n";
        cout << "7. Перевести средства на другой счет\n";
        cout << "0. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите сумму для внесения: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Введите сумму для снятия: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            cout << "Текущий баланс: " << account.getBalance() << endl;
            break;
        case 4:
            cout << "Сумма начисленных процентов за месяц: " << account.getInterest() << endl;
            break;
        case 5:
            cout << "Введите новую процентную ставку: ";
            cin >> newRate;
            account.setInterestRate(newRate);
            break;
        case 6:
            cout << "Номер банковского счета: " << account.getAccountNumber() << endl;
            break;
        case 7:
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            transfer(account, otherAccount, amount);
            break;
        case 0:
            cout << "Выход из меню." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "RUS");

    BankAccount account1(123, 1000.0);
    BankAccount account2(456, 500.0);

    account1.setInterestRate(0.05); // 5% годовых

    cout << "Взаимодействие с первым счетом:" << endl;
    interactWithAccount(account1);

    cout << "\nВзаимодействие со вторым счетом:" << endl;
    interactWithAccount(account2);

    return 0;
}