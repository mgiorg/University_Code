int fib(int n) {
    if (n<2) return 1;
    return fib(n-1)+fib(n-2);
}

/**
int fib_eq(int n) {
    int di = n;
    int a = 1;
    if(di<2) goto E;
    di--;
    a = fib_eq(di);
    int b = a;
    di--;
    a = fib_eq(di);
    a = a+b;

E: return a;
}
*/