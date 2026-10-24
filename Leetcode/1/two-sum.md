# TWO SUM


We can think of solving this naivly by iterating through the elements. 
For each element, check for another element later in the array that would add up to the target. 

This solution has a time complexity of O(n^2) because of the nested loop. 


To get a better time complexity can use a hashmap. 
This will allow us to step away from O(n^2)  and go for O(n).

The hashmap keeps track of the seen elements and their indexes. This is done assuming all elements are unique.