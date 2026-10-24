Given an array of positive integers. 

Alice and Bob playing a game, Alice can chooses either all single digit numbers or all double digit numbers and the rest given to Bob.

Alice wins if her sum of numbers is greater than Bob. 

return True if Alice can win. 


Iterate through the list. 
- get the sum of single digit numbers. 
- get the sum of double digit numbers. 
- get the total sum 

if single digit sum  > total sum - single digit or double digit sum > total sum - double digit then Alice wins. retrun True. 