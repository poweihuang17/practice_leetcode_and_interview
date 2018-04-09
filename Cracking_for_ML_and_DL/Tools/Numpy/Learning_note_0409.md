# numpy learning note
- Is pandas really so important?

## Useful link in chinese
- https://www.youtube.com/watch?v=2TkMujKoDPI&index=4&list=PLXO45tsB95cKKyC45gatc8wEc3Ue7BlI4

## Numpy basic
- Create a array using two dimensional list
- Attributes of numpy array
-- Number of dim
-- shape
-- size

## Create array
- zeros
- empty: no assignment
- array: need input to initialize
- arange: similar to range in python. with steps.
- reshape: reshape it into mxr
- linspace: could define how many parts will we have.

## Basic operation
- +: add element by element
- **: square or... x**2=x**x element by element.
- b<3: true or false for every element
- matrix operation : * for element-wise, dot for matrix multiplication
- random.random- initialize a random matrix
- sum/min/max could be applied through axis. The axis=i means for loop through the ith index.

## Basic operation II
- argmin: index of minimum value: flattened index
- argmax: index of maximum value
- Why flattened index? I don't know...
- mean and average are all for calculation of average number.
- Half of this clip. Maybe need to stop.
- median/cumsum/diff : easy to understand
- nonzero: this is really hard to understand why do we need this.
- sort: sort by each row.
- transpose
- clip: saturation
- Each operation could select axis

##  Numpy index
- A[1][2], A[1,2], A[1,:],A[1,1:2]
- Q : How to do index iteration for a numpy matrix?
- For loop for row and column(use transpose)
- flat and flatten- iterate through all item.
- Did I miss anything in this clip?
- Maybe....
- Need to check it later.