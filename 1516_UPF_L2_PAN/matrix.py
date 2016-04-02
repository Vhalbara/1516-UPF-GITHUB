import math

def build_Matrix (length):

    Matrix = []

    for i in range(length):
        Line = []

        for j in range(length):
                Line.append((i+1)*(j+1))

        Matrix.append(Line)

    return Matrix

def build_Identity (length):

    Matrix = []

    for i in range(length):
        Line = []

        for j in range(length):
            if (i == j):
                Line.append(1)
            else:
                Line.append(0)

        Matrix.append(Line)

    return Matrix

def copy_Matrix (M):

    Matrix = []

    for i in range(len(M)):
        
        Matrix.append(M[i][:])

    return Matrix

def display_Matrix(Matrix):

    for i in range(len(Matrix)):

        for j in range(len(Matrix[0])):
            print("{0:2.2f}".format(Matrix[i][j]),end=(" "))

        print("")

def addition_Matrix(M,N):
    
    if(len(M)!=len(N) and len(M[0])!=len(N[0])):
        print("Les matrices ne sont pas de même taille")
        return False
    
    Matrix = []

    for i in range(len(M)):
        L = []

        for j in range(len(M[0])):
            L.append(M[i][j]+N[i][j])

        Matrix.append(L)

    return Matrix

def multiply_Scalar(M,a):

    Matrix = []

    for i in range(len(M)):
        L = []

        for j in range(len(M[0])):
            L.append(M[i][j]*a)

        Matrix.append(L)

    return Matrix

def multiply_Line(M,i,a):

    Matrix = []
    n = len(M[0])
    
    for l in range(i):
        Matrix.append(M[l][:])

    L = []      
    for j in range(n):
        L.append(M[i][j]*a)

    Matrix.append(L)

    for l in range(i+1, len(M)):
        Matrix.append(M[l][:])

    return Matrix

def swap_Line(M,i,j):

    Matrix = []
    
    for l in range(len(M)):
        if(l == i):
            Matrix.append(M[j][:])
        elif(l == j):
            Matrix.append(M[i][:])
        else:
            Matrix.append(M[l][:])

    return Matrix

def transvection_Line(M,i,j,a):

    Matrix = []

    for l in range(i):
        Matrix.append(M[l][:])
    
    for c in range(len(M[0])):
        L.append((a*M[j][c]) + M[i][c])

    for l in range(i+1, len(M)):
        Matrix.append(M[l][:])
        
    return Matrix

# faire pour les colonnes

def transposition(M):

    Matrix = []
    
    for l in range(len(M)):
        Line = []
        
        for c in range(len(M[0])):
            Line.append(M[c][l])

        Matrix.append(Line)
    return Matrix

def product_Matrix(M,N):
    # condition M a autant de colonne que N a de ligne
    if(len(M[0]) != len(N)):
       print("Multiplication impossible")
       return False
    
    Matrix = []
    
    for l in range(len(M)):
        Line=[]

        for c in range(len(N[0])):
            somme = 0.0
            
            for i in range(len(M[0])):
                somme += M[l][i] * N[i][c]

            Line.append(somme)

        Matrix.append(Line)

    return Matrix

def compare_Matrix(M,N):
    if(len(M)!= len(N) or len(M[0])!= len(N[0])):
        return False
    
    for i in range(len(M)):
        
        for j in range(len(M[0])):
            # deux float égaux si val absolue supérieur à la précision 10^-10
            if(abs(M[i][j]-N[i][j])> 0.0000000001):
                return False

    return True

def generate_Block (M,deb,fin):
    Matrix = []
    
    for i in range(deb,fin):
        Line = []
        for j in range(deb,fin):
            Line.append(M[i][j])

        Matrix.append(Line)

    return Matrix

def block_to_Matrix (a,b,c,d):
    Matrix = []
    
    for i in range(len(a)):
        Line = []
        
        Line.append(a[i][:] + b[i][:])

        Matrix.append(Line)

    for i in range(len(c)):
        Line = []
        
        Line.append(c[i][:] + d[i][:])

        Matrix.append(Line)

    return Matrix

def strassen (M,N):
    n = len(M[0])

    a = generate_Block(M,0,n//2)
    b = generate_Block(M,n//2,n)
    c = generate_Block(M,0,n//2)
    d = generate_Block(M,n//2,n)

    alpha = generate_Block(N,0,n//2)
    beta = generate_Block(N,n//2,n)
    omega = generate_Block(N,0,n//2)
    delta = generate_Block(N,n//2,n)
        
    Line.append(b * alpha + b * omega)
    Line.append(a * beta + b * delta)

    Matrix.append(Line)

    Line.append(alpha * c - alpha * d)
    Line.append(beta * c + d * delta)

    Matrix.append(Line)
    
def main():
    A =[]
    for i in range(2):
	Line = []
	for j in range(2):
		Line.append(i+j)
	A.append(Line)

    B = []
    for i in range(2):
	Line = []
	for j in range(2):
		Line.append(i+j)
	B.append(Line)
	
    C = []
    for i in range(2):
	Line = []
	for j in range(2):
		Line.append(i+j)
	C.append(Line)

    D = []
    for i in range(2):
	Line = []
	for j in range(2):
		Line.append(i+j)
	D.append(Line)
