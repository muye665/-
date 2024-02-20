from my_utils import str_util
from my_utils import file_util

a = '山重水复疑无路'
print(f"字符串为：{a}")
print(f"字符串反转结果为：{str_util.str_reverse(a)}")
print(f"字符串序列从2到4的切片为：{str_util.substr(a,2,4)}")

b = "D:\\bill.txt"
file_util.print_file_info(b)

