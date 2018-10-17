# Leading k digits of n!:

We know
```
log10(a) = b
=> a = 10^b
```
if: b = x + y

x = integer part of b
y = decimal part of b

0 <= 10^y < 10

now: 
```
1st digit = pow(10,y );
1st 2 digits = pow(10,y+1 );
...
1st k digits = pow(10,y+k-1 );
```
so for `n!`
`b = log10(1*2*..*(n-1)*n) = log10(1)+log10(2) + ... + log10(n-1) + log10(n);`

1st k digits for n! = pow(10,y+k-1);

# Trilling K digits for n!:

Trilling k digits = (1*2*..*(n-1)*n)%10^(k-1) 


# Problem Resource:

1) https://www.codechef.com/problems/FRJUMP
2) http://lightoj.com/volume_showproblem.php?problem=1282