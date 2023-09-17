path = ""
dic = {}

td,tq = list(map(int,input().split(" ")))

while td:
    td -= 1
    thislinetokens = input()[1:-1].split(" ") # 去除 <> 并按照空格取出token ['hh', 'qwq=123', 'rew', '=', '345']
    if thislinetokens == [""]: break
    name = thislinetokens[0]
    tokens = thislinetokens[1:]
    if name[0] == '/':
        path = path[:1-len(name)]
        if path: path = path[:-1]
        continue
    # else
    path += ("." if path else "") + name
    
    i,length = 0,len(tokens)
    """
    k=v         k=v
    k =v        k,=v
    k= v        k=,v
    k = v       k,=,v
    
    """
    while i < length:
        #k=v; k=,v
        if "=" in tokens[i]:
            key,value = tokens[i].split("=")
            if value == "": 
                value = tokens[i+1]
                i+=1
            
        else:
        # k,=,v; k,=v
            key,value = tokens[i],tokens[i+1]
            i+=1
            if value == "=":
                value = tokens[i+1]
                i+=1
            elif value[0] == "=":
                value = value[1:]
            else:
                pass # 合法 则不可能出现此情况
        dic[path+"~"+key] = value
        i += 1

# print(dic)

while tq:
    tq -= 1
    q = input()
    if not q: break
    print(dic.get(q,"Not found!"))

