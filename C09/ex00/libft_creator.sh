#!/bin/bash

# Compile all C files in the current directory
gcc -Wall -Wextra -Werror -c *.c

# Create the static library
ar -rcs libft.a *.o

# Clean up object files
rm -f *.o
