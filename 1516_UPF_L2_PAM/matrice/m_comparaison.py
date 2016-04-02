from m_base import *
from m_operation import *

def compare(M,N):
    if(len(M)!= len(N) or len(M[0])!= len(N[0])):
        return False

    n = len(M[0])
    
    for i in range(len(M)):
        
        for j in range(n):
            # deux float égaux si val absolue supérieur à la précision 10^-10
            if(abs(M[i][j]-N[i][j])> 0.0000000001):
                return False

    return True

def etre_symetrique (M):
    n = len(M[0])
    
    for i in range(len(M)):
        
        for j in range(i+1,n):
            
            if(abs(M[i][j] - M[j][i]) > 0.00000001):
                print("Matrice non symetrique.")
                return False

    print("Matrice symetrique.")
    return True

def etre_antisymetrique (M):
    n = len(M[0])
    
    for i in range(1,len(M)):
        
        for j in range(i,n):
            # astuce précédente invalide car la valeur de la diagonale doit être égale à 0
            if(abs(M[i][j] + M[j][i]) > 0.00000001):
                
                print("Matrice non anti-symetrique.")
                return False

    print("Matrice anri-symetrique.")
    return True

def etre_orthogonale (Matrice):
    comp = compare(m_produit_mat(m_transposition(Matrice), Matrice)
                   , gen_identite(len(Matrice),len(Matrice[0])))

    if(comp):
        print("Matrice orthogonale")
        return comp

    print("Matrice non orthogonale")
    return False
