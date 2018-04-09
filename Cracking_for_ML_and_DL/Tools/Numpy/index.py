import numpy as np

A=np.arange(3,15)
A=A.reshape((3,4))
print(A)
print(A[2][0])
print(A[2,0])
print(A[2,:])
print(A[:,1])
print(A[1,1:2])

for column in A.T:
	print(column)

# How to do index iteration for a numpy matrix?

print(A.flatten())
for item in A.flat:
	print(item)