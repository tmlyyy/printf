*This project has been created as part of the 42 curriculum by \<thamoliv>.*

# ft_printf

## Description

**ft_printf** is a 42 curriculum project that aims to recreate part of the behavior of the `printf()` function from the C standard library.

The `ft_printf` function was implemented using variadic functions (`stdarg.h`), allowing it to receive a variable number of arguments and interpret them according to the format specifiers present in the format string.

The project was developed strictly following the 42 Norm, prioritizing clarity and modularity.

## Implemented Specifiers

The function supports the following specifiers:

| Specifier | Description                                  |
| --------- | -------------------------------------------- |
| `%c`      | Prints a single character                    |
| `%s`      | Prints a string                              |
| `%p`      | Prints a pointer address in hexadecimal      |
| `%d`      | Prints a signed decimal number               |
| `%i`      | Prints an integer in base 10                 |
| `%u`      | Prints an unsigned decimal number            |
| `%x`      | Prints a number in hexadecimal (lowercase)   |
| `%X`      | Prints a number in hexadecimal (uppercase)   |
| `%%`      | Prints a literal percent sign                |

## Instructions

### Compile the library

Use the provided Makefile:

```bash
make
```

This command will compile all source files and generate the static library:

```text
libftprintf.a
```

### Other available commands

#### Remove object files

```bash
make clean
```

Removes all compiled object files (`*.o`).

#### Remove object files and library

```bash
make fclean
```

Removes the library `libftprintf.a` and all object files.

#### Recompile the project

```bash
make re
```

Removes all generated files and recompiles from scratch.

### Using the library

Include the header in your file:

```c
#include "ft_printf.h"
```

Compile your program alongside the library:

```bash
cc main.c libftprintf.a -o program
```

Run:

```bash
./program
```

## Algorithm and Data Structure

The `ft_printf` function works by iterating through the format string character by character using a pointer. When a regular character is found, it is written directly to the standard output using `write()`. When a `%` is found, the pointer advances to the next character, which determines the conversion to apply.

The conversion logic is delegated to a separate static function (`if_check`), which uses a chain of conditionals to match the specifier and call the appropriate handler function. Each handler is responsible for printing one type of argument and returning the number of characters written.

This modular approach was chosen because it keeps each responsibility isolated: the main function handles traversal, the `if_check` function handles dispatching, and each helper handles a single conversion. This makes the code easier to debug, read, and extend.

No complex data structures were required — the only notable structure is `va_list` from `<stdarg.h>`, which internally manages the variable argument list passed to the function.

## Resources

The following topics and references were used during the development of this project:

### Variadic Functions

- `stdarg.h`
- `va_list`, `va_start`, `va_arg`, `va_end`

These allow a function to receive a variable number of arguments, which is the foundation of `ft_printf`.

### Number Conversion

- Decimal to string conversion
- Hexadecimal conversion (lowercase and uppercase)
- Unsigned integer representation
- Memory address to hexadecimal (`%p`)

### Pointers

- Pointer manipulation
- Printing memory addresses
- Handling null pointers (`NULL`)

### References

- Manual `stdarg(3)`
- Manual `printf(3)`
- Manual `write(2)`
- 42 official project documentation for `ft_printf`

### Artificial Intelligence

This project also used AI tools as a support for learning and concept review. AI was used for:

- Detailed explanation of variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- Understanding decimal to string and hexadecimal conversion
- Clarifying pointer printing and `NULL` handling
- Discussing test cases and comparing behavior with the original `printf`

All final code was implemented, tested, and understood by the project author.

### Concepts Practiced

- Recursion
- String manipulation
- Numeric type conversion
- Static libraries
- Modular code organization in C
- Writing code following the 42 Norm

## Example

```c
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		count;
	void	*ptr;

	ptr = (void *)0x1234;

	count = ft_printf(
		"String: %s | Char: %c | Hex: %x | HEX: %X | Ptr: %p | Unsigned: %u | Decimal: %d | Integer: %i\n",
		"Hello World",
		'A',
		255,
		255,
		ptr,
		4294967295U,
		-42,
		42);
	printf("ft_printf returned: %d\n", count);

	count = printf(
		"String: %s | Char: %c | Hex: %x | HEX: %X | Ptr: %p | Unsigned: %u | Decimal: %d | Integer: %i\n",
		"Hello World",
		'A',
		255,
		255,
		ptr,
		4294967295U,
		-42,
		42);
	printf("printf returned: %d\n", count);

	return (0);
}
```

### Output

```text
String: Hello World | Char: A | Hex: ff | HEX: FF | Ptr: 0x1234 | Unsigned: 4294967295 | Decimal: -42 | Integer: 42
ft_printf returned: 112

String: Hello World | Char: A | Hex: ff | HEX: FF | Ptr: 0x1234 | Unsigned: 4294967295 | Decimal: -42 | Integer: 42
printf returned: 112
```

This example demonstrates that `ft_printf` reproduces the behavior of the original `printf`, both in output formatting and in the number of characters printed returned by the function.