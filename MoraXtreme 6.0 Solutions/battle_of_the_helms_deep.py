
import random
import time
#test
# o,c,s,b = 100,1,40,30
# l,m,n = 400,5,2
# k1,k2,k3,k4 = 0.5,2.5,0.7,175
o,c,s,b = map(int,input().split())
l,m,n = map(int,input().split())
k1,k2,k3,k4 = map(int,input().split())


#before battle
L=l
l += n*b*k1 
survivor_rate = l * (s + b)
max_survivor_rate = 0
#sending soldiers+builders to battle
for i in range(b+1):
    soldiers = s
    builders = i
    orcs = o
    limit = l
    catapults_dmg = c * k4
    #1 day 1 iteration
    day = 0
    human_kill_speed = (soldiers+builders/2)*k2
    orc_kill_speed = orcs*k3
    while limit>0 and soldiers+builders>0:
        if m-n == day or orcs <= 0:
            victory = True
            survivor_rate = limit * (soldiers+builders + b-i)
            #print("rate: ",survivor_rate," limit: ",limit)
            #print("after day ",day,"sol: ",soldiers," bul: ",builders," orcs: ",orcs,catapults_dmg)
            
            max_survivor_rate = max(max_survivor_rate,survivor_rate)
            break
            
        human_kill_speed = max((soldiers+builders/2)*k2,0)
        orc_kill_speed = max(orcs*k3,0)

        limit = limit - catapults_dmg + (b-i)*k1
        #average speeds are given, average deaths of soldier and builders are relative to fraction from total
        temp = max(soldiers - orc_kill_speed * soldiers/(soldiers+builders),0)
        builders = max(builders - orc_kill_speed * builders/(soldiers+builders),0)
        soldiers=temp
        orcs = max(orcs - human_kill_speed,0)
        catapults_dmg = c * k4*(orcs/o)#linearly proportional
        day+=1
        
    else:
        victory = False
        survivor_rate = 0

#sending soldiers to battle
for i in range(s+1):
    
    soldiers = i
    builders = b
    orcs = o
    limit = l
    day = 0
    human_kill_speed = soldiers*k2
    orc_kill_speed = orcs*k3
    catapults_dmg = c * k4
    while limit>0 and soldiers+builders>0:
        if m-n == day or orcs <= 0:
            victory1 = True
            survivor_rate = limit * (soldiers+builders + s-i)
            # print("rate: ",survivor_rate," limit: ",limit)
            # print("after day ",day,"sol: ",soldiers," bul: ",builders," orcs: ",orcs,catapults_dmg)
            max_survivor_rate = max(max_survivor_rate,survivor_rate)
            break
        human_kill_speed = max(soldiers*k2,0)
        orc_kill_speed = max(orcs*k3,0)

        limit = limit - catapults_dmg + (builders+(s-i)/2)*k1
        soldiers = max(soldiers-orc_kill_speed ,0)
        orcs = max(orcs-human_kill_speed,0)
        catapults_dmg = c*k4*(orcs/o)
        day+=1
        
    else:
        victory1 = False
        survivor_rate = 0
        
if victory or victory1:
    print("VICTORY")
else:
    print("DEFEAT")

print(round(max_survivor_rate,3))
