for _ in range(int(input())):
    r,b,e = map(int,input().split())

    R = {}
    B = {}

    for i in range(r):
        R['R'+str(i+1)]= 'R'+str(i+1)
    for i in range(b):
        B['B'+str(i+1)]= 'B'+str(i+1)


    R_in = list(map(str,input().split()))
    B_in = list(map(str,input().split()))
    for i in range(len(R_in)):
        R['R'+str(i+2)]= R_in[i]

    for i in range(len(B_in)):
        B['B'+str(i+2)]=B_in[i]



    for _ in range(e):
        o,x,y = input().split()
        if(o=='w'):

            mr=1000000000
            mb=1000000000

            cr = 0
            cb = 0

            fr=True

            while x!='R1' and x!='B1':
                # print(x)
                if(fr==True):
                    x = R[x]
                    cr = cr  + 1
                    
                if(fr==False):
                    x = B[x]
                    cb = cb + 1



                if(x[0]=='B'):
                    fr=False
                    cb = cr
                elif(x[1]=='R'):
                    fr=True
                    cr =cb


            if(cr>0): 
                mr = min(cr,cr)
            if(cb>0):
                mb = min(mb,cb)


            cr = 0
            cb = 0

            fb=True
            while(y!='B1' and y!= 'R1'):
                if(fb==True):
                    y = B[y]
                    cb = cb  + 1
                if(fb==False):
                    y = R[y]
                    cr = cr + 1



                if(y[0]=='R'):
                    fb=False
                    cr = cb
                elif(y[1]=='B'):
                    fb=True
                    cb =cr



            if(cr>0): 
                mr = min(cr,cr)
            if(cb>0):
                mb = min(mb,cb)



            if(mr == mb):
                print('TIE',mr)
            elif(mr<mb):
                print('RED',mr)
            elif(mb<mr):
                print('BLUE',mb)

        if(o=='c'):
            if(x[0]=='B'):
                B[x]=y
            else:
                R[x]=y




