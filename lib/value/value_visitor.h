#pragma once
#include <memory>

class Value;
class Fraction;
class Irrational;

class IValueVisitor {
public:
    virtual ~IValueVisitor(){};
    virtual void visit(const Fraction& fraction) = 0;
    virtual void visit(const Irrational& irrational) = 0;
};

//=================================Addition=================================

class IAdditionValueVisitor : virtual public IValueVisitor {
public:
    std::unique_ptr<Value> val;
};

class AdditionFractionVisitor : public IAdditionValueVisitor {
    const Fraction& value_;

public:
    AdditionFractionVisitor(const Fraction& f) : value_(f) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class AdditionIrrationalVisitor : public IAdditionValueVisitor {
    const Irrational& value_;

public:
    AdditionIrrationalVisitor(const Irrational& i) : value_(i) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class AdditionValueVisitor : public IAdditionValueVisitor {
    const Value& value_;

public:
    AdditionValueVisitor(const Value& val) : value_(val) {}
    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

//=================================Subtraction=================================

class ISubtractionValueVisitor : virtual public IValueVisitor {
public:
    std::unique_ptr<Value> val;
};

class SubtractionFractionVisitor : public ISubtractionValueVisitor {
    const Fraction& value_;

public:
    SubtractionFractionVisitor(const Fraction& f) : value_(f) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class SubtractionIrrationalVisitor : public ISubtractionValueVisitor {
    const Irrational& value_;

public:
    SubtractionIrrationalVisitor(const Irrational& i) : value_(i) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class SubtractionValueVisitor : public ISubtractionValueVisitor {
    const Value& value_;

public:
    SubtractionValueVisitor(const Value& val) : value_(val) {}
    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

//=================================Multiplication=================================

class IMultiplicationValueVisitor : virtual public IValueVisitor {
public:
    std::unique_ptr<Value> val;
};

class MultiplicationFractionVisitor : public IMultiplicationValueVisitor {
    const Fraction& value_;

public:
    MultiplicationFractionVisitor(const Fraction& f) : value_(f) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class MultiplicationIrrationalVisitor : public IMultiplicationValueVisitor {
    const Irrational& value_;

public:
    MultiplicationIrrationalVisitor(const Irrational& i) : value_(i) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class MultiplicationValueVisitor : public IMultiplicationValueVisitor {
    const Value& value_;

public:
    MultiplicationValueVisitor(const Value& val) : value_(val) {}
    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

//=================================Division=================================

class IDivisionValueVisitor : virtual public IValueVisitor {
public:
    std::unique_ptr<Value> val;
};

class DivisionFractionVisitor : public IDivisionValueVisitor {
    const Fraction& value_;

public:
    DivisionFractionVisitor(const Fraction& f) : value_(f) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class DivisionIrrationalVisitor : public IDivisionValueVisitor {
    const Irrational& value_;

public:
    DivisionIrrationalVisitor(const Irrational& i) : value_(i) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class DivisionValueVisitor : public IDivisionValueVisitor {
    const Value& value_;

public:
    DivisionValueVisitor(const Value& val) : value_(val) {}
    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

//=================================Power=================================

class IPowerValueVisitor : virtual public IValueVisitor {
public:
    std::unique_ptr<Value> val;
};

class PowerFractionVisitor : public IPowerValueVisitor {
    const Fraction& value_;

public:
    PowerFractionVisitor(const Fraction& f) : value_(f) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class PowerIrrationalVisitor : public IPowerValueVisitor {
    const Irrational& value_;

public:
    PowerIrrationalVisitor(const Irrational& i) : value_(i) {}

    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};

class PowerValueVisitor : public IPowerValueVisitor {
    const Value& value_;

public:
    PowerValueVisitor(const Value& val) : value_(val) {}
    virtual void visit(const Fraction& fraction) override;
    virtual void visit(const Irrational& irrational) override;
};