# COS 110 Pointer Projects

Practice projects for learning pointers and dynamic memory in C++ (Chapter 10.1-10.2).

**Unofficial practice materials** designed to help COS 110 students at the University of Pretoria master pointer concepts.

## 📚 Projects Overview

This repository contains **5 hands-on projects** that cover pointer concepts from basics to advanced:

### 1. [Dynamic Array Manager](./project1_dynamic_array/) (EO1 Level)
**Topics:** Basic dynamic array allocation and deallocation

Learn to dynamically allocate arrays, perform basic operations (sum, average, min, max), and properly deallocate memory.

**Files:** README.md, Makefile, main.cpp (starter), solution/

### 2. [Memory Leak Detective](./project2_memory_leak_detective/) (EO1-EO2 Level)
**Topics:** Memory leaks, dangling pointers, debugging

Interactive program with 6 scenarios to identify and fix common memory management errors.

**Files:** README.md, Makefile, main.cpp (starter), solution/

### 3. [Pointer Arithmetic Workshop](./project3_pointer_arithmetic/) (EO1 Level)
**Topics:** Pointer arithmetic, array traversal

Hands-on workshop demonstrating pointer arithmetic with different data types and interactive exercises.

**Files:** README.md, Makefile, main.cpp (starter), solution/

### 4. [Student Records System](./project4_student_records/) (EO2 Level)
**Topics:** Dynamic arrays with structs

Menu-driven application to manage student records using dynamic arrays of structs.

**Files:** README.md, Makefile, main.cpp (starter), solution/

### 5. [2D Dynamic Array Manager](./project5_2d_dynamic_array/) (EO2-EO3 Level)
**Topics:** Two-dimensional dynamic arrays, advanced memory management

Create and manage 2D dynamic arrays (matrices) with proper multi-level allocation and deallocation.

**Files:** README.md, Makefile, main.cpp (starter), solution/

## Quick Start

### Option 1: GitHub Codespaces (Recommended - No Installation Required!)

**What is Codespaces?** GitHub provides a free cloud-based development environment that runs Ubuntu Linux with all the tools you need (g++, make, valgrind) already installed. You code directly in your browser - no setup required!

**Steps:**
1. Click the green **"Code"** button at the top of this repository
2. Select the **"Codespaces"** tab
3. Click **"Create codespace on main"**
4. **Wait approximately 2 minutes** for the environment to build
   - GitHub is setting up a complete Ubuntu Linux environment for you
   - Installing C++ compiler (g++), build tools (make), and memory debugger (valgrind)
   - You'll see a progress bar and terminal output - this is normal!
5. Once loaded, you'll see VS Code in your browser
6. Open the terminal (View → Terminal or Ctrl+`)
7. Navigate to a project and run:
   ```bash
   cd project1_dynamic_array
   make
   ./array_manager
   ```

**Codespaces is completely free** for students and includes 60 hours/month of usage.

### Option 2: Local Development (Windows with WSL)

If you're using Windows, you can use **WSL (Windows Subsystem for Linux)** to run these projects locally:

**One-time setup:**
1. Install WSL2 with Ubuntu:
   ```powershell
   wsl --install
   ```
2. Restart your computer when prompted
3. Open Ubuntu from the Start menu
4. Install build tools:
   ```bash
   sudo apt update
   sudo apt install build-essential git valgrind
   ```

**Clone and run projects:**
```bash
git clone https://github.com/SwiftTuition/COS110-Pointer-Projects.git
cd COS110-Pointer-Projects/project1_dynamic_array
make
./array_manager
```

### Option 3: Local Development (Linux/macOS)

**Clone the repository:**
```bash
git clone https://github.com/SwiftTuition/COS110-Pointer-Projects.git
cd COS110-Pointer-Projects
```

**Build and run a project:**
```bash
cd project1_dynamic_array
make
./array_manager
```

## 📖 Requirements

- **C++ Standard:** C++98
- **Compiler:** g++ with `-std=c++98 -Wall -Wextra -pedantic` flags
- **Tools:** make (Makefiles provided for all projects)

## Learning Objectives

By completing these projects, you will master:

- ✅ Dynamic memory allocation (`new`, `delete`, `new[]`, `delete[]`)
- ✅ Pointer declaration, initialization, and dereferencing
- ✅ Address-of operator (`&`) and dereference operator (`*`)
- ✅ Pointer arithmetic and array-pointer relationships
- ✅ Memory leak prevention and detection
- ✅ Dangling pointer avoidance
- ✅ Dynamic arrays and 2D dynamic arrays
- ✅ Proper memory management in real-world scenarios

## 📝 Project Structure

Each project includes:

- **README.md**: Detailed problem statement, requirements, and tips
- **Makefile**: Easy compilation with `make` command
- **main.cpp**: Starter code with TODOs (for you to complete)
- **solution/**: Reference solution (check after attempting!)
- **sample_output.txt**: Expected program output

## 🔧 Compilation

All projects use the same compilation process:

```bash
make          # Build the project
make run      # Build and run
make clean    # Remove compiled files
make memcheck # Check for memory leaks (requires valgrind)
```

## 🐛 Debugging Tips

- **Memory Leaks:** Use `make memcheck` to detect memory leaks with valgrind
- **Segmentation Faults:** Check pointer initialization and array bounds
- **Compilation Errors:** Read error messages carefully - they point to the line and issue
- **Logic Errors:** Add `cout` statements to trace variable values

## Additional Resources

- **Textbook:** Absolute C++ (Chapter 10.1-10.2)
- **Lecture Slides:** Available on ClickUP
- **Premium Tutoring:** Free students can upgrade to premium for personalized support. Premium students can ask questions in the premium WhatsApp group.

## Support

Having issues with the projects? Use the **Issues** tab above to report bugs or problems.

---

**Created for COS 110 students at University of Pretoria by Swift Tuition**
