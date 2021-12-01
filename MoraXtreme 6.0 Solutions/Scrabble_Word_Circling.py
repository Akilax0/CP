
from typing import NamedTuple, List, Dict, Optional
from random import choice
from string import ascii_uppercase
from typing import Generic, TypeVar, Dict, List, Optional
from abc import ABC, abstractmethod

Grid = List[List[str]]  # type alias for grids

V = TypeVar('V') # variable type
D = TypeVar('D') # domain type


# Base class for all constraints
class Constraint(Generic[V, D], ABC):
    # The variables that the constraint is between
    def __init__(self, variables: List[V]) -> None:
        self.variables = variables

    # Must be overridden by subclasses
    @abstractmethod
    def satisfied(self, assignment: Dict[V, D]) -> bool:
        ...

class CSP(Generic[V, D]):
    def __init__(self, variables: List[V], domains: Dict[V, List[D]]) -> None:
        self.variables: List[V] = variables # variables to be constrained
        self.domains: Dict[V, List[D]] = domains # domain of each variable
        self.constraints: Dict[V, List[Constraint[V, D]]] = {}
        for variable in self.variables:
            self.constraints[variable] = []
            if variable not in self.domains:
                raise LookupError("Every variable should have a domain assigned to it.")

    def add_constraint(self, constraint: Constraint[V, D]) -> None:
        for variable in constraint.variables:
            if variable not in self.variables:
                raise LookupError("Variable in constraint not in CSP")
            else:
                self.constraints[variable].append(constraint)

    def consistent(self, variable: V, assignment: Dict[V, D]) -> bool:
        for constraint in self.constraints[variable]:
            if not constraint.satisfied(assignment):
                return False
        return True

    def backtracking_search(self, assignment: Dict[V, D] = {}) -> Optional[Dict[V, D]]:
        # assignment is complete if every variable is assigned (our base case)
        if len(assignment) == len(self.variables):
            return assignment

        # get all variables in the CSP but not in the assignment
        unassigned: List[V] = [v for v in self.variables if v not in assignment]

        # get the every possible domain value of the first unassigned variable
        first: V = unassigned[0]
        for value in self.domains[first]:
            local_assignment = assignment.copy()
            local_assignment[first] = value
            # if we're still consistent, we recurse (continue)
            if self.consistent(first, local_assignment):
                result: Optional[Dict[V, D]] = self.backtracking_search(local_assignment)
                # if we didn't find the result, we will end up backtracking
                if result is not None:
                    return result
        return None

class GridLocation(NamedTuple):
    row: int
    column: int


def generate_grid(rows: int, columns: int, letters: List[str]) -> Grid:
    # initialize grid with random letters
    return [[letters[r][c] for c in range(columns)] for r in range(rows)]


def display_grid(grid: Grid) -> None:
    for row in grid:
        print("".join(row))


def generate_domain(word: str, grid: Grid) -> List[List[GridLocation]]:
    domain: List[List[GridLocation]] = []
    height: int = len(grid)
    width: int = len(grid[0])
    length: int = len(word)
    for row in range(height):
        for col in range(width):
            columns: range = range(col, col + length)
            rows: range = range(row, row + length)
            if col + length <= width:
                # left to right
                # domain.append([GridLocation(row, c) for c in columns])
                grid_locs = [(grid[row][c], GridLocation(row, c)) for c in columns]
                word_aplha, positions  = zip(*grid_locs)
                if ''.join(word_aplha) == word:
                    domain.append(list(positions))
                elif ''.join(word_aplha[::-1]) == word:
                    domain.append(list(positions)[::-1])
                # diagonal towards bottom right
                if row + length <= height:
                    # domain.append([GridLocation(r, col + (r - row)) for r in rows])
                    grid_locs = [(grid[r][col + (r - row)], GridLocation(r, col + (r - row))) for r in rows]
                    word_aplha, positions  = zip(*grid_locs)
                    if ''.join(word_aplha) == word:
                        domain.append(list(positions))
                    elif ''.join(word_aplha[::-1]) == word:
                        domain.append(list(positions)[::-1])
            if row + length <= height:
                # top to bottom
                # domain.append([GridLocation(r, col) for r in rows])
                grid_locs = [(grid[r][col], GridLocation(r, col)) for r in rows]
                word_aplha, positions  = zip(*grid_locs)
                if ''.join(word_aplha) == word:
                    domain.append(list(positions))
                elif ''.join(word_aplha[::-1]) == word:
                    domain.append(list(positions)[::-1])
                # diagonal towards bottom left
                if col+1 - length >= 0:
                    # domain.append([GridLocation(r, col - (r - row)) for r in rows])
                    grid_locs = [(grid[r][col - (r - row)], GridLocation(r, col - (r - row))) for r in rows]
                    word_aplha, positions  = zip(*grid_locs)
                    if ''.join(word_aplha) == word:
                        domain.append(list(positions))
                    elif ''.join(word_aplha[::-1]) == word:
                        domain.append(list(positions)[::-1])
    return domain


class WordSearchConstraint(Constraint[str, List[GridLocation]]):
    def __init__(self, words: List[str]) -> None:
        super().__init__(words)
        self.words: List[str] = words

    def satisfied(self, assignment: Dict[str, List[GridLocation]]) -> bool:
        # if there are any duplicates grid locations then there is an overlap
        all_locations = [locs for values in assignment.values() for locs in values]
        return len(set(all_locations)) == len(all_locations)


if __name__ == "__main__":
    n = int(input())

    letters : List[str] = [input().upper() for i in range(n)]
    grid: Grid = generate_grid(n,n, letters)

    words: List[str] = [l.upper() for l in input().split()]
    locations: Dict[str, List[List[GridLocation]]] = {}
    for word in words:
        locations[word] = generate_domain(word, grid)
    csp: CSP[str, List[GridLocation]] = CSP(words, locations)
    csp.add_constraint(WordSearchConstraint(words))
    solution: Optional[Dict[str, List[GridLocation]]] = csp.backtracking_search()
    if solution is None:
        print("No solution found!")
    else:
        print("Solution found")
        for word, grid_locations in solution.items():
            pos_dict = []
            for index, letter in enumerate(word):
                (row, col) = (grid_locations[index].row, grid_locations[index].column)
                latter = grid[row][col]
                pos_dict.append(f"{letter} : ({row},{col})")
            print(" | ".join(pos_dict))

