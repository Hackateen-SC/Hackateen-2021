def inv(a, m) :
     
    m0 = m
    x0 = 0
    x1 = 1
 
    if (m == 1) :
        return 0
 
    while (a > 1) :
        q = a // m
        t = m
 
        m = a % m
        a = t
 
        t = x0
        x0 = x1 - q * x0
        x1 = t
     
    if (x1 < 0) :
        x1 = x1 + m0
 
    return x1

def findMinX(primes, modules):
     
    prod = 1
    for i in range(4) :
        prod = prod * primes[i]
 
    result = 0
 
    for i in range(4):
        pp = prod // primes[i]
        result = result + modules[i] * inv(pp, primes[i]) * pp
     
     
    return result % prod

def nCrModpDP(n, r, p):
    C = [0] * (r + 1);
    C[0] = 1;
    for i in range(1, (n + 1)):
        j = min(i, r);
        while(j > 0):
            C[j] = (C[j] + C[j - 1]) % p;
            j -= 1;
    return C[r];
 
def nCrModpLucas(n, r, p):
    if (r == 0):
        return 1;
        
    ni = int(n % p);
    ri = int(r % p);
    
    return (nCrModpLucas(int(n / p), int(r / p), p) *
            nCrModpDP(ni, ri, p)) % p;
 
for t in range(int(input())):

    n = int(input())

    primes = [43, 47, 73, 137]
    modules = []
    for prime in primes:
        modules.append( nCrModpLucas(2 * n - 1, n - 1, prime) )

    print( ((n % 20212021) * findMinX(primes, modules)) % 20212021 )
