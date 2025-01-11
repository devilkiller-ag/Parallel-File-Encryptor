## Parallel File Encryptor using Multithreading in C++


## Prerequisite to run the project
Create a `.env` file having your `encryption_key` in the project root directory.

## How to run the project?
To run the whole project run these commands in your terminal:
1. `make clean` to clean the project.
2. `make` to build the project.
3. Run `./encrypt_decrypt` to encrypt and decrypt the file.
    - It will ask the directory of the files to encrypt/decrypt.
    - It will then ask task to perform (ENCRYPT/DECRYPT).

To run the standalone cryption program run these commands in your terminal:
1. `make clean` to clean the project.
2. `make cryption` to build the project.
3. Run `./cryption your_task_data_here` to encrypt/decrypt the data.
    - It will ask the task to perform (ENCRYPT/DECRYPT).


### Prerequisite to debug in VS Code

Add following files inside the `.vscode` folder:

1. `launch.json`:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug encrypt_decrypt",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/encrypt_decrypt",
            "args": [],
            "cwd": "${workspaceFolder}",
            "preLaunchTask": "build"
        },
        {
            "name": "Debug cryption (standalone)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/cryption",
            "args": ["your_task_data_here"],
            "cwd": "${workspaceFolder}",
            "preLaunchTask": "build"
        }
    ]
}
```
For linux use `"type": "cppdbg"`, for mac use `"type": "lldb"`, and for windows use `"type": "gdb"`.


2. `task.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "build",
            "command": "make",
            "args": [],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```
