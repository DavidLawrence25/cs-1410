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