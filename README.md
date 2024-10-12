
## Matrix Calculator Project

### Overview
This project implements a Matrix Calculator in both **C** and **Java**. The calculator supports several matrix operations including:
- Addition
- Subtraction
- Multiplication
- Transpose
- Determinant
- Inverse
- Scalar Multiplication
- Variance (C version)

The **C version** is implemented in a procedural style, while the **Java version** uses Object-Oriented Programming (OOP) concepts for improved modularity and maintainability.

---

### Features
The matrix calculator supports:
- **Matrix Addition**: Adds two matrices of the same size.
- **Matrix Subtraction**: Subtracts one matrix from another.
- **Matrix Multiplication**: Multiplies two matrices where the number of columns in the first matrix matches the number of rows in the second matrix.
- **Matrix Transpose**: Computes the transpose of a matrix.
- **Determinant**: Calculates the determinant of square matrices.
- **Matrix Inverse**: Finds the inverse of a matrix if the determinant is non-zero.
- **Scalar Multiplication**: Multiplies each element of the matrix by a scalar value.
- **Variance Calculation**: (Only in C version) Computes the variance of a matrix (or list) of numbers.

---

### C Program

#### Requirements
- **Compiler**: GCC or any C compiler.
- **Libraries**: Standard C libraries (`stdio.h`, `math.h`, `stdlib.h`).

#### Compilation and Execution
To compile and run the **C** program:
1. Open a terminal.
2. Navigate to the directory containing the source file (`main.c`).
3. Run the following commands:
   ```bash
   gcc main.c -o matrix_calculator
   ./matrix_calculator
   ```

#### Program Flow
1. The program first prompts the user to select a matrix operation from the menu.
2. Based on the user input, matrices are read from the console.
3. The chosen matrix operation is performed, and the result is displayed.
4. Error checking ensures invalid operations (e.g., multiplying matrices with incompatible dimensions) are handled gracefully.

#### Key Functions
- `add()`: Adds two matrices.
- `subtract()`: Subtracts one matrix from another.
- `multiply()`: Multiplies two matrices.
- `transpose()`: Transposes a matrix.
- `det()`: Recursively calculates the determinant of a matrix.
- `inverse()`: Computes the inverse of a matrix if its determinant is non-zero.

---

### Java Program

#### Requirements
- **Java Development Kit (JDK)**: Version 8 or above.

#### Compilation and Execution
To compile and run the **Java** program:
1. Open a terminal.
2. Navigate to the directory containing the source file (`MatrixCalculator.java`).
3. Compile the program:
   ```bash
   javac MatrixCalculator.java
   ```
4. Run the program:
   ```bash
   java MatrixCalculatorApp
   ```

#### Program Flow
1. The program prompts the user to enter the dimensions of the matrix and to input the elements.
2. The user selects an operation from the menu (addition, subtraction, etc.).
3. Depending on the operation, a new matrix is computed and displayed.

#### Key OOP Features
- **Encapsulation**: The `Matrix` class encapsulates matrix data and operations.
- **Modularity**: Methods like `add()`, `subtract()`, `multiply()`, and `transpose()` allow matrix operations to be performed on instances of the `Matrix` class.
- **Error Handling**: Input validation and exception handling (e.g., for incompatible matrix operations) are built into the program.
- **Reusable Components**: The `Matrix` class methods can be reused across multiple instances of matrices for various operations.

---

### Comparison: C vs. Java

- **Structure**: The C version follows a procedural programming style, while the Java version adopts object-oriented principles.
- **Flexibility**: The Java version is more modular and easier to maintain due to its class-based structure.
- **Error Handling**: The Java version uses exception handling to catch errors related to invalid matrix operations, while the C version uses simple conditional checks.
- **Reusability**: In Java, matrix operations can be reused as methods in the `Matrix` class, making the code cleaner and more adaptable.
- **Performance**: Both versions are optimized for standard matrix operations, but Java offers better scalability for larger projects due to its OOP nature.

---

### License
This project is open-source and can be used and modified under the terms of the MIT License.

---

### Author
- **Ananya.V**: Developer of both C and Java implementations for the matrix calculator.

---

Feel free to modify this **README** as needed for your submission or distribution!
