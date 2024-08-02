#include <iostream>
#include <fstream>
using namespace std;
class nothing {
    public:
        nothing() {}
    virtual void show() {
        cout << "Nothing" << endl;
    }
    virtual void save(ofstream &);
};
class point : public nothing {
    protected:
        double x, y;
    public:
        point(double xx, double yy) : x(xx), y(yy) {};
        void show();
        void save(ofstream &);
};
class section : public point {
    protected:
        double x1, y1;
    public:
        section(double xx, double yy, double xx1, double yy1) : point(xx, yy), x1(xx1), y1(yy1) {};
        void show();
        void save(ofstream &);
        nothing* operator * (section);
};
void nothing :: save(ofstream &BRUH) {
    //ofstream BRUH;
    //BRUH.open("lmao.txt");
    BRUH << "Nothing" << endl;
}
void point :: save(ofstream &BRUH) {
    //ofstream BRUH;
    //BRUH.open("lmao.txt");
    BRUH << "Point (" << x << " , " << y << ")" << endl;
    //BRUH.close();
}
void point :: show() {
    cout << "Point (" << x << " , " << y << ")" << endl;
}
void section :: save(ofstream &BRUH) {
    //ofstream BRUH;
    //BRUH.open("lmao.txt");
    BRUH << "Section (" << x << " , " << y << ") " << "--" << " (" << x1 << " , " << y1 << ")" << endl;
    //BRUH.close();
}
void section :: show() {
    cout << "Section (" << x << " , " << y << ") " << "--" << " (" << x1 << " , " << y1 << ")" << endl;
}
nothing* section :: operator * (section lmao) {
    nothing *bruh;
    bruh = new nothing;
    double leftX_cur = x, leftY_cur = y, rightX_cur = x1, rightY_cur = y1, leftX_lmao = lmao.x, leftY_lmao = lmao.y, rightX_lmao = lmao.x1, rightY_lmao = lmao.y1;
    if (x > x1) {
        leftX_cur = x1;
        leftY_cur = y1;
        rightX_cur = x;
        rightY_cur = y;
    }
    if (lmao.x > lmao.x1) {
        leftX_lmao = lmao.x1;
        leftY_lmao = lmao.y1;
        rightX_lmao = lmao.x;
        rightY_lmao = lmao.y;
    }
    if ((x1 - x)/(lmao.x1 - lmao.x) == (y1 - y)/(lmao.y1 - lmao.y)) {
        if ((lmao.x - x)/(x1 - x) == (lmao.y - y)/(y1 - y)) {
            if (rightX_lmao >= leftX_cur || rightX_cur >= leftX_lmao) {
                if (rightX_lmao == leftX_cur) {
                    bruh = new point(leftX_cur, leftY_cur);
                    return bruh;
                }
                if (rightX_cur == leftX_lmao) {
                    bruh = new point(rightX_cur, rightY_cur);
                    return bruh;
                }
                if (rightX_lmao > leftX_cur) {
                    double leftX_ans = leftX_lmao, leftY_ans = leftY_lmao, rightX_ans = rightX_lmao, rightY_ans = rightY_lmao;
                    if (rightX_cur < rightX_lmao) {
                        rightX_ans = rightX_cur;
                        rightY_ans = rightY_cur;
                    }
                    if (leftX_cur > leftX_lmao) {
                        leftX_ans = leftX_cur;
                        leftY_ans = leftY_cur;
                    }
                    bruh = new section(leftX_ans, leftY_ans, rightX_ans, rightY_ans);
                    return bruh;

                }
                if (rightX_cur > leftX_lmao) {
                    double leftX_ans = leftX_lmao, leftY_ans = leftY_lmao, rightX_ans = rightX_lmao, rightY_ans = rightY_lmao;
                    if (rightX_lmao < rightX_cur) {
                        rightX_ans = rightX_lmao;
                        rightY_ans = rightY_lmao;
                    }
                    if (leftX_lmao > leftX_cur) {
                        leftX_ans = leftX_lmao;
                        leftY_ans = leftY_lmao;
                    }
                    bruh = new section(leftX_ans, leftY_ans, rightX_ans, rightY_ans);
                    return bruh;
                }
            } else {
                return bruh;
            }
        } else {
            return bruh;
        }
    } else {
        double a_cur, b_cur, c_cur, a_lmao, b_lmao, c_lmao, x_ans, y_ans;
        a_cur = y1 - y;
        b_cur = x - x1;
        c_cur = x1*y - x*y1;
        a_lmao = lmao.y1 - lmao.y;
        b_lmao = lmao.x - lmao.x1;
        c_lmao = lmao.x1 * lmao.y - lmao.x * lmao.y1;
        x_ans = -(c_cur*b_lmao - c_lmao*b_cur)/(a_cur*b_lmao - a_lmao*b_cur);
        y_ans = -(c_lmao*a_cur - c_cur*a_lmao)/(a_cur*b_lmao - a_lmao*b_cur);
        if (leftX_cur <= x_ans && x_ans <= rightX_cur && leftX_lmao <= x_ans && x_ans <= rightX_lmao && leftY_cur <= y_ans && y_ans <= rightY_cur && leftY_lmao <= y_ans && y_ans <= rightY_lmao) {
            bruh = new point(x_ans, y_ans);
            return bruh;
        } else {
            return bruh;
        }
    }
}
int main() {
    nothing* p;
    //пересекаются в одной точке
    //section s1(5.5, 2., 5.5, 8.), s2(3., 3., 8., 7.);
    //не пересекаются
    section s1(8., 1., 8., 3.), s2(7., 4., 8., 5.);
    //совпадают в одной точке
    //section s1(1., 4., 2., 5.), s2(2., 5., 3., 6.);
    p = s1 * s2;
    p -> show();
    ofstream BRUH("lmao.txt");
    p -> save(BRUH);
    BRUH.close();
    delete p;
}
