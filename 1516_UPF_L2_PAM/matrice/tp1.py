def main ():
    M = saisie_auto()

    N = saisie_auto()

    print("----------------------------------\n",compare_matrice(M,N));

def saisie ():
    taille = int(input("Quelle est la taille de la matrice: "))
    M=[]
    
    for l in range(taille):
        N=[]
        
        for c in range(taille):
            print("M[",l,"][",c,"] = ")
            N.append(float(input()));
            
        M.append(N)
        
    return M

def construire_identite (taille):
    M=[]
    
    for l in range(taille):
        N=[]
        
        for c in range(taille):
            
            if(l==c):
                N.append(1)
            else:
                N.append(0)
                
        M.append(N)
        
    return M

def saisie_auto ():
    taille = int(input("Quelle est la taille de la matrice: "))
    M=[]
    base = 1.0
    
    for l in range(taille):
        N=[]
        
        for c in range(taille):
            print("M[",l,"][",c,"] = ",base)
            N.append(base);
            base += 1.0
    
        M.append(N)
        
    return M


def affichage(M):
    n = len(M[0])
    
    for l in range(n):
        
        for c in range(n):
            print('[',M[l][c],']',end=" ")
            
        print('\n')

def addition_matrice():
    return M


# Exercice 5 : Tp 1
def multiplie_ligne(M,i,a):
    
    for c in range(len(M[i])):
        M[i][c] *= a
        
    return M

# Exercice 6 : Tp 1
def permuter_ligne(M,i,j):
    
    for c in range(len(M[0])):
        M[i][c],M[j][c] = M[j][c],M[i][c]
        
    return M

# Exercice 7 : Tp 1
def transvection_ligne(M,i,j,a):
    
    for c in range(len(M[0])):
        M[i][c] = (a*M[j][c]) + M[i][c]
        
    return M

# Exercice 8 a : Tp 1
def multiplie_colonne(M,i,a):
    
    for l in range(len(M[i])):
        M[l][i] *= a
        
    return M

# Exercice 8 b : Tp 1
def permuter_colonne(M,i,j):
    
    for l in range(len(M[0])):
        M[l][i],M[l][j] = M[l][j],M[l][i]
        
    return M

# Exercice 8 c : Tp 1
def transvection_colonne(M,i,j,a):
    
    for l in range(len(M[0])):
        M[l][i] = (a*M[l][j]) + M[l][i]
        
    return M

# Exercice 9 : Tp 1
def transposition(M):

    N = M[:]
    
    for l in range(1,len(N[0])):
        
        for c in range(l):
            N[l][c],M[c][l] = N[c][l],N[l][c]
    
    return N

# Exercice 10 : Tp 1
def produit_matrice(M,N):
    # condition M a autant de colonne que N a de ligne
    if(len(M[0]) != len(N)):
       print("Multiplication impossible")
       return False
    
    MN = []
    
    for l in range(len(M)):
        temp=[]

        for c in range(len(N[0])):
            somme = 0.0
            
            for i in range(len(M[0])):
                somme += M[l][i] * N[i][c]

            temp.append(somme)

        MN.append(temp)

    return MN

# Exercice 10 : Tp 1
def compare_matrice(M,N):
    if(len(M)!= len(N)):
        return False
    
    for i in range(len(M)):
        
        for j in range(len(M)):
            # deux float égaux si val absolue supérieur à la précision 10^-10
            if(abs(M[i][j]-N[i][j])> 0.0000000001):
                return False

    return True
