def findSaddlePoint(mat, n): 
    for i in range(n): 
        min_row = mat[i][0] 
        col_ind = 0 
        for j in range(1, n): 
            if min_row > mat[i][j]: 
                min_row = mat[i][j] 
                col_ind = j 
 
        k = 0 
        for k in range(n): 
            if min_row < mat[k][col_ind]: 
                break 
 
        if k == n - 1: 
            print("Value of Saddle Point", min_row) 
            return True 
 
    return False 
 
if __name__ == '__main__': 
    mat = [[1, 2, 3], 
           [4, 5, 6], 
           [7, 8, 9]] 
     
    n = 3 
    if not findSaddlePoint(mat, n): 
        print("No Saddle Point")

