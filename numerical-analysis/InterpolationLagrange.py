# Polynome d'interpolation de lagrange

# Définition de lafonction li(x)
def l(i, X, x):
    prod = 1

    for j in range(len(X)):
        if(i!=j):
            prod *= (x-X[j])/(X[i]-X[j])

    return prod

# Interpolation de lagrange
def interpolation(X, Y, x):
    som = 0
    
    for i in range(len(X)):
        som += Y[i]*l(i,X,x)

    return som

# 2n² opérations
