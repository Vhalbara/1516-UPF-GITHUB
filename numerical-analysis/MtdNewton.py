import math # Importation d'une bibliothèque de mathématique

# Définition de la fonction f(x)
def f(x):
    return x**5 + x -3;

# Définition de la dérivée f'(x)
def fDev(x):
    return 5*x**4 +1;

# Méthode de Newton
def newton(x0,precison):
    Xnext = x0-(f(x0)/fDev(x0))
    while(abs(Xnext-x0) >= precison):
        x0 = Xnext
        Xnext = x0-(f(x0)/fDev(x0))
    print("Xnext = ",Xnext," Xn = ",x0)