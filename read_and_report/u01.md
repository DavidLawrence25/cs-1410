# 3.1 - Basic Flow of Control

## Sequential Flow

*one instruction is executed after another in a predetermined order*

## Selective Flow

*instructions are executed or ignored based on predefined conditions*

### If Statements

*execute a set of instructions if the statement is true, and ignore them otherwise*

> `if (a > b) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << a << endl;`<br>
> `}`

### If Else Statements

*executes one set of instructions if the statement is true, and executes the other if it's false*

> `if (a > b) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << a << endl;`<br>
> `} else {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << b << endl;`<br>
> `}`

### If Else-If Else Statements

*executes the first set of instructions whose condition is true, executing the else's set if none of them are*

> `if (a > b) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << a << endl;`<br>
> `} else if (a < b) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << b << endl;`<br>
> `} else {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`std::cout << "a == b\n";`<br>
> `}`

### Switch Statements

*uses hashing to execute exactly one set of instructions based on a unique set of cases an input may satisfy*

> `switch (a) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`case 69:`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`cout << "haha funny number\n";`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`break;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`case 420:`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`cout << "weed\n";`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`break;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`default:`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`cout << "boring\n";`<br>
> `}`

## Repetitive Flow

*instructions are repeated based on a given condition*

### While Loops

*a type of pre-test loop where a set of instructions executes until the given condition is false*

> `while (x != 1) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`cout << x << endl;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`if (x % 2 == 0) x /= 2;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`else x = 3 * x + 1;`<br>
> `}`

### Do-While Loops

*a type of post-test loop where a set of instructions executes, then loops until the given condition is false*

> `do {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`cout << x << endl;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`if (x % 2 == 0) x /= 2;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`else x = 3 * x + 1;`<br>
> `} while (x != 1);`

### For Loops

*a special type of while loop reserved for when the programmer knows how many times the set of instructions will run*

> `for (int i = 0; i < 10; i++) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`cout << i << endl;`<br>
> `}`

### For-Each Loops

*a special type of loop used to iterate over a container, presumably to perform an operation using each element*

> `std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};`<br><br>
> `for (int x : nums) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`cout << x << " ** 2 = " << x * x << endl;`<br>
> `}`

# 3.2 - Block Structure & Scope

## Block

*a delimited sequence of statements. usually defined via these: {}*

## Indentation

*a common programming practice where deeper blocks of code are indented via whitespace(s), making the control flow easier to follow. most languages don't require it, but it's psychopathic to completely avoid it*

### Spaces VS Tabs

*an ongoing debate on whether indents should be created via space characters or tab characters. one isn't inherently better than the other, so it's mostly up to your styleguide of choice*

- Pros of Spaces
    - Consistent Across Editors
    - Always Interpreted Correctly (i think)
- Cons of Spaces
    - Larger File Sizes
    - Width of Indent Defined by Author, Not by Reader
- Pros of Tabs
    - Smaller File Sizes
    - Adjustable to Reader Preference
- Cons of Tabs
    - Inconsistent Across Editors
    - May be Intepreted Differently (maybe)

### Never-Nesters

*a subset of programmers who make a conscious effort to limit the level of nesting in their code. this practice usually leads to more readable, concise code*

- **Inversion:** when the main logic of a function is nested inside a bunch of if statements, **invert the conditions** and opt for **early returns** (this moves the main logic to the bottom of the function)
- **Extraction:** when a block has sensibly independent functionality from the code it's nested in, **extract the block** out into **its own function**

## Scope

*where a certain variable, function, or class is defined inside a program*

### Global Scope

*a variable, function, or class is defined for the entire file. pretty dangerous, so don't overuse this*

### Class Scope

*a variable or function is defined inside an entire class*

### Local Scope

*a variable or function is defined only in the block it was defined in and the blocks nested inside it*

### Basic Example

> `// Global Scope`<br>
> `#include <iostream>`<br>
> `#include <string>`<br>
> `#include <math.h>`<br>
> `using namespace std;`<br><br>
> `const double PI = 3.14159;`<br><br>
> `int get_num() {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`string input; // Local Variable`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`cin >> input;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return stoi(input);`<br>
> `}`<br><br>`// This Function Has No Significance`<br>
> `bool foo(int num) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`if (num > 0) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int x = sqrt(num); // x is Local to This If Statement`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`return x > PI; // Comparing Local Variable to Global Variable`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`}`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`if (num < 0) {`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int x = num * num; // x is Local to This If Statement (independent of the earlier if statement)`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`return x < PI;`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`}`<br>
> &nbsp;&nbsp;&nbsp;&nbsp;`return false;`<br>
> `}`

### Memory Allocation

*the code allocates memory for a particular variable while it is in use and deallocates it when it is no longer needed*

<table>
	<th>
		<td>Local Scope</td>
		<td>Global Scope</td>
	</th>
	<tr>
		<td>Memory Allocation</td>
		<td>When the variable enters the scope</td>
		<td>When the program loads</td>
	</tr>
	<tr>
		<td>Memory Deallocation</td>
		<td>When the variable exits the scope</td>
		<td>When the program terminates</td>
	</tr>
	<tr>
		<td>Variable Initialization</td>
		<td>When the variable enters the scope</td>
		<td>When the program loads</td>
	</tr>
</table>