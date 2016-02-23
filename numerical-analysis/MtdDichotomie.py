import math # Importation d'une bibliothèque de mathématique

# Définition de la fonction f(x)
def f(x):
    return x*x-1 

# Dichotomie
def dichotomie(a,b,prec):
    for i in range(math.floor((math.log(b-a)+(prec*math.log(10)))/math.log(2))+1):
        m =(a+b)/2
        if(abs(f(m))<=0.00000000001):
            print("On a trouve l'algoritme: ",m)
            return m
        if(f(m)>0.00000000001 and f(a)>0.00000000001):
            a=m
        if(f(m)<-0.00000000001 and f(a)<0.00000000001):
            a=m
        if(f(m)>0.00000000001 and f(b)>0.00000000001):
            b=m
        if(f(m)<-0.00000000001 and f(b)<-0.00000000001):
            b=m
    print("La valeur aprochee de la solution est de: ",m)
    return m

# Dichotomie optimisée
def dichotomie_opti(a,b,prec):
    for i in range(math.floor((math.log(b-a)+(prec*math.log(10)))/math.log(2))+1):
        m =(a+b)/2
        if(abs(f(m))<=0.00000000001):
            print("On a trouve l'algoritme: ",m)
            return m
        if(f(a)*f(m)>0.00000000001):
            a=m
        else:
            b=m
    print("La valeur aprochee de la solution est de: ",m)
    return m