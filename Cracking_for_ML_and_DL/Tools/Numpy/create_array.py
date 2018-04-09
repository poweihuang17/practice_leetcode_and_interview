import numpy as np

array=np.array([[1,2,3],[2,3,4]])
print (array)

print ('number of dimension:',array.ndim)
print ('shape', array.shape)
print ('size', array.size)

a=np.array([[2,3,4],[1,2,3]],dtype=np.int)
print (a.dtype)

a=np.array([[2,3,4],[1,2,3]],dtype=np.float32)
print (a.dtype)


a=np.zeros((3,4))
print (a)

a=np.empty((3,4))
print (a)
#Similar to range
a=np.arange(10,20,2)

a=np.arange(12).reshape(3,4)
print (a)

a=np.linspace(1,10,20).reshape((4,5))
print (a)