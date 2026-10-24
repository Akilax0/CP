# Max Consecutive Sums

The problem asks to find the maximum conseuctive number of 1 in a binary array. 
The solution is naively done by iterating through each element and keeping a local count `curr` and compares with `max_cons` which is the global max count. If 0 is enountered reset curr.

