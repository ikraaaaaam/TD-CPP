#include "MatrixBase.h"
#include "MatrixNumerical.h"

int main() {
    MatrixNumerical<double> mat1(2, 2);
    MatrixNumerical<double> mat2(2, 2);

    mat1.addElement(0, 0, 1.0);
    mat1.addElement(0, 1, 2.0);
    mat1.addElement(1, 0, 3.0);
    mat1.addElement(1, 1, 4.0);

    mat2.addElement(0, 0, 5.0);
    mat2.addElement(0, 1, 6.0);
    mat2.addElement(1, 0, 7.0);
    mat2.addElement(1, 1, 8.0);

    MatrixNumerical<double> sum = mat1 + mat2;
    MatrixNumerical<double> difference = mat1 - mat2;
    MatrixNumerical<double> product = mat1 * mat2;
    MatrixNumerical<double> scalarMultiplication = mat1 * 2.0;

    sum.display();
    difference.display();
    product.display();
    scalarMultiplication.display();

    MatrixNumerical<double> identity = MatrixNumerical<double>::getIdentity(2);
    identity.display();

    double determinant = mat1.getDeterminant();
    cout << "Determinant of mat1: " << determinant << endl;

    return 0;
}
