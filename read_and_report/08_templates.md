# 13.2 - Template Functions

In everyday life, a template is a model that can be used and reused for similar (but distinct) purposes. Software like Microsoft Word has a library of templates for common types of documents that look good. They lift the burden of graphic design away from the user so they can focus on the writing. Templates in C++ work in a roughly equivalent manner.

## The Problem

Let's say you are trying to write a function to find the maximum of some vector of numbers. You know that your users might pass in integers, floats, and doubles, so you write this:

> <code>
> double max_of(vector&lt;double&gt; numbers);<br>
> float max_of(vector&lt;float&gt; numbers);<br>
> int max_of(vector&lt;int&gt; numbers);
> </code>

<br>

Obviously, this is super repetitive. Not only is the type in question written twice per function declaration, but the implementation for each one would look nearly identical.

## Using Templates with Functions

The function described above can be rewritten like so:

> <code>
> template &lt;typename Number&gt;<br>
> Number max_of(vector&lt;Number&gt; numbers);
> </code>

<br>

This is much cleaner. We have exactly one declaration and definition of the function, and its purpose is still very clear. This isn't without its costs, however.

## Downsides of Templates

Although templates are great, they bring a decent number of issues to the table that need to be taken into consideration.

### They Allow All Types

The point of a template is to allow a bit of code to dynamically type symbols. This is great and all, but it also means that the code will accept any type; not just the ones that make sense.

If your function doesn't rely on type-specific methods, it may end up working out; however, this often won't be the case. Maybe a user decides to pass a `vector` of `string`s into our `max_of` function, and now the code has to decide what it means for one `string` to be "greater than" another.

This won't necessarily increase the number of errors your code will throw, as it would throw an error anyway if you tried to pass a `string` into a non-templated function that was expecting an integer, but it does make static analysis much harder.

### They Complicate Compilation

Templated code inherently makes compliation harder. Usually, the compiler can instantly assign a type to a symbol, and if it can't, it throws an error. If templates are involved, the compiler has to wait to compile that code until it finds all instances of it in the program. Then, it must compile a version of the templated code for each type we use it on.

### Prevent Easy Separation of Declarations & Definitions

When writing code to be reused, it's common practice to separate declarations and definitions into header and implementation files respectively. That way, users of the code only have to focus on what they can call, not what the code does under the hood. Additionally, this allows the authors to make their implementation closed-source while still allowing others to use their code.

With templates, however, this is not as simple. Without going too deep into the technical details, there must be a statement including the implementation file at the end of the header file for it to compile correctly. Alternatively (and more commonly), you could just put the definitions in the header file, but this partially defeats the purpose of separating them in the first place.

# 13.3 - Template Classes & Structs

You may have noticed that I do not refer to code that uses templates as "templated functions". This is because, although functions can be templated, they aren't the only things that have this ability. Classes and structures are also capable of using templates.

## Containers & Collections

The usefulness of a templated class or structure is less clear than it was for functions. Usually, you would want to know exactly what type of data you store in your objects. There is one group of structures that make complete sense for templates, though: containers.

The built-in `vector` makes ample use of templates. It would be a huge pain if you had to write a version of the container for every type you might want to store in it. This is especially true when considering user-defined types, as the standard library has no way of knowing what structures and classes you might create.

## Using Templates with Structures

Consider a simple `Node` structure that simply stores some data and a pointer to another `Node`. Instead of making a different type of `Node` for every data type we store in it, we could just do this:

> <code>
> template &lt;typename T&gt;<br>
> struct Node {<br>
> &ensp;&ensp;T data;<br>
> &ensp;&ensp;Node *next;<br>
> };<br>
> <br>
> // Later on in the program...<br>
> Node&lt;int&gt; head = {69, nullptr};
> </code>

<br>

To the right of the type name `Node`, we put the type we're using for the template in angle brackets. If we were using a structure with multiple types in its template, we would just separate the types in the angle brackets by a comma.

## Constant Value Expressions

Similar to how default arguments work for functions, templates can have default constants. Consider this example (adjusted from the textbook) of a `Stack`:

> <code>
> template &lt;typename T, size_t kCapacity = 100&gt;<br>
> class Stack {<br>
> &ensp;public:<br>
> &ensp;&ensp;size_t size();<br>
> <br>
> &ensp;&ensp;void Push(T data);<br>
> &ensp;&ensp;T Pop();<br>
> &ensp;&ensp;T Peek();<br>
> <br>
> &ensp;private:<br>
> &ensp;&ensp;T items_[kCapacity];<br>
> &ensp;&ensp;size_t size_ = 0;<br>
> };
> </code>

<br>

If we like the capacity of our `Stack` as is, we could simply ignore it when declaring instances of it. This will create a `Stack` with the default capacity of `100`:

> `Stack<int> stack0;`

If we decide we need a `Stack` with a capacity of `1000` instead of `100`, we can just do this:

> `Stack<int, 1000> stack1;`
