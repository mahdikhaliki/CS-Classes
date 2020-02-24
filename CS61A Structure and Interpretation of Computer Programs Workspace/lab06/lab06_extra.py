"""Midterm Review"""
from lab06 import *

# Q6
def summation(n, term):
    """Return the sum of the first n terms of a sequence.

    >>> summation(5, lambda x: pow(x, 3))
    225
    """
    total, k = 0, 1
    while k <= n:
        total, k = total + term(k), k + 1
    return total

def interleaved_sum(n, odd_term, even_term):
    """Compute the sum odd_term(1) + even_term(2) + odd_term(3) + ..., up
    to n.

    >>> # 1 + 2^2 + 3 + 4^2 + 5
    ... interleaved_sum(5, lambda x: x, lambda x: x*x)
    29
    >>> from construct_check import check
    >>> check(LAB_SOURCE_FILE, 'interleaved_sum', ['While', 'For', 'Mod'])
    True
    """
    "*** YOUR CODE HERE ***"
    def sum_odd(total, i):
        if i > n:
            return total
        total += odd_term(i)
        return sum_even(total, i+1)

    def sum_even(total, i):
        if i > n:
            return total
        total += even_term(i)
        return sum_odd(total, i+1)
    return sum_odd(0, 1)

# Q7
def paths(m, n):
    """Return the number of paths from one corner of an
    M by N grid to the opposite corner.

    >>> paths(2, 2)
    2
    >>> paths(5, 7)
    210
    >>> paths(117, 1)
    1
    >>> paths(1, 157)
    1
    """
    "*** YOUR CODE HERE ***"
    def paths_helper(x, y):
        if x == m - 1 and y == n - 1:
            return 1
        elif x >= m or y >= n:
            return 0
        return paths_helper(x+1, y) + paths_helper(x, y+1)

    return paths_helper(0, 0)

# Q8
def insert_into_all(item, lsts):
    """Assuming that lsts is a list of lists, return a new list consisting of
    all the lists in lsts, but with item added to the front of each.

    >>> lsts = [[], [1, 2], [3]]
    >>> insert_into_all(0, lsts)
    [[0], [0, 1, 2], [0, 3]]
    """
    return [[item] + lst for lst in lsts]

def inc_subseqs(s):
    """Assuming that S is a list, return a nested list of all subsequences
    of S (a list of lists) for which the elements of the subsequence
    are strictly nondecreasing. The subsequences can appear in any order.

    >>> seqs = inc_subseqs([1, 3, 2])
    >>> sorted(seqs)
    [[], [1], [1, 2], [1, 3], [2], [3]]
    >>> inc_subseqs([])
    [[]]
    """
    def subseq_helper(s, prev):
        if not s:
            return ____________________
        elif s[0] < prev:
            return ____________________
        else:
            with_first = ______________________
            without_first = ______________________
            return insert_into_all(________, ______________) + ________________
    return subseq_helper(____, ____)

# Q9
def dict_to_lst(d):
    """Returns a list containing all the (key, value) pairs in d as two-element
    tuples ordered by increasing value.

    >>> nums = {1: 5, 2: 3, 3: 4}
    >>> dict_to_lst(nums)
    [(2, 3), (3, 4), (1, 5)]
    >>> words = {'first': 'yes', 'second': 'no', 'third': 'perhaps'}
    >>> dict_to_lst(words)
    [('second', 'no'), ('third', 'perhaps'), ('first', 'yes')]
    """
    result = []
    for _ in range(len(d)):
        pair = min(d.items(), key=lambda item: item[1])
        d.pop(pair[0])
        result.append(pair)
    return result

# Q10
def filter(pred, lst):
    """Filters lst with pred using mutation.
    >>> original_list = [5, -1, 2, 0]
    >>> filter(lambda x: x % 2 == 0, original_list)
    >>> original_list
    [2, 0]
    """
    "*** YOUR CODE HERE ***"
    for elem in lst[:]:
        if not pred(elem):
            lst.remove(elem)

# Q11
def replace_all(d, x, y):
    """Replace all occurrences of x as a value (not a key) in d with y.
    >>> d = {3: '3', 'foo': 2, 'bar': 3, 'garply': 3, 'xyzzy': 99}
    >>> replace_all(d, 3, 'poof')
    >>> d == {3: '3', 'foo': 2, 'bar': 'poof', 'garply': 'poof', 'xyzzy': 99}
    True
    """
    "*** YOUR CODE HERE ***"
    for i in d:
        if d[i] == x:
            d[i] = y

# Q12
def prune_leaves(t, vals):
    """Return a modified copy of t with all leaves that have a label
    that appears in vals removed.  Return None if the entire tree is
    pruned away.

    >>> t = tree(2)
    >>> print(prune_leaves(t, (1, 2)))
    None
    >>> numbers = tree(1, [tree(2), tree(3, [tree(4), tree(5)]), tree(6, [tree(7)])])
    >>> print_tree(numbers)
    1
      2
      3
        4
        5
      6
        7
    >>> print_tree(prune_leaves(numbers, (3, 4, 6, 7)))
    1
      2
      3
        5
      6
    """
    "*** YOUR CODE HERE ***"
    if is_leaf(t) and label(t) in vals:
        return None
    return tree(label(t), [b for b in branches(t)])

# Q13
def add_trees(t1, t2):
    """
    >>> numbers = tree(1,
    ...                [tree(2,
    ...                      [tree(3),
    ...                       tree(4)]),
    ...                 tree(5,
    ...                      [tree(6,
    ...                            [tree(7)]),
    ...                       tree(8)])])
    >>> print_tree(add_trees(numbers, numbers))
    2
      4
        6
        8
      10
        12
          14
        16
    >>> print_tree(add_trees(tree(2), tree(3, [tree(4), tree(5)])))
    5
      4
      5
    >>> print_tree(add_trees(tree(2, [tree(3)]), tree(2, [tree(3), tree(4)])))
    4
      6
      4
    >>> print_tree(add_trees(tree(2, [tree(3, [tree(4), tree(5)])]), \
    tree(2, [tree(3, [tree(4)]), tree(5)])))
    4
      6
        8
        5
      5
    """
    "*** YOUR CODE HERE ***"



def traverse_tree(t):
    print(label(t))
    for b in branches(t):
        traverse_tree(b)
