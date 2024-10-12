import java.util.Scanner;

class Matrix {
    private int[][] elements;
    private int rows;
    private int cols;

    // Constructor to initialize matrix with size
    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        elements = new int[rows][cols];
    }

    // Method to read matrix from user input
    public void readMatrix(Scanner sc) {
        System.out.println("Enter elements of matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                elements[i][j] = sc.nextInt();
            }
        }
    }

    // Method to display the matrix
    public void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(elements[i][j] + "\t");
            }
            System.out.println();
        }
    }

    // Addition of two matrices
    public Matrix add(Matrix other) {
        if (this.rows != other.rows || this.cols != other.cols) {
            throw new IllegalArgumentException("Matrix dimensions do not match for addition.");
        }
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.elements[i][j] = this.elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    // Subtraction of two matrices
    public Matrix subtract(Matrix other) {
        if (this.rows != other.rows || this.cols != other.cols) {
            throw new IllegalArgumentException("Matrix dimensions do not match for subtraction.");
        }
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.elements[i][j] = this.elements[i][j] - other.elements[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    public Matrix multiply(Matrix other) {
        if (this.cols != other.rows) {
            throw new IllegalArgumentException("Matrix dimensions do not match for multiplication.");
        }
        Matrix result = new Matrix(this.rows, other.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < this.cols; k++) {
                    result.elements[i][j] += this.elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    // Transpose of matrix
    public Matrix transpose() {
        Matrix transposed = new Matrix(this.cols, this.rows);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                transposed.elements[j][i] = this.elements[i][j];
            }
        }
        return transposed;
    }

    // Determinant of matrix (for square matrices)
    public int determinant() {
        if (this.rows != this.cols) {
            throw new IllegalArgumentException("Determinant can only be calculated for square matrices.");
        }
        return calculateDeterminant(this.elements, this.rows);
    }

    // Helper method to calculate determinant recursively
    private int calculateDeterminant(int[][] matrix, int n) {
        if (n == 1) return matrix[0][0];
        int det = 0;
        int[][] temp = new int[n][n];
        int sign = 1;
        for (int f = 0; f < n; f++) {
            getCofactor(matrix, temp, 0, f, n);
            det += sign * matrix[0][f] * calculateDeterminant(temp, n - 1);
            sign = -sign;
        }
        return det;
    }

    // Method to find cofactor for determinant calculation
    private void getCofactor(int[][] matrix, int[][] temp, int p, int q, int n) {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != p && col != q) {
                    temp[i][j++] = matrix[row][col];
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Inverse of matrix
    public Matrix inverse() {
        int det = this.determinant();
        if (det == 0) {
            throw new IllegalArgumentException("Matrix inverse doesn't exist (determinant is 0).");
        }
        Matrix adjoint = adjointMatrix();
        Matrix inverse = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                inverse.elements[i][j] = adjoint.elements[i][j] / det;
            }
        }
        return inverse;
    }

    // Adjoint of matrix
    public Matrix adjointMatrix() {
        Matrix adjoint = new Matrix(this.rows, this.cols);
        if (this.rows == 1) {
            adjoint.elements[0][0] = 1;
            return adjoint;
        }
        int sign;
        int[][] temp = new int[this.rows][this.rows];
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                getCofactor(this.elements, temp, i, j, this.rows);
                sign = (i + j) % 2 == 0 ? 1 : -1;
                adjoint.elements[j][i] = sign * calculateDeterminant(temp, this.rows - 1);
            }
        }
        return adjoint;
    }

    // Scalar multiplication
    public Matrix scalarMultiply(int scalar) {
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.elements[i][j] = this.elements[i][j] * scalar;
            }
        }
        return result;
    }
}

public class MatrixCalculatorApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns for matrix A:");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        Matrix matrixA = new Matrix(r1, c1);
        matrixA.readMatrix(sc);

        System.out.println("Choose operation: 1. Add 2. Subtract 3. Multiply 4. Transpose 5. Determinant 6. Inverse 7. Scalar Multiplication");
        int choice = sc.nextInt();

        switch (choice) {
            case 1:
                System.out.println("Enter rows and columns for matrix B (should be the same as A):");
                int r2 = sc.nextInt();
                int c2 = sc.nextInt();
                if (r1 != r2 || c1 != c2) {
                    System.out.println("Addition not possible.");
                } else {
                    Matrix matrixB = new Matrix(r2, c2);
                    matrixB.readMatrix(sc);
                    Matrix result = matrixA.add(matrixB);
                    System.out.println("Sum of matrices:");
                    result.displayMatrix();
                }
                break;

            case 2:
                // Subtraction case similar to addition

            case 3:
                // Multiplication case

            case 4:
                Matrix transposed = matrixA.transpose();
                System.out.println("Transpose of matrix:");
                transposed.displayMatrix();
                break;

            case 5:
                int det = matrixA.determinant();
                System.out.println("Determinant: " + det);
                break;

            case 6:
                Matrix inverse = matrixA.inverse();
                System.out.println("Inverse of matrix:");
                inverse.displayMatrix();
                break;

            case 7:
                System.out.println("Enter scalar value:");
                int scalar = sc.nextInt();
                Matrix scaled = matrixA.scalarMultiply(scalar);
                System.out.println("Scalar multiplied matrix:");
                scaled.displayMatrix();
                break;

            default:
                System.out.println("Invalid choice.");
        }

        sc.close();
    }
}

