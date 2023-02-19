import numpy as np
import sys
from copy import deepcopy

mat = []  # 結果を入れるリスト(行列)
data = np.zeros((256,256,256), dtype=np.uint8)

#データ読み込み
def depth_data(mat):
    with open('../shindokaku.txt', 'r', encoding='utf-8') as fin:  # ファイルを開く
        for line in fin.readlines():  # 行をすべて読み込んで1行ずつfor文で回す

            row = []  # 行のデータを保存
            #row = np.array([300, 300, 300])
            toks = line.split(' ')  # 行をカンマで分割する

            for tok in toks:  # 分割したトークン列を回す
                try:
                    num = float(tok)  # 整数に変換
                except ValueError:
                    print(e, file=sys.stderr)  # エラーが出たら画面に出力して
                    continue  # スキップ

                row.append(num)  # 行に保存

            mat.append(row)  # 行をnumsに保存
            

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
                cross_section = np.sum(diff)* (2**-0.5)
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


depth_data(mat)# 関数
arr_1d = np.array(mat)#list to array

#３次元ボクセル処理
for height in range(arr_1d.shape[0]): 
    for weight in range(arr_1d.shape[1]):
        num_depth=round(arr_1d[height][weight]/(5/256))

        #data[height,weight,num_depth]=1 # 表面のみ代入
        if(num_depth==0):
            data[height,weight,num_depth]=1
        for depth in range(num_depth): #体積的な
            data[height,weight,depth]=1

np.savetxt('data2.txt',arr_1d,fmt='%f')
#丸め込み
for height in range(arr_1d.shape[0]): 
    for weight in range(arr_1d.shape[1]):
        w=round(arr_1d[height][weight]/(5/256))
        arr_1d[height,weight]=w

#確認行為
print(crofton_surface(data)*((5/256)**2)-12.5)
"""#print(data[61,125,226])
print(data[59,123+9,199])
#print(data.index(1))
x=np.where(data==1)
print(x)"""
#print(data[0,3,0])
np.savetxt('data1.txt',arr_1d,fmt='%d')


