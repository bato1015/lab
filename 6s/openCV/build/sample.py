from copy import deepcopy
import numpy as np

data = np.zeros((257,128,100), dtype=np.uint8)
for x in range(data.shape[0]):
    for y in range(data.shape[1]):
        for z in range(data.shape[2]):
            if (x-50)**2+(y-50)**2+(z-50)**2 < 50**2 and z < 50.5:
                data[x,y,z] = 1

def crofton_surface(data):
    padded = np.pad(data, 1, 'constant', constant_values=0)

    cross_section_sum = 0

    # along axis X, Y, Z
    for axis in [0, 1, 2]:
        diff = np.abs(np.sign(np.diff(padded,axis=axis)))
        cross_section = np.sum(diff)
        cross_section_sum += cross_section

    # along axis XY, YZ, ZX, -XY, -YZ, -ZX
    for axis1 in [0, 1, 2]:
        for axis2 in [0, 1, 2]:
            if axis1 >= axis2:
                continue
            for sgn in [1, -1]:
                rolled = deepcopy(padded)
                for i in range(padded.shape[axis1]):
                    slicer = tuple([(slice(None) if j != axis1 else [i]) for j in range(3)])
                    rolled[slicer] = np.roll(rolled[slicer], i*sgn, axis=axis2)

                diff = np.abs(np.sign(np.diff(rolled, axis=axis1)))
                cross_section = np.sum(diff) * (2**-0.5)
                cross_section_sum += cross_section

    # along axis XYZ, XY-Z, X-Y-Z, X-YZ
    rollsgn = [
        [1, 1],
        [1, -1],
        [-1, 1],
        [-1, -1]
    ]
    for sgns in rollsgn:
        rolled = deepcopy(padded)
        for i in range(padded.shape[0]):
            rolled[[i], : , :] = np.roll(rolled[[i], : , :], i*sgns[0], axis=1)
            rolled[[i], : , :] = np.roll(rolled[[i], : , :], i*sgns[1], axis=2)

        diff = np.abs(np.sign(np.diff(rolled, axis=0)))
        cross_section = np.sum(diff) * (3**-0.5)
        cross_section_sum += cross_section

    crofton_s = cross_section_sum / 13 * 2
    return crofton_s

print(crofton_surface(data))