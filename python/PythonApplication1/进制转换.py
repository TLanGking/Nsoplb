#name = "我是你爹"
#age = 666

#text = f"尊敬的{name}先生,您的大会员等级为：{age}"

#print(text)

#text2 = f"尊敬的{name}先生,您的大会员等级为：{age:#b}" #  :#b  (二进制)

#print(text2)

#text3 = f"尊敬的{name}先生,您的大会员等级为：{age:#o}" #   :#o  (八进制)

#print(text3)

#text = f"尊敬的{name}先生,您的大会员等级为：{age:#x}"  #      :#x (十六进制)

#print(text)

temp1 = bin(666) # bin() 十进制 -> 二进制

temp2 = oct(666)  # oct() 十进制 -> 8进制

temp3 = hex(666)  # hex()  十进制 -> 16进制

#print(temp1)
#print(temp2)
#print(temp3)

value1 = int(temp1,base= 2)
value2 = int(temp2,base= 8)
value3 = int(temp3,base= 16)

print(value1)
print(value2)
print(value3)
