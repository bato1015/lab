import seiretu
from copy import deepcopy


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
        cross_section = np.sum(diff)* (3**-0.5)
        cross_section_sum += cross_section

    crofton_s = cross_section_sum / 13 * 2
    return crofton_s

print(crofton_surface(data)*se)