def LongestWordLength(str):
    n = len(str)
    res = 0;
    curr_len = 0;
    longest = ""

    for i in range(0, n):
        if (str[i] != ' '):
            longest += str[i]
            curr_len += 1
        else:
            res = max(res, curr_len)
            curr_len = 0
            longest = ""
    return max(res, curr_len), longest


def countOccurance(str, char):
    count = 0
    for i in str:
        if i == char:
            count = count + 1
    return char, count


def isPalindrome(str):
    for i in range(0, int(len(str) / 2)):
        if str[i] != str[len(str) - i - 1]:
            return False
    return True


def subStr(mainstr, sub):
    res = []
    flag = 0
    k = 0
    for i in range(0, len(mainstr)):
        k = i
        flag = 0
        for j in range(len(sub)):
            if mainstr[k] != sub[j]:
                flag = 1
            if flag:
                break
            k = k + 1
        if flag == 0:
            res.append(i)
    return res


def freq(str):
    str = str.split()
    str2 = []
    for i in str:
        if i not in str2:
            str2.append(i)

    print("Frequency of each word in the string is")
    for i in range(0, len(str2)):
        print('Frequency of', str2[i], 'is :', str.count(str2[i]))


flag = 1
while flag == 1:
    print("\n\n/*************MENU**************/\n")
    print("1. To display word with the longest length :")
    print("2. To determines the frequency of occurrence of particular character in the string ")
    print("3. To check whether given string is palindrome or not :")
    print("4. To display index of first appearance of the substring :")
    print("5. To count the occurrences of each word in a given string :")
    print("6. Exit \n")
    choice = int(input("Enter your choice : "))

    if choice == 1:
        # s = input("Enter the String to find the longest word : ")
        s = "The sky was sunny and beautiful"
        l, str = LongestWordLength(s)
        print("Longest word is {1} of length {0}".format(l, str))

    elif choice == 2:
        # s = input("Enter the String to find the occurance of a particular character : ")
        # c = input("Enter the character whose occurance is to be find : ")
        c = "s"
        c, cnt = countOccurance(s, c)
        print("Character {0} occured {1} times in string : {2} ".format(c, cnt, s))

    elif choice == 3:
        s = input("Enter the String to check palindrome: ")
        if isPalindrome(s):
            print("Yes string {0} is palindrome ".format(s))
        else:
            print("No string {0} is not palindrom ".format(s))

    elif choice == 4:
        # s = input("Enter the main String : ")
        # s1 = input("Enter the substring : ")
        s = "The sky was sunny and beautiful"
        s1 = "ful"
        print("starting indices of substring {1} in string {0} is {2} ".format(s, s1, subStr(s, s1)))

    elif choice == 5:
        s = " BMW BMW Ferrari Ferrari BMW Kia Audi Audi"
        freq(s)

    else:
        print("Wrong choice")
        flag = 0

