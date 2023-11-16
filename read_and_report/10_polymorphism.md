# Chapter 12 (no section in particular)

Object-oriented programming is defined by three main concepts: **encapsulation** (discussed in unit 4), **inheritance**, and **polymorphism**. I could try to introduce inheritance here, considering I have yet to talk about it in a read and report, but I just finished writing a paper and would rather go to bed soon. Polymorphism, on the other hand, is a scary word and is also in the name of this Markdown file, so I'll talk about it.

## Programming Without Polymorphism

Before I explain what polymorphism is, let's try drawing some stuff without it. The program we will (not actually) write is meant to draw various shapes throughout the program based on an input from the user.

First, let's define some shape classes.

<table><tr>
	<td><code>
		class Circle {<br>
		&ensp;public:<br>
		&ensp;&ensp;void Draw();<br>
		};
	</code></td>
	<td><code>
		class Rectangle {<br>
		&ensp;public:<br>
		&ensp;&ensp;void Draw();<br>
		};
	</code></td>
	<td><code>
		class Triangle {<br>
		&ensp;public:<br>
		&ensp;&ensp;void Draw();<br>
		};
	</code></td>
</tr></table>

Simple enough. They would probably have a lot more to them in practice, but we're just trying to motivate polymorphism here. Anyway, let's write some code to use these classes.

<code>
	std::cout << "C:\tCircle\nR:\tRectangle\nT:\tTriangle\n";<br>
	std::cout << "Please choose a shape: ";<br>
	<br>
	char choice;<br>
	std::cin >> choice;<br>
	std::cin.ignore();<br>
	<br>
	Circle *c = nullptr;<br>
	Rectangle *r = nullptr;<br>
	Triangle *t = nullptr;<br>
	<br>
	switch (choice) {<br>
	&ensp;&ensp;case 'C':<br>
	&ensp;&ensp;case 'c':<br>
	&ensp;&ensp;&ensp;&ensp;c = new Circle();<br>
	&ensp;&ensp;&ensp;&ensp;c->Draw();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	&ensp;&ensp;case 'R':<br>
	&ensp;&ensp;case 'r':<br>
	&ensp;&ensp;&ensp;&ensp;r = new Rectangle();<br>
	&ensp;&ensp;&ensp;&ensp;r->Draw();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	&ensp;&ensp;case 'T':<br>
	&ensp;&ensp;case 't':<br>
	&ensp;&ensp;&ensp;&ensp;t = new Triangle();<br>
	&ensp;&ensp;&ensp;&ensp;t->Draw();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	}
</code>

<br>

If you're anything like me, alarm bells are going off in your head right now. There is sooo much repitition in this code, and extending it would be a pain. We can't do much about that `switch` statement if we want to process the user's input, but wouldn't it be nice if we could simplify the creation and use of the different shapes? This is exactly what inheritance and polymorphism allow us to do.

## Refactoring With Polymorphism

Let's start by generalizing each shape class. In our example, each shape was identical, so having multiple doesn't make too much sense, but there would be some differences in practice. Nevertheless, we know that any shape we create will have some common features.

<code>
	class Shape {<br>
	&ensp;public:<br>
	&ensp;&ensp;virtual void Draw();<br>
	};
</code>

<br>

Notice that `virtual` keyword. You don't have to think too much about what it means, but it's essentially there to allow subclasses to override the method.

Anyway, time to rewrite those class definitions.

<code>
	class Circle : public Shape { ... };<br>
	class Rectangle : public Shape { ... };<br>
	class Triangle : public Shape { ... };<br>
</code>

<br>

That was easy. Like I said, you can add more functionality to these classes if you'd like, but what matters to us is that all of these shapes have a `Draw()` method by default. This cleans up our driver drastically.

<code>
	std::cout << "C:\tCircle\nR:\tRectangle\nT:\tTriangle\n";<br>
	std::cout << "Please choose a shape: ";<br>
	<br>
	char choice;<br>
	std::cin >> choice;<br>
	std::cin.ignore();<br>
	<br>
	Shape *s = nullptr;<br>
	<br>
	switch (choice) {<br>
	&ensp;&ensp;case 'C':<br>
	&ensp;&ensp;case 'c':<br>
	&ensp;&ensp;&ensp;&ensp;s = new Circle();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	&ensp;&ensp;case 'R':<br>
	&ensp;&ensp;case 'r':<br>
	&ensp;&ensp;&ensp;&ensp;s = new Rectangle();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	&ensp;&ensp;case 'T':<br>
	&ensp;&ensp;case 't':<br>
	&ensp;&ensp;&ensp;&ensp;s = new Triangle();<br>
	&ensp;&ensp;&ensp;&ensp;break;<br>
	}<br>
	<br>
	if (s != nullptr) s->Draw();
</code>

<br>

It's worth mentioning that, in the textbook's no-polymorphism section, the calls to `Draw()` were placed in a second `switch` statement. This might be necessary depending on the application, but to save myself some time and effort, I compressed them into one `switch` statement. In the polymorphic case, though, there's a clear benefit to delaying the call until after the first `switch` statement: you only have to call `Draw()` once, and you don't have to worry about what shape you're drawing.

## The Prerequisites for Polymorphism

Before you go off to use polymorphism in all your OOP stuff, you should know that there are five requirements for it to work:

### Inheritance

There must be at least one class that inherits from a parent class. Without multiple classes, there's no point to polymorphism anyway.

### Function Overriding

You must be able to override the definition of a method in your subclasses. This means that a caller can unknowingly call a child class's version of the method.

### A Pointer or Reference Variable

I understand why this is a requirement, but I can't exactly explain it. Just know that it is one.

### Upcasting

You must be able to point a parent-type pointer to a child-type object with no issues.

### A Virtual Function

If the `virtual` keyword is omitted, any calls to the child method will result in the parent method being ran instead. Including the `virtual` keyword fixes this.
