# 5.1 - Data Structures

## Data Structures

*containers for storing, organizing, transporting, and accessing data*

## Type Specifiers

*a name that uniquely identifies a data type*

### Built-In Types

- boolean (`bool`)
- integer (`int` & `char`)
- floating-point number (`float` & `double`)

### Programmer-Created Types

- `Foo`
- `Bar`
- `Baz`
- literally anything you want

## Aggregate Data

*a named container that can hold a group of related values, made via structures, classes, and/or arrays*

# 5.2 - Enumerations

## Enumeration

*a collection of symbolic constants*

## Constants

*a constant value with a name*

### Ways to Define Constants (in C++)

- `#define kNumberOfStudents 100`
- `const int kNumberOfStudents = 100;`
- `enum { kNumberOfStudents = 100 };`

### Advantages

- Provides **short-hand names** for **long values**
- Makes code **self-documenting** (assuming the constant is well-named)
- Makes code **more adaptable** and **reusable**

## `enum` Syntax

> <code>
> enum &lt;class | struct&gt; &lt;name&gt; &lt;: data type&gt; {<br>
> &ensp;&ensp;kConstant0 &lt;= value&gt;,<br>
> &ensp;&ensp;kConstant1 &lt;= value&gt;,<br>
> &ensp;&ensp;...<br>
> } &lt;variable list (extremely uncommon)&gt;;
> </code>

### Examples

#### Eliminating "Magic Numbers"

> <code>
> enum { kQuit, kSearch, kInput, kImport, kHelp };<br>
> <br>
> int command = get_command();<br>
> <br>
> switch (command) {<br>
> &ensp;&ensp;case kQuit:<br>
> &ensp;&ensp;&ensp;&ensp;exit(0);<br>
> &ensp;&ensp;case kSearch:<br>
> &ensp;&ensp;&ensp;&ensp;search(person_file, index_file);<br>
> &ensp;&ensp;&ensp;&ensp;break;<br>
> &ensp;&ensp;case kInput:<br>
> &ensp;&ensp;&ensp;&ensp;input();<br>
> &ensp;&ensp;&ensp;&ensp;break;<br>
> &ensp;&ensp;case kImport:<br>
> &ensp;&ensp;&ensp;&ensp;import(person_file, index_file);<br>
> &ensp;&ensp;&ensp;&ensp;break;<br>
> &ensp;&ensp;case kHelp:<br>
> &ensp;&ensp;&ensp;&ensp;help();<br>
> &ensp;&ensp;&ensp;&ensp;break;<br>
> &ensp;&ensp;default:<br>
> &ensp;&ensp;&ensp;&ensp;cerr &gt;&gt; "Unknown command\n";<br>
> &ensp;&ensp;&ensp;&ensp;break;<br>
> }
> </code>

#### Naming Special Values

> <code>
> enum {<br>
> &ensp;&ensp;kURead = 1;&ensp;&ensp;&ensp;&ensp;&ensp;// 000 000 001<br>
> &ensp;&ensp;kUWrite = 2;&ensp;&ensp;&ensp;&ensp;// 000 000 010<br>
> &ensp;&ensp;kUExe = 4;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// 000 000 100<br>
> &ensp;&ensp;kGRead = 8;&ensp;&ensp;&ensp;&ensp;&ensp;// 000 001 000<br>
> &ensp;&ensp;kGWrite = 16;&ensp;&ensp;&ensp;// 000 010 000<br>
> &ensp;&ensp;kGExe = 32;&ensp;&ensp;&ensp;&ensp;&ensp;// 000 100 000<br>
> &ensp;&ensp;kORead = 64;&ensp;&ensp;&ensp;&ensp;// 001 000 000<br>
> &ensp;&ensp;kOWrite = 128;&ensp;&ensp;// 010 000 000<br>
> &ensp;&ensp;kOExe = 256;&ensp;&ensp;&ensp;&ensp;// 100 000 000<br>
> };
> </code>

# 5.3 - Structures

## Structure Specification: Fields & Members

> <code>
> struct Student {<br>
> &ensp;&ensp;int id;<br>
> &ensp;&ensp;std::string name;<br>
> &ensp;&ensp;double gpa;<br>
> };
> </code>

## Structure Definition & Objects

*Note: I'm copying and pasting this paragraph because I like the simile it uses.*

We can use a blueprint as another metaphor for a structure. Blueprints show essential details like the number and size of bedrooms. Similarly, structure specifications show the number, type, name, and order of the structure fields. Nevertheless, a blueprint isn't a house, and you can't live in it. However, given the blueprint, we can make as many identical houses as we wish, and while each one looks like the others, it has a different, distinct set of occupants and a distinct street address. Similarly, each object created from a structure specification looks like the others, but each can store distinct values, and each has a distinct memory address.

### Automatic Definition

*the structs are defined and allocated on the stack*

> <code>
> Student alice;<br>
> Student bob;<br>
> Student charlie;
> </code>

### Dynamic Allocation

*the pointers are defined and allocated automatically on the stack, but the structs they point to are allocated dynamically on the heap*

> <code>
> Student *david = new Student;<br>
> Student *ella = new Student;<br>
> Student *faith = new Student;
> </code>

### Initializing Structures & Fields

#### Inherited from C

> <code>
> Student alice = { 123, "alice", 3.0 };<br>
> Student bob = { 456, "bob", 4.0 };<br>
> Student charlie = { 789, "charlie", 2.0 };
> </code>

#### ANSI 2020

> <code>
> Student alice { 123, "alice", 3.0 };<br>
> Student bob { 456, "bob", 4.0 };<br>
> Student charlie { 789, "charlie", 2.0 };
> </code>

#### ANSI 2015

> <code>
> Student charlie;<br>
> ...<br>
> charlie = { 789, "charlie", 2.0 };
> </code>

### Field Selection: The Dot & Arrow Operators

#### The Dot Operator

*when the field is a value*

> <code>
> Student alice = { 123, "alice", 3.0 };<br>
> std::cout &lt;&lt; alice.id &lt;&lt; ": " &lt;&lt; alice.name &lt;&lt; "(GPA = " &lt;&lt; alice.gpa &lt;&lt; ")\n"<br>
> alice.gpa = 3.7;
> </code>

#### The Arrow Operator

*when the field is a pointer (example doesn't count)*

> <code>
> Student alice = { 123, "alice", 3.0 };<br>
> std::cout &lt;&lt; alice-&gt;id &lt;&lt; ": " &lt;&lt; alice-&gt;name &lt;&lt; "(GPA = " &lt;&lt; alice-&gt;gpa &lt;&lt; ")\n"<br>
> alice-&gt;gpa = 3.7;
> </code>

## Moving Structures Within a Program

### Assignment

*copying an existing structure to another variable*

> <code>
> Student alice = { 123, "alice", 3.0 };<br>
> ...<br>
> Student alices_clone;<br>
> alices_clone = alice;
> </code>

### Function Argument

*passing a structure into a function as an argument*

> <code>
> void print(Student temp) {<br>
> &ensp;&ensp;std::cout &lt;&lt; "ID:&ensp;&ensp;&ensp;" &lt;&lt; temp.id &lt;&lt; '\n';<br>
> &ensp;&ensp;std::cout &lt;&lt; "Name: " &lt;&lt; temp.name &lt;&lt; '\n';<br>
> &ensp;&ensp;std::cout &lt;&lt; "GPA:&ensp;&ensp;" &lt;&lt; temp.gpa &lt;&lt; '\n';<br>
> }<br>
> ...<br>
> print(bob);
> </code>

### Function Return Value

*returning a structure from a function*

> <code>
> Student read() {<br>
> &ensp;&ensp;Student temp;<br>
> <br>
> &ensp;&ensp;std::cout &gt;&gt; "Enter a student ID: ";<br>
> &ensp;&ensp;std::cin &lt;&lt; temp.id;<br>
> &ensp;&ensp;std::cout &gt;&gt; "Enter a student name: ";<br>
> &ensp;&ensp;std::cin &lt;&lt; temp.name;<br>
> &ensp;&ensp;std::cout &gt;&gt; "Enter a student GPA: ";<br>
> &ensp;&ensp;std::cin &lt;&lt; temp.gpa;<br>
> <br>
> &ensp;&ensp;return temp;<br>
> }<br>
> ...<br>
> Student student0 = read();
> </code>
