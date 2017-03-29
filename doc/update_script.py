# 用于更新本仓库的数据以及readme.md文件
# Python版本要求 Python 3.4+

import os

sources = ['CodeForces', 'CSU', 'FZU', 'HDU', 'HYSBZ', 'PAT', 'POJ', 'UVA', 'ZOJ']
files = []
for file in os.listdir('.'):
    if not file.endswith('.py'): files.append(file)

nestList = []
def dfs(nowfullname, sub, depth):
    # 如果是空的文件夹，说明还没有任何实现，就先不加入内容
    if not os.listdir(nowfullname + sub): return
    dirs = []
    flag = False
    for obj in os.listdir(nowfullname + sub):
        if obj == 'README.md':
            flag = True
        if os.path.isdir(nowfullname + sub + '/' + obj): dirs.append(obj)
    # 如果程序运行到这里，那么说明这个节点是叶子节点
    if not dirs:
        nestList.append('   ' * depth + '- [' + sub + '](.doc' + nowfullname[1:] + sub + ')\n')
        if flag == False:
            print('error @ ', nowfullname + sub)
    else:
        nestList.append('   ' * depth + '- ' + sub + '\n')
        for _dir in dirs:
            dfs(nowfullname + sub + '/', _dir, depth + 1)

for file in files:
    dfs('./', file, 0)

maintext_before = """
    
## 1.目录
    
"""

maintext_after = """
    
## 2.[成就](./src)

## 3.[博客](http://blog.csdn.net/zlqdhrdhrdhr?viewmode=contents)

## 4.参考

- *CLRS 3rd*
- *Algorithm 4th*
- *算法竞赛入门经典*
- *挑战程序设计竞赛*
- *图论算法理论实现及应用*
- *离散数学及其应用*

## 5.[后记](saysomething.txt)


"""


maintext_middle = ''.join(nestList)

final = maintext_before + maintext_middle + maintext_after

# print(final)

f = open('../README.md', 'w', encoding='utf-8')
f.write(final)
f.close()

