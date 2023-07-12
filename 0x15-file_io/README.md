# C Programming Project: File I/O

This project involves working with file descriptors and the I/O system calls in C, specifically the `open`, `close`, `read`, and `write` calls, as well as the `O_RDONLY`, `WR_ONLY`, and `O_RDWR` flags to create, open, close, read, write, and set permissions of files in C.

The three standard file descriptors are as follows:

| Integer value | Name            | `<unistd.h>` symbolic constant | `<stdio.h>` file stream |
| ------------- | -------------- | -------------------------------| ------------------------|
| 0             | Standard Input | STDIN_FILENO                   | stdin                   |
| 2             | Standard Output| STDOUT_FILENO                  | stdout                  |
| 3             | Standard Error | STDERR_FILENO                  | stderr                  |

In addition to these calls, this project involves working with the POSIX standard output.

## Tests :heavy_check_mark:

The `tests` folder contains the test files that were provided by the `alx-intranet`.

## Header File :file_folder:

The `holberton.h` file is the header file that contains prototypes for all functions written in the project.

| File                      | Prototype                                                            |
| ------------------------- | -------------------------------------------------------------------- |
| `0-read_textfile.c`       | `ssize_t read_textfile(const char *filename, size_t letters);`       |
| `1-create_file.c`         | `int create_file(const char *filename, char *text_content);`         |
| `2-append_text_to_file.c` | `int append_text_to_file(const char *filename, char *text_content);` |

## Tasks :page_with_curl:

The project includes the following tasks:

### Task 0: Tread lightly, she is near

This task is implemented in the `0-read_textfile.c` file. It involves creating a C function that reads a text file and prints it to the POSIX standard output.

The `letters` parameter is the number of letters the function should read and print. If the file is `NULL` or cannot be opened or read, the function returns `0`. If the `write` call fails or does not write the expected number of bytes, the function returns `0`. Otherwise, the function returns the actual number of bytes the function can read and print.

### Task 1: Under the snow

This task is implemented in the `1-create_file.c` file. It involves creating a C function that creates a file.

The `filename` parameter is the name of the file to create, while the `text_content` parameter is a null-terminated string to write to the file. If `text_content` is `NULL`, the function creates an empty file.

The created file has the permissions `rw-------`. If the file already exists, the existing permissions are not changed. Existing files are truncated. If `filename` is `NULL` or the function fails, it returns `-1`. Otherwise, it returns `1` on success.

### Task 2: Speak gently, she can hear

This task is implemented in the `2-append_text_to_file.c` file. It involves creating a C function that appends text at the end of a file.

The `filename` parameter is the name of the file, while the `text_content` parameter is a null-terminated string to append to the file. The function does not create the file if it does not exist. If `text_content` is `NULL`, nothing is added to the file.

If the function fails or `filename` is `NULL`, it returns `-1`. If the file does not exist or the user lacks write permissions on the file, it returns `-

