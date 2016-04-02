import tp1
import math

def main ():
    L = []

    N = []

    N.append(math.sqrt(2)/2)
    N.append((math.sqrt(2)/2)*-1)

    L.append(N)

    N = []

    N.append(math.sqrt(2)/2)
    N.append(math.sqrt(2)/2)

    L.append(N)
    
    tp1.affichage(L)
    N = tp1.transposition(L)
    tp1.affichage(L)
    tp1.affichage(N)
    
    tp1.affichage(tp1.produit_matrice(N,L))

    print(verifie_orthogonale(L))

def  verifie_symetrique (M):
    n=len(M[0])
    for i in range(n):
        for j in range(i+1,n):
            if(abs(M[i][j] - M[j][i]) > 0.00000001):
                print("Matrice non symetrique.")
                return False

    print("Matrice symetrique.")
    return True

def verifie_antisymetrique (M):
    n=len(M[0])
    for i in range(1,n):
        
        for j in range(i,n):
            # astuce précédente invalide car la valeur de la diagonale doit être égale à 0
            if(abs(M[i][j] + M[j][i]) > 0.00000001):
                
                print("Matrice non anti-symetrique.")
                return False

    print("Matrice anri-symetrique.")
    return True

def strassen (M,N):
    # condition M a autant de colonne que N a de ligne
    if(len(M[0]) != len(N)):
       print("Multiplication impossible")
       return 0

def verifie_orthogonale (M):
    comp = tp1.compare_matrice(tp1.produit_matrice(tp1.transposition(M),M),tp1.construire_identite(len(M[0])))

    if(comp):
        print("Matrice orthogonale")
        return comp

    print("Matrice non orthogonale")
    return False
