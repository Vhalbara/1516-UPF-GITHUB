import math #Importation d'une bibliothèque de mathématique

#Dichotomie
def f(x):
    return x*x-1 

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


#Méthode du point fixe
def heron():
    n = int(input("Entrez le nombre de decimale: "))
    x=1
    for i in range(math.floor(math.log(n)/math.log(2)+1)):
        x=(x+2/x)/2
    print("valeur aprochee de racine 2 avec ",n," decimales exacte est: ",x)
    return x


#Méthode de Newton
def fn(x):
    return x**5 + x -3;

def fnDev(x):
    return 5*x**4 +1;

def newton(x0,precison):
    Xnext = x0-(fn(x0)/fnDev(x0))
    while(abs(Xnext-x0) >= precison):
        x0 = Xnext
        Xnext = x0-(fn(x0)/fnDev(x0))
    print("Xnext = ",Xnext," Xn = ",x0)


#Méthode de la sécante
def fs(x):
    return x**3 - 2

def mtdSecante(x0,x1):
    x2 = x1 - ((x1-x0)/(fs(x1)-fs(x0)))*fs(x1)
    while(abs(x2-x1) >= 0.000000000001):
        x0 = x2 # Xn-1 = Xn+1
        x2 = x2 - ((x2-x1)/(fs(x2)-fs(x1)))*fs(x2) # n++
        x1 = x0 # Xn = Xn
    print("Xnext = ",x2," Xn = ",x1)
