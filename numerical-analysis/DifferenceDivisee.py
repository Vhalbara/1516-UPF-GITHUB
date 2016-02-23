# Différence divisée
def differenceDivisee(X, Y):
    n=len(X)
    t=[]
    for i in range(n*n):
    	t.append(0.0)

    for i in range(n):
    	t[i*n+0]=Y[i]

    for i in range(1,n):
        
        for j in range(n-1,i-1,-1):
            t[j*n+i]=(t[(j*n)+(i-1)]-t[((j-1)*n)+(i-1)])/(X[j]-X[j-i])

    return t

def PI(X, i, x):
    p = 1

    for j in range(i):
        p *= x-X[j]

    return p

def Interpolation2(X,Y,x):
    t = differenceDivisee(X,Y)
    s,n = 0,len(X)

    for i in range(n):
        s+= t[i*(n+1)]*PI(X,i,x)

    return s;
