#Td4 : programmation analyse matricielle

#Exercice 1


#Exercice 3

def jacobi (A,X0,B,k):
    X = X0[:]
    n = len(A)
    for iter in range(k):
        
        for i in range(n):
            somme = 0

            for j in range(i):
                somme -= A[i][j] * X[j]

            for j in range(i+1,n):
                somme -= A[i][j] * X[j]

            X[i] = somme / A[i][i]

    return X
