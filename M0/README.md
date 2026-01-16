# Libft

These projects are purely academic. They belong to the curriculum of the 42code course. They cover the first levels of C programming. 
The projects replicate some functions from the <stdio.h> and <string.h> libraries.

## 🌟 Highlights
isalpha: Checks if a character is a letter of the alphabet.

isdigit: Checks if a character is a numeric digit.

isalnum: Determines if a character is alphanumeric (letter or number).

isascii: Checks if a character belongs to the ASCII character set.

isprint: Checks if a character is printable (includes spaces).

toupper: Converts a character to uppercase.

tolower: Converts a character to lowercase.

strlen: Calculates the length of a string.

memset: Fills a block of memory with a specified value.

bzero: Sets a block of memory to zero (similar to memset with 0).

memcpy: Copies a block of memory from one location to another.

memmove: Safely copies memory even if the areas overlap.

strlcpy: Safely copies strings, guaranteeing null termination.

strlcat: Safely concatenates strings with a limited length.

strchr: Finds the first occurrence of a character in a string.

strrchr: Finds the last occurrence of a character in a string.

strncmp: Compares the first n characters of two strings.

memchr: Searches for a character within a block of memory.

memcmp: Compares two blocks of memory.

strnstr: Searches for a substring within another string with a bounded length.

atoi: Converts a numeric string to an integer.

calloc: Allocates memory initialized to zero for an array.

strdup: Duplicates a string by dynamically allocating memory.

// BONUS ////

ft_lstnew: Creates a new node with the provided content and `next` = NULL.

ft_lstadd_front: Adds a node to the beginning of the list, updating the pointer to the first node.

ft_lstsize: Traverses the list, counting all nodes.

ft_lstlast: Traverses the list until the last node is found (when `next` is NULL).

ft_lstadd_back: Adds a node to the end of the list, using `ft_lstlast` to find the last node.

ft_lstdelone: Frees the contents using the `del` function and then frees the node.

ft_lstclear: Frees all nodes in the list and sets the pointer to NULL.

ft_lstiter: Applies the `f` function to the contents of each node.

ft_lstmap: Creates a new list by applying the `f` function to each element. If the creation of any node fails, it frees the entire new list created up to that point.
  

## ✍️ Author 💭

All projects on this GitHub repository are written by **Lucia Estrada** (lestrada-lucia.estradag@gmail.com). October 2025.
