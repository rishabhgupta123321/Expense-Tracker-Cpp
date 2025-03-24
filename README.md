# Expense Tracker in C++

## 📌 Overview
This is a simple **Expense Tracker** program written in **C++**. It allows users to:
- **Add expenses** with a date, category, and amount.
- **View all recorded expenses** in a formatted table.
- **Delete expenses** by date.
- **Delete all expenses** stored in the file.

The program stores expenses in a file called `Expenses.txt`, making the data persistent.

---

## 🛠️ How It Works
### **1️⃣ Menu Options**
When you run the program, you will see a menu like this:

Expense Tracker

1. Add Expense
2. View Expenses
3. Delete Expense
4. Delete All Data
5. Exit Enter choice:

### **2️⃣ Adding an Expense**
You will be prompted to enter the **date**, **category**, and **amount** of the expense:

Enter date (YYYY-MM-DD): 2024-03-24 

Enter category (Food, Transport, etc.): Food 

Enter amount: 15

Expense added successfully!

This data is saved in `Expenses.txt`.

### **3️⃣ Viewing Expenses**
If expenses exist, they will be displayed in a table:

--- Expense List --- 

Date Category Amount

2024-03-24 Food $15 

2024-03-23 Transport $8

### **4️⃣ Deleting Expenses by Date**
You can delete all expenses of a specific date:

Enter date to delete expenses (YYYY-MM-DD): 2024-03-23 

Expenses on 2024-03-23 deleted.

### **5️⃣ Deleting All Expenses**
If you want to delete all stored expenses:

Deleted All Expenses successfully!

### **6️⃣ Exit**
To quit the program, select `5`.

---

## 📌 Usage Instructions
1. **Compile the program** using g++ (or any C++ compiler):
   ```sh
   g++ Expense-Tracker-Cpp.cpp -o ExpenseTracker

2. Run the compiled program:

  ./ExpenseTracker

3. Follow the on-screen menu to track your expenses.

📌 Example Input/Output

Input:

1
2024-03-24
Food
15

1
2024-03-23
Transport
8

2

Output:

--- Expense List ---

Date        Category       Amount

----------------------------------

2024-03-24  Food          $15

2024-03-23  Transport     $8



🛠️ Technologies Used
• C++
• File Handling (fstream)
• Vectors (vector)
• Formatted Output (iomanip)


👨‍💻 Author
• Name: Rishabh Gupta
• GitHub: rishabhgupta123321
