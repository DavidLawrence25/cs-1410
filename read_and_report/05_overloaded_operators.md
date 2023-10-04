# 11.1 - Operator Overloads & `friend` Functions

## Overloaded Operators

*user-defined functions called using operators instead of explicit function calls*

### Syntax

`TypeA operator☺(TypeB other);`

- TypeA = some type
- TypeB = another (or the same) type
- ☺ = the operator to be overloaded

### Rules

New overloaded operators cannot...

- **change** the meaning of **an intrinsic or built-in operator** (e.g., you can't change "+" to "-" for ints or doubles)
- the **precedence or associativity** of any operator
- the **number of operands**
- **create a new operator** (i.e., they can only overload existing operators)
- overload an operator **outside of a class context**

Although not a rule, it's important to keep overloaded operators simple and intuitive. If there's an intuitive way to add two objects, use that for your overload for "+". Also, if it's an expensive operation, make it look expensive. The convenience is not worth screwing over the users of your class.

## `friend` Functions

*like a trusted neighbor: not a member of our family, but we trust them with house keys and carrying out tasks on our behalf*

### Rules

`friend` functions...

- **must be declared as a friend** in the friending class's specification
- are **not members** of the class that declares them as a friend
	- nevertheless **have access** to the friending class' **private features**
	- are **not bound to an object**, so they have one more parameter than a member function
	- **not** called with the **dot operator**
	- defined outside of the class **do not include** the **class name** and **scope resolution** operator as part of the class name
- **can be** declared as **friends of more than one class** and, when used this way, are called *bridge functions*

Friend functions are **controversial** because they **weaken encapsulation**, but they can also **strengthen some overloaded operators** by allowing them to perform useful tasks not otherwise possible.

## 4 Things to Know

1. If an overloaded operator is implemented as a **member or a non-member** (a.k.a. `friend`) function
2. How the operator's **operands are translated** into the implementing function's arguments
3. The function **declaration** looks quite **different from** the function **call**
4. For **which class** an operator is overloaded

# 11.2 - Operator Overloads as Member Functions

## Arithmetic Operators for Numeric Classes

### `fraction.h`

> <code>
> class Fraction {<br>
> &ensp;public:<br>
> &ensp;&ensp;Fraction();<br>
> &ensp;&ensp;Fraction(int numerator, int denominator);<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;Fraction operator+(Fraction other);<br>
> &ensp;&ensp;Fraction operator-(Fraction other);<br>
> &ensp;&ensp;Fraction operator*(Fraction other);<br>
> &ensp;&ensp;Fraction operator/(Fraction other);<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;int get_numerator();<br>
> &ensp;&ensp;int get_denominator();<br>
> <br>
> &ensp;private:<br>
> &ensp;&ensp;int numerator_;<br>
> &ensp;&ensp;int denominator_;<br>
> };
> </code>

### `fraction.cc`

> <code>
> #include "fraction.h"<br>
> <br>
> Fraction::Fraction() {<br>
> &ensp;&ensp;numerator_ = 0;<br>
> &ensp;&ensp;denominator_ = 1;<br>
> }<br>
> <br>
> Fraction::Fraction(int numerator, int denominator) {<br>
> &ensp;&ensp;numerator_ = numerator;<br>
> &ensp;&ensp;denominator_ = denominator;<br>
> }<br>
> <br>
> Fraction Fraction::operator+(Fraction other) {<br>
> &ensp;&ensp;int numerator = numerator_ * other.denominator_<br>
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;+ denominator_ * other.numerator_;<br>
> &ensp;&ensp;int denominator = denominator_ * other.denominator_;<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;return Fraction(numerator, denominator);<br>
> }<br>
> <br>
> Fraction Fraction::operator-(Fraction other) {<br>
> &ensp;&ensp;int numerator = numerator_ * other.denominator_<br>
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- denominator_ * other.numerator_;<br>
> &ensp;&ensp;int denominator = denominator_ * other.denominator_;<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;return Fraction(numerator, denominator);<br>
> }<br>
> <br>
> Fraction Fraction::operator*(Fraction other) {<br>
> &ensp;&ensp;int numerator = numerator_ * other.numerator_;<br>
> &ensp;&ensp;int denominator = denominator_ * other.denominator_;<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;return Fraction(numerator, denominator);<br>
> }<br>
> <br>
> Fraction Fraction::operator/(Fraction other) {<br>
> &ensp;&ensp;int numerator = numerator_ * other.denominator_;<br>
> &ensp;&ensp;int denominator = denominator_ * other.numerator_;<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;return Fraction(numerator, denominator);<br>
> }<br>
> <br>
> int Fraction::get_numerator() {<br>
> &ensp;&ensp;return numerator_;<br>
> }<br>
> <br>
> int Fraction::get_denominator() {<br>
> &ensp;&ensp;return denominator_;<br>
> }
> </code>

### `main.cc`

> <code>
> #include "fraction.h"<br>
> <br>
> int main() {<br>
> &ensp;&ensp;Fraction a = {3, 4};<br>
> &ensp;&ensp;Fraction b = {1, 3};<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;Fraction x;<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;x = a + b;<br>
> &ensp;&ensp;std::cout << x.get_numerator() << '/' << x.get_denominator() << '\n';<br>
> &ensp;&ensp;x = a - b;<br>
> &ensp;&ensp;std::cout << x.get_numerator() << '/' << x.get_denominator() << '\n';<br>
> &ensp;&ensp;x = a * b;<br>
> &ensp;&ensp;std::cout << x.get_numerator() << '/' << x.get_denominator() << '\n';<br>
> &ensp;&ensp;x = a / b;<br>
> &ensp;&ensp;std::cout << x.get_numerator() << '/' << x.get_denominator() << '\n';<br>
> &ensp;&ensp;<br>
> &ensp;&ensp;return 0;<br>
> }
> </code>

## Unary vs. Binary Operator Member Functions

### Unary: `-a` -> `a.operator-();`

- Only has one operand, so implementing function doesn't have any parameters
- The operand always becomes the implicit argument (bound via the `this` pointer)

### Binary: `a + b` -> `a.operator+(b);`

- Has two operands
- Left operand becomes the implicit argument
- Right operand becomes the explicit argument

## Overloaded Asymmetric Member Operators

### Symmetric Operators: `x ☺ y == y ☺ x;`

- Addition and multiplication of scalars
- Addition of matrices
- Comparisons for equality

### Asymmetric Operators: `x ☺ y != y ☺ x;`

- Subtraction and division of scalars
- Subtraction, multiplication, and division of matrices
- Ordered comparisons (e.g., greater than)
