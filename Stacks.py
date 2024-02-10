class Stacks:
    def __init__(self) -> None:
        pass
    
    def is_balanced(self, parentheses):
        stack = []
        mapping = {"}":"{",
                   "]":"[",
                   ")":"("}
        for char in parentheses:
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack
    
    def reverse_string(self, str):
        stack = []
        for char in str:
            stack.append(char)
        reversed_string = ""
        while stack:
            reversed_string += stack.pop()
        return reversed_string



if __name__ == "__main__":
    stacks = Stacks()
    print(stacks.is_balanced("()[]"))
    print(stacks.reverse_string("password"))