import math # Importation d'une bibliothèque de mathématique

# Définition de la fonction f(x)
def f(x):
    return x**3 - 2

# Méthode de la sécante
def mtdSecante(x0,x1):
    x2 = x1 - ((x1-x0)/(f(x1)-f(x0)))*f(x1)
    while(abs(x2-x1) >= 0.000000000001):
        x0 = x2 # Xn-1 = Xn+1
        x2 = x2 - ((x2-x1)/(f(x2)-f(x1)))*f(x2) # n++
        x1 = x0 # Xn = Xn
    print("Xnext = ",x2," Xn = ",x1)
