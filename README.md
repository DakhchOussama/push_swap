# Push Swap Project

Welcome to the Push Swap project! 🔄 This project challenges you to implement a sorting algorithm for a set of integers using two stacks.

## Project Overview

- **Language:** C 🖋
- **Norm:** The project must adhere to the Norm, including bonus files/functions. 📋
- **Memory Management:** Functions should not quit unexpectedly (e.g., segmentation fault, bus error) except for undefined behaviors. Properly free all heap-allocated memory space to avoid memory leaks. 🚮
- **Makefile:** Submit a Makefile to compile your source files with the flags `-Wall`, `-Wextra`, and `-Werror`. Use `cc`, and the Makefile must not relink. 🛠️
- **Makefile Rules:** Include at least the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re` in your Makefile. 🗂️
- **Bonus Rules:** If applicable, include a `bonus` rule in your Makefile, adding headers, libraries, or functions that are forbidden in the main part of the project. Bonuses should be in a different file `_bonus.{c/h}`. 🌟
- **Libft Usage:** If your project allows using your libft, copy its sources and its associated Makefile into a libft folder. Your project’s Makefile must compile the library using its Makefile, then compile the project. 📚
- **Test Programs:** While not mandatory for submission, creating test programs is encouraged for testing your work and your peers’ work. These tests can be useful during your defense. 🧪

## Project Details

Implement a sorting algorithm that efficiently rearranges a stack of integers. The challenge is to perform the sorting with a limited set of operations on two stacks, following a set of rules.

### Sorting Rules

- `sa`: Swap the first two integers at the top of stack A. 🔀
- `sb`: Swap the first two integers at the top of stack B. 🔀
- `ss`: Execute `sa` and `sb` simultaneously. 🔄
- `pa`: Push the first integer at the top of stack A to stack B. ⬆️
- `pb`: Push the first integer at the top of stack B to stack A. ⬆️
- `ra`: Rotate the integers on stack A upwards, moving the first integer to the bottom. 🔄
- `rb`: Rotate the integers on stack B upwards, moving the first integer to the bottom. 🔄
- `rr`: Execute `ra` and `rb` simultaneously. 🔄
- `rra`: Rotate the integers on stack A downwards, moving the last integer to the top. 🔄
- `rrb`: Rotate the integers on stack B downwards, moving the last integer to the top. 🔄
- `rrr`: Execute `rra` and `rrb` simultaneously. 🔄

## Evaluation

- Mandatory and bonus parts will be evaluated separately. 📊
- Peer evaluations are allowed during defense. You can use your tests or the tests of the peer you are evaluating. 👥

## Submission

1. Clone this repository to your local machine. 🔄
2. Implement your solution following the project requirements. 🚀
3. Add test programs for evaluation and defense. 🧪
4. Submit your work to your assigned Git repository. 📤

## How to Use 🚀

1. Clone the repository to your local machine. 🔄
2. Navigate to the project folder. 🗂️
3. Build the project using the provided Makefile.
   ```
   $ make
   ```
Happy coding! 🚀
