# Google C++ Style Guide

## Table of Contents

<table>
	<tr>
		<td><a href="#c-version">C++ Version</a></td>
		<td></td>
	</tr>
	<tr>
		<td><a href="#header-files">Header Files</a></td>
		<td>
			<ul>
				<li><a href="#self-contained-headers">Self-Contained Headers</a></li>
				<li><a href="#the-define-guard">The #define Guard</a></li>
				<li><a href="#include-what-you-use">Include What You Use</a></li>
				<li><a href="#forward-declarations">Forward Declarations</a></li>
				<li><a href="#inline-functions">Inline Functions</a></li>
				<li><a href="#names-and-order-of-includes">Names and Order of Includes</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a href="#scoping">Scoping</a></td>
		<td>
			<ul>
				<li><a href="#namespaces">Namespaces</a></li>
				<li><a href="#internal-linkage">Internal Linkage</a></li>
				<li><a href="#nonmember-static-member-and-global-functions">Nonmember, Static Member, and Global Functions</a></li>
				<li><a href="#local-variables">Local Variables</a></li>
				<li><a href="#static-and-global-variables">Static and Global Variables</a></li>
				<li><a href="#thread_local-variables">thread_local Variables</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a href="#classes">Classes</a></td>
		<td>
			<ul>
				<li><a href="#doing-work-in-constructors">Doing Work in Constructors</a></li>
				<li><a href="#implicit-conversions">Implicit Conversions</a></li>
				<li><a href="#copyable-and-movable-types">Copyable and Movable Types</a></li>
				<li><a href="#structs-vs-classes">Structs vs. Classes</a></li>
				<li><a href="#structs-vs-pairs-and-tuples">Structs vs. Pairs and Tuples</a></li>
				<li><a href="#inheritance">Inheritance</a></li>
				<li><a href="#operator-overloading">Operator Overloading</a></li>
				<li><a href="#access-control">Access Control</a></li>
				<li><a href="#declaration-order">Declaration Order</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a href="#functions">Functions</a></td>
		<td>
			<ul>
				<li><a href="#inputs-and-outputs">Inputs and Outputs</a></li>
				<li><a href="#write-short-functions">Write Short Functions</a></li>
				<li><a href="#function-overloading">Function Overloading</a></li>
				<li><a href="#default-arguments">Default Arguments</a></li>
				<li><a href="#trailing-return-type-syntax">Trailing Return Type Syntax</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a href="#google-sepcific-magic">Google-Specific Magic</a></td>
		<td>
			<ul>
				<li><a href="#ownership-and-smart-pointers">Ownership and Smart Pointers</a></li>
				<li><a href="#cpplint">cpplint</a></li>
			</ul>
		</td>
	</tr>
	<tr>
		<td><a href="#other-c-features">Other C++ Features</a></td>
		<td>
			<ul>
				<li><a href="#rvalue-references">Rvalue References</a></li>
				<li><a href="#friends">Friends</a></li>
				<li><a href="#exceptions">Exceptions</a></li>
				<li><a href="#noexcept">noexcept</a></li>
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

## Classes

Classes are the fundamental unit of code in C++. Naturally, we use them extensively. This section lists the main dos and don'ts you should follow when writing a class.

### Doing Work in Constructors

Avoid virtual method calls in constructors, and avoid initialization that can fail if you can't signal an error.

**Definition:**

It is possible to perform arbitrary initialization in the body of the constructor.

**Pros:**

- No need to worry about whether the class has been initialized or not.

- Objects that are fully initialized by constructor call can be `const` and may also be easier to use with standard containers or algorithms.

**Cons:**

- If the work calls virtual functions, these calls will not get dispatched to the subclass implementations. Future modification to your class can quietly introduce this problem even if your class is not currently subclassed, causing much confusion.

- There is no easy way for constructors to signal errors, short of crashing the program (not always appropriate) or using exceptions (which are forbidden).

- If the work fails, we now have an object whose initialization code failed, so it may be an unusual state requiring a `bool IsValid()` state checking mechanism (or similar) which is easy to forget to call.

- You cannot take the address of a constructor, so whatever work is done in the constructor cannot easily be handed off to, for example, another thread.

**Decision:**

Constructors should never call virtual functions. If appropriate for your code, terminating the program may be an appropriate error handling response. Otherwise, consider a factory function or `Init()` method as described in TotW #42. Avoid `Init()` methods on objects with no other states that affect which public methods may be called (semi-constructed objects of this form are particularly hard to work with correctly).

### Implicit Conversions

Do not define implicit conversions. Use the `explicit` keyword for conversion operators and single-argument constructors.

**Definition:**

Implicit conversions allow an object of one type (called the source type) to be used where a different type (called the destination type) is expected, such as when passing an `int` argument to a function that takes a `double` parameter.

In addition to the implicit conversions defined by the language, users can define their own, by adding appropriate members to the class definition of the source or destination type. An implicit conversion in the source type is defined by a type conversion operator named after the destination type (e.g., `operator bool()`). An implicit conversion in the destination type is defined by a constructor that can take the source type as its only argument (or only argument with no default value).

The `explicit` keyword can be applied to a constructor or a conversion operator, to ensure that it can only be used when the destination type is explicit at the point of use, e.g., with a cast. This applies not only to implicit conversions, but to list initialization syntax:

> <code>
> class Foo {<br>
> &ensp;&ensp;explicit Foo(int x, double y);<br>
> &ensp;&ensp;...<br>
> };<br>
> <br>
> void Func(Foo f);
> </code>

<br>

> <code>
> Func({42, 3.14});&ensp;&ensp;// Error
> </code>

<br>

This kind of code isn't technically an implicit conversion, but the language treats it as one as far as explicit is concerned.

**Pros:**

- Implicit conversions can make a type more usable and expressive by eliminating the need to explicitly name a type when it's obvious.

- Implicit conversions can be a simpler alternative to overloading, such as when a single function with a `string_view` parameter takes the place of separate overloads for `std::string` and `const char*`.

- List initialization syntax is a concise and expressive way of initializing objects.

**Cons:**

- Implicit conversions can hide type-mismatch bugs, where the destination type does not match the user's expectation, or the user is unaware that any conversion will take place.

- Implicit conversions can make code harder to read, particularly in the presence of overloading, by making it less obvious what code is actually getting called.

- Constructors that take a single argument may accidentally be usable as implicit type conversions, even if they are not intended to do so.

- When a single-argument constructor is not marked explicit, there's no reliable way to tell whether it's intended to define an implicit conversion, or the author simply forgot to mark it.

- Implicit conversions can lead to call-site ambiguities, especially when there are bidirectional implicit conversions. This can be caused either by having two types that both provide an implicit conversion, or by a single type that has both an implicit constructor and an implicit type conversion operator.

- List initialization can suffer from the same problems if the destination type is implicit, particularly if the list has only a single element.

**Decision:**

Type conversion operators, and constructors that are callable with a single argument, must be marked `explicit` in the class definition. As an exception, copy and move constructors should not be `explicit`, since they do not perform type conversion.

Implicit conversions can sometimes be necessary and appropriate for types that are designed to be interchangeable, for example when objects of two types are just different representations of the same underlying value. In that case, contact your project leads to request a waiver of this rule.

Constructors that cannot be called with a single argument may omit `explicit`. Constructors that take a single `std::initializer_list` parameter should also omit `explicit`, in order to support copy-initialization (e.g., `MyType m = {1, 2};`).

### Copyable and Movable Types

A class's public API must make clear whether the class is copyable, move-only, or neither copyable nor movable. Support copying and/or moving if these operations are clear and meaningful for your type.

**Definition:**

A movable type is one that can be initialized and assigned from temporaries.

A copyable type is one that can be initialized or assigned from any other object of the same type (so is also movable by definition), with the stipulation that the value of the source does not change. `std::unique_ptr<int>` is an example of a movable but not copyable type (since the value of the source `std::unique_ptr<int>` must be modified during assignment to the destination). `int` and `std::string` are examples of movable types that are also copyable. (For `int`, the move and copy operations are the same; for `std::string`, there exists a move operation that is less expensive than a copy.)

For user-defined types, the copy behavior is defined by the copy constructor and the copy-assignment operator. Move behavior is defined by the move constructor and the move-assignment operator, if they exist, or by the copy constructor and the copy-assignment operator otherwise.

The copy/move constructors can be implicitly invoked by the compiler in some situations, e.g., when passing objects by value.

**Pros:**

Objects of copyable and movable types can be passed and returned by value, which makes APIs simpler, safer, and more general. Unlike when passing objects by pointer or reference, there's no risk of confusion over ownership, lifetime, mutability, and similar issues, and no need to specify them in the contract. It also prevents non-local interactions between the client and the implementation, which makes them easier to understand, maintain, and optimize by the compiler. Further, such objects can be used with generic APIs that require pass-by-value, such as most containers, and they allow for additional flexibility in e.g., type composition.

Copy/move constructors and assignment operators are usually easier to define correctly than alternatives like `Clone()`, `CopyFrom()` or `Swap()`, because they can be generated by the compiler, either implicitly or with `= default`. They are concise, and ensure that all data members are copied. Copy and move constructors are also generally more efficient, because they don't require heap allocation or separate initialization and assignment steps, and they're eligible for optimizations such as copy elision.

Move operations allow the implicit and efficient transfer of resources out of rvalue objects. This allows a plainer coding style in some cases.

**Cons:**

Some types do not need to be copyable, and providing copy operations for such types can be confusing, nonsensical, or outright incorrect. Types representing singleton objects (`Registerer`), objects tied to a specific scope (`Cleanup`), or closely coupled to object identity (`Mutex`) cannot be copied meaningfully. Copy operations for base class types that are to be used polymorphically are hazardous, because use of them can lead to object slicing. Defaulted or carelessly-implemented copy operations can be incorrect, and the resulting bugs can be confusing and difficult to diagnose.

Copy constructors are invoked implicitly, which makes the invocation easy to miss. This may cause confusion for programmers used to languages where pass-by-reference is conventional or mandatory. It may also encourage excessive copying, which can cause performance problems.

**Decision:**

Every class's public interface must make clear which copy and move operations the class supports. This should usually take the form of explicitly declaring and/or deleting the appropriate operations in the `public` section of the declaration.

Specifically, a copyable class should explicitly declare the copy operations, a move-only class should explicitly declare the move operations, and a non-copyable/movable class should explicitly delete the copy operations. A copyable class may also declare move operations in order to support efficient moves. Explicitly declaring or deleting all four copy/move operations is permitted, but not required. If you provide a copy or move assignment operator, you must also provide the corresponding constructor.

> <code>
> class Copyable {<br>
> &ensp;public:<br>
> &ensp;&ensp;Copyable(const Copyable& other) = default;<br>
> &ensp;&ensp;Copyable& operator=(const Copyable& other) = default;<br>
> <br>
> &ensp;&ensp;// The implicit move operations are suppressed by the declarations above.<br>
> &ensp;&ensp;// You may explicitly declare move operations to support efficient moves.<br>
> };<br>
> <br>
> class MoveOnly {<br>
> &ensp;public:<br>
> &ensp;&ensp;MoveOnly(MoveOnly&& other) = default;<br>
> &ensp;&ensp;MoveOnly& operator=(MoveOnly&& other) = default;<br>
> <br>
> &ensp;&ensp;// The copy operations are implicitly deleted, but you can<br>
> &ensp;&ensp;// spell that out explicitly if you want:<br>
> &ensp;&ensp;MoveOnly(const MoveOnly&) = delete;<br>
> &ensp;&ensp;MoveOnly& operator=(const MoveOnly&) = delete;<br>
> };<br>
> <br>
> class NotCopyableOrMovable {<br>
> &ensp;public:<br>
> &ensp;&ensp;// Not copyable or movable<br>
> &ensp;&ensp;NotCopyableOrMovable(const NotCopyableOrMovable&) = delete;<br>
> &ensp;&ensp;NotCopyableOrMovable& operator=(const NotCopyableOrMovable&)<br>
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;= delete;<br>
> <br>
> &ensp;&ensp;// The move operations are implicitly disabled, but you can<br>
> &ensp;&ensp;// spell that out explicitly if you want:<br>
> &ensp;&ensp;NotCopyableOrMovable(NotCopyableOrMovable&&) = delete;<br>
> &ensp;&ensp;NotCopyableOrMovable& operator=(NotCopyableOrMovable&&)<br>
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;= delete;<br>
> };
> </code>

These declarations/deletions can be omitted only if they are obvious:

- If the class has no `private` section, like a `struct` or an interface-only base class, then the copyability/movability can be determined by the copyability/movability of any public data members.

- If a base class clearly isn't copyable or movable, derived classes naturally won't be either. An interface-only base class that leaves these operations implicit is not sufficient to make concrete subclasses clear.

- Note that if you explicitly declare or delete either the constructor or assignment operation for copy, the other copy operation is not obvious and must be declared or deleted. Likewise for move operations.

A type should not be copyable/movable if the meaning of copying/moving is unclear to a casual user, or if it incurs unexpected costs. Move operations for copyable types are strictly a performance optimization and are a potential source of bugs and complexity, so avoid defining them unless they are significantly more efficient than the corresponding copy operations. If your type provides copy operations, it is recommended that you design your class so that the default implementation of those operations is correct. Remember to review the correctness of any defaulted operations as you would any other code.

To eliminate the risk of slicing, prefer to make base classes abstract, by making their constructors protected, by declaring their destructors protected, or by giving them one or more pure virtual member functions. Prefer to avoid deriving from concrete classes.

### Structs vs. Classes

Use a `struct` only for passive objects that carry data; everything else is a `class`.

The `struct` and `class` keywords behave almost identically in C++. We add our own semantic meanings to each keyword, so you should use the appropriate keyword for the data-type you're defining.

structs should be used for passive objects that carry data, and may have associated constants. All fields must be public. The struct must not have invariants that imply relationships between different fields, since direct user access to those fields may break those invariants. Constructors, destructors, and helper methods may be present; however, these methods must not require or enforce any invariants.

If more functionality or invariants are required, a `class` is more appropriate. If in doubt, make it a `class`.

For consistency with STL, you can use `struct` instead of `class` for stateless types, such as traits, template metafunctions, and some functors.

Note that member variables in structs and classes have different naming rules.

### Structs vs. Pairs and Tuples

Prefer to use a `struct` instead of a pair or a tuple whenever the elements can have meaningful names.

While using pairs and tuples can avoid the need to define a custom type, potentially saving work when writing code, a meaningful field name will almost always be much clearer when reading code than `.first`, `.second`, or `std::get<X>`. While C++14's introduction of `std::get<Type>` to access a tuple element by type rather than index (when the type is unique) can sometimes partially mitigate this, a field name is usually substantially clearer and more informative than a type.

Pairs and tuples may be appropriate in generic code where there are not specific meanings for the elements of the pair or tuple. Their use may also be required in order to interoperate with existing code or APIs.

### Inheritance

Composition is often more appropriate than inheritance. When using inheritance, make it `public`.

**Definition:**

When a sub-class inherits from a base class, it includes the definitions of all the data and operations that the base class defines. "Interface inheritance" is inheritance from a pure abstract base class (one with no state or defined methods); all other inheritance is "implementation inheritance".

**Pros:**

Implementation inheritance reduces code size by re-using the base class code as it specializes an existing type. Because inheritance is a compile-time declaration, you and the compiler can understand the operation and detect errors. Interface inheritance can be used to programmatically enforce that a class expose a particular API. Again, the compiler can detect errors, in this case, when a class does not define a necessary method of the API.

**Cons:**

For implementation inheritance, because the code implementing a sub-class is spread between the base and the sub-class, it can be more difficult to understand an implementation. The sub-class cannot override functions that are not virtual, so the sub-class cannot change implementation.

Multiple inheritance is especially problematic, because it often imposes a higher performance overhead (in fact, the performance drop from single inheritance to multiple inheritance can often be greater than the performance drop from ordinary to virtual dispatch), and because it risks leading to "diamond" inheritance patterns, which are prone to ambiguity, confusion, and outright bugs.

**Decision:**

All inheritance should be `public`. If you want to do private inheritance, you should be including an instance of the base class as a member instead. You may use `final` on classes when you don't intend to support using them as base classes.

Do not overuse implementation inheritance. Composition is often more appropriate. Try to restrict use of inheritance to the "is-a" case: `Bar` subclasses `Foo` if it can reasonably be said that `Bar` "is a kind of" `Foo`.

Limit the use of `protected` to those member functions that might need to be accessed from subclasses. Note that data members should be `private`.

Explicitly annotate overrides of virtual functions or virtual destructors with exactly one of an `override` or (less frequently) `final` specifier. Do not use `virtual` when declaring an override. Rationale: A function or destructor marked `override` or `final` that is not an override of a base class virtual function will not compile, and this helps catch common errors. The specifiers serve as documentation; if no specifier is present, the reader has to check all ancestors of the class in question to determine if the function or destructor is virtual or not.

Multiple inheritance is permitted, but multiple implementation inheritance is strongly discouraged.

### Operator Overloading

Overload operators judiciously. Do not use user-defined literals.

**Definition:**

C++ permits user code to declare overloaded versions of the built-in operators using the `operator` keyword, so long as one of the parameters is a user-defined type. The `operator` keyword also permits user code to define new kinds of literals using `operator""`, and to define type-conversion functions such as `operator bool()`.

**Pros:**

Operator overloading can make code more concise and intuitive by enabling user-defined types to behave the same as built-in types. Overloaded operators are the idiomatic names for certain operations (e.g., `==`, `<`, `=`, and `<<`), and adhering to those conventions can make user-defined types more readable and enable them to interoperate with libraries that expect those names.

User-defined literals are a very concise notation for creating objects of user-defined types.

**Cons:**

- Providing a correct, consistent, and unsurprising set of operator overloads requires some care, and failure to do so can lead to confusion and bugs.

- Overuse of operators can lead to obfuscated code, particularly if the overloaded operator's semantics don't follow convention.

- The hazards of function overloading apply just as much to operator overloading, if not more so.

- Operator overloads can fool our intuition into thinking that expensive operations are cheap, built-in operations.

- Finding the call sites for overloaded operators may require a search tool that's aware of C++ syntax, rather than e.g., grep.

- If you get the argument type of an overloaded operator wrong, you may get a different overload rather than a compiler error. For example, `foo < bar` may do one thing, while `&foo < &bar` does something totally different.

- Certain operator overloads are inherently hazardous. Overloading unary & can cause the same code to have different meanings depending on whether the overload declaration is visible. Overloads of `&&`, `||`, and `,` (comma) cannot match the evaluation-order semantics of the built-in operators.

- Operators are often defined outside the class, so there's a risk of different files introducing different definitions of the same operator. If both definitions are linked into the same binary, this results in undefined behavior, which can manifest as subtle run-time bugs.

- User-defined literals (UDLs) allow the creation of new syntactic forms that are unfamiliar even to experienced C++ programmers, such as `"Hello World"sv` as a shorthand for `std::string_view("Hello World")`. Existing notations are clearer, though less terse.

- Because they can't be namespace-qualified, uses of UDLs also require use of either using-directives (which we ban) or using-declarations (which we ban in header files except when the imported names are part of the interface exposed by the header file in question). Given that header files would have to avoid UDL suffixes, we prefer to avoid having conventions for literals differ between header files and source files.

**Decision:**

Define overloaded operators only if their meaning is obvious, unsurprising, and consistent with the corresponding built-in operators. For example, use `|` as a bitwise- or logical-or, not as a shell-style pipe.

Define operators only on your own types. More precisely, define them in the same headers, `.cc` files, and namespaces as the types they operate on. That way, the operators are available wherever the type is, minimizing the risk of multiple definitions. If possible, avoid defining operators as templates, because they must satisfy this rule for any possible template arguments. If you define an operator, also define any related operators that make sense, and make sure they are defined consistently. For example, if you overload `<`, overload all the comparison operators, and make sure `<` and `>` never return `true` for the same arguments.

Prefer to define non-modifying binary operators as non-member functions. If a binary operator is defined as a class member, implicit conversions will apply to the right-hand argument, but not the left-hand one. It will confuse your users if `a < b` compiles but `b < a` doesn't.

Don't go out of your way to avoid defining operator overloads. For example, prefer to define `==`, `=`, and `<<`, rather than `Equals()`, `CopyFrom()`, and `PrintTo()`. Conversely, don't define operator overloads just because other libraries expect them. For example, if your type doesn't have a natural ordering, but you want to store it in a `std::set`, use a custom comparator rather than overloading `<`.

Do not overload `&&`, `||`, `,` (comma), or unary `&`. Do not overload `operator""`, i.e., do not introduce user-defined literals. Do not use any such literals provided by others (including the standard library).

Type conversion operators are covered in the section on implicit conversions. The `=` operator is covered in the section on copy constructors. Overloading `<<` for use with streams is covered in the section on streams. See also the rules on function overloading, which apply to operator overloading as well.

### Access Control

Make classes' data members `private`, unless they are constants. This simplifies reasoning about invariants, at the cost of some easy boilerplate in the form of accessors (usually `const`) if necessary.

For technical reasons, we allow data members of a test fixture class defined in a `.cc` file to be protected when using Google Test. If a test fixture class is defined outside of the `.cc` file it is used in, for example in a `.h` file, make data members `private`.

### Declaration Order

Group similar declarations together, placing public parts earlier.

A class definition should usually start with a public: section, followed by protected:, then private:. Omit sections that would be empty.

Within each section, prefer grouping similar kinds of declarations together, and prefer the following order:

1. Types and type aliases (`typedef`, `using`, `enum`, nested structs and classes, and `friend` types)
2. (Optionally, for structs only) non-`static` data members
3. Static constants
4. Factory functions
5. Constructors and assignment operators
6. Destructor
7. All other functions (`static` and non-`static` member functions, and `friend` functions)
8. All other data members (`static` and non-`static`)

Do not put large method definitions inline in the class definition. Usually, only trivial or performance-critical, and very short, methods may be defined inline. See Inline Functions for more details.

## Functions

### Inputs and Outputs

The output of a C++ function is naturally provided via a return value and sometimes via output parameters (or in/out parameters).

Prefer using return values over output parameters: they improve readability, and often provide the same or better performance.

Prefer to return by value or, failing that, return by reference. Avoid returning a pointer unless it can be null.

Parameters are either inputs to the function, outputs from the function, or both. Non-optional input parameters should usually be values or const references, while non-optional output and input/output parameters should usually be references (which cannot be null). Generally, use `std::optional` to represent optional by-value inputs, and use a `const` pointer when the non-optional form would have used a reference. Use non-`const` pointers to represent optional outputs and optional input/output parameters.

Avoid defining functions that require a `const` reference parameter to outlive the call, because `const` reference parameters bind to temporaries. Instead, find a way to eliminate the lifetime requirement (for example, by copying the parameter), or pass it by `const` pointer and document the lifetime and non-null requirements.

When ordering function parameters, put all input-only parameters before any output parameters. In particular, do not add new parameters to the end of the function just because they are new; place new input-only parameters before the output parameters. This is not a hard-and-fast rule. Parameters that are both input and output muddy the waters, and, as always, consistency with related functions may require you to bend the rule. Variadic functions may also require unusual parameter ordering.

### Write Short Functions

Prefer small and focused functions.

We recognize that long functions are sometimes appropriate, so no hard limit is placed on functions length. If a function exceeds about 40 lines, think about whether it can be broken up without harming the structure of the program.

Even if your long function works perfectly now, someone modifying it in a few months may add new behavior. This could result in bugs that are hard to find. Keeping your functions short and simple makes it easier for other people to read and modify your code. Small functions are also easier to test.

You could find long and complicated functions when working with some code. Do not be intimidated by modifying existing code: if working with such a function proves to be difficult, you find that errors are hard to debug, or you want to use a piece of it in several different contexts, consider breaking up the function into smaller and more manageable pieces.

### Function Overloading

Use overloaded functions (including constructors) only if a reader looking at a call site can get a good idea of what is happening without having to first figure out exactly which overload is being called.

**Definition:**

You may write a function that takes a const `std::string&` and overload it with another that takes `const char*`. However, in this case consider `std::string_view` instead.

> <code>
> class MyClass {<br>
> &ensp;public:<br>
> &ensp;&ensp;void Analyze(const std::string &text);
> &ensp;&ensp;void Analyze(const char *text, size_t textlen);
> };
> </code>

<br>

**Pros:**

Overloading can make code more intuitive by allowing an identically-named function to take different arguments. It may be necessary for templatized code, and it can be convenient for Visitors.

Overloading based on `const` or ref qualification may make utility code more usable, more efficient, or both. (See TotW 148 for more.)

**Cons:**

If a function is overloaded by the argument types alone, a reader may have to understand C++'s complex matching rules in order to tell what's going on. Also many people are confused by the semantics of inheritance if a derived class overrides only some of the variants of a function.

**Decision:**

You may overload a function when there are no semantic differences between variants. These overloads may vary in types, qualifiers, or argument count. However, a reader of such a call must not need to know which member of the overload set is chosen, only that something from the set is being called. If you can document all entries in the overload set with a single comment in the header, that is a good sign that it is a well-designed overload set.

### Default Arguments

Default arguments are allowed on non-virtual functions when the default is guaranteed to always have the same value. Follow the same restrictions as for function overloading, and prefer overloaded functions if the readability gained with default arguments doesn't outweigh the downsides below.

**Pros:**

Often you have a function that uses default values, but occasionally you want to override the defaults. Default parameters allow an easy way to do this without having to define many functions for the rare exceptions. Compared to overloading the function, default arguments have a cleaner syntax, with less boilerplate and a clearer distinction between 'required' and 'optional' arguments.

**Cons:**

Defaulted arguments are another way to achieve the semantics of overloaded functions, so all the reasons not to overload functions apply.

The defaults for arguments in a virtual function call are determined by the static type of the target object, and there's no guarantee that all overrides of a given function declare the same defaults.

Default parameters are re-evaluated at each call site, which can bloat the generated code. Readers may also expect the default's value to be fixed at the declaration instead of varying at each call.

Function pointers are confusing in the presence of default arguments, since the function signature often doesn't match the call signature. Adding function overloads avoids these problems.

**Decision:**

Default arguments are banned on virtual functions, where they don't work properly, and in cases where the specified default might not evaluate to the same value depending on when it was evaluated. (For example, don't write `void f(int n = counter++);`.)

In some other cases, default arguments can improve the readability of their function declarations enough to overcome the downsides above, so they are allowed. When in doubt, use overloads.

### Trailing Return Type Syntax

Use trailing return types only where using the ordinary syntax (leading return types) is impractical or much less readable.

**Definition:**

C++ allows two different forms of function declarations. In the older form, the return type appears before the function name. For example:

> <code>
> int foo(int x);
> </code>

<br>

The newer form uses the auto keyword before the function name and a trailing return type after the argument list. For example, the declaration above could equivalently be written:

> <code>
> auto foo(int x) -> int;
> </code>

<br>

The trailing return type is in the function's scope. This doesn't make a difference for a simple case like int but it matters for more complicated cases, like types declared in class scope or types written in terms of the function parameters.

**Pros:**

Trailing return types are the only way to explicitly specify the return type of a lambda expression. In some cases the compiler is able to deduce a lambda's return type, but not in all cases. Even when the compiler can deduce it automatically, sometimes specifying it explicitly would be clearer for readers.

Sometimes it's easier and more readable to specify a return type after the function's parameter list has already appeared. This is particularly true when the return type depends on template parameters. For example:

> <code>
> template&lt;typename T, typename U&gt;<br>
> auto add(T t, U, u) -> decltype(t + u);
> </code>

<br>

versus

> <code>
> template&lt;typename T, typename U&gt;<br>
> decltype(declval&lt;T&&gt;() + declval&lt;U&gt;()) add(T t, U, u);
> </code>

**Cons:**

Trailing return type syntax is relatively new and it has no analogue in C++-like languages such as C and Java, so some readers may find it unfamiliar.

Existing code bases have an enormous number of function declarations that aren't going to get changed to use the new syntax, so the realistic choices are using the old syntax only or using a mixture of the two. Using a single version is better for uniformity of style.

**Decision:**

In most cases, continue to use the older style of function declaration where the return type goes before the function name. Use the new trailing-return-type form only in cases where it's required (such as lambdas) or where, by putting the type after the function's parameter list, it allows you to write the type in a much more readable way. The latter case should be rare; it's mostly an issue in fairly complicated template code, which is discouraged in most cases.

## Google-Sepcific Magic

There are various tricks and utilities that we use to make C++ code more robust, and various ways we use C++ that may differ from what you see elsewhere.

### Ownership and Smart Pointers

Prefer to have single, fixed owners for dynamically allocated objects. Prefer to transfer ownership with smart pointers.

**Definition:**

"Ownership" is a bookkeeping technique for managing dynamically allocated memory (and other resources). The owner of a dynamically allocated object is an object or function that is responsible for ensuring that it is deleted when no longer needed. Ownership can sometimes be shared, in which case the last owner is typically responsible for deleting it. Even when ownership is not shared, it can be transferred from one piece of code to another.

"Smart" pointers are classes that act like pointers, e.g., by overloading the `*` and `->` operators. Some smart pointer types can be used to automate ownership bookkeeping, to ensure these responsibilities are met. `std::unique_ptr` is a smart pointer type which expresses exclusive ownership of a dynamically allocated object; the object is deleted when the `std::unique_ptr` goes out of scope. It cannot be copied, but can be moved to represent ownership transfer. `std::shared_ptr` is a smart pointer type that expresses shared ownership of a dynamically allocated object. `std::shared_ptr`s can be copied; ownership of the object is shared among all copies, and the object is deleted when the last `std::shared_ptr` is destroyed.

**Pros:**

- It's virtually impossible to manage dynamically allocated memory without some sort of ownership logic.

- Transferring ownership of an object can be cheaper than copying it (if copying it is even possible).

- Transferring ownership can be simpler than 'borrowing' a pointer or reference, because it reduces the need to coordinate the lifetime of the object between the two users.

- Smart pointers can improve readability by making ownership logic explicit, self-documenting, and unambiguous.

- Smart pointers can eliminate manual ownership bookkeeping, simplifying the code and ruling out large classes of errors.

- For `const` objects, shared ownership can be a simple and efficient alternative to deep copying.

**Cons:**

- Ownership must be represented and transferred via pointers (whether smart or plain). Pointer semantics are more complicated than value semantics, especially in APIs: you have to worry not just about ownership, but also aliasing, lifetime, and mutability, among other issues.

- The performance costs of value semantics are often overestimated, so the performance benefits of ownership transfer might not justify the readability and complexity costs.

- APIs that transfer ownership force their clients into a single memory management model.

- Code using smart pointers is less explicit about where the resource releases take place.

- `std::unique_ptr` expresses ownership transfer using move semantics, which are relatively new and may confuse some programmers.

- Shared ownership can be a tempting alternative to careful ownership design, obfuscating the design of a system.

- Shared ownership requires explicit bookkeeping at run-time, which can be costly.

- In some cases (e.g., cyclic references), objects with shared ownership may never be deleted.

- Smart pointers are not perfect substitutes for plain pointers.

**Decision:**

If dynamic allocation is necessary, prefer to keep ownership with the code that allocated it. If other code needs access to the object, consider passing it a copy, or passing a pointer or reference without transferring ownership. Prefer to use `std::unique_ptr` to make ownership transfer explicit. For example:

> <code>
> std::unique_ptr&lt;Foo&gt; FooFactory();<br>
> void FooConsumer(std::unique_ptr&lt;Foo&gt; ptr);
> </code>

Do not design your code to use shared ownership without a very good reason. One such reason is to avoid expensive copy operations, but you should only do this if the performance benefits are significant, and the underlying object is immutable (i.e., `std::shared_ptr<const Foo>`). If you do use shared ownership, prefer to use `std::shared_ptr`.

Never use `std::auto_ptr`. Instead, use `std::unique_ptr`.

### cpplint

Use `cpplint.py` to detect style errors.

`cpplint.py` is a tool that reads a source file and identifies many style errors. It is not perfect, and has both false positives and false negatives, but it is still a valuable tool.

Some projects have instructions on how to run `cpplint.py` from their project tools. If the project you are contributing to does not, you can download `cpplint.py` separately.

## Other C++ Features

### Rvalue References

Use rvalue references only in certain special cases listed below.

**Definition:**

Rvalue references are a type of reference that can only bind to temporary objects. The syntax is similar to traditional reference syntax. For example, `void f(std::string&& s);` declares a function whose argument is an rvalue reference to a `std::string`.

When the token '`&&`' is applied to an unqualified template argument in a function parameter, special template argument deduction rules apply. Such a reference is called a forwarding reference.

**Pros:**

- Defining a move constructor (a constructor taking an rvalue reference to the class type) makes it possible to move a value instead of copying it. If `v1` is a `std::vector<std::string>`, for example, then `auto v2(std::move(v1))` will probably just result in some simple pointer manipulation instead of copying a large amount of data. In many cases this can result in a major performance improvement.

- Rvalue references make it possible to implement types that are movable but not copyable, which can be useful for types that have no sensible definition of copying but where you might still want to pass them as function arguments, put them in containers, etc.

- `std::move` is necessary to make effective use of some standard-library types, such as `std::unique_ptr`.

- Forwarding references which use the rvalue reference token, make it possible to write a generic function wrapper that forwards its arguments to another function, and works whether or not its arguments are temporary objects and/or const. This is called 'perfect forwarding'.

**Cons:**

- Rvalue references are not yet widely understood. Rules like reference collapsing and the special deduction rule for forwarding references are somewhat obscure.

- Rvalue references are often misused. Using rvalue references is counter-intuitive in signatures where the argument is expected to have a valid specified state after the function call, or where no move operation is performed.

**Decision:**

Do not use rvalue references (or apply the `&&` qualifier to methods), except as follows:

- You may use them to define move constructors and move assignment operators (as described in Copyable and Movable Types).

- You may use them to define `&&`-qualified methods that logically "consume" `*this`, leaving it in an unusable or empty state. Note that this applies only to method qualifiers (which come after the closing parenthesis of the function signature); if you want to "consume" an ordinary function parameter, prefer to pass it by value.

- You may use forwarding references in conjunction with `std::forward`, to support perfect forwarding.

- You may use them to define pairs of overloads, such as one taking `Foo&&` and the other taking `const Foo&`. Usually the preferred solution is just to pass by value, but an overloaded pair of functions sometimes yields better performance and is sometimes necessary in generic code that needs to support a wide variety of types. As always: if you're writing more complicated code for the sake of performance, make sure you have evidence that it actually helps.

### Friends

We allow use of `friend` classes and functions, within reason.

Friends should usually be defined in the same file so that the reader does not have to look in another file to find uses of the private members of a class. A common use of `friend` is to have a `FooBuilder` class be a friend of `Foo` so that it can construct the inner state of `Foo` correctly, without exposing this state to the world. In some cases it may be useful to make a unittest class a friend of the class it tests.

Friends extend, but do not break, the encapsulation boundary of a class. In some cases this is better than making a member `public` when you want to give only one other class access to it. However, most classes should interact with other classes solely through their public members.

### Exceptions

We do not use C++ exceptions.

**Pros:**

- Exceptions allow higher levels of an application to decide how to handle "can't happen" failures in deeply nested functions, without the obscuring and error-prone bookkeeping of error codes.

- Exceptions are used by most other modern languages. Using them in C++ would make it more consistent with Python, Java, and the C++ that others are familiar with.

- Some third-party C++ libraries use exceptions, and turning them off internally makes it harder to integrate with those libraries.

- Exceptions are the only way for a constructor to fail. We can simulate this with a factory function or an Init() method, but these require heap allocation or a new "invalid" state, respectively.

- Exceptions are really handy in testing frameworks.

**Cons:**

- When you add a throw statement to an existing function, you must examine all of its transitive callers. Either they must make at least the basic exception safety guarantee, or they must never catch the exception and be happy with the program terminating as a result. For instance, if `f()` calls `g()` calls `h()`, and `h` throws an exception that `f` catches, `g` has to be careful or it may not clean up properly.

- More generally, exceptions make the control flow of programs difficult to evaluate by looking at code: functions may return in places you don't expect. This causes maintainability and debugging difficulties. You can minimize this cost via some rules on how and where exceptions can be used, but at the cost of more that a developer needs to know and understand.

- Exception safety requires both RAII and different coding practices. Lots of supporting machinery is needed to make writing correct exception-safe code easy. Further, to avoid requiring readers to understand the entire call graph, exception-safe code must isolate logic that writes to persistent state into a "commit" phase. This will have both benefits and costs (perhaps where you're forced to obfuscate code to isolate the commit). Allowing exceptions would force us to always pay those costs even when they're not worth it.

- Turning on exceptions adds data to each binary produced, increasing compile time (probably slightly) and possibly increasing address space pressure.

- The availability of exceptions may encourage developers to throw them when they are not appropriate or recover from them when it's not safe to do so. For example, invalid user input should not cause exceptions to be thrown. We would need to make the style guide even longer to document these restrictions!

**Decision:**

On their face, the benefits of using exceptions outweigh the costs, especially in new projects. However, for existing code, the introduction of exceptions has implications on all dependent code. If exceptions can be propagated beyond a new project, it also becomes problematic to integrate the new project into existing exception-free code. Because most existing C++ code at Google is not prepared to deal with exceptions, it is comparatively difficult to adopt new code that generates exceptions.

Given that Google's existing code is not exception-tolerant, the costs of using exceptions are somewhat greater than the costs in a new project. The conversion process would be slow and error-prone. We don't believe that the available alternatives to exceptions, such as error codes and assertions, introduce a significant burden.

Our advice against using exceptions is not predicated on philosophical or moral grounds, but practical ones. Because we'd like to use our open-source projects at Google and it's difficult to do so if those projects use exceptions, we need to advise against exceptions in Google open-source projects as well. Things would probably be different if we had to do it all over again from scratch.

This prohibition also applies to exception handling related features such as `std::exception_ptr` and `std::nested_exception`.

There is an exception to this rule (no pun intended) for Windows code.

### noexcept

Specify `noexcept` when it is useful and correct.

**Definition:**

The `noexcept` specifier is used to specify whether a function will throw exceptions or not. If an exception escapes from a function marked `noexcept`, the program crashes via `std::terminate`.

The `noexcept` operator performs a compile-time check that returns true if an expression is declared to not throw any exceptions.

**Pros:**

- Specifying move constructors as `noexcept` improves performance in some cases, e.g., `std::vector<T>::resize()` moves rather than copies the objects if `T`'s move constructor is `noexcept`.

- Specifying `noexcept` on a function can trigger compiler optimizations in environments where exceptions are enabled, e.g., compiler does not have to generate extra code for stack-unwinding, if it knows that no exceptions can be thrown due to a `noexcept` specifier.

**Decision:**

You may use `noexcept` when it is useful for performance if it accurately reflects the intended semantics of your function, i.e., that if an exception is somehow thrown from within the function body then it represents a fatal error. You can assume that `noexcept` on move constructors has a meaningful performance benefit. If you think there is significant performance benefit from specifying `noexcept` on some other function, please discuss it with your project leads.

Prefer unconditional `noexcept` if exceptions are completely disabled (i.e., most Google C++ environments). Otherwise, use conditional `noexcept` specifiers with simple conditions, in ways that evaluate `false` only in the few cases where the function could potentially throw. The tests might include type traits check on whether the involved operation might throw (e.g., `std::is_nothrow_move_constructible` for move-constructing objects), or on whether allocation can throw (e.g., `absl::default_allocator_is_nothrow` for standard default allocation). Note in many cases the only possible cause for an exception is allocation failure (we believe move constructors should not throw except due to allocation failure), and there are many applications where it’s appropriate to treat memory exhaustion as a fatal error rather than an exceptional condition that your program should attempt to recover from. Even for other potential failures you should prioritize interface simplicity over supporting all possible exception throwing scenarios: instead of writing a complicated `noexcept` clause that depends on whether a hash function can throw, for example, simply document that your component doesn’t support hash functions throwing and make it unconditionally `noexcept`.
