#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "point2d.hpp"
#include <string>

namespace geo {

class Triangle {
    private:
        Point2D _t1, _t2, _t3;

    public:
        Triangle();
        Triangle(Point2D t1, Point2D t2, Point2D t3);

        void SetT1(Point2D t1);
        void SetT2(Point2D t2);
        void SetT3(Point2D t3);

        Point2D GetT1() const { return _t1; }
        Point2D GetT2() const { return _t2; }
        Point2D GetT3() const { return _t3; }

        //hitung panjang ketiga sisi
        float sideA() const; //sisi t1 dan t2
        float sideB() const; //sisi t2 dan t3
        float sideC() const; //sisi t1 dan t3

        //tentukan tipe segitiganya
        std::string TriangleType() const;
};

} // namespace geo

#endif
