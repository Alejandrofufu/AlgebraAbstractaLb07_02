import math

def inverse(a, b):
    g, x, y = gcdExtended(a, b)
    if g != 1:
        print("The gcd is not 1")
        return
    return (x % b + b) % b

def gcdExtended(a, b): 
    if a == 0 :  
        return b,0,1
    gcd,x1,y1 = gcdExtended(b%a, a) 
    x = y1 - (b//a) * x1 
    y = x1 
    return gcd,x,y


def main():
    print("pregunta a)")
    eP1 = 6537
    nP1 = 999630013489
    cP1 = 747120213790
    pP1 = 999671
    qP1 = 999959
    phi = (pP1-1)*(qP1-1)
    dP1 = inverse(eP1,phi)
    mP1 = pow(cP1,dP1,nP1)
    print("mensaje es: ",mP1)
    print("mensaje cifrado es: ",pow(mP1,eP1,nP1))


    print()
    print("pregunta b)")
    # PJ = {e, n} = c1
    e1 = 7
    n = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667
    c1 = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544
    
    # Pj = {e2, n} = c2
    e2 = 11
    c2 = 35794234179725868774991807832568455403003778024228226193532908190484670252364665786748759822531352444533388184
    if math.gcd(e1, e2) == 1:
        g, x, y = gcdExtended(e1, e2)
        if x < 0:
          if math.gcd(c1, n) == 1:
            c1 = inverse(c1, n)
            x = abs(x)
        else:
            if math.gcd(c2, n) == 1:
              c2 = inverse(c2, n)
              y = abs(y)
    m = (pow(c1, x)*pow(c2, y)) % n
    print("mensaje: ",m)
    print("c1 = ",pow(m, e1, n))
    print("c2 = ",pow(m, e2, n))
    
if __name__ == '__main__':
    main()
