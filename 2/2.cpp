#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#include <Windows.h>
#include <math.h>
#include <cmath>

using namespace std;

int main() {
    initwindow(500, 500);
    int cx = 250, cy = 250;
    int a1 = 15; //angle
    double PI = 3.14159265358979323846;
    double angle = a1 % 180 * PI / 180;//angle in degrees
    //s - square, t - top, b - bottom, r - right, l - left
    double st[2][2] = { cx - 50,cy - 50,cx + 50,cy - 50 };
    double sb[2][2] = { cx - 50,cy + 50,cx + 50,cy + 50 };
    double sr[2][2] = { cx + 50,cy - 50,cx + 50,cy + 50 };
    double sl[2][2] = { cx - 50,cy + 50,cx - 50,cy - 50 };
    //t - triangle, b - bottom, r - right, l - left
    double tb[2][2] = { cx - 50,cy + 20,cx + 50,cy + 20 };
    double tr[2][2] = { cx,cy - 50,cx + 50,cy + 20 };
    double tl[2][2] = { cx,cy - 50,cx - 50,cy + 20 };
    //m - matrix, s - scale, 2 = ++
    double ms[2][2] = { 0.8,0,0,0.8 };
    double ms2[2][2] = { 1.25,0,0,1.25 };
    //m - matrix, r - rotate
    double mr[2][2] = { cos(angle), -sin(angle),sin(angle),cos(angle) };
    //m - matrix, n - new
    double mn[2][2];

    line(st[0][0], st[0][1], st[1][0], st[1][1]);
    line(sb[0][0], sb[0][1], sb[1][0], sb[1][1]);
    line(sr[0][0], sr[0][1], sr[1][0], sr[1][1]);
    line(sl[0][0], sl[0][1], sl[1][0], sl[1][1]);

    line(tb[0][0], tb[0][1], tb[1][0], tb[1][1]);
    line(tr[0][0], tr[0][1], tr[1][0], tr[1][1]);
    line(tl[0][0], tl[0][1], tl[1][0], tl[1][1]);

    //-----------------------

    for (int a = 0; a < 1; a += 0) {
        for (int b = 0; b < 20; b++) {
            //---------
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] -= 250;
                }
            }

            //--------

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] -= 250;
                }
            }

            //--------
            Sleep(100);
            cleardevice();

            //st

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = st[i][0] * ms[0][j] + st[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = st[i][0] * mr[0][j] + st[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//st

            //sb

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sb[i][0] * ms[0][j] + sb[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sb[i][0] * mr[0][j] + sb[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sb

            //sr

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sr[i][0] * ms[0][j] + sr[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sr[i][0] * mr[0][j] + sr[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sr

            //sl

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sl[i][0] * ms[0][j] + sl[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sl[i][0] * mr[0][j] + sl[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sl

            //-------------

            //tr

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tr[i][0] * ms[0][j] + tr[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tr[i][0] * mr[0][j] + tr[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tr

            //tl

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tl[i][0] * ms[0][j] + tl[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tl[i][0] * mr[0][j] + tl[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tl

            //tb

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tb[i][0] * ms[0][j] + tb[i][1] * ms[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tb[i][0] * mr[0][j] + tb[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tb
        }
        cleardevice();

        for (int b = 0; b < 20; b++) {
            //---------
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] -= 250;
                }
            }

            //--------

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] -= 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] -= 250;
                }
            }

            //--------
            Sleep(100);
            cleardevice();

            //st

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = st[i][0] * ms2[0][j] + st[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = st[i][0] * mr[0][j] + st[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    st[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//st

            //sb

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sb[i][0] * ms2[0][j] + sb[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sb[i][0] * mr[0][j] + sb[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sb[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sb

            //sr

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sr[i][0] * ms2[0][j] + sr[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sr[i][0] * mr[0][j] + sr[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sr[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sr

            //sl

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sl[i][0] * ms2[0][j] + sl[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = sl[i][0] * mr[0][j] + sl[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sl[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//sl

            //-------------

            //tr

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tr[i][0] * ms2[0][j] + tr[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tr[i][0] * mr[0][j] + tr[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tr[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tr

            //tl

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tl[i][0] * ms2[0][j] + tl[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tl[i][0] * mr[0][j] + tl[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tl[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tl

            //tb

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tb[i][0] * ms2[0][j] + tb[i][1] * ms2[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] = mn[i][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] = tb[i][0] * mr[0][j] + tb[i][1] * mr[1][j];
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    mn[i][j] += 250;
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tb[i][j] = mn[i][j];
                }
            }

            line(mn[0][0], mn[0][1], mn[1][0], mn[1][1]);//tb
        }

    }

    getch();
    closegraph();
    return 0;
}