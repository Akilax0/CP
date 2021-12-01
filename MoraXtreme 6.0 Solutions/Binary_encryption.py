import numpy as np
        
def count(msg):
    frequency = dict()
    
    
    for letter in msg:
        
        if frequency.get(letter) == None:
            frequency[letter] = 1
            
        else:
            frequency[letter] += 1
    chars = list(frequency.keys())
    vals = list(frequency.values())
    order = sorted([[vals[i],chars[i]]for i in range(len(chars))])
    for i in range(len(chars)):
        chars[i] = order[i][1]
        vals[i] = order[i][0]
    
    return chars,vals

def encrypt(message):
    
    chars,freqs = count(message)
    if len(message)==1:
        return 0
    char_dict = dict()
    for i,j in zip(chars,freqs):
        char_dict[i] = ''
        
    #print(chars,freqs)
    while len(chars)>1:
        
        char1 = chars.pop(0)
        char2 = chars.pop(0)
        
        freq1 = freqs.pop(0)
        freq2 = freqs.pop(0)
        new_freq = freq1+freq2
        for i in char1:
           char_dict[i] = '0'+char_dict[i]
        for i in char2:
            char_dict[i] = '1'+char_dict[i]
        index = -1
        for i in range(len(chars)):
            if freqs[i] >= new_freq:
                index = i
                break
        freqs.insert(index,new_freq)        
        chars.insert(index,char1+char2)

    encrypted = ''
    for char in message:
        encrypted += char_dict[char]
    #print(encrypted)
    #print(char_dict)
    return encrypted

if __name__ == '__main__':
    message = input()
    print(encrypt(message))