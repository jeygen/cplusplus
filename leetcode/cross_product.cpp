/*
Problem Statement: Cross Product of 3D Vectors

Given two 3D vectors represented as arrays, calculate their cross product.

Function Signature:

python
Copy code
def crossProduct(v1: List[int], v2: List[int]) -> List[int]:
Input:

Two lists, v1 and v2, each of length 3. -10^4 <= v1[i], v2[i] <= 10^4
Output:

A list of length 3 representing the cross product of v1 and v2.
Example:

Input:

python
Copy code
v1 = [1, 0, 0]
v2 = [0, 1, 0]
Output:

python
Copy code
[0, 0, 1]
Note:

For two vectors v1 = [a1, b1, c1] and v2 = [a2, b2, c2], the cross product v1 x v2 is given by:

python
Copy code
[
    (b1*c2 - c1*b2),
    (c1*a2 - a1*c2),
    (a1*b2 - b1*a2)
]
*/
