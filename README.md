# Student Management System

## Overview
The **Student Management System** is a console-based application written in C. It enables educational institutions to efficiently manage student records, including their personal information, courses, and GPA calculations. The system provides functionalities for staff and students, ensuring secure access and data management.

---

## Features
- **Staff Menu:**
  - Register new students.
  - Add new courses for existing students.
  - Display and delete student records.
  - Calculate GPA for students.
  - View a list of registered students.

- **Student Menu:**
  - View personal information.
  - Calculate GPA.
  - Print transcript.

- **Login System:**
  - Separate login for staff and students with secure authentication.

- **Data Management:**
  - Save student records in text files for persistence.
  - Allow editing and deletion of records.

---

## Technologies Used
- **Language:** C
- **File Handling:** Persistent storage using text files.
- **Platform:** Console-based application.

---

## Installation

### Prerequisites
- A C compiler (e.g., GCC).
- A terminal or IDE for running C programs.

### Steps
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/YourUsername/Student-Management-System.git
   ```

2. **Navigate to the Project Directory:**
   ```bash
   cd Student-Management-System
   ```

3. **Compile the Program:**
   ```bash
   gcc main.c -o student_management_system
   ```

4. **Run the Program:**
   ```bash
   ./student_management_system
   ```

---

## Usage

1. **Staff Login:**
   - Enter the staff registration number and password to log in.
   - Access the staff menu to manage student records.

2. **Student Login:**
   - Enter the student registration number and password to log in.
   - View personal information, calculate GPA, or print the transcript.

3. **Main Menu Options:**
   - Choose to log in as a staff or student or exit the program.

---

## Project Structure
```
Student-Management-System/
|-- main.c          # Main program file
|-- students/       # Folder containing student data files
|-- README.md       # Documentation for the project
```

---

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m 'Add new feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request on GitHub.

---


## Contact
For questions or suggestions, feel free to contact the repository owner:
- **GitHub:** [Maxim Mamdouh](https://github.com/0Maxbon0)
