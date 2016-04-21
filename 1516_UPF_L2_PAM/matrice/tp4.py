#Td4 : programmation analyse matricielle

from m_base import *
from math import sqrt

#Exercice 1

def norme1 (Matrice):
    maxima = 0
    n = len(Matrice)
    for i in range(n):
        somme = 0

        for j in range(n):
            somme += Matrice[j][i]

        if(maxima < somme):
            maxima = somme

    return maxima

def normeInfinie (Matrice):
    maxima = 0
    n = len(Matrice)
    for i in range(n):
        somme = 0

        for j in range(n):
            somme += Matrice[i][j]

        if(maxima < somme):
            maxima = somme

    return maxima

def normeProbinus (Matrice):
    somme = 0
    n = len(Matrice)
    for i in range(n):
        for j in range(n):
            somme += Matrice[i][j] * Matrice[i][j]

    return sqrt(somme)

#Exercice 2

def cond1 (Matrice):
    return norme1(Matrice) * norme1(inverse(Matrice))

def condInf (Matrice):
    return normeInfinie(Matrice) * normeInfinie(inverse(Matrice))

def inverse (M):
    n = len(M[0])
    N = clone(M)
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
               for k in range(i):
                a = N[k][i]/N[i][i]
                for j in range(n):
                    N[k][j] = N[k][j]-(a*N[i][j])
                    Id[k][j] = Id[k][j]-(a*Id[i][j])
    
    for i in range(n):
        for j in range(n):
            Id[i][j] = Id[i][j]/N[i][i]
            
    return Id

#Exercice 3

def jacobi (A,X0,B,k):
    Xa = X0[:]
    n = len(A)
    for iter in range(k):
        Xb = Xa[:]        
        for i in range(n):
            somme = B[i]

            for j in range(i):
                somme -= A[i][j] * Xb[j]

            for j in range(i+1,n):
                somme -= A[i][j] * Xb[j]

            Xa[i] = somme / A[i][i]
            
    return Xa

#Exercice 4

def gauss_seidel (A,X0,B,k):
    X = X0[:]
    n = len(A)
    for iter in range(k):
        
        for i in range(n):
            somme = B[i]

            for j in range(i):
                somme -= A[i][j] * X[j]

            for j in range(i+1,n):
                somme -= A[i][j] * X[j]

            X[i] = somme / A[i][i]
            
    return X
    
