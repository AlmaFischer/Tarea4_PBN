from parabolico import *
s=Simulador(9.81)
obj1 = Objeto(5,10,0,5,45,1)
obj2 = Objeto(12,1,10,10,1,-1)
r=s.run([obj1,obj2])
c=s.collide(obj1,obj2)
d=s.distance(obj1)
print(d)
if c == True:
    print("Colisión")
else:
    print("Los objetos no colisionan")