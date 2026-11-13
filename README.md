*This project has been created as part of the 42 curriculum by imel-hac.*

# Libft

## Description

Libft is the first project of the 42 curriculum. The goal is to build your own C library by re-implementing a set of standard libc functions, plus additional utility functions for strings, memory, output and linked lists. The library is reused in later 42 projects, so it must be correct, norm-compliant and free of leaks.

The result is a static library, `libft.a`, made of three parts:

1. **Part 1: libc re-implementations** (same behavior as the originals)
2. **Part 2: additional functions** (not in libc, or in a different form)
3. **Part 3: linked list functions** using `t_list`

## Instructions

### Compilation

```bash
make          # builds libft.a (flags: -Wall -Wextra -Werror)
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```
### Installation

Clone the repository and go into the project folder:

```bash
git clone <your-repository-url> libft
cd libft
```

Then build the library with `make` (see Compilation above). This creates `libft.a` in the project root.

### Execution

Libft is a library, not a program, so it has no executable of its own. To use it, include the header in your code:

```c
#include "libft.h"
```

Then compile your program with `libft.a` and run it:

```bash
cc -Wall -Wextra -Werror main.c libft.a
./a.out
```

## Library contents

### Part 1: libc functions

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Allocation (use `malloc`) | `ft_calloc`, `ft_strdup` |

### Part 2: additional functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring of a string, allocated with `malloc`. |
| `ft_strjoin` | Concatenates two strings into a new allocated string. |
| `ft_strtrim` | Removes a set of characters from both ends of a string. |
| `ft_split` | Splits a string on a delimiter character into a NULL-terminated array of strings. |
| `ft_itoa` | Converts an integer to an allocated string. |
| `ft_strmapi` | Applies a function to each character (with its index) and returns the new string. |
| `ft_striteri` | Applies a function to each character (with its index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3: linked lists

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node's content with a given function, then the node. |
| `ft_lstclear` | Deletes and frees a node and all that follow it. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Builds a new list by applying a function to each node, cleaning up on failure. |

## Technical choices

- library built with `ar rcs`.
- Behavior matches the original libc functions, including edge cases (NULL, size 0, overlapping memory in `ft_memmove`).
- Every `malloc` is checked, and nothing is leaked on failure paths.

## Resources

- `man 3` pages for each libc function (`man 3 strlcpy`, `man 3 memmove`, etc.)
- The C standard library reference: https://en.cppreference.com/w/c
- *The C Programming Language*, Kernighan & Ritchie
- GNU Make manual: https://www.gnu.org/software/make/manual/
- The 42 Norm (norminette) documentation

### Use of AI

<Fill this in with what you actually did. For example: "AI was used to explain the difference between `memcpy` and `memmove`, All code was written, tested and understood by the me.">