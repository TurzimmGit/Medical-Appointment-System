<p align="center">
  <img src="assets/programLogo.png" width="125px" height="125px" alt="Project Logo"/>
</p>

<p align="center">
  <h1 align="center">Medical Appointment Manager</h1>
</p>

<p align="center">
  <em>
    A professional C implementation of a medical scheduling system featuring modular architecture and dynamic memory management.
  </em>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-MIT-E92063?style=flat-square&logo=opensourceinitiative&logoColor=white"/>
  <img src="https://img.shields.io/badge/For-UFMT_Academic_Training-E92063?style=flat-square&logo=gitbook&logoColor=white"/>
  <img src="https://img.shields.io/badge/🛠_Status-Completed-E92063?style=flat-square"/>
</p>

<p align="center"><em>Built with:</em></p>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C-E92063?style=flat-square&logo=c&logoColor=white"/>
  <img src="https://img.shields.io/badge/Paradigm-Modular_Programming-E92063?style=flat-square&logo=code&logoColor=white"/>
  <img src="https://img.shields.io/badge/Editor-VS_Code-E92063?style=flat-square&logo=visualstudiocode&logoColor=white"/>
</p>

---

<details><summary><b>📋 Table of Contents</b></summary>

- [🧭 Overview](#overview)
- [⚙️ Features](#features)
- [📁 Project Structure](#project-structure)
- [🗂️ Project Index](#project-index)
- [🧩 Get Started](#get-started)
- [🧠 Usage](#usage)
- [💖 Author](#author)
- [📜 License](#license)

</details>

<a id="overview"></a>
## 🧭 Overview

This project is a medical consultation management system designed to register, delete, update, and search for patient records. It ensures data integrity and prevents scheduling conflicts, serving as a solid example of **C Data Structures** and **Modular Programming**.

### ㅤ---
<details><summary><b>Why This Project? (The Python to C Transition)</b></summary>

This system was originally conceived as an academic challenge at **UFMT (Federal University of Mato Grosso)**. While the initial logic was prototyped and tested in **Python**, I chose to reimplement the entire core in **C** as a rigorous technical exercise.

By "porting" the logic from a high-level language to a mid-level one, I was able to:
- **Master Memory Management:** Moving from Python's automatic garbage collection to manual `malloc` and `free` operations.
- **Implement Robust Data Structures:** Building a linked list from scratch using pointers and custom structs.
- **Architectural Refactoring:** Separating the application into a modular structure (Headers and Sources) to improve maintainability and follow professional C standards.

**Note on Language:** To preserve the original academic context of the UFMT proposal, internal variables and comments are in **Portuguese**. However, the repository structure, documentation, and build instructions are provided in **English** to align with global development practices.

</details>

---

<a id="features"></a>
## ⚙️ Features

|      | Category          | Description |
| :--- | :---------------- | :----------- |
| 🎯 | **Core CRUD** | Comprehensive management of patient records (Create, Read, Update, Delete). |
| 🛠️ | **Conflict Logic** | Prevents doctor double-booking by enforcing a strict 30-minute window check. |
| 🔍 | **Search Engine** | Look up patients efficiently by Unique ID or Full Name using list traversal. |
| 🛡️ | **Data Validation** | Strict type and format checking for dates (DD/MM/YYYY) and times (HH:MM). |
| ⚡ | **Modular Design** | Separation of concerns across `Modelo` (Data), `Lista` (Logic), and `Main` (UI). |

---

<a id="project-structure"></a>
## 📁 Project Structure

The project is organized into a clean directory tree to separate interfaces from implementations:

```sh
MEDICAL-APPOINTMENT-MANAGER/
├── include/             # Header files (.h) - Declarations
│   ├── Modelo.h         # Struct definitions and data prototypes
│   └── ListaEncadeada.h # Linked list operation prototypes
├── src/                 # Source files (.c) - Implementations
│   ├── Modelo.c         # Data validation logic
│   ├── ListaEncadeada.c # Linked list engine
│   └── main.c           # Entry point and User Interface
└── sistema.exe          # Compiled binary

```

---

<a id="get-started"></a>

## 🧩 Get Started

#### 🛠️ Build From Source

To compile and run this project, ensure you have a C compiler (GCC/MinGW) installed.

**1. Clone the repository**

```bash
git clone [https://github.com/your-username/medical-appointment-manager-c.git](https://github.com/your-username/medical-appointment-manager-c.git)
cd medical-appointment-manager-c

```

**2. Compile (Standard GCC)**

```bash
gcc src/main.c src/Modelo.c src/ListaEncadeada.c -Iinclude -o sistema.exe

```

**3. Run**

```bash
./sistema.exe

```

---

<a id="usage"></a>

### 🧠 Usage

* **Scheduling:** When adding a new patient, the system verifies if the doctor is available at the chosen date and time.
* **30-Min Rule:** If a new appointment is requested within 30 minutes of an existing one for the same doctor, the system will block the entry to avoid overlapping.
* **Formatting:** All names are automatically sanitized into `Title Case` to maintain database consistency.

---

<a id="author"></a>

## 👤 Author

* **Turzimm** — *Information Systems Student at UFMT* 📎 [GitHub Profile](https://github.com/TurzimmGit) | [LinkedIn](https://linkedin.com/in/artur-ferreira-sales-26a927370/)
If this project helped you or inspired you in some way, consider giving it a ⭐!

---

<a id="license"></a>

## 📜 License

This project is licensed under the **MIT License**.

For full details, see the [LICENSE](https://www.google.com/search?q=LICENSE) file.

<p align="left">
<a href="#top">
<img src="https://img.shields.io/badge/Back_to_Top_⭱-E92063?style=flat&logoColor=white" />
</a>
</p>
