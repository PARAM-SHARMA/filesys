# File Sys

# 🗂️ In-Memory File System (C++)

A simple command-line **in-memory file system simulator** written in C++.  
This project mimics basic file system operations such as creating directories, creating files, navigating between directories, serializing/deserializing the file tree, and visualizing the structure.

---

## 📌 Features

- 📁 Create directories
- 📄 Create files
- 📂 Navigate between directories (`cd`)
- 🗑️ Remove directories
- 🌳 Print directory tree
- 📃 List directory contents
- 📍 Show current path
- 💾 Serialize file system into a string
- 🔄 Deserialize string back into file system structure

---

## 🏗️ Project Structure

```

.
├── FS.h          # File system class definition
├── FS.cpp        # File system implementation
├── main.cpp      # CLI interface
└── README.md

````

### Core Components

#### `FS` Class
Represents the in-memory file system.

#### `Node` Structure (Private)
Represents a file or directory.

```cpp
struct Node {
    std::string name;
    bool isFile;
    std::string content;
    std::vector<Node*> children;
    int childCount;
    Node* parent;
};
````

Each node can be:

* A **directory** (`isFile == false`)
* A **file** (`isFile == true`)

---

## ⚙️ Supported Commands

| Command | Arguments           | Description                        |
| ------- | ------------------- | ---------------------------------- |
| `mkdir` | `name path`         | Create a new directory             |
| `touch` | `name path`         | Create a new file                  |
| `rmdir` | `path`              | Remove a directory                 |
| `cd`    | `path`              | Change current directory           |
| `pwd`   | —                   | Print current working directory    |
| `ls`    | —                   | List contents of current directory |
| `tree`  | —                   | Print entire file system tree      |
| `ser`   | —                   | Serialize file system              |
| `dser`  | `serialized_string` | Deserialize file system            |
| `exit`  | —                   | Exit program                       |

---

## 🖥️ Example Usage

```bash
/root> mkdir home /
Directory 'home' created successfully in /

/root> cd home

/root/home> touch file1 .
File 'file1' created successfully in .

/root/home> ls
File file1

/root/home> pwd
/root/home

/root/home> tree
root
 home
  file1
```

---

## 🔄 Serialization Format

The file system is serialized into a flat string format.

Each node is encoded as:

```
type~name~content~childCount
```

Where:

* `type` → `file` or `dir`
* `name` → name of node
* `content` → only for files
* `childCount` → number of children

Example:

```
dir~root~1 dir~home~1 file~file1~~0
```

---

## 🧠 How It Works

* The system starts with a root directory named `"root"`.
* Each node keeps track of:

  * Its parent
  * Its children
  * Whether it is a file or directory
* Paths are parsed using `/`
* The tree is built dynamically using heap allocation (`new`)

---

## 🚀 How to Compile & Run

### Using g++

```bash
g++ main.cpp FS.cpp -o filesystem
./filesystem
```

Or if everything is in one file:

```bash
g++ main.cpp -o filesystem
./filesystem
```

---

## 📚 Concepts Demonstrated

* Object-Oriented Programming (OOP)
* Tree Data Structures
* Recursion (Tree traversal, serialization, deserialization)
* Command parsing with enums
* Dynamic memory allocation
* Basic CLI interaction

---

## ⚠️ Limitations

* No memory deallocation (no destructor implemented)
* No validation for duplicate file/directory names
* No persistent storage (in-memory only)
* Minimal error handling
* No file content editing command

---

## 🛠️ Future Improvements

* Add file editing functionality
* Implement recursive deletion
* Add memory cleanup (destructor)
* Support absolute and relative paths more robustly
* Improve serialization format (JSON-like structure)
* Add unit tests

---

## 👨‍💻 Author

Developed as a C++ practice project to simulate file system behavior and strengthen understanding of tree structures and recursion.

---

## 📜 License

This project is open-source and free to use for educational purposes.
