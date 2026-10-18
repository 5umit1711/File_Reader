# File Reader

File Reader is a C++17 command-line program that recursively scans the `test_data` directory, builds a word index, and prints the lines containing an exact word match. Searches are case-insensitive; words may contain letters, digits, and underscores.

## Requirements

- A C++17-compatible compiler (GCC)
- GNU Make

### Install on Windows

Install MSYS2 from [msys2.org](https://www.msys2.org/) (or with `winget install --id MSYS2.MSYS2 -e`). Open the **MSYS2 UCRT64** terminal and install the compiler and Make:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc make
```

Use that terminal to build the project. Alternatively, if GCC and Make are already available in your `PATH`, run the build command from PowerShell or Command Prompt.

### Install on Ubuntu / Debian

```sh
sudo apt update
sudo apt install build-essential
```

## Build

From the project root (the directory containing `Makefile`):

```sh
make
```

This creates `file_reader.exe`. To remove the generated executable:

```sh
make clean
```

## Run

Run the program from the project root so it can find the `test_data` directory. Pass one word to search for:

**PowerShell**

```powershell
.\file_reader.exe example
```

**MSYS2 / Linux**

```sh
./file_reader.exe example
```

The search is case-insensitive and matches whole words, not substrings. For example, searching for `reader` does not match `readers`. The program prints matching lines and their file names; if there are no matches, it reports that no matches were found. Add or edit text files under `test_data` to search your own content.

## Push to GitHub

Create an empty repository on GitHub, then run these commands from the project root. Replace the URL with the URL of your repository:

```sh
git init
git add .
git commit -m "Add File Reader"
git branch -M main
git remote add origin https://github.com/<your-username>/<your-repository>.git
git push -u origin main
```
