# %%
import numpy as np

from collections import namedtuple
from random import shuffle

from uniquetol import uniquetol

# %%
def GetVariables():
    #-
    numOnes = np.random.randint(1, 14)
    ctsInitial = np.empty(100, int)
    ctsInitial[:numOnes] = 1
    ctsInitial[numOnes:] = np.random.randint(2, 14, 100 - numOnes)
    
    #-
    rangeVals = (np.random.randint(-87, -12), np.random.randint(13, 88))
    valsInitial = np.random.uniform(rangeVals[0], rangeVals[1] + 1, 100)
    
    #-
    rangeShifts = (np.random.randint(-334, -86), np.random.randint(87, 335))
    shifts = np.random.randint(rangeShifts[0], rangeShifts[1] + 1, 100)
    valsInitial += shifts
    
    #-
    diffs = [np.random.uniform(1e-7, 1e-7, ct) for ct in ctsInitial]
    testArr = np.concatenate([v + ct for v, ct in zip(valsInitial, diffs)])
    shuffle(testArr)
    
    #-
    (u, ix, inv, cts) = uniquetol(
        testArr,
        return_indices=True, return_inverse=True, return_counts=True,
    )
    spaces = np.diff(u)
    
    #-
    Vars = namedtuple('Vars', 'testArr u ix inv cts spaces')
    return Vars(testArr, u, ix, inv, cts, spaces)


# %%
def main():
    global variables
    variables = GetVariables()
    
    global testArr, u, ix, inv, cts, spaces
    (testArr, u, ix, inv, cts, spaces) = variables
    
    print("`return_index` functionality working: ", end = '')
    print(testArr[ix] == u)
    
    print("`return_inverse` functionality working: ", end = '')
    print(testArr == u[inv])
    
    print(variables)


# %%
main()