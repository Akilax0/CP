eq = ['-','+','*']


def check_brackets(s):
	if s[0] in eq or s[-1] in eq:
		return False
	return True

def ans(s):

	if s[0] in eq or s[-1] in eq:
		return -1

	for i in range(len(s)):
		if(s[i]=='*'):
			a = ans(s[:i])
			b = ans(s[i+1:])


			if a == -1 or b==-1:
				return "invalid"

			return a * b
			
		elif(s[i]=="+"):
			

	return eval(s)


for _ in range(int(input())):
	s = input()

	print(" ")

	if(check_brackets(s)):
		print(ans(s))
	else:
		print("invalid")
