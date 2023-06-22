from parabolico import *
s=Simulador(9.81)
obj1 = Objeto(5,10,0,5,45,1)
obj2 = Objeto(12,1,10,10,30,-1)
obj3 = Objeto(20,10,100,50,45,-1)
r=s.run([obj1,obj2,obj3])
c=s.collide(obj1,obj3)
d=s.distance(obj1)


cnt = 1
for result in r:
    if round(result.t,1) == 0.0:
        print(f"Objeto {cnt}")
        cnt = cnt + 1

    print(f"En el tiempo {round(result.t,1)} x: {round(result.x,2)} y: {round(result.y,2)}") #Asi se imprimen los valores porque estan guardados en un struct de a tres {t,x,y}


print(d)

if c == True:
    print("Colisión")
else:
    print("Los objetos no colisionan")

