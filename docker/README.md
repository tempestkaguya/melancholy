# What is Docker?

Think of it as a virtual machine however instead of running a full virtual machine with its own kernel, containers share the host's operating system kernel, making them lightweight and fast. It's an easy way to test out Melancholy from a safe container.

# How to get started?

First of all, make sure to run this command inside your terminal: `make` or `make build` it builds the container. Otherwise the configuration commands will NOT work.

## Configuration commands

```bash
# Launches melancholy inside the docker container
make run

# Starts a bash shell inside the container for debugging
make debug

# Removes unused docker data and frees up disk space
make clean
```