#include "value_visitor.h"

#include "value.h"

//=================================Addition=================================

void AdditionFractionVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction + value_);
}

void AdditionFractionVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational + value_);
}

void AdditionIrrationalVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction + value_);
}
void AdditionIrrationalVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational + value_);
}

void AdditionValueVisitor::visit(const Fraction& fraction) {
    AdditionFractionVisitor fractionVisitor(fraction);
    value_.accept(fractionVisitor);
    val = std::move(fractionVisitor.val);
}
void AdditionValueVisitor::visit(const Irrational& irrational) {
    AdditionIrrationalVisitor irrationalVisitor(irrational);
    value_.accept(irrationalVisitor);
    val = std::move(irrationalVisitor.val);
}

//=================================Subtraction=================================

void SubtractionFractionVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction - value_);
}

void SubtractionFractionVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational - value_);
}

void SubtractionIrrationalVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction - value_);
}
void SubtractionIrrationalVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational - value_);
}

void SubtractionValueVisitor::visit(const Fraction& fraction) {
    SubtractionFractionVisitor fractionVisitor(fraction);
    value_.accept(fractionVisitor);
    val = std::move(fractionVisitor.val);
}
void SubtractionValueVisitor::visit(const Irrational& irrational) {
    SubtractionIrrationalVisitor irrationalVisitor(irrational);
    value_.accept(irrationalVisitor);
    val = std::move(irrationalVisitor.val);
}

//=================================Multiplication=================================

void MultiplicationFractionVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction * value_);
}

void MultiplicationFractionVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational * value_);
}

void MultiplicationIrrationalVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction * value_);
}
void MultiplicationIrrationalVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational * value_);
}

void MultiplicationValueVisitor::visit(const Fraction& fraction) {
    MultiplicationFractionVisitor fractionVisitor(fraction);
    value_.accept(fractionVisitor);
    val = std::move(fractionVisitor.val);
}
void MultiplicationValueVisitor::visit(const Irrational& irrational) {
    MultiplicationIrrationalVisitor irrationalVisitor(irrational);
    value_.accept(irrationalVisitor);
    val = std::move(irrationalVisitor.val);
}

//=================================Division=================================

void DivisionFractionVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction / value_);
}

void DivisionFractionVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational / value_);
}

void DivisionIrrationalVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction / value_);
}
void DivisionIrrationalVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational / value_);
}

void DivisionValueVisitor::visit(const Fraction& fraction) {
    DivisionFractionVisitor fractionVisitor(fraction);
    value_.accept(fractionVisitor);
    val = std::move(fractionVisitor.val);
}
void DivisionValueVisitor::visit(const Irrational& irrational) {
    DivisionIrrationalVisitor irrationalVisitor(irrational);
    value_.accept(irrationalVisitor);
    val = std::move(irrationalVisitor.val);
}

//=================================Power=================================

void PowerFractionVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction.power(value_));
}

void PowerFractionVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational.power(value_));
}

void PowerIrrationalVisitor::visit(const Fraction& fraction) {
    val = std::move(fraction.power(value_));
}
void PowerIrrationalVisitor::visit(const Irrational& irrational) {
    val = std::move(irrational.power(value_));
}

void PowerValueVisitor::visit(const Fraction& fraction) {
    PowerFractionVisitor fractionVisitor(fraction);
    value_.accept(fractionVisitor);
    val = std::move(fractionVisitor.val);
}
void PowerValueVisitor::visit(const Irrational& irrational) {
    PowerIrrationalVisitor irrationalVisitor(irrational);
    value_.accept(irrationalVisitor);
    val = std::move(irrationalVisitor.val);
}