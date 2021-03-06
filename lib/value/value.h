#pragma once

#include <iostream>
#include <memory>

#include "value_visitor.h"

class IAdditionValueVisitor;
class ISubtractionValueVisitor;
class IMultiplicationValueVisitor;
class IDivisionValueVisitor;
class IPowerValueVisitor;

/*=======================================VALUE=======================================*/

class Value {
public:
    Value(){};
    virtual ~Value(){};

    virtual double value() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Value& val);
    virtual void print(std::ostream& os) const = 0;

    static std::unique_ptr<Value> read(std::istream& is);

    virtual std::unique_ptr<Value> clone() const = 0;

    // Addition
    virtual void accept(IAdditionValueVisitor& visitor) const = 0;

    virtual std::unique_ptr<Value> operator+(const Value& other) const;

    virtual std::unique_ptr<Value> operator+(const Fraction& other) const = 0;
    virtual std::unique_ptr<Value> operator+(const Irrational& other) const = 0;

    // Subtraction
    virtual void accept(ISubtractionValueVisitor& visitor) const = 0;

    virtual std::unique_ptr<Value> operator-(const Value& other) const;

    virtual std::unique_ptr<Value> operator-(const Fraction& other) const = 0;
    virtual std::unique_ptr<Value> operator-(const Irrational& other) const = 0;

    // Multiplication
    virtual void accept(IMultiplicationValueVisitor& visitor) const = 0;

    virtual std::unique_ptr<Value> operator*(const Value& other) const;

    virtual std::unique_ptr<Value> operator*(const Fraction& other) const = 0;
    virtual std::unique_ptr<Value> operator*(const Irrational& other) const = 0;

    // Division
    virtual void accept(IDivisionValueVisitor& visitor) const = 0;

    virtual std::unique_ptr<Value> operator/(const Value& other) const;

    virtual std::unique_ptr<Value> operator/(const Fraction& other) const = 0;
    virtual std::unique_ptr<Value> operator/(const Irrational& other) const = 0;

    // Power
    virtual void accept(IPowerValueVisitor& visitor) const = 0;

    virtual std::unique_ptr<Value> power(const Value& other) const;

    virtual std::unique_ptr<Value> power(const Fraction& other) const = 0;
    virtual std::unique_ptr<Value> power(const Irrational& other) const = 0;
};

/*=======================================FRACTION=======================================*/

class Fraction : public Value {
private:
    int nominator_, denominator_;

public:
    Fraction(int nominator = 0, int denominator = 1);

    virtual double value() const override;

    int nominator() const;
    int denominator() const;

    void setNominator(int nom);
    void setDenominator(int den);

    virtual void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Fraction& val);

    Fraction(const Fraction& fraction);

    virtual std::unique_ptr<Value> clone() const override;

    // Addition
    virtual void accept(IAdditionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator+(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator+(const Irrational& other) const override;

    // Subtraction
    virtual void accept(ISubtractionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator-(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator-(const Irrational& other) const override;

    // Multiplication
    virtual void accept(IMultiplicationValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator*(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator*(const Irrational& other) const override;

    // Division
    virtual void accept(IDivisionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator/(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator/(const Irrational& other) const override;

    // Power
    virtual void accept(IPowerValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> power(const Fraction& other) const override;
    virtual std::unique_ptr<Value> power(const Irrational& other) const override;

private:
    void initializeFraction(int nominator, int denominator);
};

/*=======================================IRRATIONAL=======================================*/

class Irrational : public Value {
private:
    double value_;

public:
    Irrational(double value = 0.0) : value_(value) {}

    virtual double value() const override;

    void setValue(double val);

    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Irrational& val);

    Irrational(const Irrational& irrational);

    virtual std::unique_ptr<Value> clone() const override;

    // Addition
    virtual void accept(IAdditionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator+(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator+(const Irrational& other) const override;

    // Subtraction
    virtual void accept(ISubtractionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator-(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator-(const Irrational& other) const override;

    // Multiplication
    virtual void accept(IMultiplicationValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator*(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator*(const Irrational& other) const override;

    // Division
    virtual void accept(IDivisionValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> operator/(const Fraction& other) const override;
    virtual std::unique_ptr<Value> operator/(const Irrational& other) const override;

    // Power
    virtual void accept(IPowerValueVisitor& visitor) const override;

    virtual std::unique_ptr<Value> power(const Fraction& other) const override;
    virtual std::unique_ptr<Value> power(const Irrational& other) const override;
};