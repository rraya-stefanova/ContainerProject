🧩 Project Description – Custom Generic Set Management Framework
This project represents a custom-built framework for managing collections of sets and multisets of elements,
implemented in C++ using templates and object-oriented design principles.
It offers a flexible, reusable foundation for handling different types of data collections—such as sets,
multisets, and containers of these sets—focused on generic programming and memory-safe design.

💡 Key Components:
✅ Set<T>
A fully templated class representing a mathematical set—a collection of unique elements of type T.
Handles dynamic memory allocation with manual management (free, copyFrom, move).
Complies with the Rule of Five: copy/move constructors, assignment operators, and destructor.

Supports:
- addElement() with uniqueness enforcement.
- print() for outputting the set contents.
- operator[] with bounds checking and fallback.
- clone() for deep-copy polymorphism.
- setName() and getName() for labeling sets.
Ideal for both standalone use and polymorphic storage (as seen in the Container class).

🔁 MultiSet<T>
Likely an extension or separate implementation of Set<T> that allows duplicate elements.
Used where frequency counts or repeated entries are meaningful (e.g., word counting, inventory).

📦 Container
Manages a dynamic array of Set<char>*, enabling the storage and manipulation of multiple polymorphic sets (e.g., mixing Set<char> and MultiSet<char>).
Implements:
- Copy/move semantics.
- Dynamic resizing.
- Deep copying of contained sets via clone().
- addSymbols() to populate sets from a character list.

🧪 main() Function
- Demonstrates usage of Set<int>, MultiSet<int>, and Set<char> variants.
- Dynamically creates and stores sets in a Set<char>* array.
- Shows labeling, populating, and printing sets/multisets.
- Serves as an example or test driver for the framework.


