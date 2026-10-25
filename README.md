# ft_printf

A reimplementation of `printf` from scratch: format parsing, `va_list`
handling and number conversion, without calling the libc `printf` family.

> Part of the **42 school curriculum**. Built by **Arda Aycan**.

## What is supported

| Specifier | Prints |
| --- | --- |
| `%c` | a single character |
| `%s` | a string (`(null)` for `NULL`) |
| `%p` | a pointer as `0x…` (`(nil)` for `NULL`) |
| `%d` / `%i` | signed decimal |
| `%u` | unsigned decimal |
| `%x` / `%X` | hexadecimal, lower / upper case |
| `%%` | a literal percent sign |

| Flag | Effect |
| --- | --- |
| `+` | always show the sign of a number |
| ` ` (space) | show a space where a positive sign would be |
| `#` | `0x` / `0X` prefix for hexadecimal |

Flags can be combined, and the function returns the number of characters
actually written — or `-1` if the format string ends with a lone `%`.

**Not implemented:** width, precision, and the `-` / `0` flags. They are parsed
so they do not break the format, but they do not pad anything. The 42 mandatory
part does not require them; this is stated here so the output is not a surprise.

## Build

```bash
make            # libftprintf.a
make clean
make fclean
make re
```

Link it next to the program that uses it:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -I. -o program
```

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("%s has %d apples and %#x bytes\n", "Arda", 3, 255);
	return (0);
}
```

## How it works

- `ft_printf` walks the format string, copying ordinary characters and handing
  each `%` sequence to the specifier dispatcher.
- Flags are collected first (`ft_check_edge_cases`), then the specifier decides
  what to read from the `va_list`.
- Every write goes through `ft_putchar` / `ft_charput_counter`, which also keeps
  the character count that the function returns.
- Numbers are converted recursively (decimal and hexadecimal), including
  `INT_MIN` and full 64-bit pointer values.

## Edge cases

- `%s` with `NULL` prints `(null)`.
- `%p` with `NULL` prints `(nil)`.
- `%d` with `INT_MIN` does not overflow.
- A format string ending in `%` returns `-1`.

## Files

| File | Contents |
| --- | --- |
| `ft_printf.c` | entry point, format walk, return value |
| `ft_formatspecifier.c` | dispatch on the conversion character |
| `ft_check_edge_cases.c` | flags (`+`, space, `#`, and skipped `-`/`0`) |
| `ft_if_*.c` | one file per conversion |
| `ft_putchar.c`, `ft_putstr.c`, `ft_strlen.c`, `ft_strdup.c` | small helpers |

## Author

**Arda Aycan** ([@EpicYamo](https://github.com/EpicYamo)).
