# 2.1 - Operators and Operands

## Operators

*symbols that instruct the computer to do something simple. usually either 1-3 symbols or a keyword*

### Unary Operators

- Requires **1 Operand**
- Comprehensive List:
	- **+** (MAKE POSITIVE)
	- **-** (NEGATE)
	- **!** (LOGICAL NOT)
	- **~** (BITWISE NOT)
	- **++** (INCREMENT)
	- **--** (DECREMENT)
	- **\*** (INDIRECTION)
	- **&** (ADDRESS OF)

### Binary Operators

- Requires **2 Operands**
- Comprehensive List:
	- **+** (PLUS)
	- **-** (MINUS)
	- **\*** (MULTIPLY)
	- **/** (DIVIDE)
	- **%** (MODULO)
	- **==** (EQUAL TO)
	- **!=** (NOT EQUAL TO)
	- **<** (LESS THAN)
	- **>** (GREATER THAN)
	- **<=** (LESS THAN OR EQUAL TO)
	- **>=** (GREATER THAN OR EQUAL TO)
	- **&&** (LOGICAL AND)
	- **||** (LOGICAL OR)
	- **&** (BITWISE AND)
	- **|** (BITWISE OR)
	- **^** (BITWISE XOR)
	- **<<** (BITWISE LEFT-SHIFT)
	- **>>** (BITWISE RIGHT-SHIFT)
	- **=** (ASSIGNMENT)
	- **+=** (ADDITION ASSIGNMENT)
	- **-=** (SUBTRACTION ASSIGNMENT)
	- **\*=** (MULTIPLICATION ASSIGNMENT)
	- **/=** (DIVISION ASSIGNMENT)
	- **%=** (MODULO ASSIGNMENT)
	- **&=** (BITWISE AND ASSIGNMENT)
	- **|=** (BITWISE OR ASSIGNMENT)
	- **^=** (BITWISE XOR ASSIGNMENT)
	- **<<=** (BITWISE LEFT-SHIFT ASSIGNMENT)
	- **>>=** (BITWISE RIGHT-SHIFT ASSIGNMENT)

### Ternary Operator

- Requires **3 Operands**
- **Only 1 Ternary** Operator in C++
- Example: `condition ? varYes : varNo`

## Operands

*expression acted upon by an operator*

## Order of Operations

*just like in math, not all operators are created equal*

### Precedence

*closely related to PEMDAS*

#### Basic Operators Listed in Decreasing Order of Precedence
1. \*, /, and %
2. \+ and -
3. =

### Associativity

*determines whether an expression is evaluated from left-to-right or right-to-left*

- Arithmetic Operators = Left-To-Right
- Assignment Operator = Right-To-Left

# 2.2 - Common Operators

## Assignment Operator (=)

*evaluates the expression on the right and stores it in the variable on the left*

### Examples
- `x = y + 5;` (set the value of `x` to the quantity `y + 5`)
- `int z = x = y + 5` (set the value of `x` to the quantity `y + 5`, then create an integer `z` with the value of `x`)

## Arithmetic Operators (+, -, *, /, %)

*fairly self-explanatory*

### Differences Between Math & C++
- `ab != a * b` in C++; `ab` is its own separate variable
- `^ != exponentiation` in C++; `^` is the bitwise XOR operator
- `/` isn't always normal division in C++; it's context-specific

### Division Behavior

*here's some python code to explain the behavior*

> `if isinstance(a, int) and isinstance(b, int):`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`# // is integer division in python`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return a // b`<br>
> `else:`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`# / is float division in python`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return a / b`

## Data Type Conversions

*different types behave differently, so sometimes certain variables need to be converted to a different type (implicitly or explicitly)*

### Type Promotions

*the compiler will automatically promote narrow types to wider types if they're involved in an operation with a wider type*

- **"Narrow"**: only capable of representing **relatively** small values
- **"Wide"**: capable of representing **relatively** large values

### Typecasting

*explicitly telling the compiler to convert (or cast) a variable to a different type*

#### Examples (both result in `x` being the integer 3)
- > `\\ More Explicit Typecasting`<br>`float pi = 3.14;`<br>`int x = (int)pi;`
- > `\\ Modern C++ Typecasting (error-prone)`<br>`float pi = 3.14;`<br>`int x = pi`