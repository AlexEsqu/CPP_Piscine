[The C++ Tutorial](https://www.learncpp.com/)

# 1\. Introduction

## Statements

**Program**: Sequence of instruction manipulating data to produce a desired result

**Statement**: Type of instruction causing the program to perform some action; smallest independent unit of computation in C++ but may compile into many machine language instructions ; generally end in `;`.

*   Declaration statement:
    *   Definition statement: `int x;`
    *   Assignment statement: `x = 5;`
    *   Initialization statement: `int x = 5;`
*   Jump statement
*   Expression statement
*   Compound statement
*   Selection statement (conditionals)
*   Iteration statement (loops)
*   Try blocks

**Function**: Collection of statement executed sequentially

**Identifier**: Name of a function or object, type, template…

Preprocessor directive:

**Library file**: Collection of precompiled code packaged for reuse in other programs such as the C++ Standard Library

**Comment**: Human readable note inserted in the source code of a program and ignored by compiler

*   Before Library, program, or function: use comments to describe _what_.
*   Inside library, program, or function: use comments to describe _how_.
*   Statement level: use comments to describe _why_.

## Initialization

**Data**: Any information that can be moved, processed or stored by a computer

**Value**: Single piece of data, such as number (`5`, `-6.7`), character (`’H’`, `‘$’`) or text (`”Hello”`, `“”`).

**Literals**: Values placed directly into the source code which cannot be changed

**Random Access Memory** (RAM): main memory in a computer

**Object**: Region of storage (RAM or CPU register) which can hold a value, and has associated properties, used in C++ instead of direct memory access

**Variable**: Object with an identifier (as opposed to unnamed or anonymous objects), a type, indicating how they are interpreted) and a value. They are created at runtime when memory is allocated for their use

**Definition**: Declaration statement defining a variable with an identifier.

**Assignment**: Giving a value to a defined variable

**Initialization**: Defining and providing an initial value for a variable

*   **Default initialization**: Performs no initialization and leaves at default/garbage value - `int x;`
*   **Copy initialization**: Copies right hand value into left hand variable - `int x = 5;`
*   **Direct initialization**: Also used when static casting `int x ( 6 );`
*   **Uniform / Brace / Direct List initialization**: Initializes multiple objects with consistent behavior and unambiguous syntax, disallowing narrowing conversions by providing compiling error if the variable cannot safely hold the value; preferred in modern C++ - `int x { 6 };`
*   **Copy List initialization**: Less common variant of direct list initialization - `int x = { 6 };`
*   **Value initialization / Zero initialization**: Implicitly initialize the value to default values if existing or zero or closest for given type - `int x {};`
*   Aggregate initialization : Memberwise initialization of an aggregate such as an array or struct
    *   List initialization: `MyClass x { 1, 32, 60000.0 };`
    *   Copy list initialization: `MyClass x = { 1, 32, 60000.0 };`
*   Reference initialization: `int& ref { x };`
*   Static initialization: `;`
*   Constant initialization: `constexpr double gravity { 9.8 };`
*   Dynamic initialization: `int g_myGlobalVar{ init() };`

**Instantiation**: Variable is allocated and initialized, and can sometimes be called an instance

`[[maybe_unused]]`: C++17 keyword to avoid compilation warning if the variable is not used

## Io-stream

`<<`: Insertion operator

`std::cout`: character output

`std::endl`: prints a newline and flushes the `cout` buffer, making it less efficient than `\n`

`>>`: Extraction operator

`std::cin`: character input dropping any white space, if int drops anything after integer and remainders stays in buffer for later extractions, fails if not digit

## Undefined behavior

**Implementation**: specific compiler and the associated standard library it comes with

*   **Undefined behavior** **/ UB**: Result of executing code whose behavior is not well-defined by the C++ language - Ex: using uninitialized variable
*   **Implementation-defined behavior**: Behavior defined by the implementation, but must be documented and consistent for this given implementation - Ex: `sizeof(int)`
*   **Unspecified behavior**: Behavior left up to the implementation to define, but not required to be defined

## Style Best Practice

*   Variable and function name start with lowercase letter
*   User defined types start with uppercase letter
*   Multi words are either separated by underscore (snake\_case) or intercapped (camelCase)
*   Avoid starting identifier with \_ as typically reserved for OS/library/compiler
*   Length of identifier proportional to the how long it is used / often accessed / specific to a value
*   Match the style of the code you’re working with, even if not best practice
*   processing directive must be placed on separate lines
*   keep lines to 80chars or less in length

## Operators

**Operation**: Process operating a specific operation (denoted by a symbol called **operator**) with zero or more input values (called **operands**) that produces a new value (called **output value**)

**Operators**: generally represented as `operator+` or `operator==`

*   standard arithmetic operators such as addition (`+`), subtraction (`-`), division (`/`)…
*   C++ specific symbols such as assignment (`=`), insertion (`<<`), extraction (`>>`), equality (`==`)
*   C++ keywords such as `new`, `delete` and `throw`

**Arity**: Number of operands that an operator takes as input

*   **Unary**: Operator acting on 1 operand (`operator-` in operations inverting a sign such as `-5`)
*   **Binary**: Operator acting on 2 operand called left and right (`operator-` in operations such as `1 - 2`, `operator>>` and `operator<<` taking `std::cout`or `std::cin` as left side…)
*   **Ternary**: Conditional operator
*   **Nullary**: Throw operator

**Side Effect**: Observable effect of an operator or function beyond producing a return value (assignment operator, insertion operator… which generally return their left values)

## Expression

**Expression**: Non empty sequence of literals, variables, operators and function calls that calculate a value; must be contained in a statement ( ex: `x = 1 + 3` )

**Evaluation**: Process of executing an expression

**Return value:** Result of an evaluation, which can be a value, and object, a function, or nothing

**Expression statement**: Statement with expression followed by a semicolon (ex: `x = 1 + 3;`)

**Subexpression**: Expression used as an operand (ex: `4 + 5` and `x` in `x = 4 + 5` )

**Full expression**: Expression that is not a subexpression (ex: `x = 1 + 3`)

**Compound expression**: Expression that contains two or more uses of operators (ex: `x = 4 + 6` contains `+` and `=`)

# 2\. Functions

**Function**: Reusable sequence of statement designed to do a particular job

Function call: Tells CPU to interrupt current function and execute another, bookmarking current point of execution to do so, and returning to that point to resume execution

**Caller**: Function initiating/from which the new function is called/invoked

**Callee**: Function being called/invoked

Function header: Tells compiler about the function existence, name/identifier, and return type

Function body: Curly braced and statement within in a function definition

Nested function: Function whose definition is placed inside another function, illegal in C++

**Metasyntactic variable**: Placeholder names such as foo, bar, baz…

### Value returning function

**Return by value**: Returning a copied value from function back to caller

Status/Exit/Return code: Return value from main used to signify whether a program was successful (0) or encountered an error (positive int as error value)

DRY: Don’t Repeat Yourself ≠ WET: Write Everything Twice

Early return: Return statement that is not the last statement in a function

**Whitespace**: Character used for formatting purposes, in C++ spaces, tabs and newlines

### Function Parameters

**Function parameter**: Variable used in header of a function, initialized with value by function caller

**Argument**: Value passed from the caller to the function when a function call is made

**Pass by value**: When a function is called, the value of its argument is copied into the matching parameter using copy initialization

**Unreferenced parameters**: Parameters not used by the body of the function

**Unnamed parameter**: If a parameter needs to exist but is not used, to avoid generating error, remove its name as parameter name is optional; can be documented in comment like `void doSomething(int /*count*/)`

### Local Variable

**Local variable**: Variables defined in the body of a function (or function parameters)
Should be declared as close as possible to their use

**Lifetime**: Runtime property - time during which a variable stays in memory and is accessible

**Scope**: Compile time property - part of the code where an identifier can be seen and used

**Temporary object** / **Anonymous object**: unnamed object used to hold a value only needed for a short period of time; they have no scope and no identifier, and are destroyed at the end of the full expression in which they are created

### Forward declaration

**Function prototype**: Function declaration statement ex: `int add(int x, int y);`

**Declaration**: Tell the compiler about the existence of an identifier and its associated type info

**Definition**: Declaration that implements (for function and types) or instantiate (for variable)
In C++, all definition are declarations

**Pure Declaration**: Declaration that aren’t definition, including forward declaration

**ODR / One Definition Rule**:

1.  Within a file, each function, variable, type or template in a scope can only have 1 definition
2.  Within a program, each function or variable in a scope can only have one definition
3.  Types, templates, inline functions and inline variable can have duplicate definition if identical

### Namespace

**Naming collision / Naming conflict**: Error produced when two identical identifiers are introduced in the same program, creating a compiler error if in same file, or linker error if in different files

**Scope Region**: Area of source code where all declared identifiers are considered distinct from names declared in other scopes, such as the body of a function

**Namespace**: Scope region only allowing declaration and definition

**Global Scope** / Global Namespace: Implicitly defined scope/namespace of any name not defined inside a class, function or namespace

`::`: Scope resolution operator, assumes global if no left identifier

**Qualified name**: Identifier including a namespace prefix

`**using**` **directive**: Allows to access the names in a namespace without the prefix

## Preprocessor

**Preprocessing phase**: Preprocesssor program makes various changes to the text of the code file
Ex: Strips out comment, adds newlines, process `#include` directives…

Translation: Process of preprocessing + compiling + linking

**Preprocessing directive**: Special instruction for the preprocessor transforming its output
They start with `#` , use specific syntax, and end with a newline
They are resolved before compilation from top to bottom file by file, then all defined identifier are discarded, so directive from one file not included have no impact on other files

**Macro**: Rule that defines how input text is converted into replacement output text
Good practice: Macro identifier in uppercase separated by underscore

*   Object-Like Macro: Act like functions, considered unsafe
    ex: `#define USE_YEN`
*   Function-Like Macro: Defines an identifier, sometimes with a substitution value
    ex: `#define MY_NAME "Alex"`

Conditional Compilation: Allows to specify under what condition something will or won’t compile

*   `#ifdef`: Check whether an identifier has been defined via #define, compile if so, else ignores
    Similar to `#if defined(IDENTIFIER)`

```c
#include <iostream>
#define PRINT_JOE
int main()
{
    #ifdef PRINT_JOE
        std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
    #endif
    #ifdef PRINT_BOB
        std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
    #endif
    return 0;
}
```

*   `#ifndef`: Check whether an identifier has been defined via #define, compile if not, else ignores
    Similar to `#if !defined(IDENTIFIER)`
*   `#if 0`: Exclude a block of code you can’t comment out for some reason (nested comments…)
    `#if 1`: Include the block of code back

## Header Files

**Header**: File used to propagate related forward declaration, suffixed .h or .hpp
Not added in compile command but implicitly included by #include statement
Source files should #include their paired header files if one exists

`<>` / angled brackets: Instruction to search the header only in directories specified by the `include directories`, as configured in compiler settings
To be used for header from compiler, OS or third party library

`“”` / double quotes: Instruction to first search in the current directory, then `include directories`

**Transitive Includes**: Headers included by the current header, which are implicitly included along; not reliable and should be avoided

Good practice:

*   **Order of Inclusion**: It is best practice to include files in the following order

1.  Paired header file (`#include “add.h”` in `add.cpp`)
2.  Other header from same project (`#include “mymath.h”`)
3.  3rd party header (`#include <boost/tuple/tuple.hpp>`)
4.  Standard library headers (`#include <iostream>`)

*   **Header guard / Include guard**: Conditional compilation directive checking whether an Identifier has been previously defined in this translation unit
    The unique identifier of a header can be anything, but it is best to have it identical to the header name (+ eventual path to the file if nested)
*   Each header has a specific job and is as independent as possible
*   Includes all other header needed for its functionality, and only these
*   Never include .cpp files
*   Documentation on what something does or how to use it
    Leaving documentation on how it does it for the source files

## Creating a Program

### Design

1.  Define goal in one sentence
2.  Define requirements : Constraints (budget, timeline, space, memory…) + capabilities
3.  Define tools, targets and backup plan
4.  Break down tasks into smaller tasks, either top down or bottom up
5.  Define the sequence of events

### Implementation

Outlining the main function with comments

Implement each function:

- define function prototype

- write function

- test function

- final testing

> _A complex system that works is invariably found to have evolved from a simple system that worked -_ John Gall, _Systemantics: How Systems Really Work and How They Fail_ p. 71

> _Premature optimization is the root of all evil_ - Donald Knuth

# 3\. Debugging

Syntax Error: Occurs when writing a statement that is not valid in C++ grammar

Semantic Error: Occurs when statement is syntactically valid but either:

*   violates rule of the language or
*   does not do what the programmer intended

### Bug finding Strategies

*   Code inspection
*   Running the program

**Reproduction steps**: List of clear and precise steps which can be followed to cause an issue to recur with high predictability
\- Commenting out
\- Validating code flow by printing statement at start of each function, ideally in `std::cerr`
\- Printing values of variables
\- Conditionalizing the debug code with `#ifdef DEBUG` and `#endif`
\- Logging, especially using `std::clog`, writes to `cerr` by default but can be redirected with tools such as the `<plog/Log.h>` or `spdlog`
**Log**: Sequential records of events that happened, usually time stamped
\- **Stepping**: Execute code statement by statement
**Program State**: Variable values + functions called + current point of execution
**Debugger**: Program allowing programmer to control how another program is running and examine its state
**Break point**: Special marker telling the debugger to stop execution
\- Watching variables: Inspecting the value of a variable while the program is executing in debug mode
**Call stack**: List of all active functions that have been called to the current point of execution

**Refactoring**: Process of making structural changes to a code without changing its behavior
Better to make behavioral OR structural changes, then test

**Defensive programming**: Programmer tries to anticipate all misuse cases to mitigate them

**Unit testing**: Software testing method in which small units of source code are tested

Constraint based techniques: Use of assertion or other constraints to check assumptions

**Static analysis tools / linters**: Programs that analyze source code without executing it (static) to identify specific semantic issues
Ex: clang-tidy, cpplint, cppcheck, SonarLint, Coverty, SonarQube…

# 4\. Fundamental Data Types

Bit / Binary Digit: smallest unit of memory, which can hold 0 or 1

Byte: Group of bits operated on as a unit, on modern machine generally 8 sequential bits

Memory addresses: sequential units of bytes (8 bits) in which memory is organized

Data Type: Interpretation of the binary value stored at a memory address,
Often suffixed with a `_t`; grouped in 3 groups:

**Fundamental / Primitive Data Types**: Most basic of the predetermined data types

`void`

Floating Point

Integral

1\. **Standard Integral types**: Fundamental data types stored as integer in memory
`int`, `short`, `long`, `long long` & `unsigned` variants
2\. `bool`
3\. `char`, `wchar_t` …
2\. **Compound Types**:
3\. Standard Library Types

**Incomplete Type**: Type that has been declared (compiler knows about it) but not defined (compiler does not know how much memory to allocated for objects of that type)
Used in C to denote function not returning a value, but deprecated in C++

## Object size

Size of a type: size in memory of an instantiated object of that type

C++ standard does not define the byte size of things but sets up a few ground rules

*   Object must occupy at least 1 byte
*   Byte must be at least 8 bits
*   Integral type minimum size :
    *   `char`: 8 bits
    *   `short` : 16 bits
    *   `int`: 16 bits
    *   `long`: 32 bits
    *   `long long` : 64 bits
*   `char`and `char8_t`are exactly 1 byte (at least 8 bits)

| Category | Type | Minimum Size | Typical Size |
| --- | --- | --- | --- |
| Boolean | bool | 1 byte | 1 byte |
| Character | char | 1 byte (exactly) | 1 byte |
|   | wchar\_t | 1 byte | 2 or 4 bytes |
|   | char8\_t | 1 byte | 1 byte |
|   | char16\_t | 2 bytes | 2 bytes |
|   | char32\_t | 4 bytes | 4 bytes |
| Integral | short | 2 bytes | 2 bytes |
|   | int | 2 bytes | 4 bytes |
|   | long | 4 bytes | 4 or 8 bytes |
|   | long long | 8 bytes | 8 bytes |
| Floating point | float | 4 bytes | 4 bytes |
|   | double | 8 bytes | 8 bytes |
|   | long double | 8 bytes | 8, 12, or 16 bytes |
| Pointer | std::nullptr\_t | 4 bytes | 4 or 8 bytes |

### Sizeof

`**sizeof**` **operator**: unary operator taking type or a variable and returns the size of an object of that type in byte; compilation error on a incomplete type such as void (unless GCC which returns 1)

## Integer

### Signed Integer

**Sign**: Attribute of being positive, negative or zero

**Integer**: Integral type that can represent positive and negative whole numbers, including 0

`signed`: optional keyword to indicate an integer is signed; already is by default

**Range**: All possible values a variable can hold, determined by its size in bits and whether signed

| Size / Type | Range |
| --- | --- |
| 8-bit signed | \-128 to 127 |
| 16-bit signed | \-32,768 to 32,767 |
| 32-bit signed | \-2,147,483,648 to 2,147,483,647 |
| 64-bit signed | \-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |

**Overflow**: Undefined behavior when during the evaluation of an expression the result is not mathematically defined or not in the range of the representable value for its type

### Unsigned Integer

**Unsigned Integer**: Integer than can only hold non negative numbers
`unsigned`: keyword to create unsigned integer
If out of range, divided by range + 1 and becomes remainder (”wraps around” / “modulo wrapping”)

*   Pro: Well suited for networking and systems with little memory
*   bit manipulation
*   wrap-around behavior
*   array indexing (unavoidable)
*   embedded systems for performance reasons
*   Con: Easier to overflow if lower than 0 + unexpected values when compared/mixed with signed
    Unsigned to be avoided for:
*   holding quantities even if should be non negative
*   will be compared/mixed with signed

### Fixed Width Integer

C intentionally left size of integer open to compiler implementers to perform best on each architecture, but less useful on modern, standardized architecture, so C++11 added:

| Name | Fixed Size | Fixed Range |
| --- | --- | --- |
| `std::int8_t` | 1 byte signed | \-128 to 127 // treated as signed char, so ascii interpret |
| `std::uint8_t` | 1 byte unsigned | 0 to 255 // treated as unsigned char |
| `std::int16_t` | 2 byte signed | \-32,768 to 32,767 |
| `std::uint16_t` | 2 byte unsigned | 0 to 65,535 |
| `std::int32_t` | 4 byte signed | \-2,147,483,648 to 2,147,483,647 |
| `std::uint32_t` | 4 byte unsigned | 0 to 4,294,967,295 |
| `std::int64_t` | 8 byte signed | \-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `std::uint64_t` | 8 byte unsigned | 0 to 18,446,744,073,709,551,615 |

**Fixed Width Integer**: Aliases for existing integral types with corrected size for architecture

*   Pro: Known size + portable
*   Con: May exhibit different behavior depending on architecture
*   not always defined on all architectures (but usually is on modern machine)
*   may be slower on some architectures if optimized differently

**Fast Integral type**: Returns the fastest signed/unsigned integer types of a width of at least # bits
Ex: `std::int_fast32_t`

**Least Integral Type**: Returns the smallest signed/unsigned integer of a width of at least # bits
Ex: `std::uint_least32_t`

### size\_t

`std::size_t` : Alias (typedef) for implementation defined unsigned integral type
Defined in multiple header, `<cstddef>` is the best to include
Is the return value of the `sizeof`operator
Is the proper maximum size of an object according the C++20 standard

### Best Practice

*   `int` if size does not matter
*   `std::int#_t` if storing quantity that needs a guaranteed range
*   `std::uint#_t` if bit manipulation OR wrap-around (random generation, crypto…)
*   Avoid `short`, `long` , fast, least, 8-bit fixed and any compiler specific fixed width integers

## Floating Point Numbers

### Scientific Notation

**Scientific Notation**: Shorthand for writing lengthy numbers as $significant \* 10 ^{exponent}$

**Significant Digit**: Digit in the significant ⇒ the more significant, the more precise
Trailing zeroes are significant if decimal, or if part of precise measurement

### Floating Point

Floating point: Variable that can hold a number with a fractional component, with variable digits before and after the decimal point

**Precision** of a floating point: How many significant digits can be represented without information loss, depending both on the size and the type of the value

`float`: single precision floating point data type, typically 4 bytes

`double`: double precision floating point data type, typically 8 bytes, default if fractional

`long double`: Vary between 8 and 16 bytes, strange and to be avoided

Representation with `std::cout`:

*   Truncate a trailing 0, assuming it isn´t significant
*   Defaults to 6 precision and truncate rest

**Output manipulator**: function altering how data is output, typically in `<iomanip>` header
Ex: `std::setprecision(int new_precision)` , `std::setw`

**Rounding error**: Precision is lost because a number can’t be stored precisely
Makes comparison tricky
Errors increase with addition and multiplication

### NaN and Inf

`NaN`: Stands for “Not a Number”

`inf`: Represent infinity, can be signed

Signed zero: Separate representation for +0.0 and -0.0

## Boolean Values

Boolean value: Variable that can have only two possible value : `true`/ 0 or `false` / 1
Considered integral type since actually stores 1 or 0
Doesn’t compile if assigned anything else, but will convert any integer as false or if 0 to true

`std::boolalpha` allows to print or input true or false instead of 1 or 0 until `std::noboolalpha`

### If Statements

**If Statement**: Executes code only if condition is true

**Condition** / Conditional Expression: Expression which evaluates to a boolean value

## Chars

char: Data type designed to hold a single character (letter, number, symbol or whitespace)
Integral type storing an integer interpreted as an ASCII character
Character literals are always between single quotes: `'a'`
Always 1 byte in size per C++ standard

ASCII: American Standard Code for Information Interchange, interpreting English characters and some symbols as numbers between 0 and 127 called an ASCII code or code point
Outside of that range, the result of printing char is OS dependant

Unprintable chars: Characters from 0 to 131, designed to control peripherals & mostly obsolete

**Escape Sequences**: Sequence of characters holding special meaning such as `‘/n'` or `'/t'`

**Multicharacter Literals**: Char literal which contain multiple characters, which if supported have an implementation defined value ⇒ to be avoided

Unicode standard: Character representation containing over 144.000 integer to character, stored in a 32 bit (UTF-32) or multiple 16 and 8 bit character (UTF-16 and UTF-8)

## Type conversion

Type conversion: converting value from one data type to another, stored in a temporary object

Implicit type conversion: Converting a value to the expected type without explicit casting
Usually generates a warning if unsafe (risk changing the value)

Explicit type conversion: Tell the compiler to convert to a type, generally using `static_cast<mew_type>(expression)`

# 5\. Constants

Constant: Value that might not be changed during the program’s execution

*   Constant variable
*   Object-like macro with substitution text (`#define A "hello and goodbye"` )
*   Enumerated constants

Named / symbolic constants: Constants associated with an identifier

Literal constant: Constant not associated with an identifier

## Constant variables

Constant variable: Variable whose value cannot be changed after initialization, marked `const`

*   DO NOT USE for:
    *   Function parameter
    *   Return value
*   USE whenever else possible, since it:
    *   reduce chances of bugs
    *   allows for optimization
    *   reduce complexity

## Object-like Macro

To be avoided because:

*   does not scope like normal C++ code but by preprocessor directive syntax
*   Replace code, creating weird compilation errors
*   Disconnect between code written and code compiled / debugger output

## Type qualifier

**Type qualifier**: Keyword applied to a type modifying how that type behaves

*   `const`
*   `volatile`

**CV-qualified**: Type with a type qualifier

## Literal

**Literals / Literal constants**: Values inserted directly into the code and cannot be redefined

**Literal suffixes**: If default type of a literal is not desired, can be changed with:

| Data type | Suffix | Meaning |
| --- | --- | --- |
| integral | u or U | unsigned int |
| integral | l or L | long |
| integral | ul, uL | unsigned long |
| integral | ll or LL | long long |
| integral | ull, uLL | unsigned long long |
| integral | z or Z | The signed version of std::size\_t (C++23) |
| integral | uz, uZ | std::size\_t (C++23) |
| floating point | f or F | float |
| floating point | l or L | long double |
| string | s | std::string |
| string | sv | std::string\_view |

**String**: Collection of sequential characters used to represent text

**C-Style String**: Fundemental string data type inherited from C
`const` object garanteed to exist for the entirety of the program != `std::string`: temporaty objects destroyed at the end of the full expression where they are created
Implicitly null terminated

**Magic Number**: Literal (often number) which has unclear meaning or may require to be changed later; better to replace with named symbolic constexpr

### Numeral Systems

- Decimal : By default
- Binary : No support before C++14, since `0b` prefix
- Octal : `0` prefix - `int x{ 012 }`
- Hexadecimal : `0x` prefix - `int x { 0xF }`
    Useful to represent 4 bits since 16 different value per digit

**Digit separator**: Since C++14, can add `\'` as visual non value impacting digit separator

### Printing binary numbers

- `std::bitset<int numOfBitStored>` in the `<bitset>` header allow to print binary numbers

    Ex: `std::cout << std::bitset<4>{ 0b1010 } << '\n';`

- In C++20 `<format>`, can use the `std::format()` function

    Ex: `std::cout << std::format("{:b}\n", 0b1010);`

- In C++23 `<print>` headers, can use the `std::printl()`

    Ex: `std::println("{:b} {:#b}", 0b1010, 0b1010);`


## Optimization

**Optimization**: Process of modifying software to make it work more efficiently

**Profiler**: Program to see how long various parts of the program are taking to run and impacting overall performance

**Optimizer**: Program looking for ways to improve statements or expression by rezriting, reordering or eliminating them to optimize them for a specific system

**As-If Rule**: Compiler can modify a program however it likes in order to produce more optimized code so long as these modification don't affect the program's observable behavior (except copy constructor)

- **Compile-time Evaluation**: When a compiler fully or partially evaluates an expression at compile time instead of at runtime, to produce faster and smaller executable at the cost of longer compilation time

- **Constant folding**: Optimization technique where the compiler replaces expressions that have a literal operand with the result of the expression
Ex: `int x{ 3 + 4 }` => `int x{7}`

- **Constant propagation**: Optmization technique where the compiler replaces variables with a constant values with their values to reduce memory access operations

- **Dead Code elimination**: Optimization technique where the compiler removes (optimize away) code that may be excuted but has no effect on the program's behavior; Helped by declaring values as const

**Compile-time constant**: Constant whose value is known at compile time

    Ex: Literals, constant objects whose initializers are compile-time constants

**Runtime constant**: Constant whose value is determined in a runtime context

    Ex: Constant function parameters...

```C
#include <iostream>

int five() { return 5; }

int pass(const int x) // x is a runtime constant
{ return x; }

int main()
{
    // The following are non-constants:
    [[maybe_unused]] int a { 5 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 5 };
    [[maybe_unused]] const double c { 1.2 };
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { five() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime

    return 0;
}
```

However, even runtime constant may sometimes be evaluated at compile time for optimzation, and some compile time constant cannot be used in compile time features




## Constant Expression

- By default, expression evaluate at runtime.

- Some expression must evaluate at runtime, like input and output

- Some requires an expression that can be evaluated at compile-time

    Ex: Initializer of a `constexpr`

    Ex: Non type template argument

    Ex: Defined length of a std::array or C-style array

**Constant Expression**: Expression which must be executable at compile-time (during compilation, but can include preprocessor directive)

Constant expression can include :
- Literals
- Most operand with constant expression operancs
- Constant integral variable with const expression intializer (although `constexpr` are preferred)
- `constexpr` variable
- `constexpr` function call with constant expression arguments

But they cannot include :
- Non const variables
- const non integral variables (`const double`...), need `constexpr` instead
- return of non-constexpr functions (even if returns const expression)
- Function parameters
- Operator with non const operands (`std::cout`... )
- `new`, `delete`, `throw`, `typeif`, `operator,`

### Benefits of Compile-Time Programming

**Compile-time programming**: Explicit request for code to execute at compile time
- Better performance: Executable is smaller and faster
- Versatility: works even if compiler change optimization
- Predictability
- Quality: Ensure reliable detection of programming errors at compilation
- Quality: Undefined behavior is not allowed at compile-time (if the compiler can identify it)

**Manifestly constant-evaluated expression**: Expression that must be evaluated at compile time


# 6\. Operators

# O. Bit Manipulation

# 7\. Scope, Duration and Linkage

# 8\. Control Flow

# 9\. Error Detection and Handling

# 10\. Type

# 11\. Overloading

# 11\. Templates

# F. Constexpr function

# 12\. Compound Types

## Reference

## Pointers

# 13\. Compound Types

## Enums

## Structs

# 14\. Classes

# 15\. More on Classes

# 16\. Dynamic Arrays: std::vectors

# 17\. Fixed Sized Arrays: std::array and C-style array

# 18\. Iterators

# 19\. Dynamic Allocation

# 20\. Functions

# 21\. Operator Overloading

# 22\. Move Semantic and Smart Pointers

# 23\. Object Relationship

# 24\. Inheritance

# 25\. Virtual Functions

# 26\. Templates and Classes

# 27\. Exceptions

# 28\. Input and Output

# A. Misc

# B. C++ Updatesof sequential of
