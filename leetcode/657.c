//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-23.
//

typedef int bool;

bool judgeCircle(char* moves) {
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;

    while (*moves) {
        switch (*moves) {
            case 'U':
                U++;
                break;
            case 'D':
                D++;
                break;
            case 'L':
                L++;
                break;
            case 'R':
                R++;
                break;
        }
        moves++;
    }

    return U == D && L == R;
}