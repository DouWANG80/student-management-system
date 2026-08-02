\# Dynamic Student Management System in C



A lightweight, console-based Student Management System written in C. 



\## 🚀 Key Upgrade: Dynamic Memory Management

Earlier versions of this project relied on fixed-size static arrays (which risked buffer overflow or wasted memory). This updated version implements \*\*Dynamic Memory Allocation\*\* using `realloc()` and `free()`.



\* \*\*Zero Memory Waste:\*\* Memory grows dynamically when records are added and shrinks when deleted.

\* \*\*Safe Cleanups:\*\* Prevents memory leaks by freeing allocated memory on exit or complete deletion.



\## ✨ Features

\* \*\*Add Student:\*\* Validates duplicate roll numbers and dynamically allocates memory.

\* \*\*Edit Student:\*\* Updates student records in-place.

\* \*\*Delete Student:\*\* Shifts array elements and resizes memory down dynamically.

\* \*\*List \& Search:\*\* Displays formatted tables and enables roll-number lookup.

\* \*\*Buffer Safety:\*\* Custom input buffer flushing to handle standard input cleanly.



\## 🛠️ How to Run

```bash

gcc eg252.c -o student\_manager

./student\_manager

