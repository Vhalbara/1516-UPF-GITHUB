from random import uniform

def gen_nulle(m, n):
    
    Matrice = []
    
    for i in range(m):
        Ligne = []
        
        for j in range(n):
            Ligne.append(0)

        Matrice.append(Ligne)

    return Matrice

def gen_identite(m, n):
    
    Matrice = []
    
    for i in range(n):
        Ligne = []
        
        for j in range(n):
            
            if (i == j):
                Ligne.append(1)
                
            else:
                Ligne.append(0)

        Matrice.append(Ligne)

    return Matrice

def gen_aleatoire(m, n):
    
    Matrice = []
    
    for i in range(m):
        Ligne = []
        
        for j in range(n):
            # Réel aléatoire
            Ligne.append(uniform(0,100))

        Matrice.append(Ligne)

    return Matrice

def saisie ():
    
    print("Génération de la matrice !")
    m = int(input("- nombre de ligne : "))
    n = int(input("- nombre de colonne : "))
    
    Matrice=[]
    
    for l in range(m):
        Ligne = []
        
        for c in range(n):
            print("M[",l,"][",c,"] =",end=(" "))
            Ligne.append(float(input()));
            
        Matrice.append(Ligne)
        
    return Matrice

def clone (A):

    Matrice = []

    for i in range(len(A)):
        
        Matrice.append(A[i][:])

    return Matrice

def affiche(Matrice):

    for i in range(len(Matrice)):

        for j in range(len(Matrice[0])):
            print("[{:10.4f}]".format(Matrice[i][j]),end=(" "))

        print("")

def write(Matrice,ouverture,titre):

    if(len(ouverture)!=2):
        return False
    
    id_file = open(ouverture[0],ouverture[1])
    id_file.write("# " + titre + " #\n")
    
    for i in range(len(Matrice)):

        for j in range(len(Matrice[0])):
            id_file.write("[{:10.4f}]".format(Matrice[i][j]))

        id_file.write("\n")

    id_file.close()

def open_cond(nom, ouverture):
    
    return [nom, ouverture]

def trace (Matrice): #matrice carree pour le moment

    somme = 0
    m = len(Matrice)

    for i in range(m):

        somme += Matrice[i][i]

    return somme
