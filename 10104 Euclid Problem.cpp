#include <iostream>
using namespace std;
void exEuclidean(long long A, long long B, long long &X, long long &Y, long long &D){
    //Extended Euclidean algorithm
    //給定二個整數A、B，必存在整數X、Y使得AX + BY = gcd(A, B) = D
    if (!B){
        D = A;
        X = 1;
        Y = 0;
    } else {
        exEuclidean(B, A % B, Y, X, D);
        Y -= X * (A / B);
    }
}
 
int main() {
    long long A, B, X, Y, D;
    while (cin >> A >> B){
        exEuclidean(A, B, X, Y, D);
        cout << X << " " << Y << " " << D << "\n";
    }
    return 0;
}
