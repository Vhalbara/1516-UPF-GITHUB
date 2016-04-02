from m_base import *

# Opération sur les matrices

def m_addition(M,N):
    
    if(len(M)!=len(N) and len(M[0])!=len(N[0])):
        print("Les matrices ne sont pas de même taille")
        return False
    
    Matrice = []

    for i in range(len(M)):
        Ligne = []

        for j in range(len(M[0])):
            Ligne.append(M[i][j]+N[i][j])

        Matrice.append(Ligne)

    return Matrice

def m_produit_mat(M,N):
    # condition M a autant de colonne que N a de ligne
    if(len(M[0]) != len(N)):
       print("Multiplication impossible")
       return False
    
    MN = []
    
    for l in range(len(M)):
        Ligne = []

        for c in range(len(N[0])):
            somme = 0.0
            
            for i in range(len(M[0])):
                somme += M[l][i] * N[i][c]

            Ligne.append(somme)

        MN.append(Ligne)

    return MN

def m_strassen(M,N):
   
    MN = []

    # ajoute le code

    return MN

def m_produit_scal(M,a):

    Matrice = []

    for i in range(len(M)):
        Ligne = []

        for j in range(len(M[0])):
            Ligne.append(M[i][j]*a)

        Matrice.append(Ligne)

    return Matrice

def m_transposition(M):

    Matrice = []
    m = len(M)
    n = len(M[0])

    for l in range(n):
        Matrice.append([])
    
    for l in range(m):
        
        for c in range(n):
            Matrice[c].append(M[l][c])
        
    return Matrice

# Opération sur les lignes
def m_multiplier_ligne(M,i,a):
    
    Matrice = []

    for l in range(i):
        Matrice.append(M[l][:])

    Matrice.append([])
    
    for c in range(len(M[0])):
        Matrice[i].append(a*M[i][c])

    for l in range(i+1, len(M)):
        Matrice.append(M[l][:])
        
    return Matrice

def m_permuter_ligne(M,i,j):

    Matrice = []
    
    for l in range(len(M)):
        if(l == i):
            Matrice.append(M[j][:])
        elif(l == j):
            Matrice.append(M[i][:])
        else:
            Matrice.append(M[l][:])

    return Matrice

def m_transvection_ligne(M,i,j,a):

    Matrice = []

    for l in range(i):
        Matrice.append(M[l][:])

    Matrice.append([])
    
    for c in range(len(M[0])):
        Matrice[i].append((a*M[j][c]) + M[i][c])

    for l in range(i+1, len(M)):
        Matrice.append(M[l][:])
        
    return Matrice

# Opération sur les colonnes
def m_multiplier_colonne(M,i,a):

    Matrice = []
    m = len(M)
    n = len(M[0])
    
    for l in range(len(M)):
        Matrice.append([])
        
    for l in range(m):
        
        for c in range(n):
            
            if(c == i):
                Matrice[l].append(M[l][c] * a)
            else:
                Matrice[l].append(M[l][c])
        
    return Matrice

def m_permuter_colonne(M,i,j):

    Matrice = []
    m = len(M)
    n = len(M[0])
    
    for l in range(len(M)):
        Matrice.append([])
        
    for l in range(m):
        
        for c in range(n):
            
            if(c == i):
                Matrice[l].append(M[l][j])
            elif(c == j):
                Matrice[l].append(M[l][i])
            else:
                Matrice[l].append(M[l][c])
        
    return Matrice

def m_transvection_colonne(M,i,j,a):

    Matrice = []
    m = len(M)
    n = len(M[0])
    
    for l in range(len(M)):
        Matrice.append([])
        
    for l in range(m):
        
        for c in range(n):
            
            if(c == i):
                Matrice[l].append((a*M[l][j]) + M[l][i])
            else:
                Matrice[l].append(M[l][c])
        
    return Matrice
