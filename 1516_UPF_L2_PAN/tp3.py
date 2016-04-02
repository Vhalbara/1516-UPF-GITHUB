from time import time

def main():

    print(coef_binomial_iter(6,13))
    
    print(coef_binomial_Pascal(6,13))

    
def fact_iterative (n):
    p = 1
    
    for i in range(n):
        p *= i+1
        
    return p

def fact_recursive (n):
    
    if(n <= 0):
        return 1;

    return n * fact_recursive(n-1)

def coef_binomial_iter(n,k):
    if(n < k):
        return 0
    return fact_iterative(n) / (fact_iterative(k) * fact_iterative(n-k))

def binom_recur(n,k):
    if(n < k):
        return 0
    return fact_recursive(n) / (fact_recursive(k) * fact_recursive(n-k))

def binom_Pascal(n,k):

    if(n < k):
        return 0
    
    if(k == 0):
        return 1
    
    return coef_binomial_Pascal(k-1,n-1) + coef_binomial_Pascal(k,n-1)

def binom_optimiser(n,k):
    if(n < k):
        return 0
    
    p=1

    for i in range(1,n-k+1):
        p *= (i+k) / i

    return p

# exo 3
def Fibonacci_Recursive(n):
    if(n == 0 or n == 1):
        return n

    return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2)

def Fibonacci_Iterative(n):
    a,b = 0,1
    
    for u in range(1,n):
        n = b + a
        b,a = n,a

    return b

# exo 4
def somme_chiffre (n,b):
    if(n < b):
        return n

    return somme_chiffre(n//b,b) + (n%b)

# exo 5
def PGCD (a,b):

    if(b==1):
        return a
    
    else:
        # return PGCD(a-b,b) # Ne suffit pas
        return PGCD(b,abs(a-b)) # Car PGCD(b,a) = PGCD(a,b) 
    
