from m_base import *

def m_pivot_gauss(M,b):
    N = clone(M)
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

                c[k] = c[k] - (a * c[i])

    return [N,c] # N,c ou [N,c]

def m_resoudre_triangle(T,b):
    X = []
    n = len(T)

    for i in range(n-1,-1,-1):
        somme = 0
        
        for j in range(i+1,n):
            somme += T[i][j] * X[n-1-j]

        somme = b[i] - somme
        
        if(abs(T[i][i]) < 0.00000001):
            print("Matrice non inversible")
            return False

        somme = somme/T[i][i]
        X.append(somme)
        X.reverse()
        
    return X
