import math # Importation d'une bibliothèque de mathématique

# Méthode du point fixe
def heron():
    n = int(input("Entrez le nombre de decimale: "))
    x=1
    for i in range(math.floor(math.log(n)/math.log(2)+1)):
        x=(x+2/x)/2
    print("valeur aprochee de racine 2 avec ",n," decimales exacte est: ",x)
    return x