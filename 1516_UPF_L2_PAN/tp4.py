from io import *
from pylab import *

def f (x,y):
    return y

def Euler(x,y,h,n):
    id_file = open('donnees.txt','w')
    X = Y = []
    for i in range(n):
        y = y + (h * f(x,y))
        x = x + h
        
        X.append(x)
        Y.append(y)
        
        id_file.write("x = " + str(x) + " et y = " + str(y))

    id_file.close()
    return X,Y

def dessine_courbe ():
   # X,Y = Euler(x,y,h,n)
   # plot(X,Y,'b-',"Approximation")
    t = arange(0,5,100)
    plot(t,exp(t),'r-',"Exponentielle")
    show()
    return
