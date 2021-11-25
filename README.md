# AlgebraAbstractaLb07_02
Parte a)

El codido trata de resolver un problema del algorito RSA, m^e mod n = c, teniendo e,n y c, hallar el mensaje.
Calculamos si n es producto de dos numeros, p y q, luego vemos si estos son coprimos, hallamos phi luego d, teniendo ya d podemos calcular m.
c^d mod n = m, despues en modo de comprobacion calculamos c teniendo m, m^e mod n = c.

Parte b)

Se nos pide calcular el mensaje sabiendo c1,c2,e1,e2 y n.
vemos si e1 y e2 son coprimos, si lo son comprobamos que c2 y n tambien lo sean, si lo son calculamos la inversa de e,e2 teniendo x y con este calculamos y. multiplicamos -1 a y.
Sacamos la inversa a c2 mod n teniendo un d.
Como tenemos c1,d,x e -y, ya podriamos calcular el mensaje. mensaje = c1^x d^-y mod n.
