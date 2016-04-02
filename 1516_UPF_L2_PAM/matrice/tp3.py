from tp1 import *
from math import *
from m_base import *

def copie_matrice (M):

    Matrix = []

    for i in range(len(M)):
        
        Matrix.append(M[i][:])

    return Matrix

def pivot_gauss (M):
    N = copie_matrice(M)
    n = len(M[0])
    
    for i in range(n):
        k=i
            
        while( k < n and abs(N[k][i]) < 0.00000001):
            k+=1

        if(k==n):
            print("Matrice non inversible")
            return False
        
        elif(k!=i):
            for l in range(i,n):
                a = N[i][l]
                N[i][l] = N[k][l]
                N[k][l] = a

        for k in range(i+1,n):
                a = N[k][i]/N[i][i]
                for j in range(i,n):
                    N[k][j] = N[k][j]-(a*N[i][j])

    return N

# Exercice 2 # xi = bi - somme(bii,xi)/tii
def resolve_triangulair(T,b):
    X = []
    n = len(T)
    # ligne inutile car traité après en informatique
    #if(abs(T[n-1][n-1])>0.00000001):
    #    x = b[n-1]/T[n-2][n-1]
    #    X.append(x)
    #
    #else:
    #    print("Matrice non inversible")
    #    return False
    # end en mettant n -2 quand on le laisse
    for i in range(n-1,-1,-1):
        somme = 0
        
        for j in range(i+1,n):
            somme += T[i][j] * X[n-1-j]

        somme = b[i] - somme
        
        if(T[i][i] < 0.00000001):
            print("Matrice non inversible")
            return False

        somme = somme/T[i][i]
        X.append(somme)

    return X.reverse()

def pivot_gauss_system (M,b):
    N = copie_matrice(M)
    c = b[:] # copie_liste()
    n = len(M[0])
    
    for i in range(n):
        k=i
            
        while( k < n and abs(N[k][i]) < 0.00000001):
            k+=1

        if(k==n):
            print("Matrice non inversible")
            return False
        
        elif(k!=i):
            a = c[i]
            c[i] = c[k]
            c[k] = a

            for l in range(i,n):
                a = N[i][l]
                N[i][l] = N[k][l]
                N[k][l] = a

        for k in range(i+1,n):
                a = N[k][i]/N[i][i]
                
                for j in range(i,n):
                    N[k][j] = N[k][j]-(a*N[i][j])

                b[k] = b[k] - (a * b[i])

    return [N,c] # N,c ou [N,c]

def determinant (M):

    N = copie_matrice(M)
    n = len(M[0])
    determinant = 1
    
    for i in range(n):
        k=i
            
        while( k < n and abs(N[k][i]) < 0.00000001):
            k+=1

        if(k==n):
            return 0
        
        elif(k!=i):
            determinant *= -1
            for l in range(i,n):
                a = N[i][l]
                N[i][l] = N[k][l]
                N[k][l] = a

        for k in range(i+1,n):
                a = N[k][i]/N[i][i]
                for j in range(i,n):
                    N[k][j] = N[k][j]-(a*N[i][j])

    for i in range(n):
        determinant *= N[i][i]
    
    return determinant

def inverse (M):
    n = len(M[0])
    N = copie_matrice(M)
    Id = gen_identite(n,n) 
    
    for i in range(n):
        k=i
            
        while( k < n and abs(N[k][i]) < 0.00000001):
            k+=1

        if(k==n):
            print("Matrice non inversible")
            return False
        
        elif(k!=i):
            for l in range(i,n):
                a = N[i][l]
                N[i][l] = N[k][l]
                N[k][l] = a

                a = Id[i][l]
                Id[i][l] = Id[k][l]
                Id[k][l] = a

        for k in range(i+1,n):
                a = N[k][i]/N[i][i]
                for j in range(i,n):
                    N[k][j] = N[k][j]-(a*N[i][j])
                    Id[k][j] = Id[k][j]-(a*Id[i][j])
    
    for i in range(n-1,-1,-1):
        #k=i
        #    
        #while( k > 0 and abs(N[k][i]) < 0.00000001):
        #    k = k-1
        #if(k != i):
        #    for j in range(i):
        #        N[i][j], N[k][j] = N[k][j],N[i][j]
        #        Id[i][j], Id[k][j] = Id[k][j],Id[i][j]
        # Recherche de pivot non nuls inutile car on place des pivots non nuls
        # Vu qu'il n'y aura pas de pivot non null, il n'y a pas de permutation
        for k in range(i):
                a = N[k][i]/N[i][i]
                for j in range(n):
                    N[k][j] = N[k][j]-(a*N[i][j])
                    Id[k][j] = Id[k][j]-(a*Id[i][j])
    #division des ligne de la marice identité par
    for i in range(n):
        for j in range(n):
            Id[i][j] = Id[i][j]/N[i][i]
            
    return Id

def fact_lu (M):
    n = len(M[0])
    U = clone(M)
    L = gen_identite(n,n)
    
    for i in range(n):
        # Pivot non nul
        if(abs(U[i][i]) < 0.00000001):
            print("pas de factorisation LU")
            return False
 
        for k in range(i+1,n):
                a = U[k][i]/U[i][i]
                L[k][i] = a * (-1)
                for j in range(i,n):
                    U[k][j] = U[k][j]-(a*U[i][j])

    return [L,U]

def fact_cholesky (M):
    n = len(M)
    L = gen_nulle(n,n)

    for i in range(n):
        somme = 0
        
        for k in range(i):
            somme += L[i][k] * L[i][k]

        L[i][i] = sqrt(M[i][i] - somme)

        for k in range(i+1,n):
            somme = 0
        
            for j in range(i):
                somme += L[i][j] * L[k][j]
                
            L[k][i] = (M[i][k] - somme) / L[i][i]
    
    return L

def mat ():
    Matrice = []
    Matrice.append([9,-12,-9])
    Matrice.append([-12,41,27])
    Matrice.append([-9,27,67])

    return Matrice
