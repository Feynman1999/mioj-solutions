# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    # 缩进请使用 4 个空格，遵循 PEP8 规范
    # please write your code here
    s = line
    a ,b = s.split('-')
    return int(a)-int(b)
    # return 'your_answer'