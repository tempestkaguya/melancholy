# What is this?

Melancholy, a Reverse Engineering tool built entirely upon C++ and Rust

Why C++ and Rust specifically and not just one of them? Rust's ecosystem is not comparable to C++'s, therefore i arrived to a single conclusion...
"*Just make it in both languages.*"

# What is gonna be the stack?

* **C++** Powers the *beatiful* UI, hex view and disassambler.
* **Rust** Handles the core logic, such as the binary parsing, Control Flow Graph (CFG) and heavy backend data processing.

# Libraries

I will be using Qt for C++ because I believe it's the best library for heavy-desktop app work

# How to run this?

I kept compilations as simple as possible via a shell script:

```bash
# Build the project automatically
./run.sh

# Build and run the executable directly
./run.sh r
```

Or you could just build it automatically by pressing F7

# What formats are or will be supported?

* **ELF (Linux):** Current primary focus and active development goal
* **Mach-O (MacOS):** Planned for development in the future