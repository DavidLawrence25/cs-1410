# 6.1 - Functions

## Function

*a small snippet of code designed to be reused. they are preferred over copying and pasting because they make code more readable and reduce unnecessary repetition*

## Definition vs Declaration

*functions don't need to be defined at the same time they're declared. separating them can bring the high-level logic to the surface and leave implementation details further into a program*

### Definition

*specifying the underlying logic of a function*

> `int max(int a, int b) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return a > b ? a : b;`<br>
> `}`

### Declaration

*informing the compiler and readers that a certain function exists. includes defining the return and parameter types*

> `int max(int a, int b);`

- **Note:** Trying to run this function will result in an error if it is not defined anywhere in the program. Don't forget to include the definition somewhere.

# 6.2 - Function Basics

## Return Type

*the type of data the function will return, specified directly before the function name. can be a built-in type like `int` or a custom class/struct like `Movie`.*

### Examples:

- **`float`** `sin(float x);`
- **`void`** `print(std::string text);`
- **`ComplexNumber`** `exp(ComplexNumber z);`

## Name

*the name the function will be called by in the source code. can contain letters, numbers, and underscores (no numbers at the start, though)*

### Examples:

- `int` **`get_user_input`**`(std::string prompt);`
- `void` **`_dont_touch_me`**`(std::vector<int> nums);`
- `float` **`sin2`**`(float x);`

## Parameters

*bits of data the caller of a function can pass into it*

### Examples:

- `int factorial(`**`int n`**`);`
- `void set_width(`**`int width`**`);`
- `float sin(`**`float x`**`);`

### Difference Between Parameters & Arguments

- **Parameter:** an abstract variable in a function declaration that has no definitive value
- **Argument:** a literal value passed into a function
