# Standardization in Sklearn
- Link: http://scikit-learn.org/stable/modules/preprocessing.html


## Standardiztion

- Question:

-- If there are multiple outliers in our data, how do we scale and normalize it correctly?

- "If some outliers are present in the set, robust scalers or transformers are more appropriate. The behaviors of the different scalers, transformers, and normalizers on a dataset containing marginal outliers is highlighted in Compare the effect of different scalers on data with outliers."

-- I think it's quite tricky for this question.

## import 
- from sklearn import preprocessing

## Dummy scaling
- Will make the mean equals to 0, and std equals to 1.
- Vulnerable to outliers.


### API
- preprocessing.scale(X_train)

### Utilize the same transformation on testing data
- scaler = preprocessing.StandardScaler().fit(X_train)
- scaler.transform(X_train)

### The above is the content of 4.3.1
