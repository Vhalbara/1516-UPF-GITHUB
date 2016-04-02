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

def mtdSecante(x1,x0,precision):
    Xnext = x0 - ((x1-x0)/(fs(x1)-fs(x0)))*fs(x1)
    while(abs(Xnext-x1) >= precision):
        x1,x0 = Xnext,x1
        Xnext = x0 - ((x1-x0)/(fs(x1)-fs(x0)))*fs(x1)
    print("Xnext = ",Xnext," Xn = ",x1)
