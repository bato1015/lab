import numpy as np
import sys

mat = []  # 結果を入れるリスト(行列)
data = np.zeros((129,257,257), dtype=np.uint8)

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
            

depth_data(mat)# 関数
arr_1d = np.array(mat)#list to array
for height in range(arr_1d.shape[0]): 
    for weight in range(arr_1d.shape[1]):
        num_depth=round(arr_1d[height][weight]/(5/256))
        data[height,weight,num_depth]=1

np.savetxt('data2.txt',arr_1d,fmt='%f')
for height in range(arr_1d.shape[0]): 
    for weight in range(arr_1d.shape[1]):
        w=round(arr_1d[height][weight]/(5/256))
        arr_1d[height,weight]=w
#print(data[61,125,226])
print(data[59,123+9,199])
#print(data.index(1))
x=np.where(data==1)
print(x)
np.savetxt('data1.txt',arr_1d,fmt='%d')
