#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'generatePasscode' function below.
#
# The function accepts INTEGER n as parameter.
#

def generatePasscode(n):
    # Write your code here
    if n>0 and n<1000 :
        if (n<3):
            print("Invalid Model Name")
        elif (n%3==0 and n%5==0):
            print("S"*n)
        else:
            temp=n
            d5=1
            c3=0 
            while True:
                if (d5!=0 and d5>0):
                    temp=temp-3
                    d5=math.fmod(temp,5)
                    c3=c3+1
                else:
                    break
           
            if d5<0:
                if n%5==0:
                    print("H"*n)
                else:
                    print("Invalid Model Name")
            elif d5==0:
                c3=c3*3
                c5=n-c3
                if (c3>c5 and c3%3==0):
                    print("S"*c3 + "H"*c5 )
                   
                
                elif (c5>c3 and c5%3==0):
                    print("S"*c5 + "H"*c3)
                   
                
                else:
                    print("S"*c3 + "H"*c3)
                 
            else:
                print("Invalid Model Name")
    else:
        print("Invalid Model Name")
        

if __name__ == '__main__':
    g = 5

    for g_itr in range(g):
        n = int(input().strip())

        generatePasscode(n)
