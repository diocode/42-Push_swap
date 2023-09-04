![philo_banner-01](https://github.com/diocode/philosophers/assets/107859177/c31a55ab-a055-4a8c-aee5-988e24c4970e)

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/evaluated-05%20%2F%2019%20%2F%202023-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/score-86%20%2F%20100-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/diocode/philosophers?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/diogo-gsilva' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#examples">Examples</a> •
	<a href="#norminette">Norminette</a>
</p>

## ABOUT ([Subject](/.github/en.subject.pdf))

The "Push Swap" project is a fundamental algorithm task that focuses on sorting data using two stacks and a limited set of instructions in the most efficient way possible. The objective is to write a C program, called push_swap, that calculates and displays the smallest program (a sequence of instructions) to sort a set of integer values provided as arguments.

The project aims to teach the importance of sorting algorithms, complexity analysis, and the use of basic algorithms in C programming. It involves managing two stacks, a and b, and performing operations like swapping, pushing, rotating, and reverse rotating to sort the elements in stack a in ascending order. The program must minimize the number of instructions while ensuring the proper sorting of elements. It should handle various error cases and provide clear error messages when necessary. Compliance with specified rules, including a Makefile for compilation and avoidance of global variables, is essential for a successful project evaluation.

<a href="/.github/en.subject.pdf">Click here</a> for the subject of this project.

<br>

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
$ ./git clone git@github.com:diocode/42-Push_swap.git
```

#### 2º - Enter the project folder and run `make`
```bash
$ ./cd 42-Push_swap
$ ./make
```

#### 3º - Launch the program
> The input numbers can be in a single string or individual arguments. <br>
> You can use any selection of numbers separated by spaces to be sorted.
```bash
$ ./push_swap [nbr] [nbr] [nbr] [nbr] [nbr] ...
```
or
```bash
$ ./push_swap ["number number number number ...."]
```

<br>

#### MAKEFILE COMMANDS
`make` or `make all` - Compile program **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

#### TIPS
> Use the program [`push_swap_visualizer`](https://github.com/o-reo/push_swap_visualizer) to better see the program in action. <br>
> Make sure you have a C++ compiler(gcc, clang,...) and cmake installed and updated.

![Screenshot from 2023-09-04 12-58-56](https://github.com/diocode/42-Push_swap/assets/107859177/80137c5f-4b4a-402e-ab34-44df84f82bf6)

1º - Clone the repository
```bash
$ ./git clone git@github.com:o-reo/push_swap_visualizer.git
```
2º - Move `push_swap_visualizer` inside `42-Push_swap` <br>

3º - Inside push_swap_visualizer:
```bash
$ ./mkdir build
```
4º - Inside build:
```bash
$ ./mkdir cmake ..
$ ./mkdir make
```
5º - Run the visualizer
```bash
$ ./bin/visualizer
```
<br>

## EXAMPLES
 > The performance will change if you use `-fsanitize`, `valgrind` or both together.
 
| Example | Expected Result |
| :-- | :-- |
| `./push_swap 42`           | Display nothing (0 instructions)                                             |
| `./push_swap 0 1 2 3`             | Display nothing (0 instructions)                                   |
| `./philo 4 -500 200 200`          | Invalid argument.                                              |
| `./philo 4 214748364732 200 200`  | Invalid argument.                                              |
| `./philo 1 200 200 200`           | Philosopher 1 takes a fork and dies after 200 ms.              |
| `./philo 4 500 200 2147483647`    | A philosopher dies after 500 ms                                |
| `./philo 4 200 210 200`           | A philosopher dies, it should display the death before 210 ms. |
| `./philo 4 310 200 200`           | A philosopher dies.                                            |
| `./philo 5 800 200 200 7`         | The program stops when each philosopher has eaten 7 times.     |
| `./philo 5 800 200 200`           | No philosopher dies.                                           |
| `./philo 4 2147483647 200 200`    | No philosopher dies.                                           |
| `./philo 5 800 200 150`           | No philosopher dies.                                           |
| `./philo 3 610 200 80`            | No philosopher dies.                                           |
| `./philo 2 800 200 200`           | No philosopher dies.                                           |
| `./philo 4 410 200 200`           | No philosopher dies.                                           |

<br>

## NORMINETTE
At 42 School, projects are generally expected to adhere to the Norm, the school's coding standard:

```
- No for, do while, switch, case or goto are allowed
- No more than 25 lines per function and 5 functions per file
- No assigns and declarations in the same line (unless static)
- No more than 5 variables in 1 function
... 
```
