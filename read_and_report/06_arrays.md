# 7.1 - Introduction to Arrays

## Array

*an aggregate data type that stores elements of the same data type in a specified order*

### Defining an Array: `type array_name[size];`

- `type`: the type of the elements stored in the array
- `array_name`: the name of the array
- `size`: how many elements the array can hold

### Accessing Elements: `array_name[index]`

- `array_name`: the name of the array
- `index`: where in the array to look (first element is at index 0)

## Arrays vs. Structs

<table>
	<tr>
		<td></td>
		<td>Arrays</td>
		<td>Structs</td>
	</tr>
	<tr>
		<td>Contained Data</td>
		<td>All elements are the same type</td>
		<td>Fields or elements may be different types</td>
	</tr>
	<tr>
		<td>Specification</td>
		<td>N/A</td>
		<td>
			<code>
				struct Part {<br>
				&ensp;&ensp;int code;<br>
				&ensp;&ensp;double cost;<br>
				};
			</code>
		</td>
	</tr>
	<tr>
		<td>Definition</td>
		<td>
			<code>int arr[10];</code>
			<br>
			10 = size of the array
		</td>
		<td><code>Part widget;</code></td>
	</tr>
	<tr>
		<td>Element Access</td>
		<td>
			By index or subscript
			<br>
			<code>arr[5]</code>
			<br>
			Selection operator = []
		</td>
		<td>
			By name
			<br>
			<code>widget.cost</code>
			<br>
			Selection operator = .
		</td>
	</tr>
</table>

# 7.2 - Visualizing Arrays

## One-Dimensional (1D) Arrays

`int test[10];`

<table>
	<tr>
		<td>Index</td>
		<td>0</td>
		<td>1</td>
		<td>2</td>
		<td>3</td>
		<td>4</td>
		<td>5</td>
		<td>6</td>
		<td>7</td>
		<td>8</td>
		<td>9</td>
	</tr>
	<tr>
		<td>Element</td>
		<td>41</td>
		<td>97</td>
		<td>91</td>
		<td>89</td>
		<td>89</td>
		<td>100</td>
		<td>76</td>
		<td>83</td>
		<td>91</td>
		<td>79</td>
	</tr>
</table>

## Two-Dimensional (2D) Arrays

`int test_scores [10][4];`

<table>
	<tr>
		<td></td>
		<td>0</td>
		<td>1</td>
		<td>2</td>
		<td>3</td>
		<td>4</td>
		<td>5</td>
		<td>6</td>
		<td>7</td>
		<td>8</td>
		<td>9</td>
	</tr>
	<tr>
		<td>0</td>
		<td>41</td>
		<td>97</td>
		<td>91</td>
		<td>89</td>
		<td>89</td>
		<td>100</td>
		<td>76</td>
		<td>83</td>
		<td>91</td>
		<td>79</td>
	</tr>
	<tr>
		<td>1</td>
		<td>54</td>
		<td>92</td>
		<td>95</td>
		<td>86</td>
		<td>88</td>
		<td>97</td>
		<td>81</td>
		<td>69</td>
		<td>87</td>
		<td>83</td>
	</tr>
	<tr>
		<td>2</td>
		<td>65</td>
		<td>97</td>
		<td>99</td>
		<td>90</td>
		<td>84</td>
		<td>100</td>
		<td>74</td>
		<td>89</td>
		<td>95</td>
		<td>84</td>
	</tr>
	<tr>
		<td>3</td>
		<td>73</td>
		<td>96</td>
		<td>100</td>
		<td>91</td>
		<td>82</td>
		<td>99</td>
		<td>76</td>
		<td>82</td>
		<td>98</td>
		<td>87</td>
	</tr>
</table>

## Three-Dimensional (3D) Arrays

`int class_score[5][5][5];`

I can't really do this in Markdown, but it's a rectangular prism.

## Higher-Dimensional Arrays

`int weird_array[3][5][2][7][10][4][15];`

These cannot be intuitively visualized, and going higher than 3D is seldom practical anyway. You'd probably want a structure or class at this point.

# 7.3 - Creating Arrays

## The Name of an Array is an Address

*the name of an array is a constant pointer to the array in memory*

### Assigning to a Pointer Variable

When a pointer is assigned to an array, the contents of the array are not copied to the pointer variable. Instead, both `scores` and `p2` point to the same array in memory.

> <code>
> int scores[50];<br>
> int* p2 = scores;
> </code>

### Accessing Elements

The square brackets `[]` form the indexing operator, which allows the compiler to locate a specific element in the array by computing an offset from the address stored in the pointer.

> `scores[i]` => `scores + i * sizeof(int)`

### Usage of the Address Operator (`&`)

The ampersand (`&`) is redundant when passing an array into a function because the name of the array is already an address.

> <code>
> void function(int *array) {...}&ensp;&ensp;// definition<br>
> function(scores);&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// call
> </code>

## Automatic & Dynamic Arrays

### Automatic Arrays

> `int scores1[50];`

- Memory automatically allocated on the stack upon definition
- Memory automatically deallocated from the stack once it leaves the scope

### Dynamic Arrays

> <code>
> int *scores2 = new int[50];<br>
> ...<br>
> delete[] scores2;&ensp;&ensp;// Deallocates the memory used on the heap
> </code>

<br>

- `new` allocates a block of memory on the **heap** for the array and returns the starting address
- The pointer `scores2` stores the **starting address** from `new`
- Will create a **memory leak** if it fails to deallocate the heap memory before `scores2` leaves the scope
- Square brackets are used on the `delete` statement to signify that the array itself is being deallocated, not just the pointer `scores2`.

## Specifying Array Sizes

### Automatic Arrays

The size must be a compiler-time constant, which can be one of these four things:

1. a numeric literal: `100`
2. a macro: `#define SIZE 100`
3. an enum: `enum { SIZE = 100 };`
4. a constant: `const int SIZE = 100;`

### Dynamic Arrays

The size can also be a compiler-time constant, but because the size doesn't need to be known at compile-time, ordinary variables can be used as well.

## Size vs. Capacity

**Capacity:** how much data an array can hold (use for storing data)

**Size:** how much data an array is actually holding (use for accessing data)
