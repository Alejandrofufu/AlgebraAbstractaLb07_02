#include <iostream>
#include<math.h>
using namespace std;

 long long  EuclidesGeneral( long long  a,  long long  b,  long long  & x,  long long  & y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
     long long  x1, y1;
     long long  gcd = EuclidesGeneral(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

 long long  inversoM( long long int a,  long long int m) {
     long long  x = 0, y = 0;
     long long  g = EuclidesGeneral(a, m, x, y);
    if (g != 1)
        return -1;
    else {
         long long int res = (x % m + m) % m;
        return res;
    }
}

 long long int Gcd( long long int a,  long long int b) {
     long long int t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

void NAIVE_RSA_KEY_GENERATOR( long long int p,  long long int q,  long long int & n,  long long int& e,  long long int& d) {
    n = p * q;
     long long int phi = (p - 1) * (q - 1);
     long long int pista = 0;
    while (e < phi) { // e = {2,(p - 1) * (q - 1)}
        pista = Gcd(e, phi);
        if (pista == 1) {
            d = inversoM(e, phi);
            break;
        }
        else
            e++;
    }
}
long long int modular(unsigned long long int base, unsigned long long int exp, unsigned long long int mod)
{
    long long int x = 1;
    int i;
    long long int power = base % mod;

    for (i = 0; i < sizeof(int) * 64; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}

int main() {

    //pregunta a;
    long long int e = 65537, n = 999630013489, c = 747120213790, mensaje,p,q,phi,d;
    for (long long i = 2; i < n; i++) {
        if (!(n % i)) {
            p = i; q = n / p;
            break;
        }
    }
    phi = (p - 1) * (q - 1);
    d = inversoM(e, phi);
    mensaje = modular(c, d, n);
    cout << "El mensaje es: " << mensaje;
    c = modular(mensaje, e, n);
    cout << "\nEl encriptado es: " << c; //  c != 747120213790 no se que falla


    //preguna b;
    /*
    e = 7, n = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667, 
    c = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544, mensaje, p, q, phi, d;
    long long e2 = 11, c2 = 35794234179725868774991807832568455403003778024228226193532908190484670252364665786748759822531352444533388184;
    if (Gcd(e, e2) == 1) {
        if (Gcd(c2, n) == 1) {
            p = inversoM(e, e2);// x 
            q = (1 - e * p) / e2; q = q * -1; // -y
            // mensaje = c^x * c2^-y mod n  == (c^x mod n)(c2 ^ -y ) mod n
            p = modular(c, p, n); //(c^x mod n) = p
            q = modular(c2, q, n);//(c2 ^ -y ) = q
            phi = p * q;
            mensaje = modular(phi, 1, n); // phi mod n = mensaje
        }
    }*/


    
    return 0;
}