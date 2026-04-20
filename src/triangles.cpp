#include <iostream>
#include <cmath>
#include <string>

#include "include/triangle.hpp"

namespace geo {

//epsilon untuk perbandingan float
const float EPS = 1e-4f;

bool floatEqual(float a, float b) {
    return std::fabs(a - b) < EPS;
}

Triangle::Triangle() { }

Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3)
    : _t1(t1), _t2(t2), _t3(t3) { }

void Triangle::SetT1(Point2D t1) { _t1 = t1; }
void Triangle::SetT2(Point2D t2) { _t2 = t2; }
void Triangle::SetT3(Point2D t3) { _t3 = t3; }

float Triangle::sideA() const { return _t1.distanceTo(_t2); }
float Triangle::sideB() const { return _t2.distanceTo(_t3); }
float Triangle::sideC() const { return _t1.distanceTo(_t3); }

std::string Triangle::TriangleType() const {
    float a = sideA();
    float b = sideB();
    float c = sideC();

    //cek sama sisi: ketiga sisi sama
    if (floatEqual(a, b) && floatEqual(b, c)) {
        return "sama sisi";
    }

    //cek siku-siku: menggunakan teorema Pythagoras (a² + b² = c²)
    //urutkan sisi agar sisi terpanjang jadi hipotenusa
    float sides[3] = {a, b, c};
    //simple sort 3 elemen
    if (sides[0] > sides[1]) std::swap(sides[0], sides[1]);
    if (sides[1] > sides[2]) std::swap(sides[1], sides[2]);
    if (sides[0] > sides[1]) std::swap(sides[0], sides[1]);

    float s1 = sides[0], s2 = sides[1], s3 = sides[2];
    if (floatEqual(s1*s1 + s2*s2, s3*s3)) {
        return "siku-siku";
    }

    //cek sama kaki: tepat dua sisi yang sama
    if (floatEqual(a, b) || floatEqual(b, c) || floatEqual(a, c)) {
        return "sama kaki";
    }

    //sembarang: tidak ada sisi yang sama
    return "sembarang";
}

} //namespace geo
