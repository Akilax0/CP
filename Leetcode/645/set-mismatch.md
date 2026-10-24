# Set Mismatch

Given a set of `s` integers 1 to `n` , some error has caused on number to duplicate to another number. An array that has a reptition of one number and loss of another. 

Find the number that repeats, and the number that is missing. 

Since we know the elements in the array keep a hash map count of the encountered elements. 

Second approach is get the total expected sum and take the difference with the sum of the array. 
Since the most iterated element known the difference reveals the missing number. 
