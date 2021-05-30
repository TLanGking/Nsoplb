# 1、%
#name = str(input("请输入您的姓名->"))
#age = int(input("请输入您的年龄->"))
#text = "尊敬的%s先生,您的VIP等级为%d级" %(name,age)

#text2 = "尊敬的%(name)s先生,您的VIP等级为%(age)d级" %{"name":name,"age":age}

#print(text)
#print(text2)
# 2.format
#name = str(input("请输入您的姓名->"))
#age = int(input("请输入您的年龄->"))
##text = "尊敬的{}先生,您的VIP等级为{}级".format(name,age)

##text = "尊敬的{0}先生,您的VIP等级为{1}级"
#text = "尊敬的%(name)s先生,您的VIP等级为%(age)d级"

##text2 = text.format(name,age)
#text2 = text % {"name":name,"age":age}

#print(text2)

#3.f

name = str(input("请输入您的姓名->"))
age = int(input("请输入您的年龄->"))

#text = f"尊敬的{name}先生,您的VIP等级为{age}级"

text = f"尊敬的{name + '是我爹'}先生,您的VIP等级为{age + 1000 = }级"

print(text)