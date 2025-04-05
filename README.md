# get_next_line

A custom implementation of the `get_next_line` function, designed to read and return the next line from a file descriptor.

---

## 📌 Project Description

`get_next_line` is a project developed as part of the **42 School** curriculum, aiming to create a function that reads a line from a file descriptor, returning it each time it's called. This function is essential for handling file input operations in C, allowing for efficient and straightforward line-by-line reading.

The primary objectives of this project are:

- To develop a function that returns a line read from a file descriptor.
- To manage memory efficiently, ensuring no leaks occur.
- To handle multiple file descriptors simultaneously.

### ✨ Technologies Used

- **C language** – For system-level programming and file handling.

### 💡 Challenges Faced

- Efficiently reading from a file descriptor without knowing the file's size.
- Managing static variables to retain information between function calls.
- Handling multiple file descriptors and ensuring each has its own reading state.

---

## 📖 Table of Contents

- [Project Description](#project-description)
- [How to Install and Run the Project](#how-to-install-and-run-the-project)
- [File Structure & Descriptions](#file-structure--descriptions)

---

## 🛠 How to Install and Run the Project

To compile and use the `get_next_line` function, follow these steps:

```bash
# Clone the repository
git clone https://github.com/Thanagorn16/get_next_line.git
cd get_next_line

# Compile the source files
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -c get_next_line.c get_next_line_utils.c
```
---

## 📁 File Structure & Descriptions
Each file in this repository serves a specific purpose in the implementation of `get_next_line`:

`get_next_line.c` – Contains the main get_next_line function, responsible for reading from the file descriptor and returning the next line.

`get_next_line.h` – The header file containing function prototypes and necessary includes.

`get_next_line_bonus.c` – An extended version of `get_next_line` to handle multiple file descriptors simultaneously.

`get_next_line_bonus.h` – The corresponding header for the bonus part.

`get_next_line_utils.c` – Utility functions that assist `get_next_line` in its operations.

`get_next_line_utils_bonus.c` – Utility functions for the bonus part.

`mytest.txt` – A sample text file for testing purposes.

`test_des.abc` – Another sample file for testing.
