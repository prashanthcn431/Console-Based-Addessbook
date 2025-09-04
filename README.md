

<!-- =========================================================
  PROJECT: Console-Based Address Book
  FILE: README.md
  AUTHOR: Prashanth C N
  ========================================================= -->

<!-- BADGES / TITLE -->
<h1 align="center">📘 Console-Based Address Book (C)</h1>

<p align="center">
  A simple, modular, menu-driven address book in C , input validation, and clean .c/.h separation.
</p>

<p align="center">
  <em>Educational • Open Source • Beginner-Friendly</em>
</p>

<hr/>

<!-- TABLE OF CONTENTS -->
<!-- ========================================================= -->
<h2 id="table-of-contents">📑 Table of Contents</h2>

- [Features](#features)
- [Concepts Practiced](#concepts-practiced)
- [Project Structure](#project-structure)
- [Build & Run](#build--run)
- [Sample Terminal UI](#sample-terminal-ui)
- [File Format](#file-format)
- [Code Overview](#code-overview)
- [Future Improvements](#future-improvements)
- [Author](#author)
- [License](#license)
- [Feedback](#feedback)

<hr/>

<!-- FEATURES -->
<!-- ========================================================= -->
<h2 id="features">🔧 Features</h2>

- ✅ Add new contacts (**Name, Phone, Email**)
- 🔍 Search contacts by:
  - Name
  - Phone Number
  - Email ID
- ✏️ Edit existing contact details
- ❌ Delete contacts with confirmation
- 📄 Auto **save/load** contacts using `contact.csv`
- 🔒 Input validation for:
  - 10-digit phone numbers
  - Properly formatted `.com` email addresses
- 💡 Modular `.c` and `.h` file structure

<hr/>

<!-- CONCEPTS PRACTICED -->
<!-- ========================================================= -->
<h2 id="concepts-practiced">🧠 Concepts Practiced</h2>

- `struct` usage for storing composite data
- File handling: `fopen()`, `fscanf()`, `fprintf()`
- String & character array manipulation
- Modular programming (`.h` + `.c` separation)
- Error handling & safe user input
- Menu-driven program design

<hr/>

<!-- PROJECT STRUCTURE -->
<!-- ========================================================= -->
<h2 id="project-structure">📁 Project Structure</h2>

```text
addressbook/
├── main.c                  // Main menu driver
├── contact.c   / contact.h // Core contact operations (create, list)
├── contact.txt             // A plain text file used to store and view saved contact details in a human-readable format (Name, Phone, Email).
└── README.md               // Project documentation
````

<hr/>

<!-- BUILD & RUN -->

<!-- ========================================================= -->

<h2 id="build--run">⚙️ Build & Run</h2>

**Compile:**

```bash
gcc main.c contact.c file.c validate.c edit_contact.c search_contact.c delete_contact.c -o addressbook
```

**Run:**

```bash
./addressbook
```

<hr/>

<!-- SAMPLE TERMINAL UI -->

<!-- ========================================================= -->

<h2 id="sample-terminal-ui">📸 Sample Terminal UI</h2>

```text
================= Address Book =================
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: _
```

<hr/>

<!-- FILE FORMAT -->

<!-- ========================================================= -->

<h2 id="file-format">🗂️ File Format (`contact.csv`)</h2>

* CSV fields: `Name,Phone,Email`
* Phone: exactly 10 digits (e.g., `9876543210`)
* Email: must end with `.com` (e.g., `user@example.com`)

**Example:**

```csv
Alice,9876543210,alice@example.com
Bob,9123456789,bob@work.com
```

<hr/>

<!-- CODE OVERVIEW -->

<!-- ========================================================= -->

<h2 id="code-overview">🧩 Code Overview</h2>

* **`main.c`**
  Initializes the app, displays the menu, routes choices to modules.

* **`contact.c / contact.h`**
  Create and list contacts; in-memory storage operations.



<hr/>

<!-- FUTURE IMPROVEMENTS -->

<!-- ========================================================= -->

<h2 id="future-improvements">📦 Future Improvements</h2>

* Contact grouping (tags/categories)
* Export contacts to **PDF** or **JSON**
* **GUI** version using C++/Qt or GTK
* Partial keyword search / fuzzy matching
* Undo feature for deletions

<hr/>

<!-- AUTHOR -->

<!-- ========================================================= -->

<h2 id="author">👨‍💻 Author</h2>

* **Prashanth C N**
* 📧 Email: [prashanthcn431@mail.com](mailto:prashanthcn431@mail.com)
* 🔗 LinkedIn: [https://www.linkedin.com/in/prashanthcn26](https://www.linkedin.com/in/prashanthcn26)

<hr/>

<!-- LICENSE -->

<!-- ========================================================= -->

<h2 id="license">📎 License</h2>

This project is licensed for **educational and open-source use**.
Feel free to **fork** or **contribute**.

<hr/>

<!-- FEEDBACK -->

<!-- ========================================================= -->

<h2 id="feedback">🙌 Feedback</h2>

Have suggestions or improvements?
Please open an **Issue** or **Pull Request**. Collaboration is welcome!

```
