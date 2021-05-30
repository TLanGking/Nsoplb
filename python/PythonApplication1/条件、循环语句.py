while True:
    print("1.开始游戏")
    print("2.更多游戏")
    print("3.游戏设置")
    print("4.官方论坛")
    print("5.退出游戏")
    temp = int(input("请输出您的选项->"))

    if temp == 1:
        print("您选择开始游戏！")
    elif temp == 2:
        print("如需访问更多游戏，请登录网站:'http:\\www.4399.com'")
    elif temp == 3:
        print("此功能还未开放，敬请期待！")
    elif temp == 4:
        print("请自行登录官网！")
    elif temp == 5:
        print("您真的要退出游戏吗？")
        value = int(input("1(是) / 2(否) ->"))
        if value == 1:
            print("感谢使用！")
            break
        elif value == 2:
            continue
    else:
        print("输入错误!")