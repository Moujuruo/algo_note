def permutation(S):
    if not S:
        return [[]]
    else:
        res, perms = [], permutation(S[1:])
        for i, _ in enumerate(S):
            for perm in perms:
                res.append(perm[:i] + [S[0]] + perm[i:])
        return res
    
print(permutation([1, 2, 3]))