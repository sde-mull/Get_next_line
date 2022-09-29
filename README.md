<table>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/78042197/192562397-81efc45d-0387-46df-bae4-ddf3a284c745.png" width=75px height=75px/></td>
    <td><h1 align="left"> Get_next_line - 42Project &nbsp&nbsp</td>
  </tr>
</table>

>**_Reading a line from a fd is way too tedious_**

<p align="justified">
  The aim of this project is to create a function that reads from file descriptors and returns line by line everytime is called until the end of the file.
</p>

<h4>Prototype</h4>

```bash
char *get_next_line(int fd);
```

<h2>How to use it</h2>
<h4>Clone the repository</h4>

```bash
git clone https://github.com/sde-mull/Get_next_line.git
```
<h4>Run your program</h4>

```bash
in your file.c
#include "Get_next_line/get_next_line.h"        //for one file descriptor
#include "Get_next_line/get_next_line_bonus.h"  //for multiple files descriptors at the same time

then compile with
gcc file.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c              //for one file descriptor
gcc file.c Get_next_line/get_next_line_bonus.c Get_next_line/get_next_line_utils_bonus.c  //for multiple files descriptors at the same time
```
<h2>Grade:</h2>
<img width="1033" alt="image" src="https://user-images.githubusercontent.com/78042197/193090681-2202fc70-39db-4fc3-b433-04fcda43f6b0.png">


