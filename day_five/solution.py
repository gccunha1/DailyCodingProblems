def cons(a, b):
    def pair(f):
        return f(a, b)

    return pair


def car(par):
    def return_first(a, b):
        return a

    return par(return_first)


def cdr(par):
    def return_last(a, b):
        return b

    return par(return_last)


if __name__ == "__main__":
    print(cdr(cons(3, 4)))
    print(car(cons(3, 4)))
