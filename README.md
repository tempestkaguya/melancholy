# What is this?

Melancholy, a Reverse Engineering tool built with C++ and Rust

Why use both C++ and Rust instead of just one? The Rust ecosystem isn't yet as mature as the C++ ecosystem, therefore I arrived at a single conclusion...
"*Just make it in both languages.*"

# What is the stack?

* **C++** Powers the *beautiful* UI, hex view, and disassembler.
* **Rust** Handles the core logic, such as the binary parsing, Control Flow Graph (CFG), and heavy backend data processing.

# Libraries

* **Qt (C++):** Chosen because it is the most robust library for heavy desktop app work

# How to run this?

Compilation is simplified via a shell script. You can also press F7 to build the project automatically.

```bash
# Build the project automatically
./run.sh

# Build and run the executable directly
./run.sh r
```

# Contribute

If you would like to contribute to Melancholy, please take a look at our [Contributing Policy](CONTRIBUTING.md)