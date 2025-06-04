# C++ Module 06 - Exercise 02: Identify Real Type

## Assignment Overview

This exercise focuses on runtime type identification (RTTI) in C++ without using `std::typeinfo`. The goal is to implement a system where we can randomly generate objects of different derived classes and then identify their actual types using `dynamic_cast`.

**Core Requirements:**
- Implement a `Base` class with a public virtual destructor.
- Create three empty classes `A`, `B`, and `C` that publicly inherit from `Base`.
- Implement `Base* generate(void)`: Randomly instantiates `A`, `B`, or `C` and returns the instance as a `Base` pointer.
- Implement `void identify(Base* p)`: Prints the actual type of the object pointed to by `p` ("A", "B", or "C").
- Implement `void identify(Base& p)`: Prints the actual type of the object referenced by `p` ("A", "B", or "C"). **Using a pointer inside this function is forbidden.**
- The `typeinfo` header is forbidden.
- Provide a `main` function to test the implementation.

## Key Concepts Learned

This exercise reinforces understanding of several important C++ concepts:

1.  **Polymorphism:**
    *   The ability to treat objects of different derived classes through a common base class interface (`Base*` or `Base&`).
    *   Essential for `generate()` returning `Base*` and `identify()` functions accepting `Base*` or `Base&`.

2.  **Virtual Destructors:**
    *   Ensuring that the correct destructor (derived class destructor followed by base class destructor) is called when deleting a derived class object through a base class pointer. This prevents memory leaks and undefined behavior.

3.  **Runtime Type Identification (RTTI):**
    *   The process of determining the actual type of an object at runtime.
    *   This exercise specifically explores RTTI using `dynamic_cast`.

4.  **`dynamic_cast` with Pointers:**
    *   `dynamic_cast<DerivedType*>(base_ptr)` attempts to convert `base_ptr` to `DerivedType*`.
    *   If the object pointed to by `base_ptr` is actually of `DerivedType` (or a class derived from it), it returns a valid pointer to the derived object.
    *   Otherwise (if the cast is not possible), it returns `nullptr`.
    *   This is used in `identify(Base* p)`.

5.  **`dynamic_cast` with References:**
    *   `dynamic_cast<DerivedType&>(base_ref)` attempts to convert `base_ref` to a reference of `DerivedType`.
    *   If the object referenced by `base_ref` is actually of `DerivedType` (or a class derived from it), the cast succeeds, and a reference to the derived object is returned.
    *   Otherwise (if the cast is not possible), it throws a `std::bad_cast` exception.
    *   This is the required method for `identify(Base& p)`, as using pointers within this function is forbidden. This necessitates a `try-catch` block to handle potential `std::bad_cast` exceptions.

6.  **Avoiding `std::typeinfo`:**
    *   The exercise explicitly forbids the use of `std::typeinfo` and the `<typeinfo>` header, pushing for the use of `dynamic_cast` for type identification in polymorphic scenarios.

7.  **Random Object Generation:**
    *   Implementing a mechanism to randomly select and instantiate one of the derived classes (`A`, `B`, or `C`).

## Implementation Details

### Classes
-   **`Base`**:
    ```cpp
    class Base {
    public:
        virtual ~Base() {} // Public virtual destructor
    };
    ```
-   **`A`, `B`, `C`**:
    ```cpp
    class A : public Base {};
    class B : public Base {};
    class C : public Base {};
    ```
    These are empty classes inheriting publicly from `Base`.

### Functions
-   **`Base* generate(void)`**:
    *   Uses a random number generator (e.g., `std::rand()`, `std::mt19937`) to choose between 0, 1, or 2.
    *   Based on the choice, instantiates `new A()`, `new B()`, or `new C()` and returns the pointer as `Base*`.

-   **`void identify(Base* p)`**:
    *   Checks the type using `dynamic_cast` with pointers:
    ```cpp
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        // Could be nullptr or a type not in {A, B, C} if hierarchy was different
        std::cout << "Unknown type or null pointer" << std::endl;
    }
    ```

-   **`void identify(Base& p)`**:
    *   Checks the type using `dynamic_cast` with references. This requires `try-catch` blocks because a failed `dynamic_cast` to a reference type throws `std::bad_cast`.
    ```cpp
    // In identify(Base& p)
    // No pointers allowed here for the check itself.
    // The dynamic_cast to reference throws std::bad_cast on failure.
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Suppress unused variable warning if 'a' is not used further
        std::cout << "A" << std::endl;
        return; // Found type A
    } catch (const std::bad_cast& e) {
        // It's not A, try B
    }

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return; // Found type B
    } catch (const std::bad_cast& e) {
        // It's not B, try C
    }

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return; // Found type C
    } catch (const std::bad_cast& e) {
        // This case should ideally not be reached if p is guaranteed
        // to be an instance of A, B, or C.
        std::cout << "Unknown type identified by reference" << std::endl;
    }
    ```

### Main Program (`main.cpp`)
The `main.cpp` should:
1.  Create several `Base*` (e.g., in an array or `std::vector`).
2.  Populate them with objects created by `generate()`.
3.  Iterate through the collection:
    *   Call `identify(base_ptr)` for each pointer.
    *   Call `identify(*base_ptr)` for each dereferenced pointer (to test the reference version).
4.  Clean up dynamically allocated memory (delete each `Base*`).

## Files to Turn In
-   `Makefile`
-   `*.cpp` (e.g., `main.cpp`, and any files defining `Base`, `A`, `B`, `C`, `generate`, `identify`)
-   `*.h` / `*.hpp` (e.g., `Base.hpp`, and any headers for `A`, `B`, `C`)

This exercise provides practical experience with a crucial C++ feature for handling polymorphic objects safely and effectively.
