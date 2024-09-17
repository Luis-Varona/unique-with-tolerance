# %%
import numpy as np
from numba import jit

# %%
eps = lambda x: np.finfo(x).eps

def isapprox(
        x: float, y: float, *,
        atol: float = 1e-8,
        rtol: float = None,
):
    if atol < 0:
        raise ValueError("`atol` must be non-negative")
    if rtol is None:
        rtol = max(eps(x), eps(y))**0.5
    elif rtol < 0:
        raise ValueError("`rtol` must be non-negative")
    
    return abs(x - y) <= max(atol, rtol * max(abs(x), abs(y)))

# %%
@jit(nopython=True)
def findfirst_farfrom(c: float, vec: np.ndarray, *, atol: float, rtol: float):
    idx = None
    for i, x in enumerate(vec):
        if abs(x - c) > max(atol, rtol * max(abs(c), abs(x))):
            idx = i
            break
    return idx

# %%
def uniquetol(
        vec: np.ndarray, *,
        atol: float = 1e-8,
        rtol: float = None,
        return_indices: bool = False,
        return_inverse: bool = False,
        return_counts: bool = False,
        occurrence: str = 'highest',
):
    if atol < 0:
        raise ValueError("`atol` must be non-negative")
    if rtol is None:
        rtol = eps(vec.dtype)**0.5
    elif rtol < 0:
        raise ValueError("`rtol` must be non-negative")
    if occurrence not in {'highest', 'lowest'}:
        raise ValueError('`occurrence` must be either "highest" or "lowest"')
    
    n = len(vec)
    
    if n == 0:
        vec_unique = np.empty(0)
        return_indices and (indices_unique := np.empty(0))
        return_inverse and (inverse_unique := np.empty(0))
        return_counts and (counts_unique := np.empty(0))
    else:
        isclose = lambda x, y: isapprox(x, y, atol=atol, rtol=rtol)
        
        perm_sorted = np.argsort(vec)
        vec_sorted = vec[perm_sorted]
        indices_unique = []
        idx = -1
        idx_switch = 0
        
        while idx_switch is not None:
            idx += idx_switch + 1
            indices_unique.append(idx)
            # if (idx_new := idx + 1) >= n:
            #     break
            # else:
            #     print(idx_new)
            c = vec_sorted[idx]
            idx_switch = findfirst_farfrom(c, vec_sorted[(idx + 1):], atol=atol, rtol=rtol)
        
        indices_unique = np.array(indices_unique)
        
        if return_counts or return_inverse:
            counts_unique = np.diff(np.append(indices_unique, n))
            if return_inverse:
                inverse_unique = np.concatenate(
                    [np.repeat(idx, ct) for idx, ct in enumerate(counts_unique)]
                )
                inverse_unique = inverse_unique[np.argsort(perm_sorted)]
        
        if occurrence == 'highest':
            indices_unique = np.append(indices_unique[1:] - 1, n - 1)
        
        indices_unique = perm_sorted[indices_unique]
        vec_unique = vec[indices_unique]
    
    if return_indices or return_inverse or return_counts:
        output_temp = []
        return_indices and output_temp.append(indices_unique)
        return_inverse and output_temp.append(inverse_unique)
        return_counts and output_temp.append(counts_unique)
        output = tuple([vec_unique, *output_temp])
    else:
        output = vec_unique
    
    return output