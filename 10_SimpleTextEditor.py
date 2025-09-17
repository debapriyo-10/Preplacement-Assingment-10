
def simpleTextEditor(operations):
    text = ""
    history = []
    result = []
    for op in operations:
        if op[0] == "1":
            history.append(text)
            text += op[1]
        elif op[0] == "2":
            history.append(text)
            k = int(op[1])
            text = text[:-k]
        elif op[0] == "3":
            result.append(text[int(op[1])-1])
        elif op[0] == "4":
            text = history.pop()
    return result
