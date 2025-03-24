#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to store expense details
struct Expense {
    string date;
    string category;
    double amount;
};

// Function to add an expense
void addExpense() {
    Expense expense;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> expense.date;

    cout << "Enter category (Food, Transport, etc.): ";
    cin >> expense.category;

    cout << "Enter amount: ";
    cin >> expense.amount;

    ofstream file("Expenses.txt", ios::app);
    if (file) {
        file << expense.date << " " << expense.category << " " << expense.amount << endl;
        cout << "Expense added successfully!\n";
    } else {
        cout << "Error: Could not open file.\n";
    }
    file.close();
}

// Function to view all expenses
void viewExpense() {
    ifstream file("Expenses.txt");

    if (!file) {
        cout << "No expenses found.\n";
        return;
    }

    vector<Expense> expenses;
    Expense expense;

    cout << "\n--- Expense List ---\n";
    cout << left << setw(12) << "Date" << setw(15) << "Category" << setw(10) << "Amount" << endl;
    cout << "--------------------------------------------------\n";

    while (file >> expense.date >> expense.category >> expense.amount) {
        expenses.push_back(expense);
        cout << left << setw(12) << expense.date
             << setw(15) << expense.category
             << "$" << setw(10) << expense.amount << endl;
    }

    file.close();
}

// Function to delete expenses by date
void deleteExpense() {
    string deleteDate;

    cout << "Enter date to delete expenses (YYYY-MM-DD): ";
    cin >> deleteDate;

    ifstream file("Expenses.txt");
    if (!file) {
        cout << "Error: Could not open file.\n";
        return;
    }

    vector<Expense> expenses;
    Expense expense;
    bool found = false;

    while (file >> expense.date >> expense.category >> expense.amount) {
        if (expense.date != deleteDate) {
            expenses.push_back(expense);
        } else {
            found = true;
        }
    }
    file.close();

    ofstream outFile("Expenses.txt", ios::trunc);
    for (const auto &exp : expenses) {
        outFile << exp.date << " " << exp.category << " " << exp.amount << endl;
    }
    outFile.close();

    if (found) {
        cout << "Expenses on " << deleteDate << " deleted.\n";
    } else {
        cout << "No expenses found on that date.\n";
    }
}

// Function to delete all data
void deleteAllExpense(){

    ofstream outFile("Expenses.txt", ios::trunc);
    if(!outFile){
        cout << "Error: Could not open file for deletion.\n";
        return;
    }
    cout << "Deleted All Expenses successfully!\n";
    outFile.close();
}

// Main function to handle user menu
int main() {
    int choice;

    do {
        cout << "\nExpense Tracker\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Delete Expense\n";
        cout << "4. Delete All Data\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if(!(cin >> choice)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpense();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                deleteAllExpense();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
