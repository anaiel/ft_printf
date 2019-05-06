# Ft_printf

This project was completed in december 2018 as part of the 42 school cursus. The aim was to compile a library containing the functions from our [libft](https://github.com/anaiel/libft) and our own version of the printf function. The full instuctions can be found in the *resources* folder.

![Ft_printf](https://i.imgur.com/MmqrRG4.png "Algo branch > ft_printf")

*Parsing, variadic functions*

## Solving the problem

This problem requires to do more advanced **parsing**, and also to use **variadic functions** since printf takes an undefined number of arguments.

## Using ft_printf

```
int   ft_printf(format, ...);
```

ft_printf receives a string, called the *format*, which may contain a number of placeholders introduced by the character % and concluded by the type of conversion (string to string, int to decimal, int to hexa, etc.). Between the '%' and the conversion may be a number of options: flags, modifiers (which modify the length of the expected data), field and precision. ft_printf replaces the placeholder with the content of the correspinding argument after all the options are applied. Here is a summary of the different options :

| Conversion | Effect |
|:----------:|:------:|
| d / i | Prints an int in decimal form |
| o | Prints an int in octal form |
| u | Prints an unsigned int in decimal form |
| x | Prints an int in hexadecimal form (lowercase) |
| X | Prints an int in hexadecimal form (uppercase) |
| c | Prints a char |
| s | Prints a string (char \*) |
| p | Prints a pointer's address |
| f | Prints a floar (default precision is 6) |

Field width is the minimum length of the string resulting from the conversion, and is given with a number. By default, if the resulting string is shorted that the field width, the resulting string is aligned on the right and spaces are used to fill the extra characters on the left.

The precision is also a number, preceded with a point. For diouxX conversions, it corresponds to the minimum length of the string, padded with 0 on the left if the result of the conversion is shorter than the precision. For f conversion, it specifies the number of digits after the decimal point. For s conversions, it gives the maximum number of characters to be printed from the argument.

| Flag | Effect |
|:----:|:------:|
| - | Left-justify within the field width |
| + | Forces positive numbers to be preceded with a '+' sign |
| ' ' (space) | If no sign is going to be written, a blank space is inserted before the value |
| # | o, x and X conversions are preceded with 0, 0x or 0X respectively |
| 0 | Pads with zeros instead of the default spaces |

| Modifiers | Effect |
|:---------:|:------:|
| hh | di are interpreted as signed char, ouxX as unsigned char |
| h | di are interpreted as short int, ouxX as unsigned short int |
| l | di are interpreted as long int, ouxX as unsigned long int, c as wint_t and s as wchar_t* |
| ll | di are interpreted as long long int, ouxX as unsigned long long int |
| j | di are interpreted as intmax_t, uoxX as uintmax_t |

## Getting Started

Run the `make` command to compile the library.

In future projects, the libft will be used by placing this libft folder in the projects folder. The libft.a library will be compiled at the same time as the project by adding the following rule to the Makefile :
```
libft:
    make -C ft_printf/
```
As well as the following flags to the compilation of the sources of the project :
```
-I./ft_printf/libft/includes/ -I./ft_printf/includes/ -L./ft_printf -lftprintf
```

## Authors

* **[anaiel](https://github.com/anaiel)** - *Flags, wide characters, floats*
* [Xeska](https://github.com/Xeska) - *Conversions, modifiers, binary*
