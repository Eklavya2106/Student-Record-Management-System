# 📚 Student Management System (C++)

A simple **console-based Student Management System** written in C++ that allows you to manage student records using file handling.

---

## 🚀 Features

* ➕ Add new student records
* 📄 Display all student records
* 🔍 Search student by roll number
* ✏️ Modify existing records
* ❌ Delete student records
* 💾 Persistent storage using text file (`studentRecord.txt`)

---

## 🛠️ Technologies Used

* C++ (Core Language)
* File Handling (`fstream`)
* Standard Input/Output

---

## 📂 Project Structure

```
.
├── main.cpp              # Source code
├── studentRecord.txt     # Data file (auto-created)
└── README.md             # Project documentation
```

---

## ▶️ How to Run

### 1. Compile the code

```bash
g++ main.cpp -o student
```

### 2. Run the program

```bash
./student
```

---

## 🧠 How It Works

* The program stores student data in a text file using the format:

```
Name|RollNo|Course|Address
```

* Each function performs operations directly on the file:

  * **Insert** → Appends new data
  * **Display** → Reads and prints all records
  * **Search** → Finds a record by roll number
  * **Modify** → Updates a specific record using a temporary file
  * **Delete** → Removes a record using a temporary file

---

## 📸 Sample Menu

```
--- STUDENT MANAGEMENT SYSTEM ---
1. Add Record
2. Display All
3. Modify
4. Search
5. Delete
6. Exit
```

---

## ⚠️ Limitations

* No validation for duplicate roll numbers
* Data stored in plain text (not secure)
* Console-based UI only
* Not optimized for large datasets

---

## 💡 Future Improvements

* Add GUI (using Qt or similar)
* Use database (MySQL / SQLite)
* Login system for security

---

## 🤝 Contributing

Feel free to fork this repository and improve it. Pull requests are welcome!

---

## 📜 License

This project is open-source and free to use.

---

## 👨‍💻 Author

Developed as a beginner-friendly C++ project to demonstrate file handling and basic CRUD operations.
