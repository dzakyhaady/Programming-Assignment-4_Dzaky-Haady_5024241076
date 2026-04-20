#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "include/point2d.hpp"
#include "include/triangle.hpp"

using namespace std;
using namespace geo;

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;

    /*--------------------------
    Buat loop untuk membuat menginputkan data triangle (3 buah X Y Z data) ke dalam
    variable triangles
    --------------------------*/
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;

        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cin >> x3 >> y3 >> z3;

        Point2D p1(x1, y1, z1);
        Point2D p2(x2, y2, z2);
        Point2D p3(x3, y3, z3);

        Triangle t(p1, p2, p3);
        triangles.push_back(t);
    }
    /*------------------------*/


    /*--------------------------
    Implementasikan kode untuk melakukan pengecekan apakah data pada variable triangles
    adalah "sama kaki", "sama sisi", "siku-siku", atau "sembarang"
    --------------------------*/
    for (int i = 0; i < (int)triangles.size(); i++) {
        cout << triangles[i].TriangleType() << endl;
    }

    return 0;
}
