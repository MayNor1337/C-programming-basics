#include <stdio.h>

enum Cars{
    Passenger,
    Cargo,
    Bus,
    Racing
};

struct squre{
    int X;
    int Y;
    int A;
    int P;
};

union
{
    int num;
    struct
    {
        unsigned NL:1;
        unsigned CL:1;
        unsigned SL:1;
    }keyPad;
}pole;

int main() {
    //#1
    enum Cars a = Bus;
    printf("%d\n", a);

    //#2
    struct squre b;
    b.X = 0;
    b.Y = 0;
    b.A = 5;
    b.P = b.A * 4;

    printf("%d\n", b.P);

    //#3
    int c;
    scanf("%x", &c);
    pole.num = c;
    printf("%d %d %d", pole.keyPad.NL, pole.keyPad.CL, pole.keyPad.SL);

    return 0;
}
