#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Vector10maxD {
    private:
        int N;
        double x[10];
    public:
        Vector10maxD() {N = 0;};
        Vector10maxD(int length, double bruh[]);
        bool operator == (const Vector10maxD &);
        bool operator < (const Vector10maxD &);
        void show(){
            for (int i = 0; i < N; i++) {
                cout << x[i] << "\t|\t";
            }
            cout << endl;
        };
};
Vector10maxD :: Vector10maxD(int length, double bruh[]) {
    N = length;
    int i;
    for (i = 0; i < length; i++) {
        x[i] = bruh[i];
    }
}
bool Vector10maxD :: operator == (const Vector10maxD &lmao) {
    int i;
    bool flag = 1;
    if (N == lmao.N) {
        for (i = 0; i < N; i++) {
            if (x[i] != lmao.x[i]) {
                flag = 0;
                break;
                // return 0;
            }
        }
    } else {
        flag = 0;
    }
    if (flag == 1) {
        return 1;
    } else {
        return 0;
    }
}
bool Vector10maxD :: operator < (const Vector10maxD &lmao) {
    int i;
    bool flag = 0;
    if (N < lmao.N) {
        flag = 1;
    }
    if (N == lmao.N) {
        for (i = 0; i < N; i++) {
            if (x[i] < lmao.x[i]) {
                flag = 1;
                break;
            }
            if (x[i] > lmao.x[i]) {
                break;
            }
        }
    }
    if (flag == 1) {
        return 1;
    } else {
        return 0;
    }
}
class bruh_sort
{
public:
    bool operator() (Vector10maxD a, Vector10maxD b)
    {return !(a < b);}
};
int main() {
    double mass1[5] = {4, 6, 1, 8, 0};
    double mass2[5] = {4, 6, 3, 16, 100};
    double mass3[7] = {4, 6, 1, 8, 0, 9, 6};
    Vector10maxD v1(5, mass1), v2(5, mass2), v3(7, mass3), v4(5, mass2);
    vector<Vector10maxD> V;
    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);
    for (int i = 0; i < V.size(); i++) {
        V[i].show();
    }
    sort(V.begin(), V.end(), bruh_sort());
    cout << "-------------" << endl;
    for (int i = 0; i < V.size(); i++) {
        V[i].show();
    }
    Vector10maxD v_betray;
    bool found = 0;
    int count = 0;
    /*for (int i = 0; i < V.size(); i++) {
        if (V[i] < V[0] and found == 0) {
            v_betray = V[i];
            found = 1;
        }
        if (V[i] == v_betray) {
            count++;
        }
    }*/
    for (auto i{V.begin()}; i != V.end(); i++) {
        if (*i < V[0] and found == 0) {
            v_betray = *i;
            found = 1;
        }
        if (*i == v_betray) {
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        V.erase(find(V.begin(), V.end(), v_betray));
    }
    cout << "-------------" << endl;
    for (int i = 0; i < V.size(); i++) {
        V[i].show();
    }
}
