//---------------------------------------------------------------------------

#ifndef PolynomialAndInterpInfoH
#define PolynomialAndInterpInfoH
//---------------------------------------------------------------------------

#include <math.h>
#include <vector>

double factorial(double n);
double func(double x);

<<<<<<< HEAD
const std::wstring LAGRANGE_POLYNOMIAL_STR = L"������� ��������";
const std::wstring NEWTON_I_POLYNOMIAL_STR = L"������� ������� I";
const std::wstring NEWTON_II_POLYNOMIAL_STR = L"������� ������� II";

struct InterpInfo {
	std::wstring functionStr;
    std::wstring polynomialStr;
=======
struct InterpInfo {
	std::wstring functionStr;
>>>>>>> a0c05c5aaf0b878eabd600cfe3d0078cd690247f
	double a, b;
	unsigned int N;
};

struct Polynomial {
	std::vector<double> aVec;
	std::vector<double> xVec;
};

class BasePolynomial {
public:
	BasePolynomial(InterpInfo* info);
	//~BasePolynomial();
    virtual double functionPolynomial(double x) = 0;
protected:
	std::vector<double> aVec;
	std::vector<double> xVec;
	InterpInfo* itsInfo;
	double h;
};

class LagrangePolynomial : public BasePolynomial {
public:
	LagrangePolynomial(InterpInfo* info) : BasePolynomial(info) { }
	double functionPolynomial(double x);
};

class BaseNewtonPolynomial : public BasePolynomial {
public:
	BaseNewtonPolynomial(InterpInfo* info) : BasePolynomial(info) { }
	virtual double functionPolynomial(double x) = 0;
protected:
    virtual double deltaY(int i) = 0;
};

class NewtonIPoly : public BaseNewtonPolynomial {
public:
	NewtonIPoly(InterpInfo* info);
	double functionPolynomial(double x);
private:
	double deltaY(int i);
};

class NewtonIIPoly : public BaseNewtonPolynomial {
public:
	NewtonIIPoly(InterpInfo* info);
	double functionPolynomial(double x);
private:
	double deltaY(int i);
};

#endif
