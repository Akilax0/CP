while(True):
    s = input()
    ret = 0
    for i in range(len(s)):
        ret = ret + ord(s[i])

    print(ret)
