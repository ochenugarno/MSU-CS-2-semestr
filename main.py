def add(p1, p2):
    p = dict()
    for key in p1:
        p[key] = p.get(key, 0) + p1[key]
    for key in p2:
        p[key] = p.get(key, 0) + p2[key]
    for key in list(p.keys()):
        if p[key] == 0:
            p.pop(key)
    return p


def mul(p1, p2):
    p = dict()
    for key1 in p1:
        p_el = dict()
        for key2 in p2:
            p_el[key1 + key2] = p1[key1] * p2[key2]
        p = add(p, p_el)
    return p

def print_pol(p):
    s = 1
    for keys in p:
        if s == 1:
            if p[keys] < 0:
                print(-p[keys], 'x^', keys, sep = '', end = '')
            else:
                print(p[keys], 'x^', keys, sep = '', end = '')
        else:
            if p[keys] < 0:
                print(' - ', -p[keys], 'x^', keys, sep = '', end = '')
            else:
                print(' + ', p[keys], 'x^', keys, sep = '', end = '')
        s += 1



def eval_poly(p, x):
    summ = 0
    for key in p:
        summ += x ** key * p[key]
    return summ


p1 = {0: 1, 2: 1}
p2 = {0: 1, 2: -1}
print_pol(p1)
print('')
print_pol(p2)
print('')
print_pol(mul(p1, p2))
print('')
print(eval_poly(p1, 10))
