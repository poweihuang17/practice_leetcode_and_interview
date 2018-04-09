# Note about ch14

## Multiple data origins 
- Each data may have different dimensions.

## Purpose
- Faster or data visualization.

## Hard to ascribe the meaning to the eigenvectors.
- Need to use weight or other factor to figure out what's most important for each eigenvectors.

## PCA
- Try to minimize the distance between points and line.

## PCA is not linear regression
- Linear regression focuses on y
- But PCA focuses on vertical distance

## Steps of PCA
- Mean and Normalized.
- Compute covariance
- Compute the eigenvectors by SVD. (Usually other methods to find eigenvectors, but SVD gives the same result in this case)
-- (U,S,V)=svd(Sigma);
-- Z=UX;
-- Sigma= (1/m) XXi;
-- Find the first K column of U.

## Above is the content of 14.1-14.4.

## 14.5, 14.6, 14.7
- How to choose K?
- Reconstruction from PCA results?
- Advice for applying PCA

