str = "abcdedab"
# print(str[1])
for i in range(len(str)):
    if str.count(str[i])==1:
        print(i)
        break
    # if i not in str[i]:
    #     print(str[i])
    # print(i)