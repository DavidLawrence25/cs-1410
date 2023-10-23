# 4.1 - Introduction to Pointers

## An Analogy (Shortcuts)

Often, when working with operating systems, it's helpful to access files from locations different from the one they're stored at. Hence, we have shortcuts: tiny little files that bring us to the actual file we're looking for. These shortcuts can be in completely different places and have completely different names, but their functionality is the same.

## Pointer

*a variable that stores the address of another variable in memory*

### Example 1: The `new` Operator

`Complex *z = new Complex(/*a=*/3, /*b=*/4);`

<table>
	<tr>
		<th>Address</th>
		<th>Value</th>
		<th>Variable</th>
	</tr>
	<tr>
		<td>0xA000</td>
		<td>0x00000003</td>
		<td><code>z->a</code></td>
	</tr>
	<tr>
		<td>0xA004</td>
		<td>0x00000004</td>
		<td><code>z->b</code></td>
	</tr>
	<tr>
		<td>...</td>
		<td>...</td>
		<td>...</td>
	</tr>
	<tr>
		<td>0xA100</td>
		<td>0x0000A000</td>
		<td><code>z</code></td>
	</tr>
</table>

### Example 2: Normal Instantiation

`Complex z = {/*a=*/3, /*b=*/4};`

<table>
	<tr>
		<th>Address</th>
		<th>Value</th>
		<th>Variable</th>
	</tr>
	<tr>
		<td>0xA000</td>
		<td>0x00000003</td>
		<td><code>z.a</code></td>
	</tr>
	<tr>
		<td>0xA004</td>
		<td>0x00000004</td>
		<td><code>z.b</code></td>
	</tr>
</table>

# 4.2 - Variables & Memory Addresses

## Random-Access Memory (RAM)

*the dynamically-allocated memory a computer uses for temporary runtime data and storing programs*

### Properties of Memory

1. **Size of RAM** & **Addresses** are **constant** (assuming identical hardware)
2. Data is **aligned** to a specific **number of bytes**, depending on the operating system (usually 4 or 8)
3. The **value** at a given address is **variable**
4. Each **address** corresponds to **one byte in memory**

### Simplified Example

**Size of RAM:** 65,536 Bytes (65.536 KB)

<table>
	<tr>
		<th>Address</th>
		<th>Value</th>
	</tr>
	<tr>
		<td>0x0000</td>
		<td>0xBB513DD9</td>
	</tr>
	<tr>
		<td>0x0004</td>
		<td>0x615D2836</td>
	</tr>
	<tr>
		<td>0x0008</td>
		<td>0xD56AD59F</td>
	</tr>
	<tr>
		<td>0x000C</td>
		<td>0xFDCA6A1D</td>
	</tr>
	<tr>
		<td>0x0010</td>
		<td>0x8726E408</td>
	</tr>
	<tr>
		<td>...</td>
		<td>...</td>
	</tr>
	<tr>
		<td>0xFFFC</td>
		<td>0xB9E4FCEA</td>
	</tr>
</table>

## Variables in Memory

### Defining a Variable

`float pi = 3.1415927;`

<table>
	<tr>
		<th>Address</th>
		<th>Value</th>
		<th>Variable</th>
	</tr>
	<tr>
		<td>0x0000</td>
		<td>0x40490FDB</td>
		<td><code>pi</code></td>
	</tr>
</table>

### Using a Variable

`float tau = pi * 2;`

In the statement above...

- the name `tau` represents an address; it's being used as an **l-value**
- the name `pi` represents the value 0x40490FDB; it's being used as an **r-value**

<table>
	<tr>
		<th>Address</th>
		<th>Value</th>
		<th>Variable</th>
	</tr>
	<tr>
		<td>0x0000</td>
		<td>0x40490FDB</td>
		<td><code>pi</code></td>
	</tr>
	<tr>
		<td>0x0004</td>
		<td>0x40C90FDB</td>
		<td><code>tau</code></td>
	</tr>
</table>

# 4.3 - Pointer Operators

## `new`

*allocates memory on the stack for the instantiated object and returns the corresponding memory address*

> See <a href="#example-1-the-new-operator">4.1/pointers/example-1</a> for an example

## `delete`

*deallocates the memory on the stack used by the now-deleted object*

> <code>
> struct Node {<br>
> &ensp;&ensp;int data;<br>
> &ensp;&ensp;Node *next;<br>
> };<br>
> <br>
> Node *c = new Node(256, nullptr);&ensp;&ensp;// 256 -> null<br>
> Node *b = new Node(69, c);&ensp;&ensp;// 69 -> 256 -> null<br>
> Node *a = new Node(420, b);&ensp;&ensp;// 420 -> 69 -> 256 -> null<br>
> <br>
> b->next = nullptr;&ensp;&ensp;// 420 -> 69 -> null<br>
> delete c;&ensp;&ensp;// c has been forgotten<br>
> </code>

## Accessor (`->`)

*gets a member variable of the object being pointed to*

> <code>
> struct Person {<br>
> &ensp;&ensp;std::string name;<br>
> &ensp;&ensp;int age;<br>
> };<br>
> <br>
> Person john = {"Johnny", 4};<br>
> Person *my_finger = &john;<br>
> <br>
> // My finger is pointing at 4-year-old Johnny over there.\n<br>
> std::cout << "My finger is pointing at " << my_finger->age << "-year-old " << my_finger->name << " over there.\n";
> </code>

## Pointer Definer (`*`)

*defines a pointer*

> `int *pointer;`

## Dereference Operator (`*`)

*returns the object that the pointer is pointing to*

> `std::cout << "pointer is pointing to " << *pointer << '\n';`

## Address of Operator (`&`)

*returns the address of an object*

> `std::cout << "x is stored at " << &x << '\n';`
