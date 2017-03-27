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
    for obj in os.listdir(nowfullname + sub):
        if os.path.isdir(nowfullname + sub + '/' + obj): dirs.append(obj)
    # 如果程序运行到这里，那么说明这个节点是叶子节点
    if not dirs:
        nestList.append('   ' * depth + '- [' + sub + '](' + nowfullname + sub + ')\n')
    else:
        nestList.append('   ' * depth + '- ' + sub + '\n')
        for _dir in dirs:
            dfs(nowfullname + sub + '/', _dir, depth + 1)

for file in files:
    dfs('./', file, 0)

maintext_before = """
    
    ## 算法总结
    
"""

maintext_after = """
    
    ## [博客]()

    ## 参考

    - *CLRS 3rd*
    - *Algorithm 4th*
    - *算法竞赛入门经典*
    - *挑战程序设计*
    - **

"""


