#include <iostream>
#include <vector>
#include <float.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Tower {
    double x, y, angle;

    Tower() {}
    Tower(double x, double y) : x(x), y(y), angle(0.0) {}
};

Tower pivot;

double cross(const Tower &O, const Tower &A, const Tower &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool angleCmp(const Tower &A, const Tower &B) {
    if (A.angle != B.angle) return A.angle < B.angle;
    double dxA = A.x - pivot.x, dyA = A.y - pivot.y;
    double dxB = B.x - pivot.x, dyB = B.y - pivot.y;
    return dxA * dxA + dyA * dyA < dxB * dxB + dyB * dyB;
}

bool determinant(const Tower &O, const Tower &A, const Tower &B) {
    return O.x * A.y + A.x * B.y + B.x * O.y - O.x * B.y - A.x * O.y - B.x * A.y <= 0;
}

double distance(const Tower& A, const Tower& B) {
    return hypot(A.x - B.x, A.y - B.y);
}

double triangleArea(const Tower& A, const Tower& B, const Tower& C, double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Tower> towers;
    double a, b;
    Tower o(DBL_MAX, DBL_MAX);
    int idx;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        towers.emplace_back(a, b);
        if (b < o.y || (b == o.y && a < o.x)) {
            o.x = a;
            o.y = b;
            idx = i;
        }
    }

    std::swap(towers[0], towers[idx]);
    pivot = o;

    for (int i = 1; i < n; ++i) {
        towers[i].angle = atan2(towers[i].y - pivot.y, towers[i].x - pivot.x);
    }

    std::sort(towers.begin() + 1, towers.end(), angleCmp);

    std::vector<Tower> v;

    v.push_back(towers[0]);
    v.push_back(towers[1]);
    for (int i = 2; i < n; ++i) {
        while (v.size() >= 2 && determinant(v[v.size() - 2], v.back(), towers[i])) {
            v.pop_back();
        }
        v.push_back(towers[i]);
    }

    double area = 0.0;
    for (int i = 2; i < v.size(); ++i) {
        double a = distance(v[0], v[i - 1]);
        double b = distance(v[i - 1], v[i]);
        double c = distance(v[i], v[0]);
        area += triangleArea(v[0], v[i - 1], v[i], a, b, c);
    }

    std::cout << std::fixed << std::setprecision(3) << area << std::endl;

    return 0;
}
