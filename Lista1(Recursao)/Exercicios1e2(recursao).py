import math
print ("Lista 1 Exercício 1")
n = str(input("insira um número inteiro: "))
def InvertString(n):
    if (len(n) <=1):
        return n
    else:
        return n[-1] + InvertString(n[:-1])
    
print(InvertString(n))

print ("Lista 1 Exercício 2")
n = int(input("insira um número inteiro: "))
naux = n
def Count(n, naux):
    if (n == -naux):
        return abs(n)
    else:
        print (abs(n))
        return Count(n-1, naux)
    
print(Count(n, naux))
x = int(input(""))
