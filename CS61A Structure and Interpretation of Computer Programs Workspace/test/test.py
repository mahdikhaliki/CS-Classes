def compress(lst):
    total, result, i = 0, [], 0
    for element in lst:
        if type(element) == int:
            total += element
            result[i] = sum(result[i:], total)
        else:
            result += compress(lst)
            total = 0
            i += 1

    return result



