//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

int fib(int N) {
    if (N == 1)
        return 1;
    else if (N == 0)
        return 0;

    int a = 0;
    int b = 1;
    int result = 0;

    for (int i = 2; i <= N; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}