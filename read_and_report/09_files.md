# 14.1 - Intro to Files & I/O Streams

## Files

A file is a collection of bytes stored non-volatilely (i.e., on the hard drive or some similar device), assigned a name and location in an abstract file structure. Files typically conform to an agreed-upon standard based on the extension at the end of the file name. Below are some broad file types:

### Text

A text file is designed to store plain text. They commonly appear as `.txt` files, but essentially any file format that can be reasonably read by a human in a plain text editor fits the bill. This includes source code for nearly any programming language (i'm looking at you, piet), markup documents, and human-readable data storage formats like `.json` and `.csv`.

### Raster Image

A raster image file is designed to store a 2D array of pixels that can be displayed to the user. Many raster formats exist, but the most common ones are `.png`, `.jpg/.jpeg`, and `.bmp`. They cannot be reasonably interpreted by hand, as almost all of these formats perform complex operations to compress or decompress the image, and even if you had the raw pixel data, it would be hard to understand what the image represented without drawing each pixel as you read the bytes. Thus, they would make zero sense in plain text and hex editors.

### Vector Image

Unlike raster images, vector images are designed to store a series of mathematically-defined curves that form an image when plotted in the Cartesian coordinate system. Due to their inherent lack of granular data, these images can be scaled up and down without loss of quality. Furthermore, they can be much smaller due to how little information is needed to define a single cubic Bezier curve (the standard curve used in vector graphics, defined by four points). Common formats include `.svg`, `.pdf`, and `.ai`.

### Binary

As the name would suggest, binary file formats are designed specifically for computers to read. They are quite efficient in that regard, but they are by far the hardest for a human to decipher by hand. Not only are they unintuitive and information-dense, but most binary formats are completely proprietary and thus require substantial knowledge of how the file is used and implemented in practice. They are the standard for object and save-data storage as well as executable files (`.exe`). Some binary files have no extension whatsoever, but it's generally good practice to provide some meaningful extension if a human might ever need to know about the file's existence.

## Streams

There are many ways to move data around, but by far the most common is serial data transmission. This is present in USB (which stands for universal serial bus), telecommunication, and even basic programming. Consider the basic "Hello, World!" program written in C++:

> <code>
> #include &lt;iostream&gt;<br>
> <br>
> int main() {<br>
> &ensp;&ensp;std::cout &lt;&lt; "Hello, World!\n";<br>
> &ensp;&ensp;return 0;<br>
> }
> </code>

<br>

See that `#include` statement at the top of the file? The `iostream` library relies on streams, which are inherently serial. New programmers will likely become very familiar with `std::cout` (console out) and `std::cin` (console in), but these are just two of the many streams available.

### `istream` and `ostream`: The Fundamental Streams

Streams come in two flavors: input and output. On the most basic level, input streams write data, whereas output streams read data. The aforementioned `std::cout` and `std::cin` are instances of the `std::ostream` and `std::istream` classes respectively. Besides the `std::ios` class, these two are the most fundamental streams in the C++ language.

It can sometimes be confusing to reason through which stream to use. The console streams are fairly intuitive, but reading and writing to other types of objects is less so. The basic rule to keep in mind is that the words "input" and "output" apply directly to the thing the stream is pointing to. If you want to write to a file, you're putting data **into** that file and therefore should use an input stream (specifically `std::ifstream`). Similarly, if you want to read from a file, you're getting data **out** of that file, so you should use an output stream (specifically `std::ofstream`).

# 14.2 - Important File Footnotes

Although files are very familiar to most people nowadays, there are some things worth mentioning.

## The File System

In basically any operating system, there is a mechanism for locating and manipulating files in non-volatile storage. Instead of showing the user the files exactly as they are ordered on the hard drive, the operating system provides a file system. This is a tree-like structure of directories (a.k.a. folders) and files that allows for meaningful categorization and organization.

There isn't an easy way to visualize the file structure in a Markdown document without embedding an image, but I'm thankfully not trying to explain that to you. What matters to our discussion is the difference between absolute and relative paths.

### Absolute Paths

An absolute (or full) file path is one that starts at the name of the drive and works its way down to the file in question. There is no ambiguity as to where the file might be, so long as all users are using the same machine. Here's an absolute path to a hypothetical text document on my computer:

`C:/Users/rose/Documents/RiemannHypothesisProof.txt`

The defining characteristic of an absolute path is the presence of that `C:/` at the beginning. It doesn't have to be a `C` (as that'll depend on the drive), but the point is that there's no parent directory. You may have a `C` drive and a `D` drive like I do, which both are on the same hierarchal level, but they aren't siblings because they never had or ever will have parents.

Although absolute paths can be incredibly precise, they rely on the assumption that the entire file structure is known ahead of time. Of course, shipping an app that needs to be stored in a very specific set of directories and subdirectories relative to a drive with a predefined name would be asinine. It's very unlikely that your users will have the same file structure as you, and there's no good reason to force everyone to adopt one uniform structure. Absolute paths have their place, but you probably shouldn't use them across machines.

### Relative Paths

A relative path is, well, relative. The destination is in the eye of the caller; that is, where the path leads depends on which directory the code is starting at. Take this (once again hypothetical) path for example:

`no_brainers/09_pirate_speak/translator.h`

Notice how the path doesn't start with a drive. A relative path can start at any point along the path, so long as it makes sense in the context it's used in. The example was inspired by my assignment submissions for this class. All my assignments are arranged in a single repository called `cs-1410`, and every path in the repo assumes that `cs-1410` is the root directory*. I don't have to know what the grader's file structure is in the event they want to compile the code themselves. I control the structure of the repo, and that's enough to specify a valid path.

\**Side Note: The paths never refer to `cs-1410` directly. This is because I submit assignments by zipping the contents of a folder called `submission`, which serves as a proxy root for the grader. If I used `cs-1410` explicitly, the `submission` folder would have to be named that as well, and it's also not as clean.*

### File Separators

Although file paths are relatively standard among operating systems, not everyone could agree on which character to use for the file separator. In all my code and the examples provided in my notes, directories and files are separated by the forward slash (`/`). This is standard in Linux and macOS, but Windows decided to be quirky and use the backslash (`\`). Thus, paths written for Windows may not work in Linux, and vice-versa.

What is even more frustrating about Windows' approach is that the backslash is often interpreted as an escape character. Essentially, it isn't included in the resultant string and serves as a way to either negate the meaning of special characters or code for a special character like an end-line. Therefore, using backslashes as a file separator makes you write paths like this:

`C:\\Users\\rose\\github\\frick-windows\\wtf.txt`

We're probably never going to recover from this dumb decision, but if you happen to be writing an operating system, please just use forward slashes for your file separators.

## Special Characters

In the ASCII encoding scheme, which used to be the standard for North American text, there are 128 possible characters. 52 of these characters are letters in the alphabet, 10 are decimal digits, 1 is the space character, and 32 are symbols like brackets and elementary math operations. For those keeping track, that added up to 95 characters, not 128. This is because the other 33 characters are special characters you never see. Many of these don't matter to most people, but there are a select few that genuinely matter to the common programmer:

- `0x00` (`"\0"`): NULL
- `0x09` (`"\t"`): HORIZONTAL TAB
- `0x0A` (`"\n"`): LINE FEED
- `0x0D` (`"\r"`): CARRIAGE RETURN

Because most of these can't be directly inserted into a string with a single keystroke, programmers needed a way to put them in anyway. This is where escape sequences come in. You may have noticed the string representation next to the hex values. Preceding some ASCII characters with a backslash converts the combination into its corresponding control character.

### The Carriage Return

Wahoo, another great disparity between operating systems... For whatever reason, Windows never let go of the carriage return character. This used to be the character that would tell a printhead to return to the left margin of the page, and it was often used in conjunction with the line feed to move to the next line. Nowadays, we have no reason to include the carriage return, as there's no printhead to move. Instead, we can just slap a line feed on the end of each line, and the operating system knows what to do.

That's how Linux and macOS work, anyway. Windows still requires each line to end with both a carriage return and a line feed. Most programs nowadays are aware of this discrepancy and will add or remove carriage returns depending on the operating system, but a few still don't. Essentially, just make sure you take this into consideration when handling text.
