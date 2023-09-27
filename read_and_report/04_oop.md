# 9.1 - Classes & Objects

## Object-Oriented Modeling & Design

*a way of thinking about problems using models organized around real-world concepts. the fundamental construct is the object, which combines both data structure and behavior in a single entity*

### Three Essential Concepts

- Encapsulation
- Inheritance (covered later)
- Polymorphism (covered later)

### Encapsulation

*combines attributes and operations (i.e., data structure and behavior) into an object*

#### Benefits

- **Isolate** and **protect** data from the rest of the program
- **Organize** different sections of code into **human-readable** components
- Allows users to have **minimum knowledge** of implementation details
- Makes **better naming** easier

### Properties of a Class

#### Class vs. Object

A class is often thought of as the blueprint for an object. It serves as an outline for the structure and functionality, but it isn't used directly.

An object is a particular instance of a class. It is initialized with attributes that either the class prescribes or the user defines, which may or may not be mutable. It can also use the methods given to it by the class.

#### Attributes

*values that are inherent qualities of an object. may change from object to object, but their names are prescribed by the class*

#### Operations

*the services an object can provide to the program*

Operations in C++ come in **four flavors**:

1. Constructors & Destructors
2. Accessors (aka getters and setters)
3. Algorithmic
4. Helper

#### Responsibilities

Classes should have fairly minimal responsibilities. Having a class do too many things is a sign that it would make more sense as multiple separate classes.

#### Feature Visibility

Variables, constants, and methods can exist in three levels of visibility. These control how users can access and/or mutate an object.

The public level can be seen and accessed anywhere in the program (so long as the object in question is in scope). Features in this level should be kept simple and only give users the power they need.

The protected level cannot be seen nor accessed by unrelated objects, but classes which inherit from that class can. This has a number of applications that will become apparent in the future.

The private level is only accessible to the class/object itself. Nowhere else in the program is it possible to directly access members in this level. This is especially handy for implementation details and raw data.

### Class Example (no method definitions)

> <code>
> class Time {<br>
> &ensp;private:<br>
> &ensp;&ensp;int hours;<br>
> &ensp;&ensp;int minutes;<br>
> &ensp;&ensp;int seconds;<br>
> <br>
> &ensp;public:<br>
> &ensp;&ensp;Time();<br>
> &ensp;&ensp;Time(int h, int m, int s);<br>
> &ensp;&ensp;Time(int s);<br>
> <br>
> &ensp;&ensp;Time add(Time time);<br>
> &ensp;&ensp;Time* add(Time* time);<br>
> <br>
> &ensp;&ensp;void print();<br>
> &ensp;&ensp;void read();
> </code>
