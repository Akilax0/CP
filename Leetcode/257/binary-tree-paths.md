# Binary Tree Paths

Given the root of a binary tree return all root-to-leaf paths. 

Accessing children of Binary Tree 
Left = 2 * i
Right = 2*i+1
Parent = floor\[i/2\]

Since each leaf has one path from root, Iterate through all the leafs and go back till root. 

Or we could do BFS and return but need to keep track of path in the iteration/recurson.