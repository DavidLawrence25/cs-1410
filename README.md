# CS 1410 - CE Adv. Programming

A collection of all assignments written by Rose Thorne for CS 1410, which is/was instructed by Kim Murphy.

## File/Directory Nomenclature

For clarity (and to keep Rose accountable), here are the rules she is meant to follow regarding naming files and stuff.

- **C++ Files:** `XX_name_of_file.cpp`
- **Executables:** `XX_name_of_file.exe`
- **Header Files:** `name_of_lib.hpp`
- **Markdown Files:** `XX_name_of_unit.md`
- **Directories:** `directory_name`

###### note that `XX` refers to the unit the assignment was in, padded with a zero to keep it aligned to two digits

## Notes on Custom Libraries

### What are they?

Header files found in the `custom_libraries` directory are collections of general-use functions written by Rose to be pasted into assignments to save on boilerplate.

### Why doesn't Rose use `#include "custom_lib.hpp"`?

Rose avoids directly including her custom libraries in her code because it would increase the complexity of submission. To properly submit the source code, she would need to place both the library and the assignment in the right file structure and zip that up. This pattern is, of course, subject to change.

### How are they referenced in code?

When Rose includes a function from a custom library, she writes a comment above it with one of two structures:

#### Reused Without Modification

`// borrowed from https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/custom_lib.hpp`

#### Reused With Modification

`// modified from function_name in https://github.com/DavidLawrence25/cs-1410/blob/main/custom_libraries/custom_lib.hpp`

## General C++ Style Preferences

There are a number of things Rose does to ensure visual consistency across her code.

### Indentation via Tab Characters

Rose's editor utilizes 4-wide tabs, but the exact width may vary from editor to editor.

### Case Types

- **Variables:** `snake_case`
- **Constants:** `MACRO_CASE`*
- **Functions:** `snake_case`
- **Files:** `snake_case`
- **Classes:** `PascalCase`
- **Types:** `PascalCase`
- **Enums:** `snake_case`

###### *note that this only really applies to constants whose exact values could be determined at compile time. variables marked constant to denote that they won't change throughout a function are treated as variables for casing purposes

### Always Add Curly Brackets, Even For 1-Line Blocks

This rule is mostly here for consistency and ease-of-modification.

#### Good

> `if (x > 3) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return true;`<br>
> `}`

#### Bad

> `if (x > 3) return true;`

### Comfortable Spacing

There's not a very good way of explaining it, but if you look through Rose's code, you'll see what she means.