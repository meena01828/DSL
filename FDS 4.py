from array import array

# Define matrices as lists of lists
x = [[1, 2], [4, 5]]
y = [[7, 8], [9, 10]]

# Element-wise addition
add_result = [[x[i][j] + y[i][j] for j in range(len(x[0]))] for i in range(len(x))]
print("The element-wise addition of matrices is:")
print(add_result)

# Element-wise subtraction
sub_result = [[x[i][j] - y[i][j] for j in range(len(x[0]))] for i in range(len(x))]
print("The element-wise subtraction of matrices is:")
print(sub_result)

# Transpose of matrix
transpose_result = [[x[j][i] for j in range(len(x))] for i in range(len(x[0]))]
print("The transpose of the given matrix is:")
print(transpose_result)
