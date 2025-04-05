class Solution(object):
    def fib(self, n):
        n1=0
        n2=1
        if n==0:
            return n1
        elif n==1:
            return n2
        else:
            for i in range(2,n+1):
                fib=n1+n2
                n1=n2
                n2=fib
        return fib
        