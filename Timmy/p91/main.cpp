#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
    Point() {
        x = 0;
        y = 0;
    }
    bool equals(Point b) {
        return b.x == x && b.y == y;
    }
    string str() {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

struct Line {
    Point a;
    Point b;
    float length;

    Line() {
    }
    
    Line(Point a1, Point b1) {
        a = a1;
        b = b1;
        length = sqrt(pow((float)a.x - (float)b.x, 2) + pow((float)a.y - (float)b.y, 2));
    }
    bool valid() {
        return !a.equals(b);
    }
    string str() {
        return "L[" + a.str() + ", " + b.str() + "]";
    }
};

struct Triangle {
    Line a;
    Line b;
    Line c;

    Triangle(Point ap, Point bp, Point cp){
        Line a1 = Line(ap, bp);
        Line b1 = Line(bp, cp);
        Line c1 = Line(ap, cp);
        if (a1.length > b1.length && a1.length > c1.length) {
            a = c1;
            b = b1;
            c = a1;
        }
        else if (b1.length > a1.length && b1.length > c1.length) {
            a = a1;
            b = c1;
            c = b1;
        }
        else {
            a = a1;
            b = b1; 
            c = c1;
        }
    }

    Triangle(Line a1, Line b1, Line c1) {
        if (a1.length > b1.length && a1.length > c1.length) {
            a = c1;
            b = b1;
            c = a1;
        }
        else if (b1.length > a1.length && b1.length > c1.length) {
            a = a1;
            b = c1;
            c = b1;
        }
        else {
            a = a1;
            b = b1; 
            c = c1;
        }
    }

    bool valid() {
        return a.valid() && b.valid() && c.valid();
    }

    bool isRight() {
        float al = a.length;
        float bl = b.length;
        float cl = c.length;
        //cout << cl << endl;
        float a2 = pow(al, 2);
        float b2 = pow(bl, 2);
        float ab = sqrt(a2 + b2);
        float c2 = pow(cl,2);
        // cout << (ab == cl) << endl;
        // cout << a2 << " + " << b2 << " = " << c2 << endl;
        // cout << (a2 + b2 == c2) << endl;
        return ab == cl;
    }
    string str() {
        return a.str() + ", " + b.str() + ", " + c.str();
    }
    void print() {
        cout << a.str() + ", " + b.str() + ", " + c.str() << endl;
    }
};

bool hasRightAngle(int a, int b, int c) {
    int A, B, C;
    if (a > b && a > c) {
        A = c;
        B = b;
        C = A;
    }
    else if (b > a && b > c) {
        A = a;
        B = c;
        C = b;
    }
    else {
        A = a;
        B = b;
        C = c;
    }
    return pow(A, 2) + pow(B, 2) == pow(C, 2);
}

bool noOverlappingPoints(int ax, int ay, int bx, int by, int cx, int cy) {
    bool ab = ax == bx && ay == by;
    bool ac = ax == cx && ay == cy;
    bool bc = cx == bx && cy == by;
    return !ab && !ac && ! bc;
}

int rightTrianglesInRange(int n) {
    int tris = 0;
    Point origin = Point();
    for (int ax = 0; ax <= n; ax++) {
        for (int ay = 0; ay <= n; ay++) {
            Point a = Point(ax, ay);
            for (int bx = 0; bx <= n; bx++) {
                for (int by = 0; by <= n; by++) {
                    Point b = Point(bx, by);
                    Line ab = Line(a,b);
                    Line ac = Line(a,origin);
                    Line bc = Line(b,origin);
                    Triangle t = Triangle(ab, ac, bc);
                    t.print();
                    if (t.valid() && t.isRight()) {
                        tris += 1;
                    }
                }
            }
        }
    }
    return tris;
}

int main(int argc, char** argv) {
    Triangle t = Triangle(Point(0,0), Point(1,0), Point(0,1));
    //t.print();
    //cout << t.isRight() << endl;
    cout << rightTrianglesInRange(2) << endl;
    return 0;
}