# Google C++ Style Guide

## Table of Contents

<table>
	<tr>
		<td><a>C++ Version</a></td>
		<td></td>
	</tr>
	<tr>
		<td><a>Header Files</a></td>
		<td>
			<ul>
				<li><a>Self-Contained Headers</a></li>
				<li><a>The #define Guard</a></li>
				<li><a>Include What You Use</a></li>
				<li><a>Forward Declarations</a></li>
				<li><a>Inline Functions</a></li>
				<li><a>Names and Order of Includes</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Scoping</a></td>
		<td>
			<ul>
				<li><a>Namespaces</a></li>
				<li><a>Internal Linkage</a></li>
				<li><a>Nonmember, Static Member, and Global Functions</a></li>
				<li><a>Local Variables</a></li>
				<li><a>Static and Global Variables</a></li>
				<li><a>thread_local Variables</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Classes</a></td>
		<td>
			<ul>
				<li><a>Doing Work in Constructors</a></li>
				<li><a>Implicit Conversions</a></li>
				<li><a>Copyable and Movable Types</a></li>
				<li><a>Structs vs. Classes</a></li>
				<li><a>Structs vs. Pairs and Tuples</a></li>
				<li><a>Inheritance</a></li>
				<li><a>Operator Overloading</a></li>
				<li><a>Access Control</a></li>
				<li><a>Declaration Order</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Functions</a></td>
		<td>
			<ul>
				<li><a>Inputs and Outputs</a></li>
				<li><a>Write Short Functions</a></li>
				<li><a>Function Overloading</a></li>
				<li><a>Default Arguments</a></li>
				<li><a>Trailing Return Type Syntax</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Google-Specific Magic</a></td>
		<td>
			<ul>
				<li><a>Ownership and Smart Pointers</a></li>
				<li><a>cpplint</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Other C++ Features</a></td>
		<td>
			<ul>
				<li><a>Rvalue References</a></li>
				<li><a>Friends</a></li>
				<li><a>Exceptions</a></li>
				<li><a>noexcept</a></li>
				<li><a>Run-Time Type Information</a></li>
				<li><a>Casting</a></li>
				<li><a>Streams</a></li>
				<li><a>Preincrement and Predecrement</a></li>
				<li><a>Use of const</a></li>
				<li><a>Use of constexpr</a></li>
				<li><a>Integer Types</a></li>
				<li><a>64-Bit Portability</a></li>
				<li><a>Preprocessor Macros</a></li>
				<li><a>0 and nullptr/NULL</a></li>
				<li><a>sizeof</a></li>
				<li><a>Type Deduction (including auto)</a></li>
				<li><a>Class Template Argument Deduction</a></li>
				<li><a>Designated Initializers</a></li>
				<li><a>Lambda Expressions</a></li>
				<li><a>Template Metaprogramming</a></li>
				<li><a>Boost</a></li>
				<li><a>Other C++ Features</a></li>
				<li><a>Nonstandard Extensions</a></li>
				<li><a>Aliases</a></li>
				<li><a>Switch Statements</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Inclusive Language</a></td>
		<td></td>
	</tr>
	<tr>
		<td><a>Naming</a></td>
		<td>
			<ul>
				<li><a>General Naming Rules</a></li>
				<li><a>File Names</a></li>
				<li><a>Type Names</a></li>
				<li><a>Variable Names</a></li>
				<li><a>Constant Names</a></li>
				<li><a>Function Names</a></li>
				<li><a>Namespace Names</a></li>
				<li><a>Enumerator Names</a></li>
				<li><a>Macro Names</a></li>
				<li><a>Exceptions to Naming Rules</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Comments</a></td>
		<td>
			<ul>
				<li><a>Comment Style</a></li>
				<li><a>File Comments</a></li>
				<li><a>Class Comments</a></li>
				<li><a>Function Comments</a></li>
				<li><a>Variable Comments</a></li>
				<li><a>Implementation Comments</a></li>
				<li><a>Punctuation, Spelling, and Grammar</a></li>
				<li><a>TODO Comments</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Formatting</a></td>
		<td>
			<ul>
				<li><a>Line Length</a></li>
				<li><a>Non-ASCII Characters</a></li>
				<li><a>Spaces vs. Tabs</a></li>
				<li><a>Function Declarations and Definitions</a></li>
				<li><a>Lambda Expressions</a></li>
				<li><a>Floating-Point Literals</a></li>
				<li><a>Function Calls</a></li>
				<li><a>Braced Initializer List Format</a></li>
				<li><a>Looping and Branching Statements</a></li>
				<li><a>Pointer and Reference Expressions</a></li>
				<li><a>Boolean Expressions</a></li>
				<li><a>Return Values</a></li>
				<li><a>Variable and Array Initialization</a></li>
				<li><a>Preprocessor Directives</a></li>
				<li><a>Class Format</a></li>
				<li><a>Constructor Initializer Lists</a></li>
				<li><a>Namespace Formatting</a></li>
				<li><a>Horizontal Whitespace</a></li>
				<li><a>Vertical Whitespace</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a>Exceptions to the Rules</a></td>
		<td>
			<ul>
				<li><a>Existing Non-Conformant Code</a></li>
				<li><a>Windows Code</a></li>
			</ul>
		</td>
	</tr>
</table>

## Background

C++ is one of the main development languages used by many of Google's open-source projects. As every C++ programmer knows, the language has many powerful features, but this power brings with it complexity, which in turn can make code more bug-prone and harder to read and maintain.

The goal of this guide is to manage this complexity by describing in detail the dos and don'ts of writing C++ code. These rules exist to keep the code base manageable while still allowing coders to use C++ language features productively.

Style, also known as readability, is what we call the conventions that govern our C++ code. The term Style is a bit of a misnomer, since these conventions cover far more than just source file formatting.

Most open-source projects developed by Google conform to the requirements in this guide.

Note that this guide is not a C++ tutorial: we assume that the reader is familiar with the language.

### Goals of the Style Guide

Why do we have this document?

There are a few core goals that we believe this guide should serve. These are the fundamental whys that underlie all of the individual rules. By bringing these ideas to the fore, we hope to ground discussions and make it clearer to our broader community why the rules are in place and why particular decisions have been made. If you understand what goals each rule is serving, it should be clearer to everyone when a rule may be waived (some can be), and what sort of argument or alternative would be necessary to change a rule in the guide.

The goals of the style guide as we currently see them are as follows:

#### Style rules should pull their weight

The benefit of a style rule must be large enough to justify asking all of our engineers to remember it. The benefit is measured relative to the codebase we would get without the rule, so a rule against a very harmful practice may still have a small benefit if people are unlikely to do it anyway. This principle mostly explains the rules we don’t have, rather than the rules we do: for example, goto contravenes many of the following principles, but is already vanishingly rare, so the Style Guide doesn’t discuss it.

#### Optimize for the reader, not the writer

Our codebase (and most individual components submitted to it) is expected to continue for quite some time. As a result, more time will be spent reading most of our code than writing it. We explicitly choose to optimize for the experience of our average software engineer reading, maintaining, and debugging code in our codebase rather than ease when writing said code. "Leave a trace for the reader" is a particularly common sub-point of this principle: When something surprising or unusual is happening in a snippet of code (for example, transfer of pointer ownership), leaving textual hints for the reader at the point of use is valuable (std::unique_ptr demonstrates the ownership transfer unambiguously at the call site).

#### Be consistent with existing code
Using one style consistently through our codebase lets us focus on other (more important) issues. Consistency also allows for automation: tools that format your code or adjust your #includes only work properly when your code is consistent with the expectations of the tooling. In many cases, rules that are attributed to "Be Consistent" boil down to "Just pick one and stop worrying about it"; the potential value of allowing flexibility on these points is outweighed by the cost of having people argue over them. However, there are limits to consistency; it is a good tie breaker when there is no clear technical argument, nor a long-term direction. It applies more heavily locally (per file, or for a tightly-related set of interfaces). Consistency should not generally be used as a justification to do things in an old style without considering the benefits of the new style, or the tendency of the codebase to converge on newer styles over time.

#### Be consistent with the broader C++ community when appropriate

Consistency with the way other organizations use C++ has value for the same reasons as consistency within our code base. If a feature in the C++ standard solves a problem, or if some idiom is widely known and accepted, that's an argument for using it. However, sometimes standard features and idioms are flawed, or were just designed without our codebase's needs in mind. In those cases (as described below) it's appropriate to constrain or ban standard features. In some cases we prefer a homegrown or third-party library over a library defined in the C++ Standard, either out of perceived superiority or insufficient value to transition the codebase to the standard interface.

#### Avoid surprising or dangerous constructs

C++ has features that are more surprising or dangerous than one might think at a glance. Some style guide restrictions are in place to prevent falling into these pitfalls. There is a high bar for style guide waivers on such restrictions, because waiving such rules often directly risks compromising program correctness.

#### Avoid constructs that our average C++ programmer would find tricky or hard to maintain

C++ has features that may not be generally appropriate because of the complexity they introduce to the code. In widely used code, it may be more acceptable to use trickier language constructs, because any benefits of more complex implementation are multiplied widely by usage, and the cost in understanding the complexity does not need to be paid again when working with new portions of the codebase. When in doubt, waivers to rules of this type can be sought by asking your project leads. This is specifically important for our codebase because code ownership and team membership changes over time: even if everyone that works with some piece of code currently understands it, such understanding is not guaranteed to hold a few years from now.

#### Be mindful of our scale

With a codebase of 100+ million lines and thousands of engineers, some mistakes and simplifications for one engineer can become costly for many. For instance it's particularly important to avoid polluting the global namespace: name collisions across a codebase of hundreds of millions of lines are difficult to work with and hard to avoid if everyone puts things into the global namespace.

#### Concede to optimization when necessary

Performance optimizations can sometimes be necessary and appropriate, even when they conflict with the other principles of this document.

	The intent of this document is to provide maximal guidance with reasonable restriction. As always, common sense and good taste should prevail. By this we specifically refer to the established conventions of the entire Google C++ community, not just your personal preferences or those of your team. Be skeptical about and reluctant to use clever or unusual constructs: the absence of a prohibition is not the same as a license to proceed. Use your judgment, and if you are unsure, please don't hesitate to ask your project leads to get additional input.

## C++ Version

Currently, code should target C++17, i.e., should not use C++2x features, with the exception of designated initializers. The C++ version targeted by this guide will advance (aggressively) over time.

Do not use non-standard extensions.

Consider portability to other environments before using features from C++14 and C++17 in your project.

## Header Files

In general, every `.cc` file should have an associated `.h` file. There are some common exceptions, such as unit tests and small `.cc` files containing just a `main()` function.

Correct use of header files can make a huge difference to the readability, size and performance of your code.

The following rules will guide you through the various pitfalls of using header files.

### Self-Contained Headers

Header files should be self-contained (compile on their own) and end in `.h`. Non-header files that are meant for inclusion should end in .inc and be used sparingly.

All header files should be self-contained. Users and refactoring tools should not have to adhere to special conditions to include the header. Specifically, a header should have header guards and include all other headers it needs.

When a header declares inline functions or templates that clients of the header will instantiate, the inline functions and templates must also have definitions in the header, either directly or in files it includes. Do not move these definitions to separately included header (`-inl.h`) files; this practice was common in the past, but is no longer allowed. When all instantiations of a template occur in one `.cc` file, either because they're explicit or because the definition is accessible to only the `.cc` file, the template definition can be kept in that file.

There are rare cases where a file designed to be included is not self-contained. These are typically intended to be included at unusual locations, such as the middle of another file. They might not use header guards, and might not include their prerequisites. Name such files with the `.inc` extension. Use sparingly, and prefer self-contained headers when possible.

### The `#define` Guard

All header files should have `#define` guards to prevent multiple inclusion. The format of the symbol name should be `<PROJECT>_<PATH>_<FILE>_H_`.

To guarantee uniqueness, they should be based on the full path in a project's source tree. For example, the file `foo/src/bar/baz.h` in project `foo` should have the following guard:

> <code>
> #ifndef FOO_BAR_BAZ_H_<br>
> #define FOO_BAR_BAZ_H_<br>
> ...<br>
> #endif // FOO_BAR_BAZ_H_
> </code>

### Include What You Use

If a source or header file refers to a symbol defined elsewhere, the file should directly include a header file which properly intends to provide a declaration or definition of that symbol. It should not include header files for any other reason.

Do not rely on transitive inclusions. This allows people to remove no-longer-needed `#include` statements from their headers without breaking clients. This also applies to related headers - `foo.cc` should include `bar.h` if it uses a symbol from it even if `foo.h` includes `bar.h`.

### Forward Declarations

Avoid using forward declarations where possible. Instead, include the headers you need.

**Definition:**

A "forward declaration" is a declaration of an entity without an associated definition.

> <code>
> // In a C++ source file:<br>
> class B;<br>
> void FuncInB();<br>
> extern int variable_in_b;<br>
> ABSL_DECLARE_FLAG(flag_in_b);
> </code>

<br>

**Pros:**

- Forward declarations can save compile time, as `#include`s force the compiler to open more files and process more input.

- Forward declarations can save on unnecessary recompilation. `#include`s can force your code to be recompiled more often, due to unrelated changes in the header.

**Cons:**

- Forward declarations can hide a dependency, allowing user code to skip necessary recompilation when headers change.

- A forward declaration as opposed to an `#include` statement makes it difficult for automatic tooling to discover the module defining the symbol.

- A forward declaration may be broken by subsequent changes to the library. Forward declarations of functions and templates can prevent the header owners from making otherwise-compatible changes to their APIs, such as widening a parameter type, adding a template parameter with a default value, or migrating to a new namespace.

- Forward declaring symbols from namespace `std::` yields undefined behavior.

- It can be difficult to determine whether a forward declaration or a full `#include` is needed. Replacing an `#include` with a forward declaration can silently change the meaning of code:

	> <code>
	> // b.h:<br>
	> struct B {};<br>
	> struct D : B {};<br><br>
	> // good_user.cc:<br>
	> #include "b.h"<br>
	> void f(B*);<br>
	> void f(void*);<br>
	> void test(D* x) { f(x); } // Calls f(B*)<br>
	> </code>

	If the `#include` was replaced with forward decls for `B` and `D`, `test()` would call `f(void*)`.

- Forward declaring multiple symbols from a header can be more verbose than simply `#include`ing the header.

- Structuring code to enable forward declarations (e.g., using pointer members instead of object members) can make the code slower and more complex.

**Decision:**

Try to avoid forward declarations of entities defined in another project.

### Inline Functions

Define functions inline only when they are small, say, 10 lines or fewer.

**Definition:**

You can declare functions in a way that allows the compiler to expand them inline rather than calling them through the usual function call mechanism.

**Pros:**

Inlining a function can generate more efficient object code, as long as the inlined function is small. Feel free to inline accessors and mutators, and other short, performance-critical functions.

**Cons:**

Overuse of inlining can actually make programs slower. Depending on a function's size, inlining it can cause the code size to increase or decrease. Inlining a very small accessor function will usually decrease code size while inlining a very large function can dramatically increase code size. On modern processors smaller code usually runs faster due to better use of the instruction cache.

**Decision:**

A decent rule of thumb is to not inline a function if it is more than 10 lines long. Beware of destructors, which are often longer than they appear because of implicit member- and base-destructor calls!

Another useful rule of thumb: it's typically not cost effective to inline functions with loops or switch statements (unless, in the common case, the loop or switch statement is never executed).

It is important to know that functions are not always inlined even if they are declared as such; for example, virtual and recursive functions are not normally inlined. Usually recursive functions should not be inline. The main reason for making a virtual function inline is to place its definition in the class, either for convenience or to document its behavior, e.g., for accessors and mutators.

### Names and Order of Includes

Include headers in the following order:

1. Related Header
2. C System Headers
3. C++ Standard Library Headers
4. Other Libraries' Headers
5. Your Project's Headers

All of a project's header files should be listed as descendants of the project's source directory without use of UNIX directory aliases . (the current directory) or .. (the parent directory). For example, `google-awesome-project/src/base/logging.h` should be included as:

> <code>
> #include "base/logging.h"
> </code>

<br>

In `dir/foo.cc` or `dir/foo_test.cc`, whose main purpose is to implement or test the stuff in `dir2/foo2.h`, order your includes as follows:

1. `dir2/foo2.h`
2. A Blank Line
3. C System Headers (more precisely: headers in angle brackets with the `.h` extension), e.g., `<unistd.h>`, `<stdlib.h>`
4. A Blank Line
5. C++ Standard Library Headers (without file extension), e.g., `<algorithm>`, `<cstddef>`
6. A Blank Line
7. Other Libraries' `.h` Files
8. A Blank Line
9. Your Project's `.h` Files

Separate each non-empty group with one blank line.

With the preferred ordering, if the related header `dir2/foo2.h` omits any necessary includes, the build of `dir/foo.cc` or `dir/foo_test.cc` will break. Thus, this rule ensures that build breaks show up first for the people working on these files, not for innocent people in other packages.

`dir/foo.cc` and `dir2/foo2.h` are usually in the same directory (e.g., `base/basictypes_test.cc` and `base/basictypes.h`), but may sometimes be in different directories too.

Note that the C headers such as `stddef.h` are essentially interchangeable with their C++ counterparts (`cstddef`). Either style is acceptable, but prefer consistency with existing code.

Within each section the includes should be ordered alphabetically. Note that older code might not conform to this rule and should be fixed when convenient.

For example, the includes in `google-awesome-project/src/foo/internal/fooserver.cc` might look like this:

> <code>
> #include "foo/server/fooserver.h"<br>
> <br>
> #include &lt;sys/types.h&gt;`<br>
> #include &lt;unistd.h&gt;<br>
> <br>
> #include &lt;string&gt;<br>
> #include &lt;vector&gt;<br>
> <br>
> #include "base/basictypes.h"<br>
> #include "foo/server/bar.h"<br>
> #include "third_party/absl/flags/flag.h"
> </code>

<br>

**Exception:**

Sometimes, system-specific code needs conditional includes. Such code can put conditional includes after other includes. Of course, keep your system-specific code small and localized. Example:

> <code>
> #include "foo/public/fooserver.h"<br>
> <br>
> #include "base/port.h"&ensp;&ensp;// For LANG_CXX11.<br>
> <br>
> #ifdef LANG_CXX11<br>
> #include &lt;initializer_list&gt;<br>
> #endif&ensp;&ensp;// LANG_CXX11
> </code>

## Scoping

### Namespaces

With few exceptions, place code in a namespace. Namespaces should have unique names based on the project name, and possibly its path. Do not use using-directives (e.g., `using namespace foo`). Do not use inline namespaces. For unnamed namespaces, see Internal Linkage.

**Definition:**

Namespaces subdivide the global scope into distinct, named scopes, and so are useful for preventing name collisions in the global scope.

**Pros:**

Namespaces provide a method for preventing name conflicts in large programs while allowing most code to use reasonably short names.

For example, if two different projects have a class `Foo` in the global scope, these symbols may collide at compile time or at runtime. If each project places their code in a namespace, `project1::Foo` and `project2::Foo` are now distinct symbols that do not collide, and code within each project's namespace can continue to refer to `Foo` without the prefix.

Inline namespaces automatically place their names in the enclosing scope. Consider the following snippet, for example:

> <code>
> namespace outer {<br>
> inline namespace inner {<br>
> &ensp;&ensp;void foo();<br>
> }&ensp;&ensp;// namespace inner<br>
> }&ensp;&ensp;// namespace outer
> </code>

The expressions `outer::inner::foo()` and `outer::foo()` are interchangeable. Inline namespaces are primarily intended for ABI compatibility across versions.

**Cons:**

Namespaces can be confusing, because they complicate the mechanics of figuring out what definition a name refers to.

Inline namespaces, in particular, can be confusing because names aren't actually restricted to the namespace where they are declared. They are only useful as part of some larger versioning policy.

In some contexts, it's necessary to repeatedly refer to symbols by their fully-qualified names. For deeply-nested namespaces, this can add a lot of clutter.

**Decision:**

Namespaces should be used as follows:

- Follow the rules on Namespace Names.

- Terminate multi-line namespaces with comments as shown in the given examples.

- Namespaces wrap the entire source file after includes, gflags definitions/declarations and forward declarations of classes from other namespaces.

	> <code>
	> // In the .h file<br>
	> namespace mynamespace {<br>
	> <br>
	> // All declarations are within the namespace scope.<br>
	> // Notice the lack of indentation.<br>
	> class MyClass {<br>
	> &ensp;public:<br>
	> &ensp;&ensp;...<br>
	> &ensp;&ensp;void Foo();<br>
	> };<br><br>
	> }&ensp;&ensp;// namespace mynamespace
	> </code>

	<br>

	> <code>
	> // In the .cc file<br>
	> namespace mynamespace {<br>
	> <br>
	> // Definition of functions is within scope of the namespace.<br>
	> void MyClass::Foo() {<br>
	> &ensp;&ensp;...<br>
	> }<br>
	> <br>
	> }&ensp;&ensp;// namespace mynamespace
	> </code>

	More complex `.cc` files might have additional details, like flags or using-declarations.

	> <code>
	> #include "a.h"<br>
	> <br>
	> ABSL_FLAG(bool, someflag, false, "a flag");<br>
	> <br>
	> namespace mynamespace {<br>
	> <br>
	> using ::foo::Bar;<br>
	> <br>
	> ...code for mynamespace...&ensp;&ensp;&ensp;&ensp;// Code goes against the left margin.<br>
	> <br>
	> }  // namespace mynamespace
	> </code>

- To place generated protocol message code in a namespace, use the package specifier in the `.proto` file. See Protocol Buffer Packages for details.

- Do not declare anything in namespace `std`, including forward declarations of standard library classes. Declaring entities in namespace `std` is undefined behavior, i.e., not portable. To declare entities from the standard library, include the appropriate header file.

- You may not use a using-directive to make all names from a namespace available.

	> <code>
	> // Forbidden -- This pollutes the namespace.<br>
	> using namespace foo;
	> </code>

- Do not use Namespace aliases at namespace scope in header files except in explicitly marked internal-only namespaces, because anything imported into a namespace in a header file becomes part of the public API exported by that file.

	> <code>
	> // Shorten access to some commonly used names in .cc files.<br>
	> namespace baz = ::foo::bar::baz;
	> </code>

	<br>

	> <code>
	> // Shorten access to some commonly used names (in a .h file).<br>
	> namespace librarian {<br>
	> namespace impl {&ensp;&ensp;// Internal, not part of the API.<br>
	> namespace sidetable = ::pipeline_diagnostics::sidetable;<br>
	> }&ensp;&ensp;// namespace impl<br>
	> <br>
	> inline void my_inline_function() {<br>
	> &ensp;&ensp;// namespace alias local to a function (or method).<br>
	> &ensp;&ensp;namespace baz = ::foo::bar::baz;<br>
	> &ensp;&ensp;...<br>
	> }<br>
	> }&ensp;&ensp;// namespace librarian
	> </code>

- Do not use inline namespaces.

- Use namespaces with "internal" in the name to document parts of an API that should not be mentioned by users of the API.

	> <code>
	> // We shouldn't use this internal name in non-absl code.<br>
	> using ::absl::container_internal::ImplementationDetail;
	> </code>

### Internal Linkage

When definitions in a `.cc` file do not need to be referenced outside that file, give them internal linkage by placing them in an unnamed namespace or declaring them `static`. Do not use either of these constructs in `.h` files.

**Definition:**

All declarations can be given internal linkage by placing them in unnamed namespaces. Functions and variables can also be given internal linkage by declaring them `static`. This means that anything you're declaring can't be accessed from another file. If a different file declares something with the same name, then the two entities are completely independent.

**Decision:**

Use of internal linkage in `.cc` files is encouraged for all code that does not need to be referenced elsewhere. Do not use internal linkage in `.h` files.

Format unnamed namespaces like named namespaces. In the terminating comment, leave the namespace name empty:

> <code>
> namespace {<br>
> ...<br>
> }&ensp;&ensp;// namespace
> </code>

### Nonmember, Static Member, and Global Functions

Prefer placing nonmember functions in a namespace; use completely global functions rarely. Do not use a class simply to group static members. Static methods of a class should generally be closely related to instances of the class or the class's static data.

**Pros:**

Nonmember and static member functions can be useful in some situations. Putting nonmember functions in a namespace avoids polluting the global namespace.

**Cons:**

Nonmember and static member functions may make more sense as members of a new class, especially if they access external resources or have significant dependencies.

**Decision:**

Sometimes it is useful to define a function not bound to a class instance. Such a function can be either a static member or a nonmember function. Nonmember functions should not depend on external variables, and should nearly always exist in a namespace. Do not create classes only to group static members; this is no different than just giving the names a common prefix, and such grouping is usually unnecessary anyway.

If you define a nonmember function and it is only needed in its `.cc` file, use internal linkage to limit its scope.

### Local Variables

Place a function's variables in the narrowest scope possible, and initialize variables in the declaration.

C++ allows you to declare variables anywhere in a function. We encourage you to declare them in a scope as local as possible, and as close to the first use as possible. This makes it easier for the reader to find the declaration and see what type the variable is and what it was initialized to. In particular, initialization should be used instead of declaration and assignment, e.g.,:

<table>
	<tr>
		<td>Bad</td>
		<td>Good</td>
		<td>Reason</td>
	</tr>
	<tr>
		<td><code>
			int i;<br>
			i = f();
		</code></td>
		<td><code>
			int i = f();
		</code></td>
		<td>
			Bad -- initialization separate from declaration.<br>
			Good -- declaration has initialization.
		</td>
	</tr>
	<tr>
		<td><code>
			int jobs = NumJobs();<br>
			// More code...<br>
			f(jobs);
		</code></td>
		<td><code>
			int jobs = NumJobs();<br>
			f(jobs);
		</code></td>
		<td>
			Bad -- declaration separate from use.<br>
			Good -- declaration immediately (or closely) followed by use.
		</td>
	</tr>
	<tr>
		<td><code>
			std::vector&lt;int&gt; v;<br>
			v.push_back(1);<br>
			v.push_back(2);
		</code></td>
		<td><code>
			std::vector&lt;int&gt; v = {1, 2};
		</code></td>
		<td>
			Bad -- prefer initializing using brace initialization.<br>
			Good -- v starts initialized.
		</td>
	</tr>
</table>

Variables needed for `if`, `while` and `for` statements should normally be declared within those statements, so that such variables are confined to those scopes. E.g.:

> <code>
> while (const char* p = strchr(str, '/')) str = p + 1;
> </code>

<br>

There is one caveat: if the variable is an object, its constructor is invoked every time it enters scope and is created, and its destructor is invoked every time it goes out of scope.

> <code>
> // Inefficient implementation:<br>
> for (int i = 0; i < 1000000; ++i) {<br>
> &ensp;&ensp;Foo f;&ensp;&ensp;// My ctor and dtor get called 1000000 times each.<br>
> &ensp;&ensp;f.DoSomething(i);<br>
> }
> </code>

<br>

It may be more efficient to declare such a variable used in a loop outside that loop:

> <code>
> Foo f;&ensp;&ensp;// My ctor and dtor get called once each.<br>
> for (int i = 0; i &lt; 1000000; ++i) {<br>
> &ensp;&ensp;f.DoSomething(i);<br>
> }
> </code>

### Static and Global Variables

Objects with static storage duration are forbidden unless they are trivially destructible. Informally this means that the destructor does not do anything, even taking member and base destructors into account. More formally it means that the type has no user-defined or virtual destructor and that all bases and non-static members are trivially destructible. Static function-local variables may use dynamic initialization. Use of dynamic initialization for static class member variables or variables at namespace scope is discouraged, but allowed in limited circumstances; see below for details.

As a rule of thumb: a global variable satisfies these requirements if its declaration, considered in isolation, could be `constexpr`.

**Definition:**

Every object has a storage duration, which correlates with its lifetime. Objects with static storage duration live from the point of their initialization until the end of the program. Such objects appear as variables at namespace scope ("global variables"), as static data members of classes, or as function-local variables that are declared with the `static` specifier. Function-local static variables are initialized when control first passes through their declaration; all other objects with static storage duration are initialized as part of program start-up. All objects with static storage duration are destroyed at program exit (which happens before unjoined threads are terminated).

Initialization may be dynamic, which means that something non-trivial happens during initialization. (For example, consider a constructor that allocates memory, or a variable that is initialized with the current process ID.) The other kind of initialization is static initialization. The two aren't quite opposites, though: static initialization always happens to objects with static storage duration (initializing the object either to a given constant or to a representation consisting of all bytes set to zero), whereas dynamic initialization happens after that, if required.

**Pros:**

Global and static variables are very useful for a large number of applications: named constants, auxiliary data structures internal to some translation unit, command-line flags, logging, registration mechanisms, background infrastructure, etc.

**Cons:**

Global and static variables that use dynamic initialization or have non-trivial destructors create complexity that can easily lead to hard-to-find bugs. Dynamic initialization is not ordered across translation units, and neither is destruction (except that destruction happens in reverse order of initialization). When one initialization refers to another variable with static storage duration, it is possible that this causes an object to be accessed before its lifetime has begun (or after its lifetime has ended). Moreover, when a program starts threads that are not joined at exit, those threads may attempt to access objects after their lifetime has ended if their destructor has already run.

**Decision:**

#### On Destruction

When destructors are trivial, their execution is not subject to ordering at all (they are effectively not "run"); otherwise we are exposed to the risk of accessing objects after the end of their lifetime. Therefore, we only allow objects with static storage duration if they are trivially destructible. Fundamental types (like pointers and `int`) are trivially destructible, as are arrays of trivially destructible types. Note that variables marked with `constexpr` are trivially destructible.

> <code>
> const int kNum = 10;&ensp;&ensp;// Allowed<br>
> <br>
> struct X { int n; };<br>
> const X kX[] = {{1}, {2}, {3}};&ensp;&ensp;// Allowed<br>
> <br>
> void foo() {<br>
> &ensp;&ensp;static const char* const kMessages[] = {"hello", "world"};&ensp;&ensp;// Allowed<br>
> }<br>
> <br>
> // Allowed: constexpr guarantees trivial destructor.<br>
> constexpr std::array&lt;int, 3&gt; kArray = {1, 2, 3};
> </code>

<br>

> <code>
> // bad: non-trivial destructor<br>
> const std::string kFoo = "foo";<br>
> <br>
> // Bad for the same reason, even though kBar is a reference (the<br>
> // rule also applies to lifetime-extended temporary objects).<br>
> const std::string& kBar = StrCat("a", "b", "c");<br>
> <br>
> void bar() {<br>
> &ensp;&ensp;// Bad: non-trivial destructor.<br>
> &ensp;&ensp;static std::map&lt;int, int&gt; kData = {{1, 0}, {2, 0}, {3, 0}};<br>
> }
> </code>

<br>

Note that references are not objects, and thus they are not subject to the constraints on destructibility. The constraint on dynamic initialization still applies, though. In particular, a function-local static reference of the form `static T& t = *new T;` is allowed.

#### On Initialization

Initialization is a more complex topic. This is because we must not only consider whether class constructors execute, but we must also consider the evaluation of the initializer:

> <code>
> int n = 5;&ensp;&ensp;&ensp;&ensp;// Fine<br>
> int m = f();&ensp;&ensp;// ? (Depends on f)<br>
> Foo x;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// ? (Depends on Foo::Foo)<br>
> Bar y = g();&ensp;&ensp;// ? (Depends on g and on Bar::Bar)
> </code>

<br>

All but the first statement expose us to indeterminate initialization ordering.

The concept we are looking for is called constant initialization in the formal language of the C++ standard. It means that the initializing expression is a constant expression, and if the object is initialized by a constructor call, then the constructor must be specified as constexpr, too:

> <code>
> struct Foo { constexpr Foo(int) {} };<br>
> <br>
> int n = 5;&ensp;&ensp;// Fine, 5 is a constant expression.<br>
> Foo x(2);&ensp;&ensp;&ensp;// Fine, 2 is a constant expression and the chosen constructor is constexpr.<br>
> Foo a[] = { Foo(1), Foo(2), Foo(3) };&ensp;&ensp;// Fine
> </code>

<br>

Constant initialization is always allowed. Constant initialization of static storage duration variables should be marked with `constexpr` or where possible the `ABSL_CONST_INIT` attribute. Any non-local static storage duration variable that is not so marked should be presumed to have dynamic initialization, and reviewed very carefully.

By contrast, the following initializations are problematic:

> <code>
> // Some declarations used below.<br>
> time_t time(time_t*);&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// Not constexpr!<br>
> int f();&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// Not constexpr!<br>
> struct Bar { Bar() {} };<br>
> <br>
> // Problematic initializations.<br>
> time_t m = time(nullptr);&ensp;&ensp;// Initializing expression not a constant expression.<br>
> Foo y(f());&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// Ditto<br>
> Bar b;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// Chosen constructor Bar::Bar() not constexpr.<br>
> </code>

<br>

Dynamic initialization of nonlocal variables is discouraged, and in general it is forbidden. However, we do permit it if no aspect of the program depends on the sequencing of this initialization with respect to all other initializations. Under those restrictions, the ordering of the initialization does not make an observable difference. For example:

> <code>
> int p = getpid();&ensp;&ensp;// Allowed, as long as no other static variable<br>
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;// uses p in its own initialization.
> </code>

<br>

Dynamic initialization of static local variables is allowed (and common).

#### Common Patterns


- Global strings: if you require a named global or static string constant, consider using a `constexpr` variable of `string_view`, character array, or character pointer, pointing to a string literal. String literals have static storage duration already and are usually sufficient. See TotW #140.

- Maps, sets, and other dynamic containers: if you require a static, fixed collection, such as a set to search against or a lookup table, you cannot use the dynamic containers from the standard library as a static variable, since they have non-trivial destructors. Instead, consider a simple array of trivial types, e.g., an array of arrays of ints (for a "map from `int` to `int`"), or an array of pairs (e.g., pairs of `int` and `const char*`). For small collections, linear search is entirely sufficient (and efficient, due to memory locality); consider using the facilities from `absl/algorithm/container.h` for the standard operations. If necessary, keep the collection in sorted order and use a binary search algorithm. If you do really prefer a dynamic container from the standard library, consider using a function-local static pointer, as described below.

- Smart pointers (`std::unique_ptr`, `std::shared_ptr`): smart pointers execute cleanup during destruction and are therefore forbidden. Consider whether your use case fits into one of the other patterns described in this section. One simple solution is to use a plain pointer to a dynamically allocated object and never delete it (see last item).

- Static variables of custom types: if you require static, constant data of a type that you need to define yourself, give the type a trivial destructor and a `constexpr` constructor.

- If all else fails, you can create an object dynamically and never delete it by using a function-local static pointer or reference (e.g., `static const auto& impl = *new T(args...);`).

### `thread_local` Variables

`thread_local` variables that aren't declared inside a function must be initialized with a true compile-time constant, and this must be enforced by using the `ABSL_CONST_INIT` attribute. Prefer `thread_local` over other ways of defining thread-local data.

**Definition:**

Variables can be declared with the `thread_local` specifier:

> <code>
> thread_local Foo foo = ...;
> </code>

<br>

Such a variable is actually a collection of objects, so that when different threads access it, they are actually accessing different objects. `thread_local` variables are much like static storage duration variables in many respects. For instance, they can be declared at namespace scope, inside functions, or as static class members, but not as ordinary class members.

`thread_local` variable instances are initialized much like static variables, except that they must be initialized separately for each thread, rather than once at program startup. This means that `thread_local` variables declared within a function are safe, but other `thread_local` variables are subject to the same initialization-order issues as static variables (and more besides).

`thread_local` variables have a subtle destruction-order issue: during thread shutdown, `thread_local` variables will be destroyed in the opposite order of their initialization (as is generally true in C++). If code triggered by the destructor of any `thread_local` variable refers to any already-destroyed `thread_local` on that thread, we will get a particularly hard to diagnose use-after-free.

**Pros:**

- Thread-local data is inherently safe from races (because only one thread can ordinarily access it), which makes `thread_local` useful for concurrent programming.

- `thread_local` is the only standard-supported way of creating thread-local data.

**Cons:**

- Accessing a `thread_local` variable may trigger execution of an unpredictable and uncontrollable amount of other code during thread-start or first use on a given thread.

- `thread_local` variables are effectively global variables, and have all the drawbacks of global variables other than lack of thread-safety.

- The memory consumed by a `thread_local` variable scales with the number of running threads (in the worst case), which can be quite large in a program.

- Data members cannot be `thread_local` unless they are also static.

- We may suffer from use-after-free bugs if `thread_local` variables have complex destructors. In particular, the destructor of any such variable must not call any code (transitively) that refers to any potentially-destroyed `thread_local`. This property is hard to enforce.

- Approaches for avoiding use-after-free in global/static contexts do not work for `thread_local`s. Specifically, skipping destructors for globals and static variables is allowable because their lifetimes end at program shutdown. Thus, any "leak" is managed immediately by the OS cleaning up our memory and other resources. By contrast, skipping destructors for `thread_local` variables leads to resource leaks proportional to the total number of threads that terminate during the lifetime of the program.

**Decision:**

`thread_local` variables at class or namespace scope must be initialized with a true compile-time constant (i.e., they must have no dynamic initialization). To enforce this, `thread_local` variables at class or namespace scope must be annotated with `ABSL_CONST_INIT` (or `constexpr`, but that should be rare):

> <code>
> ABSL_CONST_INIT thread_local Foo foo = ...;
> </code>

<br>

`thread_local` variables inside a function have no initialization concerns, but still risk use-after-free during thread exit. Note that you can use a function-scope `thread_local` to simulate a class- or namespace-scope `thread_local` by defining a function or static method that exposes it:

> <code>
> Foo& MyThreadLocalFoo() {<br>
> &ensp;&ensp;thread_local Foo result = ComplicatedInitialization();<br>
> &ensp;&ensp;return result;<br>
> }
> </code>

<br>

Note that `thread_local` variables will be destroyed whenever a thread exits. If the destructor of any such variable refers to any other (potentially-destroyed) `thread_local` we will suffer from hard to diagnose use-after-free bugs. Prefer trivial types, or types that provably run no user-provided code at destruction to minimize the potential of accessing any other `thread_local`.

`thread_local` should be preferred over other mechanisms for defining thread-local data.
