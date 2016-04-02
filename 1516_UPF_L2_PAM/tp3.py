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
        else:
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
        
        else:
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
